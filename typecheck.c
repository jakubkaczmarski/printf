/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:14:40 by jkaczmar          #+#    #+#             */
/*   Updated: 2021/12/06 23:30:12 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	counterofdigits(long long n)
{
	int	count;

	if (n == -2147483648)
	{
		return (11);
	}
	count = 0;
	if (n < 0 || n == 0)
		count += 1;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*createptraddress(void *ptr)
{
	unsigned long int	division;
	char				temp;
	unsigned long int	addr;
	int					counter;
	char				*str;

	str = calloc(20, sizeof(char));
	addr = (unsigned long int)ptr;
	division = 1;
	counter = 0;
	while ((addr / division >= 16) && addr >= 16)
		division *= 16;
	while (division > 0)
	{
		temp = (addr / division) + '0';
		if (temp > '9')
			temp += 39;
		str[counter++] = temp;
		addr %= division;
		division /= 16;
	}
	return (str);
}

void	ft_putunsignednbr_fd(unsigned int n, int fd)
{
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else
	{
		ft_putunsignednbr_fd(n / 10, fd);
		ft_putunsignednbr_fd(n % 10, fd);
	}
}

int	checkfortype(char s, va_list *list)
{
	if (s == 'd' || s == 'i')
		return (printdig(list));
	else if (s == 'c')
	{
		ft_putchar_fd(va_arg(*list, int), 1);
		return (1);
	}
	else if (s == 's')
		return (printstr(list));
	else if (s == 'u')
		return (printunsigned(list));
	else if (s == 'p')
		return (printptr(list));
	else if (s == 'x')
		return (printhex(list, 0));
	else if (s == 'X')
		return (printhex(list, 1));
	else if (s == '%')
		return (write(1, "%", 1));
	return (0);
}
