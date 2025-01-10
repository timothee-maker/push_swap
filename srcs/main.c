/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timothee <timothee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:02:00 by timothee          #+#    #+#             */
/*   Updated: 2025/01/04 12:47:06 by timothee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		len_av(char **av);
int		*full_a(int *pile_a, char **av);
void	print_all(int *pile_a, int *pile_b);
/*
int main(int ac, char **av)
{
	int	compteur;
	int	*pile_a;
	int	*pile_b;

	if (ac < 2)
		return (0);
	pile_a = malloc(sizeof(int) * len_av(av));
	pile_b = calloc(len_av(av), sizeof(int));
	pile_a = full_a(pile_a, &av[1]);
	print_all(pile_a, pile_b);
	// sa(pile_a);
	pb(pile_a, pile_b);
	print_all(pile_a, pile_b);
	free(pile_a);
	free(pile_b);

	return (0);
}*/


int *full_a(int *pile_a, char **av)
{
	int	i;

	i = 0;
	while (i < len_av(av) + 1)
	{
		pile_a[i] = atoi(av[i]);/*ohhhhhhhh*/
		i++;
	}
	return (pile_a);
}

int		len_av(char **av)
{
	int		i;

	i = 0;
	while (av[i + 1])
		i++;
	return (i);
}

void	print_all(int *pile_a, int *pile_b)
{
	for (int i = 0; pile_a[i]; i++)
		printf("%d", pile_a[i]);
	printf("\n");	
	for (int i = 0; pile_b[i]; i++)
		printf("%d", pile_b[i]);
	printf("\n");
}