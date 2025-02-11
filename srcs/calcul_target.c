/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:24:28 by tnolent           #+#    #+#             */
/*   Updated: 2025/02/03 11:34:59 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calcul_target(t_list *pile_a, t_list *pile_b)
{
	t_element	*actuel_a;
	t_element	*actuel_b;
	t_element	*tmp_min;

	actuel_a = pile_a->first;
	while (actuel_a != NULL)
	{
		actuel_b = pile_b->first;
		if (pile_a->smallest->nombre < pile_b->smallest->nombre)
			tmp_min = pile_a->smallest;
		else
			tmp_min = pile_b->smallest;
		while (actuel_b != NULL)
		{
			if (actuel_a->nombre < pile_b->smallest->nombre)
				tmp_min = pile_b->biggest;
			if (actuel_a->nombre >= actuel_b->nombre
				&& actuel_b->nombre > tmp_min->nombre)
				tmp_min = actuel_b;
			actuel_b = actuel_b->next;
		}
		actuel_a->target = tmp_min;
		actuel_a = actuel_a->next;
	}
}

void	calcul_target_pile_a(t_list *pile_a, t_list *pile_b)
{
	t_element	*actuel_a;
	t_element	*actuel_b;
	t_element	*tmp_min;

	actuel_b = pile_b->first;
	while (actuel_b != NULL)
	{
		calculate_b_s(pile_a, pile_a);
		actuel_a = pile_a->first;
		tmp_min = pile_a->smallest;
		while (actuel_a != NULL)
		{
			if (actuel_b->nombre <= pile_a->smallest->nombre)
				tmp_min = pile_a->smallest;
			else if (actuel_b->nombre < actuel_a->nombre
				&& (tmp_min == pile_a->smallest
					|| actuel_a->nombre < tmp_min->nombre))
				tmp_min = actuel_a;
			actuel_a = actuel_a->next;
		}
		if (tmp_min == NULL)
			tmp_min = pile_a->smallest;
		actuel_b->target = tmp_min;
		actuel_b = actuel_b->next;
	}
}
