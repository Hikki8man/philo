//
// Created by Stellar on 03/10/2021.
//

#include "../include/philo_bonus.h"

void	init_info(t_info *info, t_philo *philo)
{
	info->nb_of_philo = 0;
	info->time_to_die = 0;
	info->time_to_eat = 0;
	info->time_to_sleep = 0;
	info->meal_param = 0;
	philo->meals = 0;
}

int	parse_args(int ac, char **av, t_info *info, t_philo *philo)
{
	info->nb_of_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
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