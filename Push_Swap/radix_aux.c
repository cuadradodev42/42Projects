/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:24:35 by acuadrad          #+#    #+#             */
/*   Updated: 2025/11/11 18:46:56 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_node *stack)
{
	t_node	*current;
	int		bits;
	int		value;
	int		value_temp;

	current = stack->next;
	bits = 0;
	value = stack->target;
	if (value < 0)
		value = -value;
	while (current != stack)
	{
		value_temp = current->target;
		if (value_temp < 0)
			value_temp = -value_temp;
		if (value_temp > value)
			value = current->target;
		current = current->next;
	}
	while (value > 0)
	{
		value = value >> 1;
		bits++;
	}
	return (bits);
}

int	get_min(t_node *stack, int tmp)
{
	t_node	*current;
	int		min;

	current = stack;
	min = INT_MAX;
	while (1)
	{
		if (tmp == INT_MAX)
		{
			if (current->value < min)
				min = current->value;
		}
		else
		{
			if (current->value > tmp
				&& current->value < min)
				min = current->value;
		}
		current = current->next;
		if (stack == current)
			break ;
	}
	return (min);
}

int	set_target_pos(t_node **stack)
{
	int		min;
	int		i;
	int		len;
	t_node	*start;

	if (!stack || !*stack)
		return (-1);
	start = *stack;
	min = get_min(*stack, INT_MAX);
	i = 0;
	len = count_nodes(*stack);
	while (i < len)
	{
		if ((*stack)->value == min)
		{
			(*stack)->target = i;
			(*stack)->flag_target = 1;
			i++;
			min = get_min((*stack), min);
		}
		*stack = (*stack)->next;
	}
	*stack = start;
	return (0);
}
