
#include "push_swap.h"

void	three_a(t_hnt *a, int first, int second, int third)
{
	if (first < second && second < third)
		return;
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first > second && second < third && first < third)
		sa(a);
	else if (first < second && second > third && first > third)
		rra(a);
	else if (first > third && second < third && first > third)
		ra(a);
	else if (first > second && second > third && first > third)
	{
		sa(a);
		rra(a);
	}
}

void	three_a1(t_hnt *a, t_hnt *b, int first, int second)
{
	int	third;
	
	third = a->head->next->next->value;
	if (first < second && second > third && first < third)
		pb(a, b) && sa(a) && pa(a, b);
	else if (first > second && second < third && first > third)
		sa(a) && pb(a, b) && sa(a) && pa(a, b);
	else if (first < second && second > third && first > third)
		pb(a, b) && sa(a) && pa(a, b) && sa(a);
	else if (first > second && second > third && first > third)
		sa(a) && pb(a, b) && sa(a) && pa(a, b) && sa(a);
	else if (first > second && second < third && first < third)
		sa(a);
	else if (first < second && second > third && first < third)
		pb(a, b) && sa(a) && pa(a, b);
}

void	three_b(t_hnt *a, t_hnt *b, int first, int second)
{
	int	third;
	
	third = b->head->next->next->value;
	if (first > second && second > third && first > third)
		pa(a, b) && pa(a, b) && pa(a, b);
	else if (first > second && second < third && first > third)
		pa(a, b) && sb(b) && pa(a, b) && pa(a, b);
	else if (first < second && second > third && first > third)
		sb(b) && pa(a, b) && pa(a, b) && pa(a, b);
	else if (first > second && second < third && first < third)
		pa(a, b) && sb(b) && pa(a, b) && sa(a) && pa(a, b);
	else if (first < third && second > third && first < third)
		sb(b) && pa(a, b) && sb(b) && pa(a, b) && pa(a, b);
	else if (first < second && second < third && first < third)
		sb(b) && pa(a, b) && sb(b) && pa(a, b) && sa(a) && pa(a, b);
}

void	simple_a(t_hnt *a, t_hnt *b, int count)
{
	if (count == 1)
		return ;
	else if (count == 2)
	{
		if (a->head->value > a->head->next->value)
			sa(a);
	}
	else if (count == 3)
	{
		if (count_value(a) == 3)
			three_a(a, a->head->value, a->head->next->value, 
					a->head->next->next->value);
		else
			three_a1(a, b, a->head->value, a->head->next->value);
	}
}

void	simple_b(t_hnt *a, t_hnt *b, int count)
{
	if (count == 1)
	{
		pa(a, b);
		return ;
	}
	if (count == 2)
	{
		if (b->head->value < b->head->next->value)
			sb(b) && pa(a, b) && pa(a, b);
	}
	if (count == 3)
		three_b(a, b, b->head->value, b->head->next->value);
}

