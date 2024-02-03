/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:52:21 by rdemiray          #+#    #+#             */
/*   Updated: 2023/08/05 17:37:22 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define EARG "error invalid arg number!!"

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>

int		ft_atoi(char *str);
void	shift_bits(int pid, char c);
void	my_putnbr(int n);
void	handler_of_signals(int sig);

#endif
