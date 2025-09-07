/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emile <emile@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:10:08 by edubois-          #+#    #+#             */
/*   Updated: 2025/09/07 16:42:07 by emile            ###   ########.fr       */
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

void    get_flags(int argc, char **argv, t_data *data)
{
    int i;

    i = 0;
    data->flags = NULL;
    data->folders = NULL;
    data->files = NULL;
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
	printf("data :\n");
	printf("flags :\n");
	ft_print_array(data->flags);
	printf("folder :\n");
	ft_print_array(data->folders);
	printf("file :\n");
	ft_print_array(data->files);
}
