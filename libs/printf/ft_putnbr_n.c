/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:53:52 by dasalaza          #+#    #+#             */
/*   Updated: 2023/10/01 23:20:28 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_recursive(int nbr, int *counter_len)
{
	if (*counter_len == -1)
		return ;
	if (nbr > 9)
	{
		ft_putnbr_n((nbr / 10), counter_len);
		if (*counter_len == -1)
			return ;
	}
	ft_putchar_n((nbr % 10 + '0'), counter_len);
}

void	ft_putnbr_n(int nbr, int *counter_len)
{
	if (nbr == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			*counter_len = -1;
		else
			*counter_len += 11;
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar_n('-', counter_len);
		if (*counter_len == -1)
			return ;
		ft_putnbr_recursive(nbr * -1, counter_len);
	}
	else
	{
		if (*counter_len == -1)
			return ;
		ft_putnbr_recursive(nbr, counter_len);
		if (*counter_len == -1)
			return ;
	}
}
