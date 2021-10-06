/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 04:13:43 by jchevet           #+#    #+#             */
/*   Updated: 2021/09/30 04:13:45 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	create_threads(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&info->talk, NULL) != 0)
		return (error("Mutex_init failure", 1, philo, *info));
	while (i < info->nb_of_philo)
	{
		if (pthread_mutex_init(&philo->fork, NULL) != 0)
			return (error("Mutex_init failure", 1, philo, *info));
//		if (pthread_mutex_init(&philo->time_to_die, NULL) != 0)
//			return (error("Mutex_init failure", 1, philo, *info));
		if (pthread_create(&philo->th, NULL, &routine, (void *)philo) != 0)
			return (error("Pthread_create failure", 1, philo, *info));
		philo = philo->next;
		i++;
	}
	return (0);
}

int	destroy_mutex(t_philo *philo, t_info info)
{
	int	i;

	i = 0;
	while (i < info.nb_of_philo)
	{
		if (pthread_mutex_destroy(&philo->fork) != 0)
			return (error("Pthread_mutex_destroy failure", 1, philo, info));
//		if (pthread_mutex_destroy(&philo->time_to_die) != 0)
//			return (error("Pthread_mutex_destroy failure", 1, philo, info));
		philo = philo->next;
		i++;
	}
	if (pthread_mutex_destroy(&info.talk) != 0)
		return (error("Pthread_mutex_destroy talk failure", 1, philo, info));
	return (0);
}

int	join_threads(t_philo *philo, t_info info)
{
	int	i;

	i = 0;
	while (i < info.nb_of_philo)
	{
		if (pthread_join(philo->th, NULL) != 0)
			return (error("Pthread_join failure", 1, philo, info));
		philo = philo->next;
		i++;
	}
	return (0);
}
