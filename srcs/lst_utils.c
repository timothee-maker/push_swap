/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:14:03 by tnolent           #+#    #+#             */
/*   Updated: 2025/02/03 13:05:25 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

t_list	*initialisation(void);
void	afficherListe(t_list *liste);
void	insertion_f(t_list *liste, int nvNombre);
void	destruction(t_list *liste);

t_list	*initialisation(void)
{
	t_list	*liste;

	liste = malloc(sizeof(*liste));
	if (liste == NULL)
		exit(0);
	liste->first = NULL;
	liste->nb_element = 0;
	return (liste);
}

void	ft_free_split(char **str)
{
	int		i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	insertion_f(t_list *liste, int nvNombre)
{
	t_element	*nouveau;
	t_element	*actuel;

	nouveau = malloc(sizeof(*nouveau));
	if (liste == NULL || nouveau == NULL)
		exit(0);
	nouveau->nombre = nvNombre;
	nouveau->cost = 0;
	nouveau->next = NULL;
	nouveau->target = NULL;
	if (liste->first == NULL)
		liste->first = nouveau;
	else
	{
		actuel = liste->first;
		while (actuel->next != NULL)
			actuel = actuel->next;
		actuel->next = nouveau;
	}
	liste->nb_element += 1;
}

void	destruction(t_list *liste)
{
	t_element	*asupprimer;

	if (liste == NULL)
		exit(EXIT_FAILURE);
	while (liste->first != NULL)
	{
		asupprimer = liste->first;
		liste->first = liste->first->next;
		liste->nb_element -= 1;
		free(asupprimer);
	}
}

void	afficherliste(t_list *liste)
{
	t_element	*actuel;

	if (liste == NULL)
		exit(0);
	actuel = liste->first;
	while (actuel != NULL)
	{
		ft_printf("%d -> ", actuel->nombre);
		actuel = actuel->next;
	}
	ft_printf("NULL\tnb element : %d\n", liste->nb_element);
}
