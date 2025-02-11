/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_tim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:10:55 by tnolent           #+#    #+#             */
/*   Updated: 2024/11/20 19:09:37 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsnbr(unsigned int nb, int fd)
{
	if (nb > 9)
		ft_putunsnbr(nb / 10, fd);
	nb = (nb % 10 + '0');
	write(fd, &nb, 1);
}

int	ft_len_unsnbr(unsigned int nb)
{
	int	i;

	i = 0;
	while ((nb / 10) > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i + 1);
}

int	ft_uns_tim(unsigned int nb)
{
	if (nb < 0)
		nb *= -1;
	ft_putunsnbr(nb, 1);
	return (ft_len_unsnbr(nb));
}

// int	main(void)
// {
// 	int	nb = -2147483648;
// 	printf("\t%d", ft_uns_tim(nb));
// 	printf("\n");
// 	printf("\t%d", printf("%u", nb));
// 	return (0);
// }
