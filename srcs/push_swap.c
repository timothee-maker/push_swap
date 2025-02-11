/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:07:15 by tnolent           #+#    #+#             */
/*   Updated: 2025/02/03 14:10:51 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_3_element(t_list *pile_a);
void	handle_2_element(t_list *pile_a);
int		liste_triee(t_list *pile_a, t_list *pile_b);

void	push_swap(t_list *pile_a, t_list *pile_b)
{
	pile_a->compteur = 0;
	pb(pile_a, pile_b);
	pb(pile_a, pile_b);
	while (!liste_triee(pile_a, pile_b))
	{
		if (pile_a->nb_element == 2)
		{
			handle_2_element(pile_a);
			pile_a->compteur = 1;
		}
		if (pile_a->nb_element == 3)
		{
			handle_3_element(pile_a);
			pile_a->compteur = 1;
		}
		if (pile_a->nb_element == 3 || pile_a->compteur == 1)
		{
			end_algo(pile_a, pile_b);
			break ;
		}
		if (pile_a->compteur == 0)
			algo_ps(pile_a, pile_b);
	}
	if (pile_b->nb_element == 0)
		handle_a(pile_a);
}

void	handle_a(t_list *pile_a)
{
	int	mediane;

	if (!pile_a || pile_a->nb_element <= 3)
		return ;
	mediane = pile_a->nb_element / 2;
	calcul_a(pile_a);
	while (pile_a->smallest->position != 0)
	{
		if (pile_a->smallest->position <= mediane)
			ra(pile_a);
		else
			rra(pile_a);
		calculate_position(pile_a, pile_a);
	}
}

int	liste_triee(t_list *pile_a, t_list *pile_b)
{
	t_element	*actuel;

	if (pile_b->nb_element != 0)
		return (0);
	actuel = pile_a->first;
	while (actuel->next != NULL)
	{
		if (actuel->nombre > actuel->next->nombre)
			return (0);
		actuel = actuel->next;
	}
	return (1);
}
