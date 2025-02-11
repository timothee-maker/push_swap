/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:49:03 by tnolent           #+#    #+#             */
/*   Updated: 2024/11/23 17:11:13 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_args(char c, va_list args);
int	check_conv(char conv);

int	ft_printf(char const *str, ...)
{
	int			i;
	int			nb_args;
	va_list		args;

	i = 0;
	nb_args = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%' && check_conv(str[i + 1]))
		{
			nb_args += print_args(str[i + 1], args);
			i += 2;
		}
		else
		{
			write(1, &str[i++], 1);
			nb_args++;
		}
	}
	va_end(args);
	return (nb_args);
}

int	print_args(char c, va_list args)
{
	int	nb_args;

	nb_args = 0;
	if (c == 's')
		nb_args += ft_str_tim(va_arg(args, char *), 1);
	else if (c == 'c')
		nb_args += ft_char_tim(va_arg(args, int), 1);
	else if (c == 'd')
		nb_args += ft_nbr_tim(va_arg(args, int));
	else if (c == 'x')
		nb_args += ft_smallbase_tim(va_arg(args, int));
	else if (c == 'X')
		nb_args += ft_bigbase_tim(va_arg(args, int));
	else if (c == 'u')
		nb_args += ft_uns_tim(va_arg(args, int));
	else if (c == 'i')
		nb_args += ft_nbr_tim(va_arg(args, int));
	else if (c == 'p')
		nb_args += ft_ptr_tim(va_arg(args, uintptr_t));
	else if (c == '%')
		nb_args += write(1, "%", 1);
	return (nb_args);
}

int	check_conv(char conv)
{
	if (conv == 'c' || conv == 's' || conv == 'x' || conv == 'X' || conv == 'u')
		return (1);
	else if (conv == 'i' || conv == 'p' || conv == '%' || conv == 'd')
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int	p = 23;
// 	int	*o = &p;
// 	int	t[2][4] = {{3, 7, 9, 4}, {3, 5, 7, 8}};
// 	char	*h[] = {"okay le sang", "shesh"};
// 	char	*k = "Je suis la";

// 	printf("OG printf : %%%p\n%x%x%s%c\n", k, 29, 26, "caca", 'p');
// 	ft_printf("My printf : %%%p\n%x%x%s%c",k , 29, 26, "caca", 'p');
// 	printf("\n");
// 	return (0);
// }