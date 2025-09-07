/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emile <emile@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:09:24 by emile             #+#    #+#             */
/*   Updated: 2025/09/07 21:49:37 by emile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ls.h"

int	is_reverse_sorted(char **tab)
{
    int i;

    i = 0;
    while (tab[i] && ft_memcomp(tab[i], tab[i + 1]) >= 0)
        i++;
    if (tab[i])
        return 0;
    return 1;
}

void	reverse_sort_char(char ***files)
{
    int i;
    char *tmp;
	char **tab;

	tab = *files;
    while (!is_reverse_sorted(tab))
    {
        i = 0;
        while (tab[i])
        {
            if (ft_memcomp(tab[i], tab[i + 1]) < 0)
            {
                tmp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = tmp;
                break;
            } 
            i++;
        }
    }
	*files = tab;
}

void	select_sort(char ***files, t_data *data)
{
	if (data->f_list.r)
		reverse_sort_char(files);
}