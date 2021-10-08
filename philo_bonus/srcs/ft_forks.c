/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:59:18 by jchevet           #+#    #+#             */
/*   Updated: 2021/10/08 14:59:20 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	kill_process(t_info *info, int *philo_pid, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (kill(philo_pid[i], SIGKILL) != 0)
			error("KILL");
		i++;
	}
	sem_post(info->sem_start);
	sem_close(info->sem_start);
	printf("Error\nFORK FAILURE\n");
	free(philo_pid);
	exit(EXIT_FAILURE);
}

void	release_sem(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_of_philo)
	{
		sem_post(info->sem_start);
		i++;
	}
}

int	*create_process(t_philo *philo)
{
	int	*philo_pid;
	int	i;

	i = 0;
	philo_pid = malloc(sizeof(int) * philo->info->nb_of_philo);
	if (philo_pid == NULL)
		error("MALLOC");
	sem_wait(philo->info->sem_start);
	while (i < philo->info->nb_of_philo)
	{
		philo->id = i + 1;
		philo_pid[i] = fork();
		if (philo_pid[i] == -1)
			kill_process(philo->info, philo_pid, i);
		else if (philo_pid[i] == 0)
			routine(philo);
		i++;
	}
	release_sem(philo->info);
	return (philo_pid);
}

void	wait_process(t_info *info, int *philo_pid)
{
	int	status;
	int	pid;
	int	i;

	i = -1;
	pid = waitpid(-1, &status, 0);
	if (WEXITSTATUS(status) == 3)
	{
		while (++i < info->nb_of_philo)
		{
			if (philo_pid[i] != pid)
				if (kill(philo_pid[i], SIGKILL) != 0)
					error("KILL");
		}
		sem_post(info->talk);
	}
	else
	{
		while (++i < info->nb_of_philo - 1)
			waitpid(-1, NULL, 0);
	}
	free(philo_pid);
}
