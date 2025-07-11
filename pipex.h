/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:10:05 by marleand          #+#    #+#             */
/*   Updated: 2025/07/09 17:51:39 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H


# include <unistd.h>      // open, close, read, write, access, dup, dup2, execve, exit, fork, pipe, unlink
# include <stdlib.h>      // malloc, free, exit
# include <stdio.h>       // perror
# include <string.h>      // strerror
# include <sys/wait.h>    // wait, waitpid
# include <fcntl.h>       // open (O_RDONLY, O_WRONLY, etc.)
# include <errno.h>       // errno (used with strerror)
# include "ft_printf/ft_printf.h"  
# include "Libft/libft.h"             

void free_args(char **args);
char    *find_path(char *envp[], char **cmd1);
void failproof(char **input, char **input1, int *fd, int *fd1);
int executioner(int *pipe, int infile, char **cmd, int outfile, char **envp, int flag);
void    why_the_fail(int infile, int outfile, char **cmd1, char **cmd2, int *pipefd);
void    did_it_parse(char **cmd1, char **cmd2);
void    check_validity_of_argc(int argc);
void    waiter(pid_t id1, pid_t id2);
void    closer(int infile_fd, int outfile_fd, int pipefd[], char **cmd1, char **cmd2);
void    parse(char *strcmd1, char ***cmd1, char *strcmd2, char ***cmd2);
char    **parsecmd(char *user_input);
void    did_it_pipe(char **cmd1, char **cmd2, int pipe_status, int *pipefd);
#endif