/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 03:28:25 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/30 20:49:21 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	handle_error(t_stack **a, t_stack **b)
{
	ft_putstr("Error\n");
	free_list(a);
	free_list(b);
	exit(EXIT_FAILURE);
}

void	handle_commend(t_stack **a, char **argv, int argc)
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
			handle_error(a, NULL);
		while (str[va.j])
		{
			va.data = ft_atoi(str[va.j], &va.flag);
			if (linear_search(*a, va.data) == true)
				handle_error(a, NULL);
			add_back(a, va.data);
			va.j++;
		}
		free_arrays(str);
		va.i++;
	}
	if (va.flag == 1)
		handle_error(a, NULL);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (0);
	handle_commend(&a, argv, argc);
	manage_operation(&a, &b);
	if (is_sorted(a) == true && lst_size(b) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
