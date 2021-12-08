/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 23:19:04 by jkaczmar          #+#    #+#             */
/*   Updated: 2021/12/08 14:53:17 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	printhex(va_list *list, int form)
{
	unsigned int	num;

	num = va_arg(*list, unsigned int);
	if (num == 0)
		return (write(1, "0", 1));
	puthex(num, form);
	return (gethexlen(num));
}
int	printptr(va_list *list)
{
	void	*ptr;

	ptr = va_arg(*list, void *);
	if (!ptr)
		return (write(1, "0x0",3));
	write(1, "0x",2);
	puthex(((unsigned long long int) ptr), 0);
	return  (2 + gethexlen((unsigned long long int) ptr));
}

int	printstr(va_list *list)
{
	char	*str;

	str = va_arg(*list, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (ft_strlen("(null)"));
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	printunsigned(va_list *list)
{
	unsigned int	val;

	val = va_arg(*list, unsigned int);
	ft_putunsignednbr_fd(val, 1);
	return (counterofdigits((long long)val));
}

int	printdig(va_list *list)
{
	int	a;

	a = va_arg(*list, int);
	ft_putnbr_fd(a, 1);
	return (counterofdigits((long long)a));
}
