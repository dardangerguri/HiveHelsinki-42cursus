/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:33:57 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/09 16:22:57 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(int fd, const char *s, ...);
int	unsigned_decimal_printf(unsigned int number, int fd);
int	hexadecimal_printf(unsigned long number, char index, int fd);

#endif
