/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_tim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:48:54 by tnolent           #+#    #+#             */
/*   Updated: 2024/11/21 17:42:39 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_tim(uintptr_t nb)
{
	int	length_nb;

	length_nb = 0;
	if (nb == 0)
		length_nb += write(1, "(nil)", 5);
	else
	{
		length_nb += write(1, "0x", 2);
		ft_putnbrbase(nb, "0123456789abcdef", 1);
		length_nb += len_hexa(nb);
	}
	return (length_nb);
}

// int	main(void)
// {
// 	int nb = 4343434;
// 	uintptr_t ptr = 4343434;
// 	printf("%p\n", &ptr);
// 	printf("%lx\n", (uintptr_t)(&ptr));
// 	printf("%lx\n", (uintptr_t)(ptr));
// 	printf("\t%d\n", ft_ptr_tim(ptr));
// 	printf("\t%d\n", ft_ptr_tim(nb));
// 	printf("\t%d", printf("%x", nb));
// 	printf("\n");
// 	return (0);
// }