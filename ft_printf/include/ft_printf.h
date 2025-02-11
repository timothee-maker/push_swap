/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:45:17 by tnolent           #+#    #+#             */
/*   Updated: 2025/01/30 15:26:16 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_strlen(const char *s);
int		ft_printf(char const *str, ...);
void	ft_putusnnbr(unsigned int nb, int fd);
void	ft_putnbr(int nb, int fd);
void	ft_putnbrbase(uintptr_t nb, char *base, int fd);
void	ft_xputnbrbase(unsigned int nb, char *base, int fd);
int		ft_bigbase_tim(unsigned int nb);
int		ft_smallbase_tim(unsigned int nb);
int		ft_len_unsnbr(unsigned int nb);
int		ft_uns_tim(unsigned int nb);
int		print_args(char c, va_list args);
int		ft_char_tim(char c, int fd);
int		ft_str_tim(char *s, int fd);
int		ft_nbr_tim(int n);
int		ft_ptr_tim(uintptr_t nb);
int		len_hexa(uintptr_t nb);
int		ft_len_nbr(int nb);
int		ft_nbr_tim(int nb);
int		ft_isascii(int c);

#endif