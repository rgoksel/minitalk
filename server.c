/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:17:30 by rdemiray          #+#    #+#             */
/*   Updated: 2023/08/05 17:38:47 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_of_signals(int sig)
{
	static char				bit = 7;
	static unsigned char	i;

	if (sig == SIGUSR1)
		i += (1 << bit);
	bit--;
	if (bit == -1)
	{
		write(1, &i, 1);
		i = 0;
		bit = 7;
	}
}

int	main(void)
{
	int	a;

	signal(SIGUSR1, handler_of_signals);
	signal(SIGUSR2, handler_of_signals);
	write(1, "pid: ", 5);
	a = getpid();
	my_putnbr(a);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
