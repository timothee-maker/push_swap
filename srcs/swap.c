/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timothee <timothee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:26:01 by timothee          #+#    #+#             */
/*   Updated: 2024/12/30 14:29:13 by timothee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sb(int *pile_b);
void sa(int *pile_a);

void ss(int	*pile_a, int *pile_b)
{
	sa(pile_a);
	sb(pile_b);
	printf("ss\n");
}

void sb(int *pile_b)
{
	int *temp;

	*temp = pile_b[0];
	pile_b[0] = pile_b[1];
	pile_b[1] = *temp;
	printf("sb\n");/*hooooooo*/
}

void sa(int *pile_a)
{
	int	*temp;

	*temp = pile_a[0];
	pile_a[0] = pile_a[1];
	pile_a[1] = *temp;
	printf("sa\n");/*hooooooo*/
}