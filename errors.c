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

void failproof(char **input, char **input1, int *fd, int *fd1)
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
void    why_the_fail(int infile, int outfile, char **cmd1, char **cmd2, int *pipefd)
{

    if (infile == -1 || outfile == -1)
    {
        if (infile == -1)
            perror("The infile failed to open.");
        if (outfile == -1)
            perror("The outfile failed to open.");
        failproof(cmd1, cmd2, pipefd, NULL);
        exit(1);
    }
}
void    check_validity_of_argc(int argc)
{
        if (argc != 5)
    {
        ft_printf("This should be the syntax: $> ./pipex infile cm1 cm2 outfile");
        exit(1);
    }
}

void    did_it_pipe(char **cmd1, char **cmd2, int pipe_status, int *pipefd)
{
    if (pipe_status == -1)
    {
        perror("pipe");
        failproof(cmd1, cmd2, pipefd, NULL);
        exit(1);
    }
}