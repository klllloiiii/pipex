/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamburo <okamburo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:45:57 by okamburo          #+#    #+#             */
/*   Updated: 2022/11/18 17:44:02 by okamburo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int ch, size_t count)
{
	size_t			i;
	unsigned char	*b;

	i = 0;
	b = (unsigned char *)src;
	while (i < count)
	{
		b[i] = ch;
		i++;
	}
	return (src);
}
