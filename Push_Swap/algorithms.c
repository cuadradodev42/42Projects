/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:27:03 by acuadrad          #+#    #+#             */
/*   Updated: 2025/11/03 10:27:20 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	t_node	*current;

	if (!stack)
		return (-1);
	current = stack;
	while (1)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
		if (current == stack)
			break ;
	}
	return (1);
}

int	sort_three_nodes(t_node **stack_a, int first, int second, int third)
{
	if (!stack_a || !*stack_a)
		return (-1);
	if (first > second && second < third && first < third)
	{
		sa(stack_a);
	}
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
	{
		ra(stack_a);
	}
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
	{
		rra(stack_a);
	}
	return (0);
}

int	sort_five_nodes(t_node **stack_a, t_node **stack_b, int num_nodes)
{
	int	is_error;
	int	min;
	int	second_min;

	if (!stack_a || !*stack_a || !stack_b)
		return (-1);
	is_error = 0;
	min = get_min(*stack_a, INT_MAX);
	second_min = get_min(*stack_a, min);
	while (count_nodes(*stack_a) > 3)
	{
		if ((*stack_a)->value == min || (num_nodes == 5
				&& (*stack_a)->value == second_min))
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	is_error = sort_three_nodes(stack_a, (*stack_a)->value,
			(*stack_a)->next->value, (*stack_a)->next->next->value);
	if ((*stack_b)->value < (*stack_b)->next->value)
		sb(stack_b);
	while (*stack_b)
		pa(stack_a, stack_b);
	return (is_error);
}

int	ft_sort_radix(t_node **stack_a, t_node **stack_b, int bits)
{
	int		len;

	if (!stack_a || !stack_b || !bits)
		return (-1);
	len = count_nodes(*stack_a);
	while (len > 0)
	{
		if (((*stack_a)->target & bits) == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		len--;
	}
	return (0);
}

int	ft_radix(t_node **stack_a, t_node **stack_b)
{
	int		bits;
	int		i;
	int		max_bits;

	bits = 1;
	i = 0;
	set_target_pos(stack_a);
	max_bits = get_max_bits(*stack_a);
	while (i < max_bits)
	{
		ft_sort_radix(stack_a, stack_b, bits);
		while (*stack_b)
			pa(stack_a, stack_b);
		bits = bits << 1;
		i++;
	}
	return (0);
}
