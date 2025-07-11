/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:54:52 by marleand          #+#    #+#             */
/*   Updated: 2025/07/09 17:43:16 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_and_check_argc(char **argv, char ***cmd1, char ***cmd2, int argc)
{
	if (argc != 5)
	{
		ft_printf("Try this: $> ./pipex infile cm1 cm2 outfile");
		exit(1);
	}
	*cmd1 = parsecmd(argv[2]);
	*cmd2 = parsecmd(argv[3]);
	if (*cmd1 == NULL || *cmd2 == NULL)
	{
		printf("Parsing error!\n");
		if (*cmd1)
			free (*cmd1);
		if (*cmd2)
			free (*cmd2);
		exit(1);
	}
}

char	**parsecmd(char *user_input)
{
	char	**args;

	if (!user_input || !*user_input)
	{
		ft_printf("Error: Empty command\n");
		return (NULL);
	}
	args = ft_split(user_input, ' ');
	if (!args)
	{
		perror("ft_split");
		return (NULL);
	}
	if (!args[0] || !args[0][0])
	{
		ft_printf("Error: No command specified\n");
		free_args(args);
		return (NULL);
	}
	return (args);
}

void	exec_firstborn(int *pipefd, int file_fd[], char **cmd, char **envp)
{
	char	*path;

	path = find_path(envp, cmd);
	dup2(file_fd[0], STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(file_fd[1]);
	close(pipefd[0]);
	if (path == NULL || execve(path, cmd, envp) == -1)
	{
		close(file_fd[1]);
		close(pipefd[1]);
		free_args(cmd);
		exit(1);
	}
	free_args(cmd);
}

void	exec_eldestchild(int *pipefd, int file_fd[], char **cmd, char **envp)
{
	char	*path;

	path = find_path(envp, cmd);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(file_fd[1], STDOUT_FILENO);
	close(file_fd[0]);
	close(pipefd[1]);
	if (path == NULL || execve(path, cmd, envp) == -1)
	{
		close(file_fd[1]);
		close(pipefd[0]);
		free_args(cmd);
		exit(1);
	}
	free_args(cmd);
}

void	closer(int file_fd[], int id[], int pipefd[])
{
	close(file_fd[0]);
	close(file_fd[1]);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(id[0], NULL, 0);
	waitpid(id[1], NULL, 0);
}
