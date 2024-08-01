/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:02:04 by dasalaza          #+#    #+#             */
/*   Updated: 2023/10/01 17:51:25 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_ptr(unsigned long nbr, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (*count != -1)
	{
		if (nbr >= 16 && *count != -1)
			ft_print_ptr(nbr / 16, count);
		if (*count != -1 && ft_putchar_n(base[nbr % 16], count) == -1)
			*count = -1;
	}
}

void	ft_put_ptr(unsigned long nbr, int *counter_len)
{
	ft_putstr("0x", counter_len);
	ft_print_ptr(nbr, counter_len);
}
