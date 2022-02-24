#include "ft_printf.h"

int		ft_str_u(t_list *cell, va_list arg)
{
	char			*arg_type;
	unsigned int	arg_u;
	int				len;

	arg_u = va_arg(arg, unsigned int);
	arg_type = ft_itoa_x(arg_u);
	len = (unsigned int)ft_strlen(arg_type);
	if (cell->pres != -1 && cell->zero == 1)
		cell->zero = 0;
	if (arg_u == 0 && cell->pres == 0)
	{
		ft_str_d_i_zero(cell);
		return (0);
	}
	if (cell->width >= len && cell->width > cell->pres)
		ft_write_u(cell, arg_u, len, arg_type);
	else
		ft_not_width_d_i(arg_type, cell, arg_u, len);
	free(arg_type);
	return (0);
}

void	ft_write_u(t_list *cell, unsigned int arg_u, int len, char *arg_type)
{
	int		len2;

	if (cell->minus == 1)
	{
		ft_not_width_d_i(arg_type, cell, arg_u, len);
		len2 = cell->width - len;
		if (cell->pres > len)
			len2 = cell->width - cell->pres;
		ft_write_len2(len2, 1);
	}
	else if (cell->zero == 1)
	{
		len2 = cell->width - len;
		ft_write_len2(len2, 0);
		write(1, arg_type, len);
	}
	else if (cell->zero == 0 && cell->minus == 0)
	{
		len2 = cell->width - len;
		if (cell->pres > len)
			len2 = cell->width - cell->pres;
		ft_write_len2(len2, 1);
		ft_not_width_d_i(arg_type, cell, arg_u, len);
	}
	cell->length = cell->width;
}
