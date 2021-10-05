//
// Created by Stellar on 03/10/2021.
//

#include "../include/philo_bonus.h"

int *create_process(t_philo *philo)
{
	int *philo_pid;
	int i;

	i = 0;
	philo_pid = malloc(sizeof(int) * philo->info->nb_of_philo);//do all with one philo
	if (philo_pid == NULL)
		error("MALLOC");
	gettimeofday(&philo->info->start, NULL);
	while (i < philo->info->nb_of_philo)
	{
		philo->id = i + 1;
		philo_pid[i] = fork();
		if (philo_pid[i] == -1)
		{
			free(philo_pid);
			exit(EXIT_FAILURE);
		}
		else if (philo_pid[i] == 0)
			routine(philo);
		i++;
	}
	return (philo_pid);
}

void	wait_process(t_info *info, int *philo_pid)
{
	int	status;
	int	pid;
	int i;

	i = -1;
	pid = waitpid(-1, &status, 0);
	if (WEXITSTATUS(status) == 3)
	{
		while (++i < info->nb_of_philo)
			if (philo_pid[i] != pid)
				if (kill(philo_pid[i], SIGKILL) != 0)
					error("KILL");
		sem_post(info->talk);
	}
	else
	{
		while (++i < info->nb_of_philo - 1)
			waitpid(-1, NULL, 0);
	}
	free(philo_pid);
}
