#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_string(char *s)
{
	int	count;

	if (!s)
		return (ft_print_string("(null)"));
	count = 0;
	while (*s)
		count += write(1, s++, 1);
	return (count);
}

int	ft_print_unsigned_nbr_base(unsigned int n, char *base)
{
	size_t	len_base;
	int		count;

	count = 0;
	len_base = ft_strlen(base);
	if (n >= len_base)
		count += ft_print_unsigned_nbr_base(n / len_base, base);
	return (count += ft_print_char(base[n % len_base]));
}

int	ft_print_nbr_base(int n, char *base)
{
	size_t	len_base;
	int		count;

	count = 0;
	len_base = ft_strlen(base);
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

int	ft_print_ptr_base(unsigned long long n, char *base)
{
	size_t	len_base;
	int		count;

	count = 0;
	len_base = ft_strlen(base);
	if (n >= len_base)
		count += ft_print_ptr_base(n / len_base, base);
	return (count += ft_print_char(base[n % len_base]));
}

int	ft_print_ptr(unsigned long long n)
{
	int	count;

	count = 0;
	count += ft_print_string("0x");
	return (count += ft_print_ptr_base(n, "0123456789abcdef"));
}

int	ft_parse_arg(char c, va_list *arg)
{
	int	count;

	count = 0;
	if (c == 'i' || c == 'd')
		count += ft_print_nbr_base(va_arg(*arg, int), "0123456789");
	else if (c == 'u')
		count += ft_print_unsigned_nbr_base(va_arg(*arg, int), "0123456789");
	else if (c == 'x')
		count += ft_print_unsigned_nbr_base \
				(va_arg(*arg, int), "0123456789abcdef");
	else if (c == 'X')
		count += ft_print_unsigned_nbr_base \
				(va_arg(*arg, int), "0123456789ABCDEF");
	else if (c == 'p')
		count += ft_print_ptr(va_arg(*arg, unsigned long long));
	else if (c == 's')
		count += ft_print_string(va_arg(*arg, char *));
	else if (c == 'c')
		count += ft_print_char(va_arg(*arg, int));
	else if (c == '%')
		count += ft_print_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	arg;

	va_start(arg, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += ft_parse_arg(*++format, &arg);
		else
			count += ft_print_char(*format);
		format++;
	}
	va_end(arg);
	return (count);
}
/*

#include <stdio.h>

int main()
{
	int n = 5;

	ft_printf("nb chars: %i\n", ft_printf("hey %X you %s, address %p\n", 123, "hello", &n));
	ft_printf("\n");
	printf("nb chars: %i\n", printf("hey %X you %s, address %p\n", 123, "hello", &n));


	printf("%s\n", (char *)NULL);
	ft_printf("%s\n", (char *)NULL);
}

int main()
{
	//ft_printf("%p\n", "");
	//printf("%p\n", "");

	ft_printf("%x\n", -10);
	printf("%x\n", -10);
}

int main()
{
	printf("%i\n", INT_MIN);
	ft_printf("%i\n", INT_MIN);
}
*/
