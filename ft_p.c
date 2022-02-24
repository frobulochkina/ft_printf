#include "ft_printf.h"

int		ft_str_p(t_list *cell, va_list arg)
{
	unsigned long	arg_type_p;
	int				len;
	int				len2;

	arg_type_p = va_arg(arg, unsigned long);
	if (arg_type_p == 0 && cell->pres == 0)
	{
		ft_write_p_and_pres_zero(cell);
		return (0);
	}
	len = ft_putnbr_i_x(arg_type_p);
	len2 = cell->width - (len + 2);
	if (cell->width <= (len + 2))
	{
		ft_write_p(arg_type_p, len2);
		cell->length = len + 2;
	}
	else
	{
		ft_write_else_p(cell, len2, arg_type_p);
		cell->length = cell->width;
	}
	return (0);
}

void	ft_write_p_and_pres_zero(t_list *cell)
{
	if (cell->width == 0)
	{
		write(1, "0x", 2);
		cell->length = 2;
	}
	else
	{
		ft_write_p_one(cell);
		cell->length = cell->width;
	}
}

void	ft_write_p(unsigned long arg_type_p, int len2)
{
	write(1, "0x", 2);
	ft_putnbr_hex_x(arg_type_p);
	ft_write_len2(len2, 1);
}

void	ft_write_p_one(t_list *cell)
{
	int	len2;

	len2 = cell->width - 2;
	if (cell->minus == 1)
	{
		write(1, "0x", 2);
		ft_write_len2(len2, 1);
	}
	else
	{
		ft_write_len2(len2, 1);
		write(1, "0x", 2);
	}
}

void	ft_write_else_p(t_list *cell, int len2, unsigned long arg_type_p)
{
	if (cell->minus == 1)
		ft_write_p(arg_type_p, len2);
	else
	{
		ft_write_len2(len2, 1);
		write(1, "0x", 2);
		ft_putnbr_hex_x(arg_type_p);
	}
}
