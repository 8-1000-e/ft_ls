/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:10:08 by edubois-          #+#    #+#             */
/*   Updated: 2025/09/04 15:01:28 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

int check_args(char *str)
{
    size_t i;

    i = 0;
    while (str[++i] && str[0] == '-')
    {
        if (!ft_strchr("lrRat", str[i]))
            break;
    }
    return !(str[i]);
}


void    get_flags(int argc, char **argv, t_data *data)
{
    int i;

    i = 0;
    data->flags = NULL;
    while (++i < argc)
    {
        if (check_args(argv[i]))
            ft_strapp(&data->flags, argv[i]);
    }
}
