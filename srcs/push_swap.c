/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:02:08 by timothee          #+#    #+#             */
/*   Updated: 2025/01/28 19:07:38 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	handle_3_element(t_list *pile_a);
int		handle_2_element(t_list *pile_a);
int 	liste_triee(t_list *pile_a, t_list *pile_b);
int		algo_ps(t_list *pile_a, t_list *pile_b);

int push_swap(t_list *pile_a, t_list *pile_b)
{
	int	j = pile_a->nb_element;
	int	compteur;
	
	compteur = 0;
	if (pile_a->nb_element > 3)
	{
			pb(pile_a, pile_b);
			pb(pile_a, pile_b);
	}
	while (!liste_triee(pile_a, pile_b))
	{
		if (pile_a->nb_element == 2)
			handle_2_element(pile_a);
		if (pile_a->nb_element == 3)
		{
			handle_3_element(pile_a);
			compteur = 1;
		}
		if (pile_a->nb_element == 3 && compteur == 1)
			end_algo(pile_a, pile_b);
		if (compteur == 0)
			algo_ps(pile_a, pile_b);
	}
	handle_a(pile_a);
	return (0);
}

void	handle_a(t_list *pile_a)
{
	int	mediane;

	mediane = pile_a->nb_element / 2;
	
	
	while (pile_a->smallest->position != 0)
	{
		calculate_position(pile_a, pile_a);
		if (pile_a->smallest->position <= mediane)
			ra(pile_a);
		else
			rra(pile_a);
	}
	
}

int	liste_triee(t_list *pile_a, t_list *pile_b)
{
	t_element *actuel;

	if (pile_b->nb_element != 0)
		return (0);
	actuel = pile_a->premier;
	while (actuel->suivant != NULL)
	{
		if (actuel->nombre > actuel->suivant->nombre)
			return (0);
		actuel = actuel->suivant;
	}
	return (1);
}

int	handle_2_element(t_list *pile_a)
{
	if (pile_a->premier->nombre > pile_a->premier->suivant->nombre)
		sa(pile_a);
	return (0);
}

int	handle_3_element(t_list *pile_a)
{
	t_element *actuel;

	actuel = pile_a->premier;
	if (actuel->nombre < actuel->suivant->nombre && actuel->suivant->nombre > actuel->suivant->suivant->nombre)
	{
		if (actuel->nombre >= actuel->suivant->suivant->nombre)
			rra(pile_a);
		else if (actuel->nombre < actuel->suivant->suivant->nombre)
		{
			sa(pile_a);
			ra(pile_a);
		}
	}
	else if (pile_a->premier->nombre > pile_a->premier->suivant->nombre)
	{
		if (pile_a->premier->suivant->nombre > pile_a->premier->suivant->suivant->nombre)
		{
			ra(pile_a);
			sa(pile_a);
		}
		else if (pile_a->premier->suivant->nombre < pile_a->premier->suivant->suivant->nombre)
			ra(pile_a);
	}
	return (0);
}
