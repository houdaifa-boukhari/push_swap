/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aplly_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:52:16 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/30 21:27:57 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	aplly_operations(t_stack **a, t_stack **b, char *op)
{
	if (ft_strcmp(op, "sa\n") == 0)
		swap_data(*a);
	else if (ft_strcmp(op, "sb\n") == 0)
		swap_data(*b);
	else if (ft_strcmp(op, "pb\n") == 0)
		push_data(a, b);
	else if (ft_strcmp(op, "pa\n") == 0)
		push_data(b, a);
	else if (ft_strcmp(op, "ra\n") == 0)
		rotation_data(a);
	else if (ft_strcmp(op, "rra\n") == 0)
		rrotation_data(a);
	else if (ft_strcmp(op, "rrb\n") == 0)
		rrotation_data(b);
	else if (ft_strcmp(op, "ss\n") == 0)
		sswap_data(*a, *b);
	else if (ft_strcmp(op, "rr\n") == 0)
		r_rotaion_data(a, b);
	else if (ft_strcmp(op, "rb\n") == 0)
		rotation_data(b);
	else if (ft_strcmp(op, "rrr\n") == 0)
		r_rrotation_data(a, b);
	else
		handle_error(a, b);
}

void	r_rrotation_data(t_stack **a, t_stack **b)
{
	rrotation_data(a);
	rrotation_data(b);
}
void	manage_operation(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break ;
		aplly_operations(a, b, line);
		free(line);
	}
}
