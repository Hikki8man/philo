/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 04:13:31 by jchevet           #+#    #+#             */
/*   Updated: 2021/12/06 15:02:40 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	meals_done(t_philo *philo)
{
	if (philo->info->meal_param == 1 && philo->meals <= 0)
		return (1);
	return (0);
}

void	check_death(t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philo->info->nb_of_philo)
		{
			if (philo->info->done_eating == philo->info->nb_of_philo)
				return ;
			if (!meals_done(philo))
			{
				if (philo->info->time > philo->time_before_dying)
				{
					philo->info->philo_died = 1;
					talk(philo, "died", philo->info->time, 1);
					return ;
				}
			}
			philo = philo->next;
			i++;
		}
		usleep(100);
	}
}
