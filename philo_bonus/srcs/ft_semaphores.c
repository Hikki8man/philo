/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_semaphores.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:59:37 by jchevet           #+#    #+#             */
/*   Updated: 2021/10/08 14:59:39 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	create_semaphores(t_info *info)
{
	info->forks = sem_open(SEM_FORK, O_CREAT | O_EXCL, S_IRWXU, \
	info->nb_of_philo);
	if (info->forks == SEM_FAILED)
		error("SEM_OPEN FAILURE");
	if (sem_unlink(SEM_FORK) != 0)
		error("SEM_UNLINK FAILURE");
	info->talk = sem_open(SEM_TALK, O_CREAT | O_EXCL, S_IRWXU, 1);
	if (info->talk == SEM_FAILED)
		error("SEM_OPEN FAILURE");
	if (sem_unlink(SEM_TALK) != 0)
		error("SEM_UNLINK FAILURE");
	info->sem_start = sem_open(SEM_START, O_CREAT | O_EXCL, S_IRWXU, 1);
	if (info->sem_start == SEM_FAILED)
		error("SEM_OPEN FAILURE");
	if (sem_unlink(SEM_START) != 0)
		error("SEM_UNLINK FAILURE");
}

void	close_semaphores(t_info *info)
{
	if (sem_close(info->forks) != 0)
		error("SEM_CLOSE FAILURE FORKS");
	if (sem_close(info->talk) != 0)
		error("SEM_CLOSE FAILURE TALK");
}
