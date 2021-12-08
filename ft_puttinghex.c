/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttinghex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:39:41 by jkaczmar          #+#    #+#             */
/*   Updated: 2021/12/08 14:54:02 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	puthex(unsigned long long num, int format)
{
	if (num >= 16)
	{
		puthex(num / 16, format);
		puthex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putnbr_fd(num, 1);
		else
		{
			if (format == 0)
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (format == 1)
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	gethexlen(unsigned long long nbr)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		i++;
		nbr /= 16;
	}
	return (i);
}
