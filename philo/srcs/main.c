/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 04:11:45 by jchevet           #+#    #+#             */
/*   Updated: 2021/12/03 11:20:28 by jchevet          ###   ########lyon.fr   */
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

int	main(int ac, char **av)
{
	t_info		info;
	t_philo		*philo;
	pthread_t	thread_time;

	if (ac == 5 || ac == 6)
	{
		init_info(&info);
		if (parse_args(ac, av, &info) != 0)
			return (error("Arguments invalid", 0, NULL, info));
		philo = create_list_of_philo(&info);
		if (create_threads(philo, &info) != 0)
			return (1);
		gettimeofday(&info.start, NULL);
		pthread_create(&thread_time, NULL, &clock_th, (void *)&info);
		info.threads_created = 1;
		if (info.nb_of_philo > 1)
			check_death(philo);
		if (join_threads(philo, info) != 0 || destroy_mutex(philo, info) != 0)
			return (2);
		info.all_done = 1;
		if (pthread_join(thread_time, NULL) != 0)
			return (error("Pthread_join failure", 1, philo, info));
		free_philo_list(philo, info);
		return (0);
	}
	write(2, "Error\nWrong number of arguments\n", 33);
	return (1);
}
