/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emile <emile@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:38:44 by edubois-          #+#    #+#             */
/*   Updated: 2025/09/07 16:48:01 by emile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

void	ft_print_array(char **str)
{
	int	y;

	if (!str)
		return ;
	y = 0;
	while (str[y])
	{
		printf("%s", str[y]);
		if (str[y][ft_strlen(str[y]) - 1] != '\n')
			printf("\n");
		y++;
	}
	printf("\n");
	printf("\n");
	printf("\n");
}
