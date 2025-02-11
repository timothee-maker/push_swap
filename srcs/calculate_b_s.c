/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_b_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 09:45:02 by tnolent           #+#    #+#             */
/*   Updated: 2025/01/31 18:36:50 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calcul_a(t_list *pile_a);
int	calcul_b(t_list *pile_b);

int	calculate_b_s(t_list *pile_a, t_list *pile_b)
{
	if (pile_a)
		calcul_a(pile_a);
	if (pile_b)
		calcul_b(pile_b);
	return (0);
}

int	calcul_a(t_list *pile_a)
{
	t_element	*actuel_a;
	t_element	*temp_min;
	t_element	*temp_max;

	actuel_a = pile_a->first;
	temp_min = actuel_a;
	temp_max = actuel_a;
	while (actuel_a != NULL)
	{
		if (actuel_a->nombre > temp_max->nombre)
			temp_max = actuel_a;
		if (actuel_a->nombre < temp_min->nombre)
			temp_min = actuel_a;
		actuel_a = actuel_a->next;
	}
	pile_a->biggest = temp_max;
	pile_a->smallest = temp_min;
	return (0);
}

int	calcul_b(t_list *pile_b)
{
	t_element	*actuel_b;
	t_element	*temp_min;
	t_element	*temp_max;

	if (pile_b->nb_element == 0)
		return (0);
	actuel_b = pile_b->first;
	temp_min = actuel_b;
	temp_max = actuel_b;
	while (actuel_b != NULL)
	{
		if (actuel_b->nombre > temp_max->nombre)
			temp_max = actuel_b;
		if (actuel_b->nombre < temp_min->nombre)
			temp_min = actuel_b;
		actuel_b = actuel_b->next;
	}
	pile_b->biggest = temp_max;
	pile_b->smallest = temp_min;
	return (0);
}
