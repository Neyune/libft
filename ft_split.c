/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:49:49 by ereali            #+#    #+#             */
/*   Updated: 2019/10/15 20:43:50 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			word++;
			while (s[i] == c)
				i++;
		}
		i++;
	}
	if (s[i - 1] == c)
		return (word);
	return (word + 1);
}

static char		*ft_get_next_word(char const *s, char c, size_t *j)
{
	char	*word;
	size_t	jcopy;
	size_t	i;

	i = 0;
	while (s[*j] == c)
		(*j)++;
	jcopy = *j;
	while (s[jcopy] && s[jcopy] != c)
		jcopy++;
	if (!(word = (char *)malloc(sizeof(char) * (jcopy - *j + 1))))
		return (NULL);
	while (*j < jcopy)
	{
		word[i] = s[*j];
		i++;
		(*j)++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	word;

	i = 0;
	j = 0;
	if (!(s))
		return (NULL);
	word = ft_count_word(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (word + 1))))
		return (NULL);
	while (i < word)
	{
		if (!(tab[i] = ft_get_next_word(s, c, &j)))
			return (NULL);
		i++;
	}
	tab[word] = NULL;
	return (tab);
}

int main(int argc,char **argv)
{
	int i = 0;
	while (i < ft_count_word(argv[1], argv[2][0]))
	{
	printf("%s\n", ft_split(argv[1], argv[2][0])[i]);
	i++;
	}
	return(0);
}
