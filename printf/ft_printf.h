/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:50:08 by nnemeth           #+#    #+#             */
/*   Updated: 2022/04/11 15:16:34 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h> 
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

int				ft_printf(const char *flag, ...);
int				ft_flag(va_list args, const char flag);
int				ft_print_char(int c);
void			ft_putstr(char *str);
int				ft_print_int(int c);
char			*ft_itoa(int n);
int				ft_printstr(char *str);
int				ft_print_hex(unsigned int n, const char flag);
void			ft_putchar_fd(char c, int fd);
unsigned int	ft_print_unsignedint(unsigned int c);
int				ft_print_ptr(unsigned long long ptr);
void			ft_put_ptr(unsigned long long ptr);

#endif
