/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:25:52 by timothee          #+#    #+#             */
/*   Updated: 2025/01/28 18:59:04 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_list *pile_a, t_list *pile_b)
{
	t_element	*sommet_b;
	
	if (!pile_a || !pile_b)
		return ;
	if (pile_b->premier != NULL)
	{
		sommet_b = pile_b->premier;
		pile_b->premier = pile_b->premier->suivant;
		sommet_b->suivant = pile_a->premier;
		pile_a->premier = sommet_b;
	}
	pile_b->nb_element -= 1;
	pile_a->nb_element += 1;
	pile_a->nb_iter += 1;
	ft_printf("pa\n");
}

void pb(t_list *pile_a, t_list *pile_b)
{
	t_element	*sommet_a;
	
	if (!pile_a || !pile_b)
		return ;
	if (pile_a->premier != NULL)
	{
		sommet_a = pile_a->premier;
		pile_a->premier = pile_a->premier->suivant;
		sommet_a->suivant = pile_b->premier;
		pile_b->premier = sommet_a;
	}
	pile_a->nb_element -= 1;
	pile_b->nb_element += 1;
	pile_a->nb_iter += 1;
	ft_printf("pb\n");
}