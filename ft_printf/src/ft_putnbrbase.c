/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:08:12 by tnolent           #+#    #+#             */
/*   Updated: 2024/11/20 19:34:38 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_hexa(uintptr_t nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

void	ft_putnbrbase(uintptr_t nb, char *base, int fd)
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
		ft_putnbrbase(nb / k, base, fd);
	}
	nb = base[nb % k];
	write(fd, &nb, 1);
}
