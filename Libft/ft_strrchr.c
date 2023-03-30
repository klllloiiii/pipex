/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamburo <okamburo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:47:35 by okamburo          #+#    #+#             */
/*   Updated: 2022/11/26 23:26:13 by okamburo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	i;

	i = ft_strlen(str);
	if ((char)ch == '\0')
		return ((char *)str + i);
	while (i--)
		if (str[i] == (char)ch)
			return ((char *)str + i);
	return (NULL);
}
