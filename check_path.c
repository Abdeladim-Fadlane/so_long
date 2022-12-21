/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:23:33 by afadlane          #+#    #+#             */
/*   Updated: 2022/12/19 10:43:29 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
static int	find(char *str, char *find)
{
	int	i;

	i = 0;
	while (find[i])
	{
		if (find[i] != str[i])
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	check_path(char *path)
{
	while (*path)
	{
		if (*path == '.')
		{
			if (find(path, ".ber"))
				return ;
		}
		path++;
	}
	perror("Error path invalid !");
	exit(1);
}