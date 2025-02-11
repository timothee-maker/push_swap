/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:23:11 by tnolent           #+#    #+#             */
/*   Updated: 2025/02/03 12:13:07 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	condition_cost(t_list *pile_a, t_list *pile_b, t_element *actuel_a);
static void	calculate_push(t_list *pile_a);

void	calculate_cost(t_list *pile_a, t_list *pile_b)
{
	t_element	*actuel_a;
	t_element	*actuel_b;

	actuel_a = pile_a->first;
	actuel_b = pile_b->first;
	pile_a->mediane = pile_a->nb_element / 2;
	pile_b->mediane = pile_b->nb_element / 2;
	calculate_position(pile_a, pile_b);
	while (actuel_a != NULL)
	{
		condition_cost(pile_a, pile_b, actuel_a);
		actuel_a = actuel_a->next;
	}
	calculate_push(pile_a);
}

static void	condition_cost(t_list *pile_a, t_list *pile_b, t_element *actuel_a)
{
	actuel_a->cost = 0;
	if (actuel_a->position <= pile_a->mediane)
		actuel_a->cost = actuel_a->position;
	else
		actuel_a->cost = pile_a->nb_element - actuel_a->position;
	if (actuel_a->target->position <= pile_b->mediane)
		actuel_a->cost += actuel_a->target->position;
	else
		actuel_a->cost += pile_b->nb_element - actuel_a->target->position;
}

void	calculate_position(t_list *pile_a, t_list *pile_b)
{
	t_element	*actuel_a;
	t_element	*actuel_b;
	int			position;

	position = 0;
	actuel_a = pile_a->first;
	actuel_b = pile_b->first;
	if (!pile_a)
		return ;
	while (actuel_a != NULL)
	{
		actuel_a->position = position;
		position += 1;
		actuel_a = actuel_a->next;
	}
	position = 0;
	if (pile_b->nb_element == 0)
		return ;
	while (actuel_b != NULL)
	{
		actuel_b->position = position;
		position += 1;
		actuel_b = actuel_b->next;
	}
}

static void	calculate_push(t_list *pile_a)
{
	t_element	*current_a;
	int			cost_min;

	current_a = pile_a->first;
	cost_min = current_a->cost;
	pile_a->push_element = current_a;
	while (current_a != NULL)
	{
		if (current_a->cost == 0 || current_a->cost == 1)
		{
			pile_a->push_element = current_a;
			break ;
		}
		if (current_a->cost < cost_min
			&& pile_a->push_element->cost > current_a->cost)
		{
			pile_a->push_element = current_a;
			cost_min = current_a->cost;
		}
		current_a = current_a->next;
	}
}
