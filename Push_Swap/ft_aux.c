/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:15:12 by acuadrad          #+#    #+#             */
/*   Updated: 2025/11/04 17:21:16 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_array_str(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

int	count_nodes(t_node *stack)
{
	t_node	*aux;
	int		size;

	if (!stack)
		return (0);
	aux = stack;
	size = 0;
	while (1)
	{
		size++;
		stack = stack->next;
		if (stack == aux)
			break ;
	}
	return (size);
}

void	ft_free_stack(t_node *stack)
{
	t_node	*current;
	t_node	*next;
	t_node	*last;

	if (stack == NULL)
		return ;
	current = stack;
	last = stack->prev;
	last->next = NULL;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack = NULL;
}

void	ft_free(t_node *stack_a, t_node *stack_b, char **str)
{
	if (stack_a)
		ft_free_stack(stack_a);
	if (str)
		ft_free_array_str(str);
	if (stack_b)
		ft_free_stack(stack_b);
}
