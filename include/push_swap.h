/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:34:24 by timothee          #+#    #+#             */
/*   Updated: 2025/01/21 12:51:39 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
#  define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ft_printf/include/ft_printf.h"

typedef struct s_element
{
	int					nombre;
	int					cost;
	int					position;
	struct s_element	*target;
	struct s_element	*suivant;
} t_element;

typedef struct s_list
{
	int			nb_element;
	int			nb_iter;
	t_element	*biggest;
	t_element	*smallest;
	t_element	*premier;
} t_list;

t_list	*initialisation();
char	**ft_split(char const *s, char c);
int     push_swap(t_list *pile_a, t_list *pile_b);
int 	handle_3_element(t_list *pile_a);
int 	liste_triee(t_list *pile_a, t_list *pile_b);
int		algo_ps(t_list *pile_a, t_list *pile_b);
void	calcul_target(t_list *pile_a, t_list *pile_b);
int		calculate_cost(t_list *pile_a, t_list *pile_b);
void	calculate_position(t_list *pile_a, t_list *pile_b);

int		calculate_b_s(t_list *pile_a, t_list *pile_b);
int		init_cost(t_list *pile_a);
void	afficherListe(t_list *liste);
void	insertion_d(t_list *liste, int nvNombre);
void	insertion_f(t_list *liste, int nvNombre);
void	suppression(t_list *liste);
void	destruction(t_list *liste);	
void	sb(t_list *pile_b);
void	sa(t_list *pile_a);
void	ss(t_list	*pile_a, t_list *pile_b);
void	pa(t_list *pile_a, t_list *pile_b);
void	pb(t_list *pile_a, t_list *pile_b);
void	ra(t_list *pile_a);
void	rb(t_list *pile_b);
void	rr(t_list *pile_a, t_list *pile_b);
void	rrb(t_list *pile_b);
void	rra(t_list *pile_a);
void	rrr(t_list *pile_a, t_list *pile_b);

#endif
