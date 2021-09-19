/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyg <pyg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:50:56 by pyg               #+#    #+#             */
/*   Updated: 2021/09/19 18:53:16 by pyg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../msh.h"

void	is_pipe(char *line, t_token *tok)
{
	char		*s;

	if (line[tok->pos] && line[tok->pos] == '|')
	{
		s = ft_strdup("|");
		tok->tokno++;
		tok->pos++;
		lst_new_addback(s, PIPE, tok);
	}
}
