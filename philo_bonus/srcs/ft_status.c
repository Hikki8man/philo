/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:58:46 by jchevet           #+#    #+#             */
/*   Updated: 2021/10/08 14:58:48 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	meals_done(t_philo *philo)
{
	if (philo->info->meal_param == 1 && philo->meals <= 0)
	{
		if (sem_close(philo->info->talk) != 0)
			error("SEM_CLOSE FAILURE");
		if (sem_close(philo->info->forks) != 0)
			error("SEM_CLOSE FAILURE");
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	philo_died(t_philo *philo)
{
	talk(philo, "died", philo->info->time);
	if (sem_close(philo->info->forks) != 0)
		error("SEM_CLOSE FAILURE");
	if (sem_close(philo->info->talk) != 0)
		error("SEM_CLOSE FAILURE");
	exit(3);
}
