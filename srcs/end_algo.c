/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:07:51 by tnolent           #+#    #+#             */
/*   Updated: 2025/01/31 21:46:46 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	end_algo(t_list *pile_a, t_list *pile_b)
{
	int	mediane_b;

	if (!pile_a || !pile_b)
		return ;
	mediane_b = pile_b->nb_element / 2;
	calculate_position(pile_a, pile_b);
	calculate_b_s(pile_a, pile_b);
	while (pile_b->biggest && pile_b->biggest->position != 0)
	{
		if (pile_b->biggest->position <= mediane_b)
			rb(pile_b);
		else if (pile_b->biggest->position > mediane_b)
			rrb(pile_b);
		calculate_position(pile_a, pile_b);
		calculate_b_s(pile_a, pile_b);
	}
	while (pile_b->nb_element != 0)
	{
		calcul_target_pile_a(pile_a, pile_b);
		push_element_back(pile_a, pile_b);
	}
}

void	push_element_back(t_list *pile_a, t_list *pile_b)
{
	int			mediane_a;
	t_element	*current_b;

	if (!pile_a || !pile_b)
		return ;
	current_b = pile_b->first;
	mediane_a = pile_a->nb_element / 2;
	calculate_position(pile_a, pile_b);
	while (current_b->target->position != 0)
	{
		if (current_b->target->position <= mediane_a)
			ra(pile_a);
		else
			rra(pile_a);
		calculate_position(pile_a, pile_b);
	}			
	if (pile_b->nb_element == 0)
		printf("houloulou");
	if (current_b->position == 0 && current_b->target->position == 0)
		pa(pile_a, pile_b);
}
