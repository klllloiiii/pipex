/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamburo <okamburo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:42:57 by okamburo          #+#    #+#             */
/*   Updated: 2022/11/21 20:29:10 by okamburo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		p;

	i = 0;
	p = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == 32 || str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\n' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{	
		if (str[i] == '-')
			p *= -1;
		if (str[i] == '+' || str[i] == '-')
			i++;
	}
	while (ft_isdigit(str[i]))
		res = res * 10 +(str[i++] - '0');
	return (res * p);
}
