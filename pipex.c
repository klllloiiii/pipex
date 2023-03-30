/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamburo <okamburo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 04:34:32 by okamburo          #+#    #+#             */
/*   Updated: 2023/03/30 04:36:01 by okamburo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_first(char **envp, char **argv, int *fd, int *pipefd)
{
	pid_t	pid;
	char	**cmd;

	pid = fork();
	if (pid < 0)
		ft_error("fork");
	if (pid == 0)
	{
		fd[0] = open(argv[1], O_RDONLY);
		if (fd[0] < 0)
			ft_error("open");
		cmd = ft_split(argv[2], ' ');
		close(pipefd[0]);
		dup2(fd[0], STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(fd[0]);
		if (cmd[0] && ft_path(envp, cmd[0]))
		{
			execve(ft_path(envp, cmd[0]), cmd, envp);
			ft_free_arr(cmd);
		}
		close(pipefd[1]);
		ft_cmd_error(cmd);
	}
}

void	ft_second(char **envp, char **argv, int *fd, int *pipefd)
{
	pid_t	pid;
	char	**cmd;

	pid = fork();
	if (pid < 0)
		ft_error("fork");
	if (pid == 0)
	{
		fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd[1] < 0)
			ft_error("open");
		cmd = ft_split(argv[3], ' ');
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		if (cmd[0] && ft_path(envp, cmd[0]))
		{
			execve(ft_path(envp, cmd[0]), cmd, envp);
			ft_free_arr(cmd);
		}
		close(pipefd[0]);
		ft_cmd_error(cmd);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		pipefd[2];
	int		status;
	int		errno;

	if (argc != 5)
		ft_msg_error("./pipex <file1> cmd cmd <cmd2>");
	if (pipe(pipefd) < 0)
		ft_error("pipe");
	ft_first(envp, argv, fd, pipefd);
	ft_second(envp, argv, fd, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
	return (0);
}
