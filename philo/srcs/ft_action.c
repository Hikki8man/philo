/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 04:12:07 by jchevet           #+#    #+#             */
/*   Updated: 2021/12/06 14:05:00 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	talk(t_philo *philo, char *str, u_int64_t time, int is_main)
{
	pthread_mutex_lock(&philo->info->talk);
	if (philo->info->philo_died != 1 || is_main)
		printf("%llu %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->info->talk);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->prev->fork);
	talk(philo, "has taken a fork", philo->info->time, 0);
	pthread_mutex_lock(&philo->fork);
	talk(philo, "has taken a fork", philo->info->time, 0);
}

void	eat(t_philo *philo)
{
	philo->time_before_dying = philo->info->time + (u_int64_t)philo->info->time_to_die;//todo test if it still works + add for bonus
	talk(philo, "is eating", philo->info->time, 0);
	custom_sleep(philo->info, (u_int64_t)philo->info->time_to_eat);
	pthread_mutex_unlock(&philo->prev->fork);
	pthread_mutex_unlock(&philo->fork);
	philo->meals--;
}

void	sleepy(t_philo *philo)
{
	talk(philo, "is sleeping", philo->info->time, 0);
	custom_sleep(philo->info, (u_int64_t)philo->info->time_to_sleep);
}
