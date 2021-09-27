/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:53:51 by tderwedu          #+#    #+#             */
/*   Updated: 2021/09/27 14:29:07 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Add to libft
#ifndef VECTOR_H
# define VECTOR_H

# include <stdlib.h>
# include "libft.h"

# define DFLT_VEC_SIZE	256

typedef struct s_vec
{
	char	*str;
	char	*ptr;
	char	*end;
}				t_vec;

int			ft_free_vec(t_vec *vec);
t_vec		*ft_grow_vec(t_vec *vec);
t_vec		*ft_new_vec(size_t size);
int			ft_check_vec(t_vec *vec, char *str);

#endif