#include "../include/philo_bonus.h"

void routine(t_philo *philo)
{
	philo->time_before_dying = time_in_ms(philo->info->start) + philo->info->time_to_die;
	create_thread(philo);
	if (philo->id % 2)
		usleep(1000);
	while (1)
	{
		if (meals_done(philo))
			break ;
		take_forks(philo);
		eat(philo);
		sleepy(philo);
		talk(philo, "is thinking", time_in_ms(philo->info->start));
	}
}

int main(int ac, char **av)
{
	t_info	info;
	t_philo	philo;
	int 	*philo_pid;

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
