/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:27:29 by acuadrad          #+#    #+#             */
/*   Updated: 2025/10/30 11:27:29 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_only_digits(char *number)
{
	int	i;

	if (!number)
		return (-1);
	i = 0;
	if (number[i] == '-' || number[i] == '+')
		i++;
	while (number[i])
	{
		if (number[i] < '0' || number[i] > '9')
		{
			return (-1);
		}
		i++;
	}
	if (number[i - 1] < '0' || number[i - 1] > '9')
		return (-1);
	return (1);
}

int	cmp_int(int a, int b)
{
	if (a < b)
		return (-1);
	else if (a > b)
		return (1);
	return (0);
}

int	not_duplicate(t_node *stack)
{
	t_node	*aux;
	t_node	*runner;

	if (!stack)
		return (-1);
	aux = stack;
	while (1)
	{
		runner = aux->next;
		while (runner != aux)
		{
			if (cmp_int(aux->value, runner->value) == 0)
				return (1);
			runner = runner->next;
		}
		aux = aux->next;
		if (aux == stack)
			break ;
	}
	return (0);
}

int	is_in_int_range(char *number, char *positiverange, char *negativerange)
{
	int		len;
	int		i;
	char	*range;

	i = 0;
	range = 0;
	if (number[i] == '-')
	{
		range = negativerange;
		i++;
	}
	else
		range = positiverange;
	while (number[i] && number[i] != 0 && number[i] == '0')
		i++;
	len = ft_strlen(&number[i]);
	if (len > 10)
		return (-1);
	if (len == 10)
		if (ft_strncmp(range, &number[i], len) > 0)
			return (-1);
	return (1);
}

char	**ft_all_args(char **argv)
{
	int				i;
	char			**args_flat;
	char			*temp_args;

	args_flat = NULL;
	temp_args = NULL;
	i = 1;
	while (argv[i] && argv[i] != 0)
	{
		temp_args = ft_strjoin_and_free(temp_args, argv[i]);
		temp_args = ft_strjoin_and_free(temp_args, " ");
		i++;
	}
	args_flat = ft_split(temp_args, ' ');
	free(temp_args);
	temp_args = NULL;
	return (args_flat);
}
