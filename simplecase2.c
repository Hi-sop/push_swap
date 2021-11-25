#include "push_swap.h"

void	passto_a(t_hnt *a, t_hnt *b)
{
	t_node *temp;

	pa(a, b);
	temp = a->head;
	if (temp->value > temp->next->value)
		ra(a);
	pa(a, b);
	temp = a->head;
	if (temp->value > temp->next->value)
		ra(a);
}

void	passto_b(t_hnt *a, t_hnt *b, int index)
{
	if (index == 1)
		pb(a, b);
	else if (index == 2)
	{
		ra(a);
		pb(a, b);
	}
	else if (index == 3)
	{
		ra(a);
		ra(a);
		pb(a, b);
	}
	else if (index == count_value(a) - 1)
	{
		rra(a);
		rra(a);
		pb(a, b);
	}
	else if (index == count_value(a))
	{
		rra(a);
		pb(a, b);
	}
}

void	findsmallbig(t_hnt *a, t_hnt *b, int small, int big)
{
	t_node	*temp;
	int index;

	temp = a->head;
	index = 1;
	while (temp)
	{
		if (temp->value == small || temp->value == big)
		{
			passto_b(a, b, index);
			temp = a->head;
			index = 0;
		}
		else
			temp = temp->next;
		index++;
	}
	three_a(a, a->head->value, a->head->next->value,
			a->head->next->next->value);
}

void	five(t_hnt *a, t_hnt *b, int small, int big)
{
	t_node	*temp;
	int	index;
	
	index = 1;
	temp = a->head;
	while (temp)
	{
		if (small == 0 && big == 0)
		{
			small = temp->value;
			big = temp->value;
		}
		else if (small > temp->value)
			small = temp->value;
		else if (big < temp->value)
			big = temp->value;
		temp = temp->next;
		index++;
	}
	findsmallbig(a, b, small, big);
	passto_a(a, b);
}
