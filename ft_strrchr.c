/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:17:38 by ereali            #+#    #+#             */
/*   Updated: 2019/10/13 15:48:49 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s);
	while (s[i] != c && s[i])
		i--;
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}
