/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student42.lisboa.pt>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:54:52 by marleand          #+#    #+#             */
/*   Updated: 2025/07/08 16:20:27 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.c"

char    free_args(char **args)
{
    while (args)
    free(args);
    lol sei q n ta done
}
char    **parse(char *user_input)
{   
    char **args;
    
    if (!user_input || !*user_input)
    {
        ft_printf("Error: Empty command\n");
        return (NULL);
    }
    
    char *temp = user_input;
    while (*temp && (*temp == ' ' || *temp == '\t'))
        temp++;

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