/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:30:17 by jkaczmar          #+#    #+#             */
/*   Updated: 2021/12/08 14:44:37 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	iteratethroughstr(const char *str, va_list *list)
{
	int	counter[2];

	counter[0] = 0;
	counter[1] = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			while (*str == ' ' && *str != '\0')
				str++;
			counter[1] = checkfortype(*str, list);
			if (counter[1] == -1)
				write(1, "(null)", 6);
				counter[0] += counter[1];
			str++;
		}
		else
		{
			write(1, str, 1);
			str++;
			counter[0] += 1;
		}
	}
	return (counter[0]);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;

	va_start(list, str);
	va_end(list);
	return (iteratethroughstr(str, &list));
}
