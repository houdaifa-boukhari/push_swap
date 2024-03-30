/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 03:28:25 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/30 03:46:44 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	linear_search(t_stack *current, int data)
{
	while (current)
	{
		if (data == current->data)
			return (true);
		current = current->next;
	}
	return (false);
}

void	handle_error(t_stack **a, t_stack **cp_a)
{
	ft_putstr("Error\n");
	free_list(a);
	free_list(cp_a);
	exit(EXIT_FAILURE);
}

void	handle_commend(t_stack **a, t_stack **cp_a, char **argv, int argc)
{
	t_va	va;
	char	**str;

	va.j = 0;
	va.i = 1;
	while (va.i < argc)
	{
		va.j = 0;
		str = ft_split(argv[va.i], ' ');
		if (*str == NULL)
			handle_error(a, cp_a);
		while (str[va.j])
		{
			va.data = ft_atoi(str[va.j], &va.flag);
			if (linear_search(*a, va.data) == true)
				handle_error(a, cp_a);
			add_back(a, va.data);
			add_back(cp_a, va.data);
			va.j++;
		}
		free_arrays(str);
		va.i++;
	}
	if (va.flag == 1)
		handle_error(a, cp_a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*cp_a;
	int		size;

	a = NULL;
	b = NULL;
	cp_a = NULL;
	if (argc <= 1)
		return (0);
	handle_commend(&a, &cp_a, argv, argc);
	size = lst_size(a);
	if (is_sorted(a) == true)
		return (0);
	if (size == 2)
		sort_two_element(&a);
	else if (size == 3)
		sort_three_element(&a);
	else if (size == 4)
		sort_four_element(&a, &b);
	else if (size == 5)
		sort_five_element(&a, &b);
	else if (size > 5)
		big_sorted(&a, &cp_a, &b);
}
