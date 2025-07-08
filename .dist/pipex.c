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

    if (argc != 5)
    {
        ft_printf("This should be the syntax: $> ./pipex infile cm1 cm2 outfile");
        exit(1);
    }
    cmd1 = parse(argv[2]);
    cmd2 = parse(argv[3]);
    if (cmd1 == NULL || cmd2 == NULL) {
        printf("Parsing error!\n");
        exit(1);
    }
    infile_fd = open(argv[1], O_RDONLY);
    outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (infile_fd == -1)
    {
        perror("The infile failed to open.");
        exit(1);
    }
    if (outfile_fd == -1)
    {
        perror("The outfile failed to open.");
        exit(1);
    }

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(1);
    }

    id1 = fork();
    if (id1 == 0)
    {
        dup2(infile_fd, STDIN_FILENO);
        dup2(pipefd[1], STDOUT_FILENO);
        // executar && fechar
    }
    id2 = fork();
    if (id2 == 0)
    {
        dup2(pipefd[0], STDIN_FILENO);
        dup2(outfile_fd, STDOUT_FILENO);
        //executar && fechar
    }
    wait(NULL)

    //Resolves command path from $PATH 

    //Executes both commands using execve() 
		
}