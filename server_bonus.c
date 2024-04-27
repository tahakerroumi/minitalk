/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum < tkerroum@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:08:43 by tkerroum          #+#    #+#             */
/*   Updated: 2024/04/27 16:10:27 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int signal)
{
	static int	bits;
	static int	i;

	if (signal == SIGUSR1)
		i = i | (1 << bits);
	bits++;
	if (bits == 8)
	{
		write(1, &i, 1);
		bits = 0;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	if (av[1] && ac != 1)
	{
		write (1, "WRONG INPUT !!!", 16);
		return (0);
	}
	ft_printf ("HERE IS THE SERVER'S PID:\n\n         %d\n\n", getpid());
	write (1, "WAITING FOR YOUR MESSAGE ... \n\n", 30);
	while (ac == 1)
	{
		signal (SIGUSR1, handler);
		signal (SIGUSR2, handler);
	}
	pause();
}
