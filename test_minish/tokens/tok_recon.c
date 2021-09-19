/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_recon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyg <pyg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:51:59 by pyg               #+#    #+#             */
/*   Updated: 2021/09/19 19:15:30 by pyg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../msh.h"

//token : A sequence of characters considered a single unit by the shell. It is either a word or an operator.

void	init_t_tok(t_token *tok)
{
	tok->tokno = 0;
	tok->i = 0;
	tok->pos = 0;
	tok->lsttok = NULL;
}

t_lsttok	*tok_recon(char *line)
{
	t_token		tok;

	init_t_tok(&tok);
	while (line && line[tok.pos])
	{
		while (line[tok.pos] && line[tok.pos] == ' ')
			tok.pos++;
		if (line[tok.pos] && isnt_special(line[tok.pos]) == 0)
		{
			is_pipe(line, &tok);
			is_less(line, &tok);
			is_more(line, &tok);
			is_quote(line, &tok, '\"');
			is_quote(line, &tok, '\'');
		}
		else
			is_word(line, &tok);
	}
	return (tok.lsttok);
}
