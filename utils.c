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
char    **parse(char *user_input)
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
