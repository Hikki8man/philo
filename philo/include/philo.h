/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 04:37:22 by jchevet           #+#    #+#             */
/*   Updated: 2021/12/11 13:40:53 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

typedef struct s_info
{
	pthread_mutex_t	talk;
	pthread_mutex_t	philo_done_eating;
	struct timeval	start;
	int				nb;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_meals;
	int				meal_param;
	int				threads_created;
	int				philo_died;
	int				done_eating;
	u_int64_t		time;
	int				all_done;

}t_info;

typedef struct s_philo
{
	pthread_mutex_t	fork;
	pthread_t		th;
	t_info			*info;
	int				id;
	int				meals;
	u_int64_t		time_before_dying;
	struct s_philo	*next;
	struct s_philo	*prev;
}t_philo;

//--------utils
int		ft_atoi(const char *nptr);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi_cmp(char *str);
char	*ft_itoa(int n);
int		time_in_ms(struct timeval start);
void	custom_sleep(t_info *info, u_int64_t time_to_do);
void	wait_thread_and_start_in_mismatch(t_philo *philo);
//--------init
void	init_info(t_info *info);
//--------Action
void	talk(t_philo *philo, char *str, u_int64_t time, int is_main);
void	take_forks(t_philo *philo);
void	eat(t_philo *philo);
void	sleepy(t_philo *philo);
//--------Status
int		meals_done(t_philo *philo);
void	check_death(t_philo *philo);
//--------parsing
int		parse_args(int ac, char **av, t_info *info);
//--------Threads
int		create_threads(t_philo *philo, t_info *info);
int		join_threads(t_philo *philo, t_info info);
int		destroy_mutex(t_philo *philo, t_info info);
//--------Routine
int		lonely_philo(t_philo *philo);
void	*routine(void *arg);
void	*clock_th(void *arg);
//--------lst
t_philo	*new_philo(int i, t_info *info);
t_philo	*lstlast(t_philo *lst);
t_philo	*create_list_of_philo(t_info *info);
void	add_back(t_philo **lst, t_philo *new);
void	free_philo_list(t_philo *philo, int nb);
//--------error
int		error(char *str, int free_list, t_philo *philo, int nb);

#endif
