/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 02:32:55 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/04/01 17:35:55 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "get_next_line/get_next_line.h"

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_value
{
	int	i;
	int	j;
	int	flag;
	int	data;
}		t_va;

t_stack	*add_front(t_stack **head, int data);
t_stack	*add_back(t_stack **head, int data);
t_stack	*last_node(t_stack *head);
t_stack	*get_index(t_stack *head, unsigned int index);
void	delete_node_at_index(t_stack **head, unsigned int index);
int		lst_size(t_stack *head);
int		ft_atoi(char *str, int *flag);
int		ft_strlen(const char *str);
void	ft_putstr(char *str);
void	swap_data(t_stack *head);
void	sswap_data(t_stack *a, t_stack *b);
void	rotation_data(t_stack **head);
void	r_rotaion_data(t_stack **a, t_stack **b);
void	r_rrotation_data(t_stack **a, t_stack **b);
void	rrotation_data(t_stack **head);
void	push_data(t_stack **stack1, t_stack **stack2);
char	**ft_split(char const *s, char c);
void	free_arrays(char **str);
void	free_list(t_stack **head);
bool	is_sorted(t_stack *a);
void	handle_error(t_stack **a, t_stack **b, char **str, char *line);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	aplly_operations(t_stack **a, t_stack **b, char *op);
void	manage_operation(t_stack **a, t_stack **b);
int		ft_strcmp(const char *s1, const char *s2);

#endif