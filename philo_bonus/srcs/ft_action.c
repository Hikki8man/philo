/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:58:10 by jchevet           #+#    #+#             */
/*   Updated: 2021/12/04 11:33:12 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	talk(t_philo *philo, char *str, u_int64_t time)
{
	sem_wait(philo->info->talk);
	printf("%llu %d %s\n", time, philo->id, str);
	if (ft_strcmp(str, "died") != 0)
		sem_post(philo->info->talk);
}

void	take_forks(t_philo *philo)
{
	sem_wait(philo->info->forks);
	talk(philo, "has taken a fork", philo->info->time);
	sem_wait(philo->info->forks);
	talk(philo, "has taken a fork", philo->info->time);
}

void	eat(t_philo *philo)
{
	talk(philo, "is eating", philo->info->time);
	custom_sleep(philo->info, (u_int64_t)philo->info->time_to_eat);
	philo->time_before_dying = philo->info->time + philo->info->time_to_die;
	philo->meals--;
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
	meals_done(philo);
}

void	sleepy(t_philo *philo)
{
	talk(philo, "is sleeping", philo->info->time);
	custom_sleep(philo->info, (u_int64_t)philo->info->time_to_sleep);
}
