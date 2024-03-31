/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 02:19:29 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/30 03:46:25 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str, int *flag)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!str || !(str[i] >= '0' && str[i] <= '9'))
		*flag = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((result * sign > INT_MAX) || (result * sign < INT_MIN))
			*flag = 1;
		i++;
	}
	if (str[i] != '\0')
		*flag = 1;
	return (result * sign);
}

void	free_arrays(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
	return ;
}

int	min_value(t_stack *head)
{
	int		i;
	t_stack	*ptr;
	t_stack	*next;

	i = 0;
	ptr = head;
	next = head->next;
	while (next)
	{
		if (ptr->data > next->data)
			ptr = next;
		next = next->next;
	}
	while (head)
	{
		if (head->data == ptr->data)
			return (i);
		i++;
		head = head->next;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		write(1, &str[i++], 1);
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
