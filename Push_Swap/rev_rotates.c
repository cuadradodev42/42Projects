/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:30:22 by acuadrad          #+#    #+#             */
/*   Updated: 2025/11/11 18:32:13 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_node **stack_a)
{
	if (!stack_a || !*stack_a)
		return (-1);
	*stack_a = (*stack_a)->prev;
	write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_node **stack_b)
{
	if (!stack_b || !*stack_b)
		return (-1);
	*stack_b = (*stack_b)->prev;
	write(1, "rrb\n", 4);
	return (0);
}

int	rrr(t_node **stack_a, t_node **stack_b)
{
	if ((!stack_a || !*stack_a) && (!stack_b || !*stack_b))
		return (-1);
	*stack_a = (*stack_a)->prev;
	*stack_b = (*stack_b)->prev;
	write(1, "rrr\n", 4);
	return (0);
}
