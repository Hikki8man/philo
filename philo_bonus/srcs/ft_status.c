//
// Created by Stellar on 03/10/2021.
//

#include "../include/philo_bonus.h"

int	meals_done(t_philo *philo)
{
	if (philo->info->meal_param == 1 && philo->meals <= 0)
		return (1);
	return (0);
}

void philo_died(t_philo *philo)
{
	talk(philo, "died", time_in_ms(philo->info->start));
	if (sem_close(philo->info->forks) != 0)
		error("SEM_CLOSE FAILURE");
	if (sem_close(philo->info->talk) != 0)
		error("SEM_CLOSE FAILURE");
	exit(3);
}
