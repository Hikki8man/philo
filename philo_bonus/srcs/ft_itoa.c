//
// Created by Stellar on 08/10/2021.
//

#include "../include/philo_bonus.h"

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
