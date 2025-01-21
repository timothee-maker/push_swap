/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:26:01 by timothee          #+#    #+#             */
/*   Updated: 2025/01/21 15:23:57 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sb(t_list *pile_b);
void sa(t_list *pile_a);

void ss(t_list	*pile_a, t_list *pile_b)
{
	sa(pile_a);
	sb(pile_b);
	pile_a->nb_iter += 1;
	ft_printf("ss\n");
}

void sb(t_list *pile_b)
{
	t_element	*temp;

	temp = pile_b->premier->suivant;
	pile_b->premier->suivant = pile_b->premier->suivant->suivant;
	temp->suivant = pile_b->premier;
	pile_b->premier = temp;
	pile_b->nb_iter += 1;
	ft_printf("sb\n");
}

void sa(t_list *pile_a)
{
	t_element	*temp;
	
	temp = pile_a->premier->suivant;
	pile_a->premier->suivant = pile_a->premier->suivant->suivant;
	temp->suivant = pile_a->premier;
	pile_a->premier = temp;
	pile_a->nb_iter += 1;
	ft_printf("sa\n");
}
