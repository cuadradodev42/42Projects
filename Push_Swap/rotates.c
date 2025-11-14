/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:28:29 by acuadrad          #+#    #+#             */
/*   Updated: 2025/11/11 18:30:00 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_node **stack_a)
{
	if (!stack_a || !*stack_a)
		return (-1);
	*stack_a = (*stack_a)->next;
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_node **stack_b)
{
	if (!stack_b || !*stack_b)
		return (-1);
	*stack_b = (*stack_b)->next;
	write(1, "rb\n", 3);
	return (0);
}

int	rr(t_node **stack_a, t_node **stack_b)
{
	if ((!stack_a || !*stack_a) && (!stack_b || !*stack_b))
		return (-1);
	*stack_a = (*stack_a)->next;
	*stack_b = (*stack_b)->next;
	write(1, "rr\n", 3);
	return (0);
}
