/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:59:14 by tnolent           #+#    #+#             */
/*   Updated: 2025/01/30 13:28:27 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list *pile_a, t_list *pile_b)
{
	t_element	*tmp;
	t_element	*current;

	if (!pile_a || !pile_b)
		return ;
	if (pile_b->first != NULL && pile_a->first != NULL)
	{
		current = pile_b->first;
		tmp = pile_b->first;
		pile_b->first = pile_b->first->next;
		while (current->next != NULL)
			current = current->next;
		current->next = tmp;
		tmp->next = NULL;
		current = pile_a->first;
		tmp = pile_a->first;
		pile_a->first = pile_a->first->next;
		while (current->next != NULL)
			current = current->next;
		current->next = tmp;
		tmp->next = NULL;
	}
	ft_printf("rr\n");
}

void	rb(t_list *pile_b)
{
	t_element	*tmp;
	t_element	*current;

	if (!pile_b)
		return ;
	if (pile_b->first != NULL)
	{
		current = pile_b->first;
		tmp = pile_b->first;
		pile_b->first = pile_b->first->next;
		while (current->next != NULL)
			current = current->next;
		current->next = tmp;
		tmp->next = NULL;
	}
	ft_printf("rb\n");
}

void	ra(t_list *pile_a)
{
	t_element	*tmp;
	t_element	*current_a;

	if (!pile_a)
		return ;
	if (pile_a->first != NULL)
	{
		current_a = pile_a->first;
		tmp = pile_a->first;
		pile_a->first = pile_a->first->next;
		while (current_a->next != NULL)
			current_a = current_a->next;
		current_a->next = tmp;
		tmp->next = NULL;
	}
	ft_printf("ra\n");
}
