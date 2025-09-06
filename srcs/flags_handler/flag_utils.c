/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 00:29:27 by edubois-          #+#    #+#             */
/*   Updated: 2025/09/05 01:10:16 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ls.h"

int ft_memcomp(char *s1, char *s2)
{
    char c1;
    char c2;

    if (!s1 || !s2)
        return (0);
    while (*s1 && *s2)
    {
        c1 = ft_tolower(*s1);
        c2 = ft_tolower(*s2);
        if (c1 != c2)
            return (c1 - c2);
        s1++;
        s2++;
    }
    c1 = ft_tolower(*s1);
    c2 = ft_tolower(*s2);
    return (c1 - c2);
}

int is_sorted(char **tab)
{
    int i;

    i = 0;
    while (tab[i] && ft_memcomp(tab[i], tab[i + 1]) <= 0)
        i++;
    if (tab[i])
        return 0;
    return 1;
}

void    sort_char_tab(char **tab)
{
    int i;
    char *tmp;

    while (!is_sorted(tab))
    {
        i = 0;
        while (tab[i])
        {
            if (ft_memcomp(tab[i], tab[i + 1]) > 0)
            {
                tmp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = tmp;
                break;
            } 
            i++;
        }
    }
}