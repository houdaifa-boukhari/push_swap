/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 02:32:55 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/04/01 17:53:19 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

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

void	index_data(t_stack *a, t_stack *cp_a);
t_stack	*add_front(t_stack **head, int data);
t_stack	*add_back(t_stack **head, int data);
t_stack	*last_node(t_stack *head);
t_stack	*get_index(t_stack *head, unsigned int index);
void	free_firt_node(t_stack **head);
int		lst_size(t_stack *head);
int		ft_atoi(char *str, int *flag);
int		ft_strlen(const char *str);
void	ft_putstr(char *str);
void	swap_data(t_stack *head, char c);
void	rotation_data(t_stack **head, char c);
void	rrotation_data(t_stack **head, char c);
void	push_data(t_stack **stack1, t_stack **stack2, char c);
char	**ft_split(char const *s, char c);
void	free_arrays(char **str);
void	free_list(t_stack **head);
void	sort_two_element(t_stack **a);
void	sort_three_element(t_stack **a);
void	sort_five_element(t_stack **a, t_stack **b);
void	sort_four_element(t_stack **a, t_stack **b);
int		min_value(t_stack *head);
bool	is_sorted(t_stack *a);
void	buble_sort(t_stack *current);
int		max_value(t_stack *current);
void	big_sorted(t_stack **a, t_stack **cp_a, t_stack **b);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif