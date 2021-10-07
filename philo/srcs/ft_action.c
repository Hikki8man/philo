/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 04:12:07 by jchevet           #+#    #+#             */
/*   Updated: 2021/09/30 04:12:15 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	talk(t_philo *philo, char *str, time_t time)
{
	pthread_mutex_lock(&philo->info->talk);
	if (philo->info->philo_died != 1)
		printf("%ld %d %s\n", time, philo->id, str);
	if (ft_strcmp(str, "died") == 0)
		philo->info->philo_died = 1;
	pthread_mutex_unlock(&philo->info->talk);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->prev->fork);
	talk(philo, "has taken a fork", philo->info->time);
	pthread_mutex_lock(&philo->fork);
	talk(philo, "has taken a fork", philo->info->time);
}
void	eat(t_philo *philo)
{
	talk(philo, "is eating", philo->info->time);
	custom_sleep(philo->info, philo->info->time_to_eat);
	pthread_mutex_unlock(&philo->prev->fork);
	pthread_mutex_unlock(&philo->fork);
	philo->time_before_dying = philo->info->time + philo->info->time_to_die;
	philo->meals--;
}

void	sleepy(t_philo *philo)
{
	talk(philo, "is sleeping", philo->info->time);
	custom_sleep(philo->info, philo->info->time_to_sleep);
}
