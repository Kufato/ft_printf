/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:41:43 by axcallet          #+#    #+#             */
/*   Updated: 2022/10/20 10:56:49 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nbr);
int	ft_putnbr_hexa_int(unsigned int nbr, char c);
int	ft_putnbr_hexa_long(unsigned long long nb);
int	ft_putnbr_dec_int(unsigned int nb);

#endif
