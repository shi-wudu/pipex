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

void free_args(char **args)
{
    char **temp = args;
    
    if (!args)
        return;
    while (*temp)
    {
        free(*temp);
        temp++;
    }
    free(args);
}
void    parse(char *strcmd1, char ***cmd1, char *strcmd2, char ***cmd2)
{
    *cmd1 = parsecmd(strcmd1);
    *cmd2 = parsecmd(strcmd2);
}
char    **parsecmd(char *user_input)
{   
    char **args;
    
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

int executioner(int *pipefd, int infile_fd, char **cmd, int outfile_fd, char **envp, int flag)
{
    char    *path;
    if (flag == 1)
    {
        path = find_path(envp, cmd);
        dup2(infile_fd, STDIN_FILENO);
        dup2(pipefd[1], STDOUT_FILENO);
        close(outfile_fd);
        close(pipefd[0]);
    	if (path == NULL || execve(path, cmd, envp) == -1)
		{
            close(infile_fd);
            close(pipefd[1]);
			free_args(cmd);
			exit(1);
		}
    }
    if (flag == 2)
    {
        path = find_path(envp, cmd);
        dup2(pipefd[0], STDIN_FILENO);
        dup2(outfile_fd, STDOUT_FILENO);
        close(infile_fd);
        close(pipefd[1]);
        
        if (path == NULL || execve(path, cmd, envp) == -1)
        {
            close(outfile_fd);
            close(pipefd[0]);
			free_args(cmd);
			exit(1);
		}
    }
    return (0);
}

void    closer(int infile_fd, int outfile_fd, int pipefd[], char **cmd1, char **cmd2)
{
    close(infile_fd);
    close(outfile_fd);
    close(pipefd[0]);
    close(pipefd[1]);
    failproof(cmd1, cmd2, NULL, NULL);
}

void    did_it_parse(char **cmd1, char **cmd2)
{
    if (cmd1 == NULL || cmd2 == NULL) {
        printf("Parsing error!\n");
		if (cmd1)
			free (cmd1);
		if (cmd2)
			free (cmd2);
        exit(1);
    }
}
void    waiter(pid_t id1, pid_t id2)
{
    waitpid(id1, NULL, 0);
    waitpid(id2, NULL, 0);
}