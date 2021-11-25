/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:52:49 by khee-seo          #+#    #+#             */
/*   Updated: 2021/11/25 18:53:04 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_node(t_hnt *hnt)
{
	t_node	*first;
	t_node	*second;

	if (count_value(hnt) <= 1)
		return ;
	first = hnt->head;
	second = hnt->tail;
	hnt->head = first->next;
	hnt->head->prev = NULL;
	first->next = NULL;
	first->prev = second;
	second->next = first;
	hnt->tail = first;
}

int	ra(t_hnt *a)
{
	push_node(a);
	write(1, "ra\n", 3);
	return (1);
}

int	rb(t_hnt *b)
{
	push_node(b);
	write(1, "rb\n", 3);
	return (1);
}

int	rr(t_hnt *a, t_hnt *b)
{
	push_node(a);
	push_node(b);
	write(1, "rr\n", 3);
	return (1);
}
