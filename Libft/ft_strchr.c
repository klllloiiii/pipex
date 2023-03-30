/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamburo <okamburo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:46:23 by okamburo          #+#    #+#             */
/*   Updated: 2022/11/26 23:30:45 by okamburo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int ch)
{
	if ((char)ch == '\0')
		return ((char *)(s + ft_strlen(s)));
	return ((char *)ft_memchr(s, ch, ft_strlen(s)));
}
