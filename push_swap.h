/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:09:33 by khee-seo          #+#    #+#             */
/*   Updated: 2021/11/25 20:53:39 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				value;
}t_node;

typedef struct s_hnt
{
	t_node	*head;
	t_node	*tail;
}t_hnt;

typedef struct s_data
{
	int	s_pivot;
	int	b_pivot;
	int	rac;
	int	rbc;
	int	pac;
	int	pbc;
}t_data;

void	tempsort(int range, int *arr);
void	find_pivot(int range, t_hnt *hnt, int *s_pivot, int *b_pivot);

void	swap_node(t_hnt *hnt);
int		sa(t_hnt *a);
int		sb(t_hnt *b);
int		ss(t_hnt *a, t_hnt *b);

void	push_node(t_hnt *hnt);
int		ra(t_hnt *a);
int		rb(t_hnt *b);
int		rr(t_hnt *a, t_hnt *b);

void	rpush_node(t_hnt *hnt);
int		rra(t_hnt *a);
int		rrb(t_hnt *b);
int		rrr(t_hnt *a, t_hnt *b);

int		pa(t_hnt *a, t_hnt *b);
int		pb(t_hnt *a, t_hnt *b);

void	simple_a(t_hnt *a, t_hnt *b, int count);
void	simple_b(t_hnt *a, t_hnt *b, int count);
void	three_a(t_hnt *a, int first, int second, int third);
void	three_a1(t_hnt *a, t_hnt *b, int first, int second);
void	three_b(t_hnt *a, t_hnt *b, int first, int second);

void	passto_a(t_hnt *a, t_hnt *b);
void	passto_b(t_hnt *a, t_hnt *b, int index);
void	findsmallbig(t_hnt *a, t_hnt *b, int small, int big);
void	five(t_hnt *a, t_hnt *b, int small, int big);

void	solve_a(int range, t_hnt *a, t_hnt *b, t_data *data);
void	solve_b(int ragne, t_hnt *a, t_hnt *b, t_data *data);
void	a_to_b(int range, t_hnt *a, t_hnt *b);
void	b_to_a(int range, t_hnt *a, t_hnt *b, int i);

void	error(char *arr);
int		count_value(t_hnt *hnt);
void	node_link(t_node *new, t_hnt *a, int flag);
void	add_node(long long int num, t_hnt *a);
int		atoinsum(char *arr, int len, t_hnt *a);

void	init_data(t_data *data);
t_node	*headnode(t_hnt *hnt);
int		sorted(int range, t_hnt *hnt);
int		rsorted(int range, t_hnt *hnt);
void	rewinding(t_hnt *a, t_hnt *b, t_data *data);

void	check(int count, int *temp);
void	duplicate_check(int count, t_hnt *a);

#endif
