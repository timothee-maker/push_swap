/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:24:28 by tnolent           #+#    #+#             */
/*   Updated: 2025/01/28 18:58:19 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void calcul_target(t_list *pile_a, t_list *pile_b)
{
	t_element *actuel_a;
	t_element *actuel_b;
	t_element *tmp_min;

	actuel_a = pile_a->premier;
	while (actuel_a != NULL)
	{
		actuel_b = pile_b->premier;
		if (pile_a->smallest < pile_b->smallest)
			tmp_min = pile_a->smallest;
		else
			tmp_min = pile_b->smallest;
		while (actuel_b != NULL)
		{
			if (actuel_a->nombre < pile_b->smallest->nombre)
				tmp_min = pile_b->biggest;
			if (actuel_a->nombre >= actuel_b->nombre && actuel_b->nombre > tmp_min->nombre)
				tmp_min = actuel_b;
			actuel_b = actuel_b->suivant;
		}
		actuel_a->target = tmp_min;
		// printf("%d -> %d\n", actuel_a->nombre, actuel_a->target->nombre);
		actuel_a = actuel_a->suivant;
	}
}

void calcul_target_pile_a(t_list *pile_a, t_list *pile_b)
{
	t_element *actuel_a;
	t_element *actuel_b;
	t_element *tmp_min;

	actuel_b = pile_b->premier;
	// pa(pile_a, pile_b);
	while (actuel_b != NULL)
	{
		calculate_b_s(pile_a, pile_a);
		actuel_a = pile_a->premier;
		tmp_min = pile_a->smallest;
		while (actuel_a != NULL)
		{
			if (actuel_b->nombre <= pile_a->smallest->nombre)
				tmp_min = pile_a->smallest;
			else if (actuel_b->nombre < actuel_a->nombre && (tmp_min == pile_a->smallest || actuel_a->nombre < tmp_min->nombre))
				tmp_min = actuel_a;
			actuel_a = actuel_a->suivant;
		}
		if (actuel_b->nombre > pile_a->biggest->nombre)
			tmp_min = pile_a->smallest;
		actuel_b->target = tmp_min;
		// printf("Biggest_a : %d, smallest_a : %d\n", pile_a->biggest->nombre, pile_a->smallest->nombre);
		// printf("%d -> %d\n", actuel_b->nombre, actuel_b->target->nombre);
		actuel_b = actuel_b->suivant;
	}
}