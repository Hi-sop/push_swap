#include "push_swap.h"

int	argv_valid(char c, int flag)
{
	if (flag == 1)
	{
		if (('0' <= c && c <= '9') || c == ' ' || c == '-')
			return (0);
		return (1);
	}
	else if (flag == 2)
	{
		if ('0' <= c && c <= '9')
			return (1);
		return (0);
	}
	else if (flag == 3)
	{
		if (c == ' ')
			return (1);
		return (0);
	}
	return (1);
}

void	argv_atoi(char *argv, t_hnt *a) 
{
	int	i;
	int st;

	i = 0;
	st = i;
	while (argv[i])
	{
		if (argv_valid(argv[i], 1))
			error("other text");
		if (argv_valid(argv[i], 3))
		{
			atoinsum(&argv[st], i - st, a);
			st = i + 1;
		}
		i++;
	}
	if (argv[i] == '\0' && argv[i - 1] != ' ')
		atoinsum(&argv[st], i - st, a);
}

void	init_hnt(t_hnt *a, t_hnt *b)
{
	if (a == NULL)
		error("a error");
	if (b == NULL)
		error("b error");
	a->head = NULL;
	b->head = NULL;
	a->tail = NULL;
	b->tail = NULL;
}

void	test(t_hnt *a, t_hnt *b)
{
	t_node *temp;
	
	temp = a->head;
	printf("-a-\n");
	while (temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
	temp = b->head;
	printf("-b-\n");
	while (temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
}

int main(int argc, char **argv)
{
	int i;
	int	count;
	t_hnt a;
	t_hnt b;

	init_hnt(&a, &b);
	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		argv_atoi(argv[i], &a);
		i++;
	}
	count = count_value(&a);
	if (count <= 3) 
		simple_a(&a, &b, count);
	else if (count == 5)
		five(&a, &b, 0, 0);
	else
		a_to_b(count, &a, &b);
//	test(&a, &b);
//	free도 만들것
	return (0);
}
