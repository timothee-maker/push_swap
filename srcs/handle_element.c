/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnolent <tnolent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:17:35 by tnolent           #+#    #+#             */
/*   Updated: 2025/02/03 14:20:04 by tnolent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_2_element(t_list *p)
{
	if (p->first->nombre > p->first->next->nombre)
		sa(p);
}

void	handle_3_element(t_list *p)
{
	if (p->first->nombre < p->first->next->nombre
		&& p->first->next->nombre > p->first->next->next->nombre)
	{
		if (p->first->nombre >= p->first->next->next->nombre)
			rra(p);
		else if (p->first->nombre < p->first->next->next->nombre)
		{
			sa(p);
			ra(p);
		}
	}
	else if (p->first->nombre > p->first->next->nombre)
	{
		if (p->first->next->nombre > p->first->next->next->nombre)
		{
			ra(p);
			sa(p);
		}
		else if (p->first->next->nombre < p->first->next->next->nombre
			&& p->first->nombre < p->first->next->next->nombre)
			sa(p);
		else
			ra(p);
	}
}
