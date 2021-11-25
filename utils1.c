#include "push_swap.h"

void	error(char *arr)
{
	int i;

	write(1, "Error\n", 6);
	i = 0;
	while (arr[i])
	{
		write(1, &arr[i], 1);
		i++;
	}
	exit(1);
}

int	count_value(t_hnt *hnt)
{
	t_node *temp;
	int	count;

	count = 0;
	temp = hnt->head;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

void	node_link(t_node *new, t_hnt *a, int flag)
{
	t_node	*temp;

	if (flag)
	{
		a->head = new;
		a->tail = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		temp = a->tail;
		a->tail = new;
		temp->next = new;
		new->prev = temp;
		new->next = NULL;
	}
}

void	add_node(int num, t_hnt *a)
{
	t_node *new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!(new))
		error("new node malloc error");
	new->value = num;
	if (a->head == NULL && a->tail == NULL)
		node_link(new, a, 1);
	else
		node_link(new, a, 0);
}

int	atoinsum(char *arr, int len, t_hnt *a)
{
	int i;
	int j;
	int max;
	long long int num;

	i = 0;
	num = 0;
	if (arr[0] == '-')
		i++;
	while (i < len)
	{
		j = 1;
		max = 1;
		while (j < len - i)
		{
			max = max * 10;
			j++;
		}
		num = num + max * (arr[i] - '0');
		i++;
	}
	if (arr[0] == '-')
		num = num * -1;
	add_node(num, a);
	return (num);
}
