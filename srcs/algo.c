/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:52:44 by tnolent           #+#    #+#             */
/*   Updated: 2025/01/21 12:37:08 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	init_cost(t_list *pile_a);

int	algo_ps(t_list *pile_a, t_list *pile_b)
{
	t_element	*actuel_a;
	t_element	*actuel_b;

	actuel_a = pile_a->premier;
	actuel_b = pile_b->premier;
	calculate_b_s(pile_a, pile_b);
	calcul_target(pile_a, pile_b);
	calculate_position(pile_a, pile_b);
	calculate_cost(pile_a, pile_b);
	
	return (0);
}
