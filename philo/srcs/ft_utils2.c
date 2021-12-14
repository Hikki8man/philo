/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:13:18 by jchevet           #+#    #+#             */
/*   Updated: 2021/12/11 14:37:28 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	*ft_calloc(size_t count, size_t size)
{
	void	*allocated_mem;

	allocated_mem = malloc(count * size);
	if (!allocated_mem)
		return (NULL);
	memset(allocated_mem, 0, count);
	return (allocated_mem);
}

static int	ft_length(int n, int *sign, unsigned int *res)
{
	int				len;
	unsigned int	tmp;

	*sign = 0;
	len = 0;
	*res = (unsigned int)n;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		*res = (unsigned int) - n;
		*sign = 1;
	}
	tmp = *res;
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	return (len += *sign);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	int				sign;
	unsigned int	res;

	len = ft_length(n, &sign, &res);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (res == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
		str[0] = '-';
	while (--len >= sign)
	{
		str[len] = res % 10 + '0';
		res /= 10;
	}
	return (str);
}

int	ft_atoi_cmp(char *str)
{
	int		nb;
	char	*s;

	nb = atoi(str);
	if (nb < 0)
		return (-1);
	s = ft_itoa(nb);
	if (s == NULL)
		return (-1);
	if (ft_strcmp(s, str) != 0)
		nb = -1;
	free(s);
	return (nb);
}
