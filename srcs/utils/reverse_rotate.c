/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:23:20 by tnolent           #+#    #+#             */
/*   Updated: 2025/01/28 18:59:40 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
// la pile a. Le dernier élément devient le premier.
void rra(t_list *pile_a);
void rrb(t_list *pile_b);
void rrr(t_list *pile_a, t_list *pile_b);

void rrr(t_list *pile_a, t_list *pile_b)
{
	t_element *actuel;
	t_element *tmp;

	if (pile_b == NULL || pile_a == NULL)
		exit(0);
	actuel = pile_a->premier;
	while (actuel->suivant->suivant != NULL)
		actuel = actuel->suivant;
	tmp = actuel->suivant;
	actuel->suivant = actuel->suivant->suivant;
	tmp->suivant = pile_a->premier;
	pile_a->premier = tmp;
	tmp = actuel->suivant;
	pile_a->nb_iter += 1;
	actuel = pile_b->premier;
	while (actuel->suivant->suivant != NULL)
		actuel = actuel->suivant;
	tmp = actuel->suivant;
	actuel->suivant = actuel->suivant->suivant;
	tmp->suivant = pile_b->premier;
	pile_b->premier = tmp;
	tmp = actuel->suivant;
	pile_a->nb_iter += 1;

	ft_printf("rrr\n");
}

void rrb(t_list *pile_b)
{
	t_element *actuel;
	t_element *tmp;

	if (pile_b == NULL)
		exit(0);
	actuel = pile_b->premier;
	while (actuel->suivant->suivant != NULL)
		actuel = actuel->suivant;
	tmp = actuel->suivant;
	actuel->suivant = actuel->suivant->suivant;
	tmp->suivant = pile_b->premier;
	pile_b->premier = tmp;
	tmp = actuel->suivant;
	pile_b->nb_iter += 1;
	ft_printf("rrb\n");
}

void rra(t_list *pile_a)
{
	t_element *actuel;
	t_element *tmp;

	if (pile_a == NULL)
		exit(0);
	actuel = pile_a->premier;
	while (actuel->suivant->suivant != NULL)
		actuel = actuel->suivant;
	tmp = actuel->suivant;
	actuel->suivant = actuel->suivant->suivant;
	tmp->suivant = pile_a->premier;
	pile_a->premier = tmp;
	tmp = actuel->suivant;
	pile_a->nb_iter += 1;
	ft_printf("rra\n");
}