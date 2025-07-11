/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-10 12:56:23 by marleand          #+#    #+#             */
/*   Updated: 2025-07-10 12:56:23 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	failproof(char **input, char **input1, int *fd, int *fd1)
{
	if (input)
		free_args(input);
	if (input1)
		free_args(input1);
	if (fd)
	{
		close(fd[0]);
		close(fd[1]);
	}
	if (fd1)
	{
		close(fd1[0]);
		close(fd1[1]);
	}
}

void	why_the_fail(int file_fd[], char **cmd1, char **cmd2, int *pipefd)
{
	if (file_fd[0] == -1 || file_fd[1] == -1)
	{
		if (file_fd[0] == -1)
			perror("The infile failed to open.");
		else if (file_fd[1] == -1)
			perror("The outfile failed to open.");
		failproof(cmd1, cmd2, pipefd, NULL);
		exit(1);
	}
}

void	free_args(char **args)
{
	char	**temp;

	temp = args;
	if (!args)
		return ;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(args);
}

void	did_it_pipe(char **cmd1, char **cmd2, int pipe_status, int *pipefd)
{
	if (pipe_status == -1)
	{
		perror("The system failed to use PIPE");
		failproof(cmd1, cmd2, pipefd, NULL);
		exit(1);
	}
}
