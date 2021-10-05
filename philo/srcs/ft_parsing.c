/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 04:12:32 by jchevet           #+#    #+#             */
/*   Updated: 2021/09/30 04:12:34 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_info(t_info *info)
{
	info->nb_of_philo = 0;
	info->time_to_die = 0;
	info->time_to_eat = 0;
	info->time_to_sleep = 0;
	info->nb_of_meals = 0;
	info->philo_died = 0;
	info->meal_param = 0;
	info->threads_created = 0;
	info->time = 0;
}

int	parse_args(int ac, char **av, t_info *info)
{
	info->nb_of_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		info->nb_of_meals = ft_atoi(av[5]);
		info->meal_param = 1;
	}
	if (info->nb_of_philo <= 0 || info->time_to_die < 0 \
	|| info->time_to_eat < 0 || info->time_to_sleep <= 0 \
	|| info->nb_of_meals < 0)
		return (1);
	return (0);
}
