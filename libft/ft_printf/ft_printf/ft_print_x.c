/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:50:20 by claprand          #+#    #+#             */
/*   Updated: 2024/04/22 14:55:12 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x(unsigned int x, char c, int *len)
{
	if (x >= 16)
	{
		ft_print_x(x / 16, c, len);
		ft_print_x(x % 16, c, len);
	}
	else
	{
		if (x <= 9)
		{
			ft_putchar_fd(x + 48, 1);
			*len += ft_hex_len(x);
		}
		else
		{
			ft_putchar_fd(x - 10 + 97, 1);
			*len += ft_hex_len(x);
		}
	}
	return (*len);
}
