/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:15:30 by dasalaza          #+#    #+#             */
/*   Updated: 2023/10/01 23:23:40 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>	/* libreria de argument lists*/
# include <unistd.h>	/* write*/

int				ft_printf(char const *format, ...);
int				ft_putchar_n(char c, int *counter_len);
void			ft_putstr(char *str, int *counter_len);
void			ft_putnbr_n(int nbr, int *counter_len);
void			ft_put_uint_nbr(unsigned int nbr, int *counter_len);
void			ft_puthexa_nbr(int nbr, int *counter_len, char *base);
void			ft_put_ptr(unsigned long nbr, int *counter_len);

#endif
