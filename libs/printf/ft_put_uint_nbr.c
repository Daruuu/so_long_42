/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uint_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:58:13 by dasalaza          #+#    #+#             */
/*   Updated: 2023/10/01 22:25:42 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_uint_nbr(unsigned int nbr, int *counter_len)
{
	if (nbr >= 10)
	{
		ft_put_uint_nbr(nbr / 10, counter_len);
		if (*counter_len == -1)
			return ;
	}
	ft_putchar_n(nbr % 10 + '0', counter_len);
	if (*counter_len == -1)
		return ;
}
