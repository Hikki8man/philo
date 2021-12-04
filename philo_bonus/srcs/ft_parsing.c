/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:58:32 by jchevet           #+#    #+#             */
/*   Updated: 2021/12/04 11:40:58 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	init_info(t_info *info, t_philo *philo)
{
	info->nb_of_philo = 0;
	info->time_to_die = 0;
	info->time_to_eat = 0;
	info->time_to_sleep = 0;
	info->meal_param = 0;
	info->time = 0;
	philo->meals = 0;
}

int	parse_args(int ac, char **av, t_info *info, t_philo *philo)
{
	info->nb_of_philo = ft_atoi_cmp(av[1]);
	info->time_to_die = ft_atoi_cmp(av[2]);
	info->time_to_eat = ft_atoi_cmp(av[3]);
	info->time_to_sleep = ft_atoi_cmp(av[4]);
	if (ac == 6)
	{
		philo->meals = ft_atoi_cmp(av[5]);
		info->meal_param = 1;
	}
	if (info->nb_of_philo <= 0 || info->time_to_die < 0 \
	|| info->time_to_eat < 0 || info->time_to_sleep < 0 \
	|| philo->meals < 0)
		return (1);
	return (0);
}
