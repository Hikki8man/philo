//
// Created by Stellar on 03/10/2021.
//

#include "../include/philo_bonus.h"

void	talk(t_philo *philo, char *str, time_t time)
{
	sem_wait(philo->info->talk);
	printf("%ld %d %s\n", time, philo->id, str);
	if (ft_strcmp(str, "died") != 0)
		sem_post(philo->info->talk);
}

void	take_forks(t_philo *philo)
{
	sem_wait(philo->info->forks);
	talk(philo, "has taken a fork", time_in_ms(philo->info->start));
	sem_wait(philo->info->forks);
	talk(philo, "has taken a fork", time_in_ms(philo->info->start));
}

void	eat(t_philo *philo)
{
	talk(philo, "is eating", time_in_ms(philo->info->start));
	custom_sleep(philo->info->time_to_eat);
	philo->time_before_dying = time_in_ms(philo->info->start) + philo->info->time_to_die;
	philo->meals--;
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
	if (meals_done(philo))
	{
		if (sem_close(philo->info->talk) != 0)
			error("SEM_CLOSE FAILURE");
		if (sem_close(philo->info->forks) != 0)
			error("SEM_CLOSE FAILURE");
		exit(EXIT_SUCCESS);
	}
}

void	sleepy(t_philo *philo)
{
	talk(philo, "is sleeping", time_in_ms(philo->info->start));
	custom_sleep(philo->info->time_to_sleep);
}