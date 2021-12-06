/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:30:17 by jkaczmar          #+#    #+#             */
/*   Updated: 2021/12/06 23:32:13 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		counter;
	int		check;

	check = 0;
	counter = 0;
	va_start(list, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			while (*str == ' ' && *str != '\0')
				str++;
			check = checkfortype(*str, &list);
			if (check == -1)
				write(1, "(null)", 6);
			else
				counter += check;
			str++;
		}
		else
		{
			write(1, str, 1);
			str++;
			counter += 1;
		}
	}
	va_end(list);
	return (counter);
}
