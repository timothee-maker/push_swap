/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:59:14 by tnolent           #+#    #+#             */
/*   Updated: 2025/01/28 18:59:51 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list *pile_a, t_list *pile_b)
{
	t_element	*tmp;
	t_element	*current;

	if (!pile_a || !pile_b)
		return ;
	if (pile_b->premier != NULL)
	{
		current = pile_b->premier;
		tmp = pile_b->premier;
		pile_b->premier = pile_b->premier->suivant;
		while (current->suivant != NULL)
			current = current->suivant;
		current->suivant = tmp;
		tmp->suivant = NULL;
	}
	if (pile_a->premier != NULL)
	{
		current = pile_a->premier;
		tmp = pile_a->premier;
		pile_a->premier = pile_a->premier->suivant;
		while (current->suivant != NULL)
			current = current->suivant;
		current->suivant = tmp;
		tmp->suivant = NULL;
	}
	pile_a->nb_iter += 1;
	ft_printf("rr\n");
}

void	rb(t_list *pile_b)
{
	t_element	*tmp;
	t_element	*current;

	if (!pile_b)
		exit(0);
	if (pile_b->premier != NULL)
	{
		current = pile_b->premier;
		tmp = pile_b->premier;
		pile_b->premier = pile_b->premier->suivant;
		while (current->suivant != NULL)
			current = current->suivant;
		current->suivant = tmp;
		tmp->suivant = NULL;
	}
	pile_b->nb_iter += 1;
	ft_printf("rb\n");
}

void	ra(t_list *pile_a)
{
	t_element	*tmp;
	t_element	*current_a;

	if (!pile_a)
		exit(0);
	if (pile_a->premier != NULL)
	{
		current_a = pile_a->premier;
		tmp = pile_a->premier;
		pile_a->premier = pile_a->premier->suivant;
		while (current_a->suivant != NULL)
			current_a = current_a->suivant;
		current_a->suivant = tmp;
		tmp->suivant = NULL;
	}
	pile_a->nb_iter += 1;
	ft_printf("ra\n");
}
