/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:16:18 by jkaczmar          #+#    #+#             */
/*   Updated: 2021/12/06 23:00:53 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	counter;

	if (s == NULL)
		return ;
	counter = 0;
	while (s[counter] != '\0')
		counter++;
	write(fd, s, counter);
}
