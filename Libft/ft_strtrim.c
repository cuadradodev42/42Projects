/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:37:22 by acuadrad          #+#    #+#             */
/*   Updated: 2025/05/15 14:02:27 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	i = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	str = ft_substr(s1, start, end - start);
	return (str);
}
/*
int main (int argc, char **argv)
{
	char *result;

	if (argc == 3)
	{
		result = ft_strtrim(argv[1], argv[2]);
		printf("la estring original es: %s\n",argv[1]);
		printf(" y queremos quitarle los siguientes caracteres: %s\n",argv[2]);
		printf("el resultado es: %s",result);
	}
	else
		printf("error, incorrect number of arguments");
}
*/