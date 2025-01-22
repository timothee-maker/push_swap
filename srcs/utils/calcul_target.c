/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:24:28 by tnolent           #+#    #+#             */
/*   Updated: 2025/01/22 16:40:34 by tnolent          ###   ########.fr       */
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
			{
				tmp_min = pile_b->biggest;
			}
			if (actuel_a->nombre > actuel_b->nombre && actuel_b->nombre > tmp_min->nombre)
				tmp_min = actuel_b;
			actuel_b = actuel_b->suivant;
		}
		actuel_a->target = tmp_min;
		// printf("%d -> %d\n", actuel_a->nombre, actuel_a->target->nombre);
		actuel_a = actuel_a->suivant;
	}
}

