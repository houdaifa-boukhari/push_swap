/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 02:36:51 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/30 21:13:56 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_data(t_stack *head, char c)
{
	int	tmp;
	int	tmp_idx;

	if (!head || !head->next)
		return ;
	tmp = head->data;
	tmp_idx = head->index;
	head->data = head->next->data;
	head->index = head->next->index;
	head->next->data = tmp;
	head->next->index = tmp_idx;
	if (c == 'a')
		ft_putstr("sa\n");
	else if (c == 'b')
		ft_putstr("sb\n");
}

void	rotation_data(t_stack **head, char c)
{
	t_stack	*last_stack;
	t_stack	*ptr;

	last_stack = last_node(*head);
	if (!head || !last_stack || !*head || !(*head)->next)
		return ;
	ptr = (*head)->next;
	ptr->prev = NULL;
	last_stack->next = *head;
	(*head)->prev = last_stack;
	(*head)->next = NULL;
	*head = ptr;
	if (c == 'a')
		ft_putstr("ra\n");
	else if (c == 'b')
		ft_putstr("rb\n");
}

void	push_data(t_stack **stack1, t_stack **stack2, char c)
{
	int	tmp;
	int	index_tmp;

	if (!stack1 || !stack2 || !*stack1)
		return ;
	tmp = (*stack1)->data;
	index_tmp = (*stack1)->index;
	*stack2 = add_front(stack2, tmp);
	(*stack2)->index = index_tmp;
	free_firt_node(stack1);
	if (c == 'a')
		ft_putstr("pa\n");
	else if (c == 'b')
		ft_putstr("pb\n");
}

void	rrotation_data(t_stack **head, char c)
{
	t_stack	*last_stack;

	last_stack = last_node(*head);
	if (!head || !last_stack || !*head || !(*head)->next)
		return ;
	last_stack->next = *head;
	last_stack->prev->next = NULL;
	last_stack->prev = NULL;
	(*head)->prev = last_stack;
	*head = last_stack;
	if (c == 'a')
		ft_putstr("rra\n");
	else if (c == 'b')
		ft_putstr("rrb\n");
}
