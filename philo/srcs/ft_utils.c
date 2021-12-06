/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 04:14:01 by jchevet           #+#    #+#             */
/*   Updated: 2021/12/06 14:07:01 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_atoi(const char *nptr)
{
	unsigned int	n;
	int				sign;

	n = 0;
	sign = 1;
	if (nptr == NULL)
		return (-1);
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		n *= 10;
		n += (*nptr - 48);
		nptr++;
	}
	return (n * sign);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*s1b;
	unsigned char	*s2b;

	if (!s1 || !s2)
		return (-1);
	s1b = (unsigned char *)s1;
	s2b = (unsigned char *)s2;
	i = 0;
	while ((s1b[i] || s2b[i]))
	{
		if (s1b[i] != s2b[i])
			return (s1b[i] - s2b[i]);
		i++;
	}
	return (0);
}

int	time_in_ms(struct timeval start)
{
	struct timeval	curr;
	unsigned long	t1;
	unsigned long	t2;

	gettimeofday(&curr, NULL);
	t1 = (unsigned long)((start.tv_sec * 1000) + (start.tv_usec / 1000));
	t2 = (unsigned long)((curr.tv_sec * 1000) + (curr.tv_usec / 1000));
	return ((int)(t2 - t1));
}

void	custom_sleep(t_info *info, u_int64_t time_to_do)
{
	time_to_do = info->time + time_to_do;
	while (info->time < time_to_do && info->philo_died != 1)
		usleep(100);
}

void	wait_thread_and_start_in_mismatch(t_philo *philo)
{
	while (philo->info->threads_created != 1)
		usleep(10);
	if (philo->id % 2 != 0)
	{
		talk(philo, "is sleeping", philo->info->time, 0);
		usleep(50000);
	}

}
