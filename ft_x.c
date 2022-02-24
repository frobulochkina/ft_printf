#include "ft_printf.h"

int		ft_str_x(t_list *cell, va_list arg)
{
	unsigned int	arg_x;
	int				len;

	arg_x = va_arg(arg, unsigned int);
	len = ft_putnbr_i_x(arg_x);
	if (cell->pres != -1 && cell->zero == 1)
		cell->zero = 0;
	if (arg_x == 0 && cell->pres == 0)
	{
		ft_str_d_i_zero(cell);
		return (0);
	}
	if (cell->width >= len && cell->width > cell->pres)
		ft_write_x(cell, arg_x, len);
	else
		ft_not_width_x_big_x(cell, arg_x, len, 0);
	return (0);
}

void	ft_write_x(t_list *cell, unsigned int arg_x, int len)
{
	int		len2;

	if (cell->minus == 1)
	{
		ft_not_width_x_big_x(cell, arg_x, len, 0);
		len2 = cell->width - len;
		if (cell->pres > len)
			len2 = cell->width - cell->pres;
		ft_write_len2(len2, 1);
	}
	else if (cell->zero == 1)
	{
		len2 = cell->width - len;
		ft_write_len2(len2, 0);
		ft_putnbr_hex_x(arg_x);
	}
	else if (cell->zero == 0 && cell->minus == 0)
	{
		len2 = cell->width - len;
		if (cell->pres > len)
			len2 = cell->width - cell->pres;
		ft_write_len2(len2, 1);
		ft_not_width_x_big_x(cell, arg_x, len, 0);
	}
	cell->length = cell->width;
}

void	ft_not_width_x_big_x(t_list *cell, long arg_x, int len, int flag)
{
	int		len2;

	if (cell->pres <= len)
	{
		(flag == 0) ? ft_putnbr_hex_x(arg_x) : ft_putnbr_hex_big_x(arg_x);
		cell->length = len;
	}
	else if (cell->pres > len)
	{
		len2 = cell->pres - len;
		ft_write_len2(len2, 0);
		(flag == 0) ? ft_putnbr_hex_x(arg_x) : ft_putnbr_hex_big_x(arg_x);
		cell->length = cell->pres;
	}
}

void	ft_putnbr_hex_x(unsigned long nb)
{
	if (nb >= 16)
	{
		ft_putnbr_hex_x(nb / 16);
		ft_putnbr_hex_x(nb % 16);
	}
	else
	{
		if (nb == 10)
			nb = 49;
		if (nb == 11)
			nb = 50;
		if (nb == 12)
			nb = 51;
		if (nb == 13)
			nb = 52;
		if (nb == 14)
			nb = 53;
		if (nb == 15)
			nb = 54;
		ft_putchar(nb + 48);
	}
}

size_t	ft_putnbr_i_x(unsigned long len)
{
	size_t	i;

	i = 0;
	while (len >= 16)
	{
		len /= 16;
		i++;
	}
	return (i + 1);
}
