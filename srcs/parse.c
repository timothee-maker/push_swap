/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 05:28:22 by tnolent           #+#    #+#             */
/*   Updated: 2025/02/11 10:47:14 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_split(char **av);
int		check_doublon(char **result, char *str, int index, int compteur);
void	ft_free_split(char **str);
void	error_case(char **result, int compteur);
void	handle_normal(char **av);

void	handle_error(int ac, char **av)
{
	if (ac < 2)
	{
		ft_printf("Error\n");
		exit(0);
	}
	if (ac == 2 && ft_strlen(av[1]) > 1)
		handle_split(av);
	else if (ac > 2)
		handle_normal(av);
	else
		exit(0);
}

void	handle_normal(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		if (!av[i][j])
			error_case(av, 1);
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				error_case(av, 1);
			if (check_doublon(av, av[i], i, 1))
				error_case(av, 1);
			j++;
		}
		i++;
	}
}

void	handle_split(char **av)
{
	char	**result_split;
	int		i;
	int		j;

	result_split = ft_split(av[1], ' ');
	i = 0;
	while (result_split[i])
	{
		j = 0;
		if (check_doublon(result_split, result_split[i], i, 0))
			error_case(result_split, 0);
		if (result_split[i][j] == '-' || result_split[i][j] == '+')
			j++;
		if (!result_split[i][j])
			error_case(result_split, 0);
		while (result_split[i][j])
		{
			if (!ft_isdigit(result_split[i][j++]))
				error_case(result_split, 0);
		}
		i++;
	}
	if (i == 0)
		error_case(result_split, 0);
	ft_free_split(result_split);
}

void	error_case(char **str, int compteur)
{
	if (compteur == 0)
		ft_free_split(str);
	ft_printf("Error\n");
	exit (0);
}

int	check_doublon(char **result, char *str, int index, int compteur)
{
	int	i;

	i = 0;
	if (compteur == 1)
		i = 1;
	while (result[i] && i < index)
	{
		if (ft_atoi(result[i]) == ft_atoi(str))
			return (1);
		i++;
	}
	return (0);
}
