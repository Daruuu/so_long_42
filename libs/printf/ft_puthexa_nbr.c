/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:36:42 by dasalaza          #+#    #+#             */
/*   Updated: 2023/10/01 20:55:09 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa_nbr(int nbr, int *counter_len, char *base)
{
	unsigned int	unbr;

	unbr = (unsigned int) nbr;
	if (unbr >= 16 && *counter_len != -1)
	{
		ft_puthexa_nbr(unbr / 16, counter_len, base);
	}
	if (*counter_len != -1 && ft_putchar_n(base[unbr % 16], counter_len) == -1)
	{
		*counter_len = -1;
	}
}
