/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigbase_tim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:48:54 by tnolent           #+#    #+#             */
/*   Updated: 2024/11/21 17:08:20 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_bigbase_tim(unsigned int nb)
{
	int	length_base;

	length_base = 0;
	if (nb == 0)
		length_base += write(1, "0", 1);
	else
	{
		ft_xputnbrbase(nb, "0123456789ABCDEF", 1);
		length_base += len_hexa(nb);
	}
	return (length_base);
}

void	ft_xputnbrbase(unsigned int nb, char *base, int fd)
{
	int	k;

	k = ft_strlen(base);
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 15)
	{
		ft_xputnbrbase(nb / k, base, fd);
	}
	nb = base[nb % k];
	write(fd, &nb, 1);
}
// int	main()
// {
// 	printf("%d\t", ft_base_tim(4233333, "0123456789abcdef", 1));
// 	printf("\n");
// 	printf("%d\t", printf("%x", 4233333));
// 	printf("\n");
// 	return (0);
// }