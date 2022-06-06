/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:43:06 by midfath           #+#    #+#             */
/*   Updated: 2021/12/12 17:38:56 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define UHEX "0123456789ABCDEF"
# define LHEX "0123456789abcdef"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_put_unbr(unsigned int nb);
int	ft_inhex(unsigned long hex);
int	ft_puthexa(unsigned int nb);
int	ft_putlowhexa(unsigned int nb);
int	ft_printf(const char *s, ...);

#endif