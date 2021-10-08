/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:59:52 by jchevet           #+#    #+#             */
/*   Updated: 2021/10/08 14:59:53 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	*check_death_time(void *arg)
{
	t_philo			*philo;
	struct timeval	start;
	struct timeval	curr;
	unsigned long	t1;
	unsigned long	t2;

	philo = (t_philo *)arg;
	gettimeofday(&start, NULL);
	while (1)
	{
		gettimeofday(&curr, NULL);
		t1 = (unsigned long)((start.tv_sec * 1000) + (start.tv_usec / 1000));
		t2 = (unsigned long)((curr.tv_sec * 1000) + (curr.tv_usec / 1000));
		philo->info->time = (int)(t2 - t1);
		if (philo->info->time > philo->time_before_dying)
			philo_died(philo);
		usleep(100);
	}
}

void	create_thread(t_philo *philo)
{
	pthread_t	clock;

	if (pthread_create(&clock, NULL, &check_death_time, (void *)philo) != 0)
		error("FAILED TO CREATE THREAD");
}
