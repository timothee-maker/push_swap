/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:02:00 by timothee          #+#    #+#             */
/*   Updated: 2025/01/11 11:20:28by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		len_av(char **av);
int		*full_a(t_list *pile_a, char **av);
void	vider_piles(t_list *pile_a, t_list *pile_b);
int		init_piles(t_list *pile_a, t_list *pile_b, int ac, char **av);

int main(int ac, char **av)
{
	t_list 	*pile_a;
	t_list 	*pile_b;
	char	**result_split;
	int		i;

	pile_a = initialisation();
	pile_b = initialisation();
	init_piles(pile_a, pile_b, ac, av);
	push_swap(pile_a, pile_b);
	vider_piles(pile_a, pile_b);
	return (0);
}

int		init_piles(t_list *pile_a, t_list *pile_b, int ac, char **av)
{
	int		i;
	char	**result_split;

	i = 0;
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		result_split = ft_split(av[1], ' ');
		full_a(pile_a, result_split);
		while (result_split[i])
			free(result_split[i++]);
		free(result_split);
	}
	else
		full_a(pile_a, &av[1]);
	pile_a->nb_iter = 0;
	return (0);
}

void	vider_piles(t_list *pile_a, t_list *pile_b)
{	
	afficherListe(pile_a);
	afficherListe(pile_b);
	destruction(pile_a);
	destruction(pile_b);
	free(pile_a);
	free(pile_b);
}

int	*full_a(t_list *pile_a, char **av)
{
	int	i;

	i = 0;
	while (i < len_av(av) + 1)
	{
		insertion_f(pile_a, atoi(av[i]));
		i++;
	}
	return (0);
}

int		len_av(char **av)
{
	int		i;

	i = 0;
	while (av[i + 1])
		i++;
	return (i);
}
