/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/04 13:11:06 by vshkonda      #+#    #+#                 */
/*   Updated: 2023/11/09 11:06:17 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(unsigned int x, char base_spec, int *len)
{
	char	*base;
	int		i;
	char	str[20];

	if (base_spec == 'X')
		base = "0123456789ABCDEF";
	else if (base_spec == 'x')
		base = "0123456789abcdef";
	i = 0;
	if (x == 0)
		print_char('0', len);
	while (x != 0)
	{
		str[i] = base[x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		print_char(str[i], len);
}
