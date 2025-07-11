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

# include <unistd.h>      
# include <stdlib.h>      // malloc, free, exit
# include <stdio.h>       // perror
# include <string.h>      // strerror
# include <sys/wait.h>    // wait, waitpid
# include <fcntl.h>       // open (O_RDONLY, O_WRONLY, etc.)
# include <errno.h>       // errno (used with strerror)
# include "ft_printf/ft_printf.h"  
# include "Libft/libft.h"             

void	free_args(char **args);
char	*find_path(char *envp[], char **cmd1);
void	failproof(char **input, char **input1, int *fd, int *fd1);
void	exec_firstborn(int *pipefd, int file_fd[], char **cmd, char **envp);
void	exec_eldestchild(int *pipefd, int file_fd[], char **cmd, char **envp);
void	why_the_fail(int file_fd[], char **cmd1, char **cmd2, int *pipefd);
void	closer(int file_fd[], int id[], int pipefd[]);
void	parse_and_check_argc(char **argv, char ***cmd1, char ***cmd2, int argc);
char	**parsecmd(char *user_input);
void	did_it_pipe(char **cmd1, char **cmd2, int pipe_status, int *pipefd);

#endif