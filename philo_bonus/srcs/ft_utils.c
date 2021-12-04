/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:59:06 by jchevet           #+#    #+#             */
/*   Updated: 2021/12/04 11:31:50 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

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

void	custom_sleep(t_info *info, u_int64_t time_to_do)
{
	time_to_do = info->time + time_to_do;
	while (info->time < time_to_do)
		usleep(100);
}

void	error(char *str)
{
	printf("Error\n%s\n", str);
	exit(EXIT_FAILURE);
}
