/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:34:47 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/30 02:34:29 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*add_front(t_stack **head, int data)
{
	t_stack	*new_node;

	new_node = NULL;
	if (!head)
		return (NULL);
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = *head;
	new_node->prev = NULL;
	if (*head)
		(*head)->prev = new_node;
	*head = new_node;
	return (*head);
}

t_stack	*add_back(t_stack **head, int data)
{
	t_stack	*new_node;
	t_stack	*ptr;

	ptr = *head;
	new_node = NULL;
	if (!head)
		return (NULL);
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	if (!*head)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (*head);
	}
	while (ptr->next)
		ptr = ptr->next;
	new_node->prev = ptr;
	ptr->next = new_node;
	return (*head);
}

t_stack	*get_index(t_stack *head, unsigned int index)
{
	unsigned int	i;

	i = 0;
	while (i < index && head)
	{
		head = head->next;
		i++;
	}
	return (head);
}

int	lst_size(t_stack *head)
{
	int	count;

	count = 0;
	if (!head)
		return (0);
	while (head)
	{
		head = head->next;
		count++;
	}
	return (count);
}

t_stack	*insert_node_at_index(t_stack **h, unsigned int idx, int n)
{
	t_stack			*new_node;
	t_stack			*position;
	unsigned int	size;

	new_node = NULL;
	position = NULL;
	size = lst_size(*h);
	if (!h || idx > size)
		return (NULL);
	else if (idx == 0)
		return (add_front(h, n));
	else if (idx == size)
	{
		new_node = add_back(h, n);
		while (new_node->next)
			new_node = new_node->next;
		return (new_node);
	}
	new_node = add_back(&new_node, n);
	position = get_index(*h, idx - 1);
	new_node->next = position->next;
	position->next = new_node;
	new_node->prev = position;
	new_node->next->prev = new_node;
	return (new_node);
}
