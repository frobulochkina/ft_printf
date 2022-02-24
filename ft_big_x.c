#include "ft_printf.h"

int		ft_str_big_x(t_list *cell, va_list arg)
{
	unsigned int	arg_big_x;
	int				len;

	arg_big_x = va_arg(arg, unsigned int);
	len = ft_putnbr_i_x(arg_big_x);
	if (cell->pres != -1 && cell->zero == 1)
		cell->zero = 0;
	if (arg_big_x == 0 && cell->pres == 0)
	{
		ft_str_d_i_zero(cell);
		return (0);
	}
	if (cell->width >= len && cell->width > cell->pres)
		ft_write_big_x(cell, arg_big_x, len);
	else
		ft_not_width_x_big_x(cell, arg_big_x, len, 1);
	return (0);
}

void	ft_write_big_x(t_list *cell, unsigned int arg_big_x, int len)
{
	int		len2;

	if (cell->minus == 1)
	{
		ft_not_width_x_big_x(cell, arg_big_x, len, 1);
		len2 = cell->width - len;
		if (cell->pres > len)
			len2 = cell->width - cell->pres;
		ft_write_len2(len2, 1);
	}
	else if (cell->zero == 1)
	{
		len2 = cell->width - len;
		ft_write_len2(len2, 0);
		ft_putnbr_hex_big_x(arg_big_x);
	}
	else if (cell->zero == 0 && cell->minus == 0)
	{
		len2 = cell->width - len;
		if (cell->pres > len)
			len2 = cell->width - cell->pres;
		ft_write_len2(len2, 1);
		ft_not_width_x_big_x(cell, arg_big_x, len, 1);
	}
	cell->length = cell->width;
}

void	ft_putnbr_hex_big_x(unsigned int nb)
{
	if (nb >= 16)
	{
		ft_putnbr_hex_big_x(nb / 16);
		ft_putnbr_hex_big_x(nb % 16);
	}
	else
	{
		if (nb == 10)
			nb = 17;
		if (nb == 11)
			nb = 18;
		if (nb == 12)
			nb = 19;
		if (nb == 13)
			nb = 20;
		if (nb == 14)
			nb = 21;
		if (nb == 15)
			nb = 22;
		ft_putchar(nb + 48);
	}
}
