/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcprintfp2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:31:40 by midfath           #+#    #+#             */
/*   Updated: 2022/06/05 17:28:54 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_addhex(unsigned long hex)
{
	int		i;

	i = 0;
	if (hex >= 16)
	{
		i += ft_put_addhex(hex / 16);
		i += ft_put_addhex(hex % 16);
	}
	else
		i += write(2, &LHEX[hex], 1);
	return (i);
}

int	ft_inhex(unsigned long hex)
{
	int	i;

	i = write(2, "0x", 2);
	i += ft_put_addhex(hex);
	return (i);
}

int	ft_put_unbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
	{
		n += '0';
		i += write(2, &n, 1);
	}
	return (i);
}
