/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_tim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:09:13 by tnolent           #+#    #+#             */
/*   Updated: 2024/11/20 11:17:48 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char_tim(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
/*
int	main()
{
	FILE* fichier = NULL;

	fichier = fopen("test.txt", "w");

	if (fichier != NULL)
	{
		ft_putchar_fd('A', 4); // Écriture du caractère A
		fclose(fichier);
	}

	return 0;
}*/
