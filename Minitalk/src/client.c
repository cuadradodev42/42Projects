/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:27:17 by acuadrad          #+#    #+#             */
/*   Updated: 2025/11/13 20:53:13 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	send_signal(int sig, int pid)
{
	if (!sig || !pid)
		return (-1);
	if (kill(pid, sig) == -1)
	{
		write(1, "Error al enviar la señal\n", 27);
		return (-1);
	}
	return (0);
}

int	send_char(unsigned char c, int pid)
{
	int				mask;

	mask = 1;
	while (mask <= 128)
	{
		if ((c & mask) == 0)
			send_signal(SIGUSR1, pid);
		else
			send_signal(SIGUSR2, pid);
		mask = mask << 1;
		usleep(100);
	}
	return (0);
}

int	send_str(char *str, int pid)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		send_char(str[i], pid);
		i++;
	}
	send_char('\0', pid);
	usleep(200);
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write (1, "Error\n", 6);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write (1, "pid no valido", 14);
	}
	send_str(argv[2], pid);
	return (0);
}
