/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_list2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 02:23:31 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/30 20:53:55 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	delete_node_at_index(t_stack **head, unsigned int index)
{
	t_stack	*current;

	current = *head;
	if (head == NULL || *head == NULL)
		return ;
	if (index == 0)
	{
		*head = current->next;
		if (current->next != NULL)
			current->next->prev = NULL;
		free(current);
		return ;
	}
	current = get_index(*head, index);
	if (current == NULL)
		return ;
	if (current->next != NULL)
		current->next->prev = current->prev;
	if (current->prev != NULL)
		current->prev->next = current->next;
	free(current);
}

t_stack	*last_node(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	free_list(t_stack **head)
{
	t_stack	*current;
	t_stack	*next;

	if (!head)
		return ;
	else if (!*head)
		return ;
	current = *head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}

void	r_rotaion_data(t_stack **a, t_stack **b)
{
	rotation_data(a);
	rotation_data(b);
}

bool	is_sorted(t_stack *a)
{
	t_stack	*next;

	if (!a || !(a->next))
		return (false);
	while (a)
	{
		if (a->next)
			next = a->next;
		if (a->data > next->data)
			return (false);
		a = a->next;
	}
	return (true);
}
