/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:51:09 by khee-seo          #+#    #+#             */
/*   Updated: 2021/11/25 19:33:14 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tempsort(int range, int *arr)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < range)
	{
		j = 0;
		while (j < range - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	find_pivot(int range, t_hnt *hnt, int *s_pivot, int *b_pivot)
{
	t_node	*node;
	int		*temp;
	int		i;

	temp = (int *)malloc(sizeof(int) * range);
	if (temp == NULL)
		error("pivot temp malloc error");
	i = 0;
	node = hnt->head;
	while (i < range)
	{
		temp[i] = node->value;
		node = node->next;
		i++;
	}
	tempsort(range, temp);
	*s_pivot = temp[range / 3];
	*b_pivot = temp[(range * 2) / 3];
	free(temp);
}
