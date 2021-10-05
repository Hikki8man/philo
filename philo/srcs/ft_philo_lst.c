/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 04:13:00 by jchevet           #+#    #+#             */
/*   Updated: 2021/09/30 04:13:07 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*new_philo(int i, t_info *info)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	philo->next = NULL;
	philo->prev = NULL;
	philo->id = i;
	philo->info = info;
	philo->time_before_dying = philo->info->time_to_die;
	if (info->meal_param == 1)
		philo->meals = info->nb_of_meals;
	return (philo);
}

t_philo	*lstlast(t_philo *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	add_back(t_philo **lst, t_philo *new)
{
	t_philo	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = lstlast(*lst);
		tmp->next = new;
		new->prev = tmp;
	}
}

t_philo	*create_list_of_philo(t_info *info)
{
	t_philo	*philos;
	t_philo	*tmp;
	int		i;

	i = 0;
	philos = NULL;
	while (i < info->nb_of_philo)
	{
		add_back(&philos, new_philo(i + 1, info));
		i++;
	}
	if (info->nb_of_philo > 1)
	{
		tmp = lstlast(philos);
		tmp->next = philos;
		philos->prev = tmp;
	}
	return (philos);
}

void	free_philo_list(t_philo *philo, t_info info)
{
	t_philo	*tmp;
	int		i;

	i = 0;
	while (i < info.nb_of_philo)
	{
		tmp = philo->next;
		free(philo);
		philo = NULL;
		philo = tmp;
		i++;
	}
}
