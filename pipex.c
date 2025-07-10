/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student.42lisboa.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-30 13:54:26 by marleand          #+#    #+#             */
/*   Updated: 2025-06-30 13:54:26 by marleand         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
    int infile_fd;
    int outfile_fd;
    char **cmd1;
    char **cmd2;
    int pipefd[2];
    pid_t id1;
    pid_t id2;
    int pipe_status;

    check_validity_of_argc(argc);
    parse(argv[2], &cmd1, argv[3], &cmd2);
    did_it_parse(cmd1, cmd2);
    infile_fd = open(argv[1], O_RDONLY);
    outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    pipe_status = pipe(pipefd);
    did_it_pipe(cmd1, cmd2, pipe_status, pipefd);
    why_the_fail(infile_fd, outfile_fd, cmd1, cmd2, pipefd);
    id1 = fork();
    if (id1 == 0)
        executioner(pipefd, infile_fd, cmd1, outfile_fd, envp, 1);
    id2 = fork();
    if (id2 == 0)
        executioner(pipefd, infile_fd, cmd2, outfile_fd, envp, 2);
    closer(infile_fd, outfile_fd, pipefd, cmd1, cmd2);
    waiter(id1, id2);
}
char     *find_path(char *envp[], char **cmd1)
{
    char    **temp;
    char    **var;
    char    *path;
    char    *tpath;

    temp = envp;
    while (*temp != NULL && ft_strncmp(*temp, "PATH=", 5) != 0)
        temp++;
    if(*temp == NULL)
        return (NULL);
    *temp += 5;
    if(*temp == NULL || (var = ft_split(*temp, ':')) == NULL) 
        return (NULL);
    while (*var)
    {
        tpath = ft_strjoin(*var, "/");
        path = ft_strjoin(tpath, *cmd1);
        free(tpath);
        if (access(path, X_OK) == 0)
            return (path);
        free(path);
        var++;
    }
    free_args(var);
    return (NULL);
}
