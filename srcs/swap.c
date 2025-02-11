/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:26:01 by timothee          #+#    #+#             */
/*   Updated: 2025/01/31 21:54:44 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list *pile_b);
void	sa(t_list *pile_a);

void	ss(t_list	*pile_a, t_list *pile_b)
{
	sa(pile_a);
	sb(pile_b);
	ft_printf("ss\n");
}

void	sb(t_list *pile_b)
{
	t_element	*temp;

	temp = pile_b->first->next;
	pile_b->first->next = pile_b->first->next->next;
	temp->next = pile_b->first;
	pile_b->first = temp;
	ft_printf("sb\n");
}

void	sa(t_list *pile_a)
{
	t_element	*temp;

	temp = pile_a->first->next;
	pile_a->first->next = pile_a->first->next->next;
	temp->next = pile_a->first;
	pile_a->first = temp;
	ft_printf("sa\n");
}
