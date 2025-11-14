/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:30:40 by acuadrad          #+#    #+#             */
/*   Updated: 2025/11/13 20:54:24 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	print_char(int bit)
{
	static int				mask = 1;
	static unsigned char	c = 0;

	if (bit == SIGUSR2)
		c = c | mask;
	mask = mask << 1;
	if (mask == 256)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		mask = 1;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("this is the pid: %d\n", pid);
	ft_printf("witing for the message\n");
	signal(SIGUSR1, print_char);
	signal(SIGUSR2, print_char);
	while (1)
	{
		pause();
	}
	return (0);
}
