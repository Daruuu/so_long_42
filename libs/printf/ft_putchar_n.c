/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:54:15 by dasalaza          #+#    #+#             */
/*   Updated: 2023/10/01 22:11:50 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_n(char c, int *counter_len)
{
	int	result;

	result = 0;
	if (*counter_len != -1)
		result = write(1, &c, 1);
	if (result == -1)
	{
		*counter_len = -1;
		return (-1);
	}
	else
	{
		*counter_len += 1;
		return (*counter_len);
	}
}
/*int	main()
{
	int	c = 97;
	size_t	ptr_len = 0;
	int		i;
	char	*ptr;
	ptr	= "hellowabcafdfda";
	
	i = 0;

	while (ptr[i] != '\0')
	{
		ft_putchar(c, ptr_len);
		i++;
	}
	return (0);
}*/
