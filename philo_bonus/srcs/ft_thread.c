//
// Created by Stellar on 03/10/2021.
//

#include "../include/philo_bonus.h"

void *check_death_time(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (time_in_ms(philo->info->start) > philo->time_before_dying)
			philo_died(philo);
		usleep(10);
	}
	return (NULL);
}

void create_thread(t_philo *philo)
{
	pthread_t clock;

	if (pthread_create(&clock, NULL, &check_death_time, (void *)philo) != 0)
		error("FAILED TO CREATE THREAD");
}