/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:11:01 by acuadrad          #+#    #+#             */
/*   Updated: 2025/11/11 18:11:01 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int index, int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->value = value;
	node->index = index;
	node->target = 0;
	node->next = node;
	node->prev = node;
	return (node);
}

int	connect_two_nodes(t_node **node1, t_node **node2)
{
	if (!node1 || !node2 || !*node1 ||!*node2)
		return (-1);
	(*node1)->next = (*node2);
	(*node1)->prev = (*node2);
	(*node2)->next = (*node1);
	(*node2)->prev = (*node1);
	return (0);
}

int	add_node_to_stack(t_node **stack, t_node **node)
{
	if (!stack || !*stack || !node || !*node)
		return (-1);
	(*stack)->prev->next = (*node);
	(*node)->prev = (*stack)->prev;
	(*node)->next = (*stack);
	(*stack)->prev = (*node);
	return (0);
}

int	ft_fill_stack(t_node **stack, char **all_args)
{
	int		i;
	t_node	*aux;

	if (!stack || !all_args)
		return (-1);
	i = 0;
	aux = NULL;
	while (all_args[i])
	{
		aux = create_node(i, ft_atoi(all_args[i]));
		if (i == 0)
			*stack = aux;
		else if (i == 1)
			connect_two_nodes(stack, &aux);
		else
			if (add_node_to_stack(stack, &aux) == -1)
				return (-2);
		i++;
		if (all_args[i] == NULL)
		{
			aux->next = *stack;
			(*stack)->prev = aux;
		}
	}
	return (0);
}
