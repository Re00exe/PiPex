/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcprintfp1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 09:57:38 by midfath           #+#    #+#             */
/*   Updated: 2022/06/05 17:28:26 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(2, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		i += ft_putstr("(null)");
		return (i);
	}
	while (*str)
		i += write(2, str++, 1);
	return (i);
}

int	ft_putnbr(int nb)
{
	int				i;
	unsigned int	n2;

	i = 0;
	if (nb < 0)
	{
		i += write(2, "-", 1);
		nb *= -1;
	}
	n2 = nb;
	if (n2 > 9)
	{
		i += ft_putnbr(n2 / 10);
		i += ft_putnbr(n2 % 10);
	}
	else
	{
		n2 += '0';
		write(2, &n2, 1);
		i++;
	}
	return (i);
}

int	ft_putlowhexa(unsigned int hex)
{
	int		i;

	i = 0;
	if (hex >= 16)
	{
		i += ft_putlowhexa(hex / 16);
		i += ft_putlowhexa(hex % 16);
	}
	else
		i += write(2, &LHEX[hex], 1);
	return (i);
}

int	ft_puthexa(unsigned int hex)
{
	int		i;

	i = 0;
	if (hex >= 16)
	{
		i += ft_puthexa(hex / 16);
		i += ft_puthexa(hex % 16);
	}
	else
		i += write(2, &UHEX[hex], 1);
	return (i);
}
