
#include "push_swap.h"

void	swap_node(t_hnt *hnt)
{
	t_node	*first;
	t_node	*second;

	if (count_value(hnt) <= 1)
		return ;
	first = hnt->head;
	second = hnt->head->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	hnt->head = second;
}

int	sa(t_hnt *a)
{
	swap_node(a);
	write(1, "sa\n", 3);
	return (1);
}

int	sb(t_hnt *b)
{
	swap_node(b);
	write(1, "sb\n", 3);
	return (1);
}

int	ss(t_hnt *a, t_hnt *b)
{
	swap_node(a);
	swap_node(b);
	write(1, "ss\n", 3);
	return (1);
}
