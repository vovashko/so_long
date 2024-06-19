/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_char.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/04 13:23:23 by vshkonda      #+#    #+#                 */
/*   Updated: 2023/11/08 16:42:22 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}
