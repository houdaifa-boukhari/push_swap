/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_list2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 02:23:31 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/30 03:47:35 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_list(t_stack *h)
// {
// 	while (h)
// 	{
// 		printf("data is : %d, and index is : %d\n", h->data, h->index);
// 		h = h->next;
// 	}
// }

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

	current = *head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}

void	buble_sort(t_stack *current)
{
	int		tmp;
	t_stack	*next;

	while (current)
	{
		next = current->next;
		while (next)
		{
			if (current->data > next->data)
			{
				tmp = current->data;
				current->data = next->data;
				next->data = tmp;
			}
			next = next->next;
		}
		current = current->next;
	}
}
