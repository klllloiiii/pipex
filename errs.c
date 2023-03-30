/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamburo <okamburo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 04:33:16 by okamburo          #+#    #+#             */
/*   Updated: 2023/03/30 04:33:38 by okamburo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_msg_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void	ft_cmd_error(char **cmd)
{
	write(2, cmd[0], ft_strlen(cmd[0]));
	write(2, ": command not found\n", 20);
	ft_free_arr(cmd);
	exit(EXIT_FAILURE);
}

void	ft_error(char *msg)
{
	if (errno == 0)
		write(2, "Error\n", 6);
	else
		perror(msg);
	exit(EXIT_FAILURE);
}
