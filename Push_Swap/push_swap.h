/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:28:24 by acuadrad          #+#    #+#             */
/*   Updated: 2025/11/07 18:31:05 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include "Lib_ft/libft.h"
#include "Lib_ft/Ft_printf/ft_printf.h"

typedef struct s_node
{
	int				value;
	int				index;
	int				target;
	int				flag_target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

int		ft_radix(t_node **stack_a, t_node **stack_b);

int		is_only_digits(char *number);
int		cmp_int(int a, int b);
int		not_duplicate(t_node *stack);
int		is_in_int_range(char *number, char *positiverange,
			char *negativerange);
char	**ft_all_args(char **argv);
int		valid_args(char **numbers);

int		sa(t_node **stack_a);
int		sb(t_node **stack_b);
int		ss(t_node **stack_a, t_node **stack_b);
int		pa(t_node **stack_a, t_node **stack_b);
int		pb(t_node **stack_a, t_node **stack_b);
int		ra(t_node **stack_a);
int		rb(t_node **stack_b);
int		rr(t_node **stack_a, t_node **stack_b);
int		rra(t_node **stack_a);
int		rrb(t_node **stack_b);
int		rrr(t_node **stack_a, t_node **stack_b);

int		number_of_sorted_nodes(t_node *stack, int position,
			int number_of_nodes);
int		is_sorted(t_node *stack);
int		count_nodes(t_node *stack);
int		sort_three_nodes(t_node **stack_a, int first, int second, int third);
int		sort_five_nodes(t_node **stack_a, t_node **stack_b, int num_nodes);
int		sort_large(t_node **stack_a, t_node **stack_b);
int		get_min(t_node *stack, int tmp);
int		get_max_bits(t_node *stack);
int		set_target_pos(t_node **stack);

t_node	*create_node(int index, int value);
int		connect_two_nodes(t_node **node1, t_node **node2);
int		add_node_to_stack(t_node **stack, t_node **node);
int		ft_fill_stack(t_node **stack, char **all_args);

void	ft_free(t_node *stack_a, t_node *stack_b, char **str);
void	ft_free_stack(t_node *stack);
char	**ft_free_split(char **str_split, unsigned int count);
char	**ft_split(char const *s, char const c);
char	**ft_all_args(char **argv);

void	ft_print_stack(t_node *stack);