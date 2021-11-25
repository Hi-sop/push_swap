#include "push_swap.h"

void	solve_a(int range, t_hnt *a, t_hnt *b, t_data *data)
{
	int	i;
	t_node *node;

	i = 0;
	while (i < range)
	{
		if (headnode(a)->value >= data->b_pivot)
		{
			ra(a);
			data->rac++;
		}
		else
		{
			pb(a, b);
			data->pbc++;
			if (headnode(b)->value >= data->s_pivot)
			{
				rb(b);
				data->rbc++;
			}
		}
		i++;
	}
}

void	solve_b(int range, t_hnt *a, t_hnt *b, t_data *data)
{
	int i;
	t_node *node;

	i = 0;
	while (i < range)
	{
		if (headnode(b)->value < data->s_pivot)
		{
			rb(b);
			data->rbc++;
		}
		else
		{
			pa(a, b);
			data->pac++;
			if (headnode(a)->value < data->b_pivot)
			{
				ra(a);
				data->rac++;
			}
		}
		i++;
	}
}

void	a_to_b(int range, t_hnt *a, t_hnt *b)
{
	t_data	data;

	if (sorted(range, a))
		return ;
	if (range <= 3)
	{
		simple_a(a, b, range);
		return ;
	}
	init_data(&data);
	find_pivot(range, a, &data.s_pivot, &data.b_pivot);
	solve_a(range, a, b, &data);
	rewinding(a, b, &data);
	a_to_b(data.rac + data.opt, a, b);
	b_to_a(data.rbc, a, b, 0);
	b_to_a(data.pbc - data.rbc, a, b, 0);
}

void	b_to_a(int range, t_hnt *a, t_hnt *b, int i)
{
	t_data	data;

	if (rsorted(range, b))
	{
		while (i < range)
		{
			pa(a, b);
			i++;
		}
		return ;
	}
	if (range <= 3)
	{
		simple_b(a, b, range);
		return ;
	}
	init_data(&data);
	find_pivot(range, b, &data.s_pivot, &data.b_pivot);
	solve_b(range, a, b, &data);
	a_to_b(data.pac - data.rac, a, b);
	rewinding(a, b, &data);
	a_to_b(data.rac, a, b);
	b_to_a(data.rbc + data.opt, a, b, 0);
}
