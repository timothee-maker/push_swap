/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smallbase_tim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:16:47 by tnolent           #+#    #+#             */
/*   Updated: 2024/11/21 17:09:14 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_smallbase_tim(unsigned int nb)
{
	int	length_base;

	length_base = 0;
	if (nb == 0)
		length_base += write(1, "0", 1);
	else
	{
		ft_putnbrbase(nb, "0123456789abcdef", 1);
		length_base += len_hexa(nb);
	}
	return (length_base);
}

// int	main()
// {
// 	printf("%d\t", ft_base_tim(4233333, "0123456789abcdef", 1));
// 	printf("\n");
// 	printf("%d\t", printf("%x", 4233333));
// 	printf("\n");
// 	return (0);
// }