/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:29:41 by tderwedu          #+#    #+#             */
/*   Updated: 2021/10/05 14:49:24 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

//TODO: on single HEADER to rule them all
// #define	MSH_EXPORT		"msh: export: `"
// #define	MSG_IDENTIFIER	"': not a valid identifier\n"

int	msh_export_print(t_exec *exec)
{
	char	*value;
	char	**argv;

	argv = exec->env;
	while (*argv)
		argv++;
	argv = utils_env_copy(exec->env, argv - exec->env);
	utils_env_sort(argv);
	while (*argv)
	{
		value = utils_env_go_2_val(*argv);
		write(1, "declare -x ", 11);
		write(1, *argv, value - *argv - (*value == '='));
		if (*value)
		{
			write(1, "=\"", 2);
			write(1, value, ft_strlen(value));
			write(1, "\"", 1);
		}
		write(1, "\n", 1);
		argv++;
	}
	return (EXIT_SUCCESS);
}

int	msh_export_var(t_msh *msh, char *exp)
{
	char	*value;
	char	**param;

	value = utils_env_check_name(exp);
	if (!value || !(*value != '=' || *value == '\0'))
		return (msh_print_error(MSH_EXPORT, exp, MSG_IDENTIFIER, EXIT_FAILURE));
	param = utils_env_param(msh->env, exp, value - exp);
	if (param)
		free(*param);
	else
	{
		param = utils_env_next_addr(msh);
		if (!param)
			return (EXIT_FAILURE);
	}
	*param = ft_strdup(exp);
	if (!*param)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	msh_export(t_exec *exec)
{
	int	i;
	int	r;
	int	ret;

	if (!exec->tab[1])
		return (msh_export_print(exec));
	i = 1;
	r = 0;
	ret = 0;
	while (exec->tab[i])
	{
		r = msh_export_var(exec->msh, exec->tab[i]);
		if (r)
			ret = r;
		i++;
	}
	return (ret);
}