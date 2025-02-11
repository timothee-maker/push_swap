/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_tim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:09:03 by tnolent           #+#    #+#             */
/*   Updated: 2024/11/20 18:22:08 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int fd)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, fd);
	}
	nb = nb % 10 + '0';
	i++;
	write(fd, &nb, 1);
}

int	ft_len_nbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		i += 2;
		nb = 147483648;
	}
	else if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while ((nb / 10) > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i + 1);
}

int	ft_nbr_tim(int nb)
{
	ft_putnbr(nb, 1);
	return (ft_len_nbr(nb));
}

// int	main(void)
// {
// 	int	a = -2147483648;
// 	printf("\t%d\n" ,ft_nbr_tim(a));
// 	printf("\t%d", printf("%d", a));
// 	return (0);
// }