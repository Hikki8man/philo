//
// Created by Stellar on 30/09/2021.
//

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

void	custom_sleep(int time_to_do)
{
	struct timeval	curr;
	int				timer;

	gettimeofday(&curr, NULL);
	timer = time_in_ms(curr);// = 0?
	while (timer < time_to_do)
	{
		usleep(10);
		timer = time_in_ms(curr);
	}
}

int	error(char *str)
{
	printf("Error\n%s\n", str);
	exit(EXIT_FAILURE);
}