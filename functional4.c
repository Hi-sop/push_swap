#include "push_swap.h"

int	pa(t_hnt *a, t_hnt *b)
{
	t_node *a_temp;
	t_node *b_temp;

	a_temp = a->head;
	b_temp = b->head;
	if (b_temp)
	{
		b->head = b_temp->next;
		if (b->head)
			b->head->prev = NULL;
		b_temp->next = a_temp;
		if (a_temp)
			a_temp->prev = b_temp;
		a->head = b_temp;
	}
	write(1, "pa\n", 3);
	return (1);
}

int	pb(t_hnt *a, t_hnt *b)
{
	t_node *a_temp;
	t_node *b_temp;

	a_temp = a->head;
	b_temp = b->head;
	if (a_temp)
	{
		a->head = a_temp->next;
		if (a->head)
			a->head->prev = NULL;
		a_temp->next = b_temp;
		if (b_temp)
			b_temp->prev = a_temp;
		else
			b->tail = a_temp;
		b->head = a_temp;
	}
	write(1, "pb\n", 3);
	return (1);
}

