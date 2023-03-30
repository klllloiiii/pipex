/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamburo <okamburo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 04:36:16 by okamburo          #+#    #+#             */
/*   Updated: 2023/03/30 04:38:30 by okamburo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h> // fork() execve()
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include "Libft/libft.h"

void	ft_free_arr(char **arr);
char	**ft_get_path(char **envp);
char	*ft_path(char **envp, char *cmd);
void	ft_msg_error(char *msg);
void	ft_error(char *msg);
void	ft_cmd_error(char **cmd);

#endif