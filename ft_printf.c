/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:29:52 by axcallet          #+#    #+#             */
/*   Updated: 2022/10/25 16:01:49 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_ptr(unsigned long ptr, int len)
{
	if (ptr != 0)
	{
		len = ft_putstr("0x");
		len += ft_putnbr_hexa_long(ptr);
	}
	else
	{
		len = ft_putstr("(nil)");
		return (len);
	}
	return (len);
}

static int	ft_check(va_list args, const char c, int len)
{
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		len += ft_check_ptr(va_arg(args, unsigned long), len);
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_putnbr_dec_int(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_putnbr_hexa_int(va_arg(args, unsigned int), c);
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] != '%')
			len += ft_putchar(s[i]);
		else
		{
			len = ft_check(args, s[i + 1], len);
			i++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
