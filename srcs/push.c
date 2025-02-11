/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:25:52 by timothee          #+#    #+#             */
/*   Updated: 2025/01/31 21:54:20 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list *pile_a, t_list *pile_b)
{
	t_element	*sommet_b;

	if (!pile_a || !pile_b)
		return ;
	if (pile_b->first != NULL)
	{
		sommet_b = pile_b->first;
		pile_b->first = pile_b->first->next;
		sommet_b->next = pile_a->first;
		pile_a->first = sommet_b;
	}
	pile_b->nb_element -= 1;
	pile_a->nb_element += 1;
	ft_printf("pa\n");
}

void	pb(t_list *pile_a, t_list *pile_b)
{
	t_element	*sommet_a;

	if (!pile_a || !pile_b)
		return ;
	if (pile_a->first != NULL)
	{
		sommet_a = pile_a->first;
		pile_a->first = pile_a->first->next;
		sommet_a->next = pile_b->first;
		pile_b->first = sommet_a;
	}
	pile_a->nb_element -= 1;
	pile_b->nb_element += 1;
	ft_printf("pb\n");
}
