/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emile <emile@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:10:08 by edubois-          #+#    #+#             */
/*   Updated: 2025/09/07 23:00:31 by emile            ###   ########.fr       */
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

int check_folder(char *str)
{
	DIR *directory;

	directory = opendir(str);
	if (directory)
	{
		closedir(directory);
		return (1);
	}
	return (0);		
}

int check_file(char *str)
{
	int fd;

	fd = open(str, O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	return (0);		
}

void	format_folders(t_data *data)
{
	int i;

	i = -1;
	while (data->folders && data->folders[++i])
	{
		if (data->folders[i][ft_strlen(data->folders[i]) - 1] != '/')
			data->folders[i] = ft_strjoin(data->folders[i], "/");
	}
}

void	fill_data(t_data *data)
{
	int i;

 	i = -1;
	while (data->flags && data->flags[++i])
	{
		if (ft_strchr(data->flags[i], 'l'))
			data->f_list->l = 1;
		if (ft_strchr(data->flags[i], 'a'))
			data->f_list->a = 1;
		if (ft_strchr(data->flags[i], 'r'))
			data->f_list->r = 1;
		if (ft_strchr(data->flags[i], 'R'))
			data->f_list->R = 1;
		if (ft_strchr(data->flags[i], 't'))
			data->f_list->t = 1;
	}
}

void    get_flags(int argc, char **argv, t_data *data)
{
    int i;

    i = 0;
    data->flags = NULL;
    data->folders = NULL;
    data->files = NULL;
	data->f_list = (t_flags *)malloc(sizeof(t_flags));
	if (!data->f_list)
		return ;
    while (++i < argc)
    {
        if (check_args(argv[i]))
            ft_strapp(&data->flags, argv[i]);
		else if (check_folder(argv[i]))
			ft_strapp(&data->folders, argv[i]);
		else if (check_file(argv[1]))
			ft_strapp(&data->files, argv[1]);
		// else
			//return error
    }
	fill_data(data);
	format_folders(data);
}