/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:34:24 by timothee          #+#    #+#             */
/*   Updated: 2025/02/03 13:06:31 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../ft_printf/include/ft_printf.h"
# include "../libft/libft.h"

typedef struct s_element
{
	int					nombre;
	int					cost;
	int					position;
	struct s_element	*target;
	struct s_element	*next;
}	t_element;

typedef struct s_list
{
	int			nb_element;
	int			compteur;
	int			mediane;
	t_element	*push_element;
	t_element	*biggest;
	t_element	*smallest;
	t_element	*first;
}	t_list;

void	handle_error(int ac, char **av);
t_list	*initialisation(void);
char	**ft_split(char const *s, char c);
void	push_swap(t_list *pile_a, t_list *pile_b);
void	handle_3_element(t_list *pile_a);
void	handle_2_element(t_list *pile_a);
void	handle_a(t_list *pile_a);
int		liste_triee(t_list *pile_a, t_list *pile_b);
int		algo_ps(t_list *pile_a, t_list *pile_b);
void	push_element_back(t_list *pile_a, t_list *pile_b);
void	end_algo(t_list *pile_a, t_list *pile_b);
void	calcul_target(t_list *pile_a, t_list *pile_b);
void	calcul_target_pile_a(t_list *pile_a, t_list *pile_b);
void	calculate_cost(t_list *pile_a, t_list *pile_b);
void	calculate_position(t_list *pile_a, t_list *pile_b);

int		calculate_b_s(t_list *pile_a, t_list *pile_b);
int		calcul_a(t_list *pile_a);
void	afficherliste(t_list *liste);
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
