/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timothee <timothee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:25:52 by timothee          #+#    #+#             */
/*   Updated: 2024/12/30 17:55:39 by timothee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pb(int *pile_a, int *pile_b)
{
	int i;
	int temp;

	i = 0;	
	if (!pile_a)
		return;
	while (pile_a[i])
		i++;
	i--;
	temp = pile_a[i];
	pile_a[i] = pile_b[0];
	pile_b[0] = temp;
	printf("%d, %d", pile_b[0], temp);
}

void pa(int *pile_a, int *pile_b)
{
	int i;
	int *temp;

	i = 0;
	if (!pile_b)
		return;
	while (pile_b[i])
		i++;
	*temp = pile_b[i];
	pile_b[i] = pile_a[0];
	pile_a[0] = *temp;
}