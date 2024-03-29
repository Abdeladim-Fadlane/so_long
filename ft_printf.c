/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:35:41 by afadlane          #+#    #+#             */
/*   Updated: 2022/12/26 11:48:46 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
		return (i);
	}
	return (ft_putstr("(null)"));
}

static int	ft_format(char s, va_list a)
{
	int	x;

	x = 0;
	if (s == 'c')
		x += ft_putchar(va_arg(a, int));
	else if (s == 's')
		x += ft_putstr(va_arg(a, char *));
	else if (s == 'd' || s == 'i')
		x += ft_putnbr(va_arg(a, int));
	else if (s == 'u')
		x += ft_putnbr(va_arg(a, unsigned int));
	else if (s == 'x')
		x += ft_hexalower(va_arg(a, unsigned int));
	else if (s == 'X')
		x += ft_hexaupper(va_arg(a, unsigned int));
	else if (s == 'p')
	{
		x += ft_putstr("0x");
		x += ft_ptr(va_arg(a, unsigned long));
	}
	else if (s == '%')
		x += ft_putchar('%');
	return (x);
}

int	ft_printf(const char *s, ...)
{
	int		x;
	int		i;
	va_list	a;

	i = 0;
	x = 0;
	va_start(a, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			x += ft_format(s[i + 1], a);
			i++;
		}
		else
			x += ft_putchar(s[i]);
		i++;
	}
	va_end(a);
	return (x);
}
