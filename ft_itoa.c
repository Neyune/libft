/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:20:36 by ereali            #+#    #+#             */
/*   Updated: 2019/10/15 22:45:14 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size_int(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*write_n(char *str, int n, size_t i)
{
	while (n > 9)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	str[i] = n + '0';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	j;

	j = size_int(n);
	if (!(str = (char *)malloc(sizeof(char) * (j + 2))))
		return (NULL);
	if (n == -2147483648)
		return (str = "-2147483648\0");
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str = write_n(str, n, j);
	str[j + 1] = '\0';
	return (str);
}
