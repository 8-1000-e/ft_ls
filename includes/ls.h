/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:51:24 by edubois-          #+#    #+#             */
/*   Updated: 2025/09/05 00:34:37 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
#define LS_H

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/printf_fd/ft_printf.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

typedef struct s_data
{
    char **flags;
}	t_data;

//get_flags.c
void    get_flags(int argc, char **argv, t_data *data);

//handle_flag.c
void    flag_l(t_data *data);

//flag_utils
void    sort_char_tab(char **tab);



#endif