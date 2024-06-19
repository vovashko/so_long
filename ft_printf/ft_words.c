/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_words.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/04 13:23:23 by vshkonda      #+#    #+#                 */
/*   Updated: 2023/11/09 10:58:28 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(const char *args, int *len)
{
	int	i;

	i = 0;
	if (!args)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (args[i] != '\0')
	{
		print_char(args[i], len);
		i++;
	}
}
