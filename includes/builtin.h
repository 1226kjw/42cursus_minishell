/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:09:00 by ji-kim            #+#    #+#             */
/*   Updated: 2021/07/05 15:09:21 by ji-kim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

// # include "list.h"
# include "struct.h"
# include "minishell.h"

extern int	g_ret;

void	ft_echo(t_cmd *cmd, int i, int flag);
void	builtin_echo(t_cmd *cmd);
void	ft_export(t_cmd *cmd, int i, char *key, char *val);
void	builtin_export(t_cmd *cmd, t_list **envl);
void	builtin_unset(t_cmd *cmd, t_list **envl);
void	builtin_env(t_list *envl, int flag);
void	builtin_cd(char *dir, t_list **envl);

#endif
