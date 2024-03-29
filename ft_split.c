/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:46:27 by afadlane          #+#    #+#             */
/*   Updated: 2022/12/26 10:08:43 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start ;
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (i < len && s[i + start] != '\0')
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static	int	ft_count(char *s, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
		i++;
	}
	return (count);
}

static char	**my_func(char *s, char c, char **p)
{
	int		j;
	int		k;
	int		i;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i])
		{
			k = i;
			while (s[i] != c && s[i])
				i++;
			p[j] = ft_substr(s, k, (i - k));
			j++;
		}
		else
			i++;
	}
	p[j] = 0;
	return (p);
}

char	**ft_split(char *s, char c)
{
	char	**p;

	if (!s)
		return (NULL);
	p = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!p)
		return (NULL);
	my_func(s, c, p);
	free(s);
	return (p);
}
