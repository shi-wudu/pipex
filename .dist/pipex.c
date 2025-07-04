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

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

int	main()
{
	printf("Original process - PID: %d\n", getpid());
	
	int id1 = fork();
	printf("After first fork - PID: %d, id1: %d\n", getpid(), id1);
	
	int id2 = fork();
	printf("After second fork - PID: %d, id1: %d, id2: %d\n", getpid(), id1, id2);
	
	return 0;
}