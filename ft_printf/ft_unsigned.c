/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unsigned.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/04 16:54:28 by vshkonda      #+#    #+#                 */
/*   Updated: 2023/11/08 16:39:45 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsint(unsigned int num, int *len)
{
	if (num >= 10)
	{
		print_unsint(num / 10, len);
		print_unsint(num % 10, len);
	}
	else
		print_char(num + '0', len);
}
