/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:00:02 by jchevet           #+#    #+#             */
/*   Updated: 2021/12/04 11:34:33 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	routine(t_philo *philo)
{
	philo->time_before_dying = philo->info->time_to_die;
	sem_wait(philo->info->sem_start);
	sem_close(philo->info->sem_start);
	create_thread(philo);
	if (philo->id % 2)
		usleep(50000);
	while (1)
	{
		meals_done(philo);
		take_forks(philo);
		eat(philo);
		sleepy(philo);
		talk(philo, "is thinking", philo->info->time);
	}
}

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	philo;
	int		*philo_pid;

	if (ac == 5 || ac == 6)
	{
		init_info(&info, &philo);
		if (parse_args(ac, av, &info, &philo) != 0)
			error("Wrong arguments");
		create_semaphores(&info);
		philo.info = &info;
		philo_pid = create_process(&philo);
		wait_process(&info, philo_pid);
		close_semaphores(&info);
		return (0);
	}
	write(2, "Error\nWrong number of arguments\n", 33);
	return (1);
}
