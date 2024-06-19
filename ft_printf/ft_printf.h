/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/04 13:14:26 by vshkonda      #+#    #+#                 */
/*   Updated: 2023/11/09 11:08:16 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

void	format_check(char form_id, va_list *args, int *len);
int		ft_printf(const char *string, ...);
void	print_str(const char *args, int *len);
void	print_char(char c, int *len);
void	print_num(int num, int *len);
void	print_unsint(unsigned int num, int *len);
void	print_hex(unsigned int x, char base_spec, int *len);
void	print_pointer(size_t pointer, int *len);

#endif
