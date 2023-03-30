/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamburo <okamburo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:47:15 by okamburo          #+#    #+#             */
/*   Updated: 2022/11/21 19:29:38 by okamburo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	s1;
	unsigned char	s2;

	while (n-- > 0)
	{
		s1 = (unsigned char) *str1++;
		s2 = (unsigned char) *str2++;
		if (s1 != s2)
			return (s1 - s2);
		if (s1 == '\0')
			return (0);
	}
	return (0);
}
