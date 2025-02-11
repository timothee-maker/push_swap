/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:10:17 by tnolent           #+#    #+#             */
/*   Updated: 2024/11/21 17:41:54 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_tim(char *str, int fd)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		i += ft_str_tim("(null)", 1);
		return (6);
	}
	while (str[i])
		i++;
	write (fd, str, i);
	i = ft_strlen(str);
	return (i);
}
/*
int	main()
{
	char *str = "Je suis la";
	ft_putstr_fd(str, STDIN_FILEN0);
	return (0);
}*/
