#include "ft_printf.h"

void	ft_str_c(t_list *cell, va_list arg)
{
	char	*arg_type_c;
	int		len;

	len = 1;
	if (cell->zero == 1 && (cell->pres >= -1))
	{
		cell->zero = 0;
		cell->pres = 0;
	}
	while (1)
	{
		arg_type_c = va_arg(arg, char *);
		if (cell->width >= len)
			cell->length = cell->width;
		if (len >= cell->width)
			cell->length = len;
		ft_write_c(cell, arg_type_c);
		break ;
	}
}

void	ft_write_c(t_list *cell, char *arg_type_c)
{
	int len2;

	len2 = cell->width - 1;
	if (cell->minus == 1)
	{
		write(1, &arg_type_c, 1);
		ft_write_len2(len2, 1);
	}
	else
	{
		ft_write_len2(len2, 1);
		write(1, &arg_type_c, 1);
	}
}
