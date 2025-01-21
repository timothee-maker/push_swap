/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:55:27 by tnolent           #+#    #+#             */
/*   Updated: 2025/01/21 14:52:20 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calculate_cost(t_list *pile_a, t_list *pile_b)
{
	t_element	*actuel_a;
	t_element	*actuel_b;
	int			mediane_a;
	int			mediane_b;

	actuel_a = pile_a->premier;
	actuel_b = pile_b->premier;
	mediane_a = pile_a->nb_element / 2;
	mediane_b = pile_b->nb_element / 2;
	while (actuel_a != NULL)
	{
		actuel_a->cost = 0;
		while (actuel_a->position != 0 && actuel_a->target->position != 0)
		{
			calculate_position(pile_a, pile_b);
			if (actuel_a->position <= mediane_a)
			{
				if (actuel_b->position <= mediane_b)
					actuel_a->cost += 1;
				break ;
			}
			else
				break ;
		}
		printf("number : %d, position : %d\n", actuel_a->nombre, actuel_a->position);
		actuel_a = actuel_a->suivant;
	}
	return (0);
}

void calculate_position(t_list *pile_a, t_list *pile_b)
{
	t_element	*actuel_a;
	t_element	*actuel_b;
	int			position;

	position = 0;
	actuel_a = pile_a->premier;
	actuel_b = pile_b->premier;
	while (actuel_a != NULL)
	{
		actuel_a->position = position;
		position += 1;
		actuel_a = actuel_a->suivant;
	}
	position = 0;
	if (pile_b->nb_element == 0)
		return;
	while (actuel_b != NULL)
	{
		actuel_b->position = position;
		position += 1;
		actuel_b = actuel_b->suivant;
	}
}

// int	init_cost(t_list *pile)
// {
// 	t_element	*actuel;

// 	actuel = pile->premier;
// 	while (actuel->suivant != NULL)
// 	{
// 		actuel->cost = 0;
// 		actuel = actuel->suivant;
// 	}
// 	return (0);
// }