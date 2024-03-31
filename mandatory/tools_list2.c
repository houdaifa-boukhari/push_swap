/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_list2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 02:23:31 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/30 21:14:01 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_firt_node(t_stack **head)
{
	t_stack	*current;

	current = *head;
	if (head == NULL || *head == NULL)
		return ;
	*head = current->next;
	if (current->next != NULL)
		current->next->prev = NULL;
	free(current);
	return ;
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

void	buble_sort(t_stack *current)
{
	int		tmp;
	t_stack	*next;

	if (!current)
		return ;
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
