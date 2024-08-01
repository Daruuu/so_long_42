/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:20:36 by dasalaza          #+#    #+#             */
/*   Updated: 2023/10/01 17:33:55 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *counter_len)
{
	size_t	i;

	if (str == NULL)
	{
		ft_putstr("(null)", counter_len);
		return ;
	}
	i = 0;
	while (str[i] != '\0' && *counter_len != -1)
	{
		ft_putchar_n(str[i], counter_len);
		i++;
	}
}
/*
int	main()
{
	int	i;
	ft_putstr("",0 );
	printf("\n-------------\n");
	printf(ft_putstr("",0 ));
	printf("%s", "");
	printf(printf("%s", ""));

	return (0);
}
*/
