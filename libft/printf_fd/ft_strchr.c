/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emile <emile@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:51:06 by edubois-          #+#    #+#             */
/*   Updated: 2025/09/07 19:20:53 by emile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	while (s && *s)
	{
		if (*s++ == (unsigned char)c)
			return ((char *)s - 1);
	}
	if (!(unsigned char)c)
		return ((char *)s);
	return (0);
}
