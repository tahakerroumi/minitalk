/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkerroum < tkerroum@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:18:43 by tkerroum          #+#    #+#             */
/*   Updated: 2024/04/22 06:07:12 by tkerroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	percent(char str, va_list ptr)
{
	int	counter;

	counter = 0;
	if (str == '%')
		counter += ft_putchar('%');
	else if (str == 'c')
		counter += ft_putchar(va_arg(ptr, int));
	else if (str == 's')
		counter += ft_putstr(va_arg(ptr, char *));
	else if (str == 'p')
		counter += ft_printp(va_arg(ptr, unsigned long));
	else if (str == 'd' || str == 'i')
		counter += ft_putnbr(va_arg(ptr, int));
	else if (str == 'u')
		counter += ft_printu(va_arg(ptr, unsigned int));
	else if (str == 'x')
		counter += ft_printhex(va_arg(ptr, unsigned int), 1);
	else if (str == 'X')
		counter += ft_printhex(va_arg(ptr, unsigned int), 2);
	else
	{
		counter += ft_putchar('%');
		counter += ft_putchar(str);
	}
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		counter;
	size_t	i;

	i = 0;
	counter = 0;
	if (!str)
		return (-1);
	va_start (ptr, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			counter += percent(str[i], ptr);
		}
		else if (str[i] == '%' && str[i + 1] == '\0')
			return (-1);
		else
			counter += ft_putchar(str[i]);
		i++;
	}
	va_end (ptr);
	return (counter);
}
