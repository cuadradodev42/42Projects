/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:53:31 by acuadrad          #+#    #+#             */
/*   Updated: 2025/11/13 20:53:57 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != 0)
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int		n;
	int		sig;
	size_t	i;
	size_t	nptr_len;

	n = 0;
	sig = 1;
	i = 0;
	nptr_len = ft_strlen(nptr);
	while ((nptr[i] >= 9 && nptr[i] <= 13 && nptr[i] != '\0') || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sig = -sig;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = (n * 10) + (nptr[i] - '0');
		i++;
	}
	return (n * sig);
}
