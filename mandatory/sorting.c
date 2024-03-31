/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 02:26:30 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/30 21:17:12 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(t_stack *h)
{
	int	min;

	if (!h)
		return (0);
	min = h->data;
	while (h)
	{
		if (min > h->data)
			min = h->data;
		h = h->next;
	}
	return (min);
}

void	sort_two_element(t_stack **a)
{
	if (!(*a) || !(*a)->next)
		return ;
	if ((*a)->data > (*a)->next->data)
		swap_data(*a, 'a');
	return ;
}

void	sort_three_element(t_stack **a)
{
	t_stack	*last;

	last = last_node(*a);
	if ((*a)->data > (*a)->next->data && (*a)->data < last->data)
		swap_data(*a, 'a');
	else if ((*a)->data > (*a)->next->data && (*a)->next->data < last->data)
		rotation_data(a, 'a');
	else if ((*a)->data < (*a)->next->data 
		&& (*a)->next->data > last->data && (*a)->data > last->data)
		rrotation_data(a, 'a');
	else if ((*a)->data < (*a)->next->data && (*a)->next->data > last->data)
	{
		swap_data(*a, 'a');
		rotation_data(a, 'a');
	}
	else if ((*a)->data > (*a)->next->data && (*a)->next->data > last->data)
	{
		swap_data(*a, 'a');
		rrotation_data(a, 'a');
	}
}

void	sort_four_element(t_stack **a, t_stack **b)
{
	int	size;
	int	idx_min;

	size = lst_size(*a);
	idx_min = min_value(*a);
	if (idx_min > (size / 2) && idx_min != 0)
	{
		rrotation_data(a, 'a');
		idx_min = min_value(*a);
		if (idx_min != 0)
			rrotation_data(a, 'a');
	}
	else if (idx_min != 0)
	{
		rotation_data(a, 'a');
		idx_min = min_value(*a);
		if (idx_min != 0)
			rotation_data(a, 'a');
	}
	push_data(a, b, 'b');
	sort_three_element(a);
	push_data(b, a, 'a');
	sort_three_element(a);
}

void	sort_five_element(t_stack **a, t_stack **b)
{
	int	size;
	int	idx_min;

	size = lst_size(*a);
	idx_min = min_value(*a);
	if (idx_min > (size / 2) && idx_min != 0)
	{
		rrotation_data(a, 'a');
		idx_min = min_value(*a);
		if (idx_min != 0)
			rrotation_data(a, 'a');
	}
	else if (idx_min != 0)
	{
		rotation_data(a, 'a');
		idx_min = min_value(*a);
		if (idx_min != 0)
			rotation_data(a, 'a');
	}
	push_data(a, b, 'b');
	sort_four_element(a, b);
	push_data(a, b, 'a');
}
