/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:43:30 by acuadrad          #+#    #+#             */
/*   Updated: 2025/11/11 19:02:38 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	update_swap_pointers(t_node **stack, t_node **temp)
{
	if (!stack || !temp || !*stack || !*temp)
		return (-1);
	(*stack)->prev->next = (*temp);
	(*temp)->next->prev = (*stack);
	(*temp)->prev = (*stack)->prev;
	(*stack)->next = (*temp)->next;
	(*stack)->prev = (*temp);
	(*temp)->next = (*stack);
	(*stack) = (*temp);
	return (0);
}

static int	swap_nodes(t_node **stack)
{
	t_node	*temp;

	if (!stack || !*stack)
		return (-1);
	if ((*stack)->next == *stack)
		return (0);
	if ((*stack)->next == (*stack)->prev)
	{
		*stack = (*stack)->next;
		return (0);
	}
	temp = (*stack)->next;
	if (update_swap_pointers(stack, &temp) == -1)
		return (-1);
	return (0);
}

int	sa(t_node **stack_a)
{
	if (!stack_a)
		return (-1);
	write(1, "sa\n", 3);
	if (swap_nodes(stack_a) == -1)
		return (-1);
	return (0);
}

int	sb(t_node **stack_b)
{
	if (!stack_b)
		return (-1);
	if (swap_nodes(stack_b) == -1)
		return (-1);
	write(1, "sb\n", 3);
	return (0);
}

int	ss(t_node **stack_a, t_node **stack_b)
{
	if ((!stack_a || !*stack_a) && (!stack_b || !*stack_b))
		return (-1);
	if (swap_nodes(stack_a) == -1)
		return (-1);
	if (swap_nodes(stack_b) == -1)
		return (-1);
	write(1, "ss\n", 3);
	return (0);
}
