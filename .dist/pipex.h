/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:10:05 by marleand          #+#    #+#             */
/*   Updated: 2025/07/08 15:58:14 by marleand         ###   ########.fr       */
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
# include "../ft_printf/ft_printf.h"  
# include "Libft/libft.h"             


#endif