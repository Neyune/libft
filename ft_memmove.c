/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 23:15:59 by ereali            #+#    #+#             */
/*   Updated: 2019/10/20 15:49:49 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			buffer[n];
	unsigned int	i;

	i = 0;
	if (!(dest) && n == 0)
		return (NULL);
	while (i < n)
	{
		buffer[i] = ((const char *)src)[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = buffer[i];
		i++;
	}
	return (dest);
}
