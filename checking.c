/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:23:11 by khee-seo          #+#    #+#             */
/*   Updated: 2021/11/25 20:46:50 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check(int count, int *temp)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if (temp[i] == temp[j] && i != j)
				error("duplicate numeric");
			j++;
		}
		i++;
	}
}

void	duplicate_check(int count, t_hnt *a)
{
	t_node	*node;
	int		*temp;
	int		i;

	temp = (int *)malloc(sizeof(int) * count);
	if (temp == NULL)
		error("check malloc error");
	node = a->head;
	i = 0;
	while (node)
	{
		temp[i] = node->value;
		node = node->next;
		i++;
	}
	check(count, temp);
	free(temp);
}
