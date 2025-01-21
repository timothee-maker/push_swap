/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:14:03 by tnolent           #+#    #+#             */
/*   Updated: 2025/01/20 11:23:03 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

t_list	*initialisation();
void	afficherListe(t_list *liste);
void	insertion_d(t_list *liste, int nvNombre);
void	insertion_f(t_list *liste, int nvNombre);
void	suppression(t_list *liste);
void	destruction(t_list *liste);

t_list	*initialisation()
{
	t_list *liste;
	
	liste = malloc(sizeof(*liste));
	if (liste == NULL)
		exit(0);
	liste->premier = NULL;
	liste->nb_element = 0;
	return (liste);
}

void	insertion_d(t_list *liste, int nvNombre)
{
	t_element *nouveau;
	
	nouveau = malloc(sizeof(*nouveau));
	if (liste == NULL || nouveau == NULL)
		exit(0);
	nouveau->nombre = nvNombre;
	nouveau->target = NULL;
	nouveau->suivant = liste->premier;
	liste->premier = nouveau;
	liste->nb_element += 1;
}

void 	insertion_f(t_list *liste, int nvNombre)
{
	t_element *nouveau;
	t_element *actuel;

	nouveau = malloc(sizeof(*nouveau));
	if (liste == NULL || nouveau == NULL)
		exit(0);
	nouveau->nombre = nvNombre;
	nouveau->cost = 0;
	nouveau->suivant = NULL;
	nouveau->target = NULL;
	if (liste->premier == NULL)
		liste->premier = nouveau;
	else
	{
		actuel = liste->premier;
		while (actuel->suivant != NULL)
			actuel = actuel->suivant;
		actuel->suivant = nouveau;
	}
	liste->nb_element += 1;
}

void	afficherListe(t_list *liste)
{
	t_element *actuel;
	if (liste == NULL)
		exit(EXIT_FAILURE);
	
	actuel = liste->premier;
	while (actuel != NULL)
	{
		printf("%d -> ", actuel->nombre);
		actuel = actuel->suivant;
	}
	printf("NULL\tnb element : %d\n", liste->nb_element);
}

void	suppression(t_list *liste)
{
	t_element	*aSupprimer;

	if (liste == NULL)
		exit(EXIT_FAILURE);
	if (liste->premier != NULL)
	{
		aSupprimer = liste->premier;
		liste->premier = liste->premier->suivant;
		free(aSupprimer);
		liste->nb_element -= 1;
	}
}

void	suppression_f(t_list *liste)
{
	t_element *aSupprimer;

	if (liste == NULL)
		exit(EXIT_FAILURE);
	if (liste->premier != NULL)
	{
		aSupprimer = liste->premier;
		liste->premier = liste->premier->suivant;
		free(aSupprimer);
		liste->nb_element -= 1;
	}
}

void	destruction(t_list *liste)
{
	t_element *aSupprimer;

	if (liste == NULL)
		exit(EXIT_FAILURE);
	while (liste->premier != NULL)
	{
		aSupprimer = liste->premier;
		liste->premier = liste->premier->suivant;
		liste->nb_element -= 1;
		free(aSupprimer);
	}
}