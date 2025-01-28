/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:52:44 by tnolent           #+#    #+#             */
/*   Updated: 2025/01/28 17:21:48 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_element(t_list *pile_a, t_list *pile_b);

int	algo_ps(t_list *pile_a, t_list *pile_b)
{
	if (pile_a->premier->target)
	{
		if (pile_a->premier->position == 0 && pile_a->premier->target->position == 0)
			pb(pile_a, pile_b);
	}
	calculate_b_s(pile_a, pile_b);
	calcul_target(pile_a, pile_b);
	calculate_position(pile_a, pile_b);
	calculate_cost(pile_a, pile_b);
	push_element(pile_a, pile_b);
		
	return (0);
}

void	push_element(t_list *pile_a, t_list *pile_b)
{
	// printf("actuel nb : %d, cost push : %d, target position : %d, target nb : %d\n", pile_a->push_element->nombre, pile_a->push_element->cost, pile_a->push_element->target->position, pile_a->push_element->target->nombre);
	if (pile_a->push_element->position <= pile_a->mediane && pile_a->push_element->position != 0)
	{
		if (pile_a->push_element->target->position <= pile_b->mediane && pile_a->push_element->target->position != 0)
			rr(pile_a, pile_b);
		else
			ra(pile_a);
	}
	else if (pile_a->push_element->target->position <= pile_b->mediane && pile_a->push_element->target->position != 0)
		rb(pile_b);
	else if (pile_a->push_element->position > pile_a->mediane)
	{
		if (pile_a->push_element->target->position > pile_b->mediane)
			rrr(pile_a, pile_b);
		else 
			rra(pile_a);
	}
	else if (pile_a->push_element->target->position > pile_b->mediane)
		rrb(pile_b);
}
