/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:15:58 by khee-seo          #+#    #+#             */
/*   Updated: 2021/11/25 20:02:17 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_data *data)
{
	if (data == NULL)
		error("data init error");
	data->s_pivot = 0;
	data->b_pivot = 0;
	data->rac = 0;
	data->rbc = 0;
	data->pac = 0;
	data->pbc = 0;
	data->opt = 0;
}

t_node	*headnode(t_hnt *hnt)
{
	if (hnt == NULL)
		return (NULL);
	return (hnt->head);
}

int	sorted(int range, t_hnt *hnt)
{
	t_node	*node;
	int		i;
	int		num;

	if (range < 1)
		return (1);
	i = 1;
	node = hnt->head;
	num = node->value;
	while (i < range)
	{
		node = node->next;
		if (node)
		{
			if (num > node->value)
				return (0);
			num = node->value;
		}
		i++;
	}
	return (1);
}

int	rsorted(int range, t_hnt *hnt)
{
	t_node	*node;
	int		i;
	int		num;

	if (range < 1)
		return (1);
	i = 0;
	node = hnt->head;
	num = node->value;
	while (i < range - 1 && node)
	{
		node = node->next;
		if (node)
		{
			if (num < node->value)
				return (0);
			num = node->value;
		}
		i++;
	}
	return (1);
}

void	rewinding(t_hnt *a, t_hnt *b, t_data *data)
{
	int	i;
	int	small;

	if (data->rac > data->rbc)
		small = data->rbc;
	else
		small = data->rac;
	i = 0;
	while (i < small)
	{
		rrr(a, b);
		i++;
	}
	i = 0;
	while (i < data->rac - small)
	{
		rra(a);
		i++;
	}
	i = 0;
	while (i < data->rbc - small)
	{
		rrb(b);
		i++;
	}
}
