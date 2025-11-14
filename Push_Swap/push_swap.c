/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:23:34 by acuadrad          #+#    #+#             */
/*   Updated: 2025/11/07 20:44:18 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_args(char **numbers)
{
	int	i;

	if (!numbers)
		return (-1);
	i = 0;
	while (numbers[i] && numbers[i] != 0)
	{
		if (is_only_digits(numbers[i]) != 1)
			return (1);
		if (is_in_int_range(numbers[i], "2147483647", "2147483648") != 1)
			return (2);
		if (numbers[i][0] == 0)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_push_swap(t_node **stack_a, t_node **stack_b)
{
	int	is_error;
	int	number_of_nodes;

	if (!stack_a || !*stack_a)
		return (-1);
	is_error = is_sorted(*stack_a);
	if (is_error != 0)
		return (is_error);
	number_of_nodes = count_nodes(*stack_a);
	if (number_of_nodes == 1)
		return (0);
	if (number_of_nodes == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			is_error = sa(stack_a);
	}
	else if (number_of_nodes == 3)
		is_error = sort_three_nodes(stack_a, (*stack_a)->value,
				(*stack_a)->next->value, (*stack_a)->next->next->value);
	else if (number_of_nodes <= 5)
		is_error = sort_five_nodes(stack_a, stack_b, number_of_nodes);
	else
		is_error = ft_radix(stack_a, stack_b);
	return (is_error);
}

int	ft_validate_and_stack(t_node **stack, char **all_args)
{
	int	is_error;

	is_error = 0;
	if (valid_args(all_args) == 0)
	{
		is_error = ft_fill_stack(stack, all_args);
		if (is_error != 0)
			return (is_error);
		is_error = not_duplicate(*stack);
		if (is_error != 0)
			return (is_error);
	}
	else
		return (-3);
	return (is_error);
}

int	main(int argc, char **argv)
{
	char	**all_args;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (-1);
	all_args = ft_all_args(argv);
	if (ft_validate_and_stack(&stack_a, all_args) != 0)
	{
		ft_free(stack_a, stack_b, all_args);
		write(2, "Error\n", 6);
		return (-1);
	}
	if (ft_push_swap(&stack_a, &stack_b) == -1)
	{
		ft_free(stack_a, stack_b, all_args);
		write(2, "Error\n", 6);
		return (-1);
	}
	ft_free (stack_a, stack_b, all_args);
	return (0);
}
