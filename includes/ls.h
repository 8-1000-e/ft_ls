/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emile <emile@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:51:24 by edubois-          #+#    #+#             */
/*   Updated: 2025/09/07 21:53:18 by emile            ###   ########.fr       */
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
# include <sys/stat.h>
# include <sys/types.h>  
# include <sys/types.h>    
# include <pwd.h>    
# include <uuid/uuid.h>
# include <dirent.h>
# include <grp.h>
#include <sys/errno.h>
#include <fcntl.h>
# include <time.h>

#define BASEROOT "./"

typedef struct s_flags
{
	int r;
	int l;
	int R;
	int a;
	int t;
}	t_flags;

typedef struct s_data
{
    char **flags;
	char **folders;
	char **files;
	t_flags f_list;
}	t_data;

//get_flags.c
void    get_flags(int argc, char **argv, t_data *data);

//handle_flag.c
void    ls(t_data *data, char *base);

//flag_utils
void    sort_char_tab(char **tab);
int ft_memcomp(char *s1, char *s2);

//sort.c
void	select_sort(char ***files, t_data *data);


#endif