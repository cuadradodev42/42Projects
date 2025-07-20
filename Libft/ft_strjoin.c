/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:35:47 by acuadrad          #+#    #+#             */
/*   Updated: 2025/05/13 13:57:49 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*result;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	result = malloc((s1len + s2len) * sizeof(char) + 1);
	if (!result)
		return (NULL);
	ft_memmove(result, s1, s1len);
	ft_memmove(&result[s1len], s2, s2len);
	result[s1len + s2len] = '\0';
	return (result);
}
