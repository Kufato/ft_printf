/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 08:52:58 by axcallet          #+#    #+#             */
/*   Updated: 2022/10/20 11:33:55 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_char_upp_low(char c)
{
	char	*base;

	if (c == 'X')
		base = "0123456789ABCDEF";
	else if (c == 'x' || c == 'p')
		base = "0123456789abcdef";
	return (base);
}

int	ft_putnbr_dec_int(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 9)
		len += ft_putnbr_dec_int(nb / 10);
	len += ft_putchar((nb % 10) + 48);
	return (len);
}

int	ft_putnbr(int nbr)
{
	long	nb;
	int		len;

	len = 0;
	nb = (long)nbr;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb = nb * -1;
	}
	if (nb > 9)
	{
		len += ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	len += ft_putchar("0123456789"[nb]);
	return (len);
}

int	ft_putnbr_hexa_int(unsigned int nbr, char c)
{
	unsigned long	nb;
	int				len;
	char			*base;

	len = 0;
	nb = (unsigned long)nbr;
	base = ft_char_upp_low(c);
	if (nb > 15)
	{
		len += ft_putnbr_hexa_int(nb / 16, c);
		nb = nb % 16;
	}
	len += ft_putchar(base[nb]);
	return (len);
}

int	ft_putnbr_hexa_long(unsigned long long nb)
{
	int		len;

	len = 0;
	if (nb > 15)
	{
		len += ft_putnbr_hexa_long(nb / 16);
		nb = nb % 16;
	}
	len += ft_putchar("0123456789abcdef"[nb]);
	return (len);
}
