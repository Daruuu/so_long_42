/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:19:20 by dasalaza          #+#    #+#             */
/*   Updated: 2023/10/01 23:21:31 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
 * funcion variadica
*/

static void	check_type_input(char format, va_list args, int *counter_len)
{
	if (format == 'c')
		ft_putchar_n(va_arg(args, int), counter_len);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), counter_len);
	else if (format == 'p')
		ft_put_ptr(va_arg(args, unsigned long), counter_len);
	else if (format == 'd' || format == 'i')
		ft_putnbr_n(va_arg(args, int), counter_len);
	else if (format == 'u')
		ft_put_uint_nbr(va_arg(args, unsigned int), counter_len);
	else if ((format == 'x') || (format == 'X'))
	{
		if (format == 'x')
			ft_puthexa_nbr(va_arg(args, int), counter_len, "0123456789abcdef");
		else
			ft_puthexa_nbr(va_arg(args, int), counter_len, "0123456789ABCDEF");
	}
	else if (format == '%')
		ft_putchar_n('%', counter_len);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		chars_printed;
	size_t	i;

	i = 0;
	va_start (args, format);
	chars_printed = 0;
	while (format[i] && chars_printed != -1)
	{
		if (format[i] == '%')
		{
			i++;
			check_type_input(format[i], args, &chars_printed);
			i++;
		}
		else
		{
			ft_putchar_n(format[i], &chars_printed);
			i++;
		}
	}
	va_end(args);
	return (chars_printed);
}
/*
int	main( )
{
    ft_printf("%s ", "");
	//printf("\n--------------\n");
	//printf("%s ", "");

}
int main()
{
    printf("test char:\n");
    ft_printf("%c\n", ' ');
    ft_printf("%c\n", 'z');
    ft_printf("%c\n", '!');
    printf("---------------\n");
	*/
	/*
    printf("test STRING:\n");
    ft_printf("%s\n", "hello");
    ft_printf("%s\n", "123-hello");
    ft_printf("%s\n", "5555-qwerty!");
	*/
/*
	int		a01;
	int		a;
	int		b;

	//int	a02;
	//int	a03;
	//int	a04;

	//a01 = -2147483647;
	a01 = -2147483648;

	a = ft_printf("%i\n", a01);
	ft_printf("%d\n", a01);
	b = printf("%i\n", a01);
	printf("mi funcion:%d\nOriginal:%d\n", a, b);
	ft_printf("%i\n", a02);
	ft_printf("%i\n", a03);
	ft_printf("%i\n", a04);
    //unsigned int test01 = 0;
//    unsigned int test01 = 100;
	unsigned int test01 = 123456789;
    unsigned int test02 = -1;
    unsigned int test03 = 100;
    unsigned int test04 = 123456789;
    unsigned int test05 = 4294967295;
	unsigned int		resutl;
    printf("test UNSIGNED INT:\n");
    ft_printf("mi	 funcion: %u\n", test01);
    printf("funcion original: %u\n", test01);
    resutl = ft_printf("%u\n", test01);
	printf("%u\n", resutl);

    ft_printf("%u\n", test02);
	ft_printf("%u\n", test03);
	ft_printf("%u\n", test04);
	ft_printf("%u\n", test05);
    return (0);
}
*/
