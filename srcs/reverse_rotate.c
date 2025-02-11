/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:23:20 by tnolent           #+#    #+#             */
/*   Updated: 2025/01/31 21:54:35 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list *pile_a);
void	rrb(t_list *pile_b);
void	rrr(t_list *pile_a, t_list *pile_b);

void	rrr(t_list *pile_a, t_list *pile_b)
{
	t_element	*actuel;
	t_element	*tmp;

	if (pile_b == NULL || pile_a == NULL)
		exit(0);
	actuel = pile_a->first;
	while (actuel->next->next != NULL)
		actuel = actuel->next;
	tmp = actuel->next;
	actuel->next = actuel->next->next;
	tmp->next = pile_a->first;
	pile_a->first = tmp;
	tmp = actuel->next;
	actuel = pile_b->first;
	while (actuel->next->next != NULL)
		actuel = actuel->next;
	tmp = actuel->next;
	actuel->next = actuel->next->next;
	tmp->next = pile_b->first;
	pile_b->first = tmp;
	tmp = actuel->next;
	ft_printf("rrr\n");
}

void	rrb(t_list *pile_b)
{
	t_element	*actuel;
	t_element	*tmp;

	if (pile_b == NULL)
		exit(0);
	actuel = pile_b->first;
	while (actuel->next->next != NULL)
		actuel = actuel->next;
	tmp = actuel->next;
	actuel->next = actuel->next->next;
	tmp->next = pile_b->first;
	pile_b->first = tmp;
	tmp = actuel->next;
	ft_printf("rrb\n");
}

void	rra(t_list *pile_a)
{
	t_element	*actuel;
	t_element	*tmp;

	if (pile_a == NULL)
		exit(0);
	actuel = pile_a->first;
	while (actuel->next->next != NULL)
		actuel = actuel->next;
	tmp = actuel->next;
	actuel->next = actuel->next->next;
	tmp->next = pile_a->first;
	pile_a->first = tmp;
	tmp = actuel->next;
	ft_printf("rra\n");
}
