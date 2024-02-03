/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:54:20 by rdemiray          #+#    #+#             */
/*   Updated: 2023/08/05 17:36:31 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	shift_bits(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(60);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	pid = ft_atoi(argv[1]);
	i = 0;
	if (argc == 3 && argv[2] != 0)
	{
		while (argv[2][i])
			shift_bits(pid, argv[2][i++]);
	}
	else
		write(2, EARG, sizeof(EARG));
	return (0);
}
