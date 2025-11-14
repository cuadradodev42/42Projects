/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:28:48 by acuadrad          #+#    #+#             */
/*   Updated: 2025/10/30 11:28:48 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	push_node_2(t_node **to, t_node **tmp)
{
	if (!*to)
	{
		(*tmp)->next = (*tmp);
		(*tmp)->prev = (*tmp);
		*to = (*tmp);
	}
	else
	{
		(*tmp)->next = *to;
		(*tmp)->prev = (*to)->prev;
		(*to)->prev->next = (*tmp);
		(*to)->prev = (*tmp);
		*to = (*tmp);
	}
}

static int	push_node(t_node **from, t_node **to)
{
	t_node	*tmp;

	if (!from || !*from || !to)
		return (-1);
	tmp = *from;
	if (tmp->next == tmp)
		*from = NULL;
	else
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		*from = tmp->next;
	}
	push_node_2(to, &tmp);
	return (0);
}

int	pa(t_node **stack_a, t_node **stack_b)
{
	if (!stack_b || !*stack_b)
		return (-1);
	if (push_node(stack_b, stack_a) == -1)
		return (-1);
	write(1, "pa\n", 3);
	return (0);
}

int	pb(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || !*stack_a)
		return (-1);
	if (push_node(stack_a, stack_b) == -1)
		return (-1);
	write(1, "pb\n", 3);
	return (0);
}
