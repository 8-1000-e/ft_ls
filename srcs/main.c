/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emile <emile@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:52:25 by edubois-          #+#    #+#             */
/*   Updated: 2025/09/07 16:31:04 by emile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

void    manage_flags(t_data *data)
{
	if (!data->folders && !data->files)
	{
		flag_l(data, BASEROOT);
	}
}    

int main(int argc, char **argv)
{
	t_data data;

    get_flags(argc, argv, &data);
    manage_flags(&data);
}