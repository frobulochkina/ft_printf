#include "ft_printf.h"

int		ft_str_d_i(t_list *cell, va_list arg)
{
	char	*arg_type;
	int		arg_int;
	long	arg_int_poz;
	int		len;

	arg_int = va_arg(arg, int);
	arg_int_poz = arg_int * (-1);
	arg_type = (arg_int < 0) ? ft_itoa_x(arg_int_poz) : ft_itoa_x(arg_int);
	len = (int)ft_strlen(arg_type);
	if (cell->pres != -1 && cell->zero == 1)
		cell->zero = 0;
	if (arg_int == 0 && cell->pres == 0)
	{
		ft_str_d_i_zero(cell);
		return (0);
	}
	if (cell->width >= (arg_int < 0 ? len + 1 : len) &&
			cell->width > (arg_int < 0 ? cell->pres + 1 : cell->pres))
		ft_write_d_i(cell, arg_type, arg_int, len);
	else
		ft_not_width_d_i(arg_type, cell, arg_int, len);
	free(arg_type);
	return (0);
}

void	ft_write_d_i(t_list *cell, char *arg_type, int arg_int, int len)
{
	int		len2;

	if (cell->minus == 1)
	{
		ft_not_width_d_i(arg_type, cell, arg_int, len);
		len2 = cell->width - (arg_int < 0 ? len + 1 : len);
		if (cell->pres > len)
			len2 = cell->width - (arg_int < 0 ? cell->pres + 1 : cell->pres);
		ft_write_len2(len2, 1);
	}
	else if (cell->zero == 1)
	{
		if (arg_int < 0)
			write(1, "-", 1);
		len2 = cell->width - (arg_int < 0 ? len + 1 : len);
		ft_write_len2(len2, 0);
		write(1, arg_type, len);
	}
	else if (cell->zero == 0 && cell->minus == 0)
		ft_write_d_i_else(cell, arg_type, arg_int, len);
	cell->length = cell->width;
}

void	ft_write_d_i_else(t_list *cell, char *arg_type, int arg_int, int len)
{
	int len2;

	len2 = cell->width - (arg_int < 0 ? len + 1 : len);
	if (cell->pres > len)
		len2 = cell->width - (arg_int < 0 ? cell->pres + 1 : cell->pres);
	ft_write_len2(len2, 1);
	ft_not_width_d_i(arg_type, cell, arg_int, len);
}

void	ft_not_width_d_i(char *arg_type, t_list *cell,
		long arg_type_int, int len)
{
	int	len2;

	if (cell->pres <= len)
	{
		if (arg_type_int < 0)
			write(1, "-", 1);
		write(1, arg_type, len);
		cell->length = (arg_type_int < 0 ? (len + 1) : len);
	}
	else if (cell->pres > len)
	{
		if (arg_type_int < 0)
			write(1, "-", 1);
		len2 = cell->pres - len;
		ft_write_len2(len2, 0);
		write(1, arg_type, len);
		cell->length = (arg_type_int < 0 ? (cell->pres + 1) : cell->pres);
	}
}

void	ft_str_d_i_zero(t_list *cell)
{
	int	len2;

	cell->length = cell->width;
	len2 = cell->width;
	ft_write_len2(len2, 1);
}
