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

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		file_fd[2];
	char	**cmd1;
	char	**cmd2;
	int		pipefd[2];
	pid_t	id[3];

	parse_and_check_argc(argv, &cmd1, &cmd2, argc);
	file_fd[0] = open(argv[1], O_RDONLY);
	file_fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	id[2] = pipe(pipefd);
	did_it_pipe(cmd1, cmd2, id[2], pipefd);
	why_the_fail(file_fd, cmd1, cmd2, pipefd);
	id[0] = fork();
	if (id[0] == 0)
	{
		free_args(cmd2);
		exec_firstborn(pipefd, file_fd, cmd1, envp);
	}
	id[1] = fork();
	if (id[1] == 0)
	{
		free_args(cmd1);
		exec_eldestchild(pipefd, file_fd, cmd2, envp);
	}
	closer(file_fd, id, pipefd);
}

char	*find_path(char *envp[], char **cmd1)
{
	char	**var;
	char	**tmp;
	char	*path;
	char	*tpath;

	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	if (!*envp)
		return (NULL);
	var = ft_split(*envp + 5, ':');
	if (!var)
		return (NULL);
	tmp = var;
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
	free_args(tmp);
	return (NULL);
}
