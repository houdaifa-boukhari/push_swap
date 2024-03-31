/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 02:36:51 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/30 20:31:41 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_data(t_stack *head)
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
}

void	sswap_data(t_stack *a, t_stack *b)
{
	swap_data(a);
	swap_data(b);
}

void	rotation_data(t_stack **head)
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
}

void	push_data(t_stack **stack1, t_stack **stack2)
{
	int	tmp;
	int	index_tmp;

	if (!stack1 || !stack2 || !*stack1)
		return ;
	tmp = (*stack1)->data;
	index_tmp = (*stack1)->index;
	*stack2 = add_front(stack2, tmp);
	(*stack2)->index = index_tmp;
	delete_node_at_index(stack1, 0);
}

void	rrotation_data(t_stack **head)
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
}
