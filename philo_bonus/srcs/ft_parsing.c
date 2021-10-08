/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:58:32 by jchevet           #+#    #+#             */
/*   Updated: 2021/10/08 14:58:34 by jchevet          ###   ########lyon.fr   */
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

int ft_atoi_cmp(char *str)
{
	int	nb;
	char *s;

	nb = atoi(str);
	if (nb < 0)
		return (-1);
	s = ft_itoa(nb);
	if (s == NULL)
		return (-1);
	if (ft_strcmp(s, str) != 0)
	{
		free(s);
		return (-1);
	}
	return (nb);
}

int	parse_args(int ac, char **av, t_info *info, t_philo *philo)
{
	info->nb_of_philo = ft_atoi_cmp(av[1]);
	if (info->nb_of_philo == -1)
		return (1);
	info->time_to_die = ft_atoi_cmp(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	printf("ARG %d\n", info->time_to_die + 200);
	if (ac == 6)
	{
		philo->meals = ft_atoi(av[5]);
		info->meal_param = 1;
	}
	if (info->nb_of_philo <= 0 || info->time_to_die < 0 \
	|| info->time_to_eat < 0 || info->time_to_sleep < 0 \
	|| philo->meals < 0)
		return (1);
	return (0);
}
