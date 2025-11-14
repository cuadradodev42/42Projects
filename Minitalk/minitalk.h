/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:50:56 by acuadrad          #+#    #+#             */
/*   Updated: 2025/11/13 20:51:05 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <limits.h>
#include <signal.h>
#include "Ft_printf/ft_printf.h"

int	send_signal(int sig, int pid);
int	send_char(unsigned char c, int pid);
int	send_str(char *str, int pid);
int	ft_atoi(const char *nptr);