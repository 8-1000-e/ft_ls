/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:19:11 by edubois-          #+#    #+#             */
/*   Updated: 2025/09/05 01:10:37 by edubois-         ###   ########.fr       */
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
        if (**files == '.')
        {
            files += 1;
            continue;
        }
        if (stat(*files, &file_stat) == 0)
            size += (file_stat.st_blocks + 1) / 2;
        files += 1;
    }
    return size;
}

void    make_Lflag(char *file)
{
    struct stat	file_stat;
    int filemod;

    if (*file == '.')
        return ;
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
    ft_printf(1, " %s\n", file);
}


void    flag_l(t_data *data)
{
    char **files;
    DIR *dir;
    struct dirent *entry;
    (void)data;

    files = NULL;
    dir = opendir(".");
    entry = readdir(dir);
    while (entry)
    {
        ft_strapp(&files, entry->d_name);
        entry = readdir(dir);
    }
    ft_printf(1, "total %d\n", get_blocks_size(files));
    sort_char_tab(files);
    while (*files)
        make_Lflag(*files++);
    closedir(dir);
}
