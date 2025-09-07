/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emile <emile@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:19:11 by edubois-          #+#    #+#             */
/*   Updated: 2025/09/07 21:52:57 by emile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ls.h"

long    get_blocks_size(char **files)
{
    struct stat file_stat;
    long size;

    size = 0;
    while (*files)
    {
        if (stat(*files, &file_stat) == 0)
            size += file_stat.st_blocks;
        files += 1;
    }
    return size;
}

void    make_lflag(char *file)
{
    struct stat	file_stat;
    int filemod;

    if (!stat(file, &file_stat))
    {
    	if (S_ISDIR(file_stat.st_mode))
            write(1, "d", 1);
        else
            write(1, "-", 1);    
    }
    filemod = file_stat.st_mode;
    if ((filemod & S_IRUSR))
        ft_printf(1, "r");
    else
        ft_printf(1, "-");
    if ((filemod & S_IWUSR))
        ft_printf(1, "w");
    else
        ft_printf(1, "-");
    if ((filemod & S_IXUSR))
        ft_printf(1, "x");
    else
        ft_printf(1, "-");
    if ((filemod & S_IRGRP))
        ft_printf(1, "r");
    else
        ft_printf(1, "-");
    if ((filemod & S_IWGRP))
        ft_printf(1, "w");
    else
        ft_printf(1, "-");
    if ((filemod & S_IXGRP))
        ft_printf(1, "x");
    else
        ft_printf(1, "-");
    if ((filemod & S_IROTH))
        ft_printf(1, "r");
    else
        ft_printf(1, "-");
    if ((filemod & S_IWOTH))
        ft_printf(1, "w");
    else
        ft_printf(1, "-");
    if ((filemod & S_IXOTH))
        ft_printf(1, "x");
    else
        ft_printf(1, "-");


    ft_printf(1, " %d ", file_stat.st_nlink);

    struct passwd *info;
    info = getpwuid(file_stat.st_uid);
    ft_printf(1, " %s", info->pw_name);

    struct group *group;
    group = getgrgid(file_stat.st_gid);
    ft_printf(1, " %s", group->gr_name);

    ft_printf(1, " %d", file_stat.st_size);

    char *time_str = ctime(&file_stat.st_mtime);
    
    char day[3];
    day[0] = time_str[8];
    day[1] = time_str[9];
    day[2] = '\0';
    
    char month[4];
    month[0] = time_str[4];
    month[1] = time_str[5];
    month[2] = time_str[6];
    month[3] = '\0';
    
    char time[6];
    time[0] = time_str[11];
    time[1] = time_str[12];
    time[2] = time_str[13];
    time[3] = time_str[14];
    time[4] = time_str[15];
    time[5] = '\0';

    ft_printf(1, " %s", day);
    ft_printf(1, " %s", month);
    ft_printf(1, " %s", time);
    
}


void    ls(t_data *data, char *base)
{
	char **files;
    DIR *dir;
    struct dirent *entry;
	

    files = NULL;
    dir = opendir(base);
    entry = readdir(dir);
    while (entry)
    {
		ft_strapp(&files, ft_strjoin(base, entry->d_name));
        entry = readdir(dir);
    }
	if (data->f_list->l)
    	ft_printf(1, "total %d\n", get_blocks_size(files));
	select_sort(&files, data);
	while (*files)
	{
    	if ((*files + ft_strlen(base))[0] == '.' && !data->f_list->a)
		{
			files += 1;
			continue ;
		}
		if (data->f_list->l)
		{
			make_lflag(*files);
			ft_printf(1, " %s\n", *files + ft_strlen(base));
		}
		else
			ft_printf(1, "%s ", *files + ft_strlen(base));
		files += 1;
	}
	if (!data->f_list->l)
		ft_printf(1, "\n");
    closedir(dir);
}
