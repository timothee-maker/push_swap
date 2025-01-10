/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timothee <timothee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:34:24 by timothee          #+#    #+#             */
/*   Updated: 2025/01/04 12:41:20 by timothee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
#  define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_element
{
	int nombre;
	struct s_element *suivant;
} t_element;

typedef struct s_list
{
	int nb_element;
	t_element *premier;
} t_list;

char **ft_split(char *str, char sep);
void sa(int *pile_a);
void sb(int *pile_b);
void ss(int	*pile_a, int *pile_b);
void pb(int *pile_a, int *pile_b);
void pa(int *pile_a, int *pile_b);
t_list *initialisation();
void afficherListe(t_list *liste);
void insertion(t_list *liste, int nvNombre);
void suppression(t_list *liste);
void destruction(t_list *liste);

#endif
