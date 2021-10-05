/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 04:13:20 by jchevet           #+#    #+#             */
/*   Updated: 2021/09/30 04:13:22 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	lonely_philo(t_philo *philo)
{
	if (philo->prev != NULL)
		return (0);
	talk(philo, "has taken a fork", time_in_ms(philo->info->start));
	custom_sleep(philo->info, philo->info->time_to_die);
	talk(philo, "died", time_in_ms(philo->info->start));
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (lonely_philo(philo) == 1)
		return (NULL);
	wait_thread_and_start_in_mismatch(philo);
//	philo->time_before_dying = time_in_ms(philo->info->start) + philo->info->time_to_die;
	while (1)
	{
		if (philo_died(philo) || meals_done(philo))
			break ;
		take_forks(philo);
		eat(philo);
		if (philo_died(philo) || meals_done(philo))
			break ;
		sleepy(philo);
		talk(philo, "is thinking", time_in_ms(philo->info->start));
	}
	return (NULL);
}
