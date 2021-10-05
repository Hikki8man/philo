/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 04:11:45 by jchevet           #+#    #+#             */
/*   Updated: 2021/09/30 04:11:48 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	error(char *str, int free_list, t_philo *philo, t_info info)
{
	if (free_list == 1)
		free_philo_list(philo, info);
	printf("Error\n%s\n", str);
	return (1);
}
//TODO make thread for time so every philo has same var

void *thread_time(void *arg)
{
	t_info *info;
	struct timeval	start;
	struct timeval	curr;
	unsigned long	t1;
	unsigned long	t2;

	info = (t_info *)arg;
	gettimeofday(&start, NULL);
	while (1)
	{
		gettimeofday(&curr, NULL);
		pthread_mutex_lock(&info->talk);
		t1 = (unsigned long)((start.tv_sec * 1000) + (start.tv_usec / 1000));
		t2 = (unsigned long)((curr.tv_sec * 1000) + (curr.tv_usec / 1000));
		info->time = (int)(t2 - t1);
		pthread_mutex_unlock(&info->talk);
		usleep(1000);
	}
}

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	*philo;
	pthread_t time;

	if (ac == 5 || ac == 6)
	{
		init_info(&info);
		if (parse_args(ac, av, &info) != 0)
			return (error("Arguments invalid", 0, NULL, info));
		philo = create_list_of_philo(&info);
		if (create_threads(philo, &info) != 0)
			return (1);
		gettimeofday(&info.start, NULL);
		pthread_create(&time, NULL, &thread_time, (void *)&info);
		info.threads_created = 1;
		if (info.nb_of_philo > 1)
			check_death(philo);
		if (join_threads(philo, info) != 0 || destroy_mutex(philo, info) != 0)
			return (2);
		free_philo_list(philo, info);
	}
	return (0);
}