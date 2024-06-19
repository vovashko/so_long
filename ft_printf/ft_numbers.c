/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numbers.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/04 13:13:20 by vshkonda      #+#    #+#                 */
/*   Updated: 2023/11/08 16:39:43 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_num(int num, int *len)
{
	unsigned int	number;

	number = num;
	if (num < 0)
	{
		number = -num;
		print_char('-', len);
	}
	if (number >= 10)
	{
		print_num(number / 10, len);
		print_num(number % 10, len);
	}
	else
		print_char(number + '0', len);
}
