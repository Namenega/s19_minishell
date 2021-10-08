/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:30:01 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/08 12:33:35 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_tab(char **env)
{
	int	i;

	if (!env)
		return ;
	i = -1;
	while (env[++i])
		free(env[i]);
	free(env);
}

size_t	size_tab(char **env)
{
	size_t	size;

	size = 0;
	if (!env)
		return (size);
	while (*env)
	{
		size++;
		env++;
	}
	return (size);
}

char	**grow_tab(char **env, size_t size)
{
	char	**new_env;
	char	**entry;

	if (!env)
		return (NULL);
	new_env = malloc(sizeof(*new_env) * (size + 1));
	entry = new_env;
	if (!new_env)
		return (NULL);
	while (*env)
	{
		*entry = ft_strdup(*env);
		if (!entry)
		{
			free(new_env);
			return (NULL);
		}
		env++;
		entry++;
	}
	*entry = NULL;
	return (new_env);
}