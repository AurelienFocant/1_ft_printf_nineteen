#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int	count;

	ft_printf("%d", -10);
	count = ft_printf("%p\n", "");
	printf("%i\n", count);
	count = printf("%p\n", "");
	printf("%i\n", count);
//	printf("\001\002\007\v\010\f\r\n");
}
