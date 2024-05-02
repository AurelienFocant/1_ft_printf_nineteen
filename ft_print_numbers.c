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
	int		a;

	count = 0;
	len_base = ft_getlen(base);
	if (n == -2147483648)
	{
		count = ft_print_string("-2147483648");
		if (count < 0)
			return (-1);
		return (count);
	}
	if (n < 0)
	{
		n = -n;
		if (ft_print_char('-') < 0)
			return (-1);
		count++;
	}
	if ((size_t) n >= len_base)
	{
		a = ft_print_nbr_base(n / len_base, base);
		if (a < 0)
			return (-1);
		count += a;
	}
	if (ft_print_char(base[n % len_base]) < 0)
		return (-1);
	count++;
	return (count);
}

int	ft_print_unsigned_nbr_base(unsigned int n, char *base)
{
	size_t	len_base;
	int		count;
	int		a;

	count = 0;
	len_base = ft_getlen(base);
	if (n >= len_base)
	{
		a = ft_print_unsigned_nbr_base(n / len_base, base);
		if (a < 0)
			return (-1);
		count += a;
	}
	a = ft_print_char(base[n % len_base]);
	if (a < 0)
		return (-1);
	count += a;
	return (count);
}

int	ft_print_ptr(unsigned long long n)
{
	int	count;
	int	a;

	if (sizeof(n) != sizeof(void *))
		return (-1);
	count = ft_print_string("0x");
	if (count < 0)
		return (-1);
	a = ft_print_ptr_base(n, "0123456789abcdef");
	if (a < 0)
		return (-1);
	count += a;
	return (count);
}

int	ft_print_ptr_base(unsigned long long n, char *base)
{
	size_t	len_base;
	int		count;
	int		a;

	count = 0;
	len_base = ft_getlen(base);
	if (n >= len_base)
	{
		a = ft_print_ptr_base(n / len_base, base);
		if (a < 0)
			return (-1);
		count += a;
	}
	if (ft_print_char(base[n % len_base]) < 0)
		return (-1);
	count++;
	return (count);
}
