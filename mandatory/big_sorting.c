/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:36:13 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/31 18:03:42 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_data(t_stack *a, t_stack *cp_a)
{
	int		idx;
	t_stack	*current;

	idx = 0;
	while (cp_a)
	{
		current = a;
		while (current)
		{
			if (cp_a->data == current->data)
			{
				current->index = idx++;
				break ;
			}
			current = current->next;
		}
		cp_a = cp_a->next;
	}
}

void	ft_range(t_stack **a, t_stack **b)
{
	int	range_min;
	int	range_max;

	range_min = 0;
	if (lst_size(*a) > 15)
		range_max = 0.045 * lst_size(*a) + 10;
	else
		range_max = 0.045 * lst_size(*a);
	while (*a)
	{
		if ((*a)->index >= range_min && (*a)->index <= range_max)
		{
			push_data(a, b, 'b');
			range_min++;
			range_max++;
		}
		else if ((*a)->index > range_max)
			rotation_data(a, 'a');
		else if ((*a)->index < range_min)
		{
			push_data(a, b, 'b');
			rotation_data(b, 'b');
			range_min++;
			range_max++;
		}
	}
}

int	max_value(t_stack *current)
{
	int	i;
	int	idx_max;

	i = 0;
	idx_max = lst_size(current) - 1;
	while (current)
	{
		if (idx_max == current->index)
			return (i);
		i++;
		current = current->next;
	}
	return (idx_max);
}

void	big_sorted(t_stack **a, t_stack **cp_a, t_stack **b)
{
	int	size;
	int	idx_max;

	buble_sort(*cp_a);
	index_data(*a, *cp_a);
	free_list(cp_a);
	ft_range(a, b);
	while (*b)
	{
		size = lst_size(*b);
		idx_max = max_value(*b);
		if (idx_max == 0)
			push_data(b, a, 'a');
		else if (idx_max > (size / 2) && idx_max != 0)
			rrotation_data(b, 'b');
		else if (idx_max <= (size / 2) && idx_max != 0)
			rotation_data(b, 'b');
	}
	free_list(a);
}
