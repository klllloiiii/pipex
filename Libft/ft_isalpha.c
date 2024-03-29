/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamburo <okamburo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:44:16 by okamburo          #+#    #+#             */
/*   Updated: 2022/11/26 00:30:47 by okamburo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int ch)
{
	if (ch >= 65 && ch <= 90)
		return (1);
	if (ch >= 97 && ch <= 122)
		return (1);
	else
		return (0);
}
