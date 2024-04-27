/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum < tkerroum@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:09:12 by tkerroum          #+#    #+#             */
/*   Updated: 2024/04/27 16:10:13 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int pid, char character)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((character >> i) & 1)
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int ac, char **av)
{
	size_t	i;
	int		pid;
	char	*message;

	if (ac != 3)
	{
		write (1, "WRONG CLIENT INPUT !!!", 23);
		return (0);
	}
	pid = ft_atoi (av[1]);
	if (pid <= 0)
	{
		write (1, "WRONG PID !!", 13);
		return (0);
	}
	message = av[2];
	i = 0;
	while (i < ft_strlen (message))
	{
		handler (pid, message[i]);
		i++;
	}
	handler (pid, '\n');
	return (0);
}
