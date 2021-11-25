/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:53:20 by khee-seo          #+#    #+#             */
/*   Updated: 2021/11/25 18:53:36 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rpush_node(t_hnt *hnt)
{
	t_node	*first;
	t_node	*second;

	if (count_value(hnt) <= 1)
		return ;
	first = hnt->head;
	second = hnt->tail;
	hnt->tail = second->prev;
	hnt->tail->next = NULL;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	hnt->head = second;
}

int	rra(t_hnt *a)
{
	rpush_node(a);
	write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_hnt *b)
{
	rpush_node(b);
	write(1, "rrb\n", 4);
	return (1);
}

int	rrr(t_hnt *a, t_hnt *b)
{
	rpush_node(a);
	rpush_node(b);
	write(1, "rrr\n", 4);
	return (1);
}
