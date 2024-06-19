/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/04 13:09:36 by vshkonda      #+#    #+#                 */
/*   Updated: 2023/11/09 11:46:57 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_check(char form_id, va_list *args, int *len)
{
	if (form_id == 's')
		print_str(va_arg(*args, char *), len);
	else if (form_id == 'c')
		print_char(va_arg(*args, int), len);
	else if (form_id == 'd' || form_id == 'i')
		print_num(va_arg(*args, int), len);
	else if (form_id == 'u')
		print_unsint(va_arg(*args, unsigned int), len);
	else if (form_id == 'x')
		print_hex(va_arg(*args, unsigned int), 'x', len);
	else if (form_id == 'X')
		print_hex(va_arg(*args, unsigned int), 'X', len);
	else if (form_id == 'p')
		print_pointer(va_arg(*args, size_t), len);
	else if (form_id == '%')
		print_char('%', len);
	else
		write(1, "Unsupported format", 18);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		ind;
	int		len;

	len = 0;
	ind = 0;
	if (string == NULL)
		return (-1);
	va_start(args, string);
	while (string[ind] != '\0')
	{
		if (string[ind] == '%')
		{
			ind++;
			format_check(string[ind], &args, &len);
		}
		else
			print_char(string[ind], &len);
		ind++;
	}
	va_end(args);
	return (len);
}

// #include "ft_printf.h"
// #include <stdio.h>
// #include <limits.h> 

// int	main(void)
// {
// 	int my;
// 	int ih;

// 	my = ft_printf(0);
//     ih = printf(0);
// 	printf("1 my: %i\n ih: %i\n ", my, ih);
//     return (0);
// }