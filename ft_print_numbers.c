/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:45:01 by afocant           #+#    #+#             */
/*   Updated: 2024/05/02 16:53:10 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr_base(int n, char *base)
{
	size_t	len_base;
	int		count;

	count = 0;
	len_base = ft_getlen(base);
	if (n == INT_MIN)
	{
		count += ft_print_nbr_base(n / (int)len_base, base);
		return (count += ft_print_char(base[n % len_base]));
	}
	if (n < 0)
	{
		n = -n;
		count += ft_print_char('-');
	}
	if ((size_t) n >= len_base)
		count += ft_print_nbr_base(n / len_base, base);
	return (count += ft_print_char(base[n % len_base]));
}

int	ft_print_unsigned_nbr_base(unsigned int n, char *base)
{
	size_t	len_base;
	int		count;

	count = 0;
	len_base = ft_getlen(base);
	if (n >= len_base)
		count += ft_print_unsigned_nbr_base(n / len_base, base);
	return (count += ft_print_char(base[n % len_base]));
}

int	ft_print_ptr(unsigned long long n)
{
	int	count;

	count = 0;
	count += ft_print_string("0x");
	return (count += ft_print_ptr_base(n, "0123456789abcdef"));
}

int	ft_print_ptr_base(unsigned long long n, char *base)
{
	size_t	len_base;
	int		count;

	count = 0;
	len_base = ft_getlen(base);
	if (n >= len_base)
		count += ft_print_ptr_base(n / len_base, base);
	return (count += ft_print_char(base[n % len_base]));
}
