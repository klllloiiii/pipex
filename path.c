/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamburo <okamburo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 04:33:42 by okamburo          #+#    #+#             */
/*   Updated: 2023/03/30 05:11:45 by okamburo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
}

char	**ft_get_path(char **envp)
{
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	return (ft_split(envp[i] + 5, ':'));
}

char	*ft_path(char **envp, char *cmd)
{
	char	**path;
	int		i;
	char	*res;

	i = -1;
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
		return (cmd);
	path = ft_get_path(envp);
	while (path[++i])
	{
		res = ft_strjoin(ft_strjoin(path[i], "/"), cmd);
		if (!access(res, 0))
		{	
			ft_free_arr(path);
			return (res);
		}
		free(res);
	}
	ft_free_arr(path);
	return (0);
}
