/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamburo <okamburo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:45:18 by okamburo          #+#    #+#             */
/*   Updated: 2022/11/22 23:59:37 by okamburo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;

	a = (unsigned char *)arr;
	i = 0;
	while (i < n)
	{
		if (*a == (unsigned char)c)
			return (a);
		i++;
		a++;
	}
	return (NULL);
}
