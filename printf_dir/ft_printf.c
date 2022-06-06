/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:18:00 by midfath           #+#    #+#             */
/*   Updated: 2022/06/05 17:29:01 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkif(va_list parm, char str)
{
	int	p;

	p = 0;
	if (str == '%')
		p = write(2, "%", 1);
	else if (str == 'c')
		p = ft_putchar(va_arg(parm, int));
	else if (str == 's')
		p = ft_putstr(va_arg(parm, char *));
	else if (str == 'p')
		p = ft_inhex(va_arg(parm, unsigned long));
	else if (str == 'd' || str == 'i')
		p = ft_putnbr(va_arg(parm, int));
	else if (str == 'u')
		p = ft_put_unbr(va_arg(parm, unsigned int));
	else if (str == 'x')
		p = ft_putlowhexa(va_arg(parm, unsigned int));
	else if (str == 'X')
		p = ft_puthexa(va_arg(parm, unsigned int));
	else
		p = ft_putchar(str);
	return (p);
}

int	ft_printf(const char *s, ...)
{
	int		cnt;
	int		i;
	va_list	parm;

	cnt = 0;
	va_start(parm, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			cnt += ft_checkif(parm, s[++i]);
		}
		else
		{
			ft_putchar(s[i]);
			cnt++;
		}
		i++;
	}
	va_end(parm);
	return (cnt);
}
