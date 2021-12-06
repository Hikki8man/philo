/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 04:13:20 by jchevet           #+#    #+#             */
/*   Updated: 2021/12/06 15:02:26 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*clock_th(void *arg)
{
	t_info			*info;
	struct timeval	start;
	struct timeval	curr;
	u_int64_t		t1;
	u_int64_t		t2;

	info = (t_info *)arg;
	gettimeofday(&start, NULL);
	while (info->all_done != 1)
	{
		gettimeofday(&curr, NULL);
		t1 = (u_int64_t)((start.tv_sec * 1000) + (start.tv_usec / 1000));
		t2 = (u_int64_t)((curr.tv_sec * 1000) + (curr.tv_usec / 1000));
		info->time = t2 - t1;
		usleep(100);
	}
	return (NULL);
}

int	lonely_philo(t_philo *philo)
{
	if (philo->prev != NULL)
		return (0);
	talk(philo, "has taken a fork", time_in_ms(philo->info->start), 0);
	custom_sleep(philo->info, philo->info->time_to_die);
	talk(philo, "died", time_in_ms(philo->info->start), 0);
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (lonely_philo(philo) == 1)
		return (NULL);
	wait_thread_and_start_in_mismatch(philo);
	while (1)
	{
		if (philo->info->philo_died || meals_done(philo))
			break ;
		take_forks(philo);
		eat(philo);
		if (philo->info->philo_died || meals_done(philo))
			break ;
		sleepy(philo);
		talk(philo, "is thinking", time_in_ms(philo->info->start), 0);
	}
	if (meals_done(philo))
	{
		pthread_mutex_lock(&philo->info->philo_done_eating);
		philo->info->done_eating += 1;
		pthread_mutex_unlock(&philo->info->philo_done_eating);
	}
	return (NULL);
}
