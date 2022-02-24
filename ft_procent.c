#include "ft_printf.h"

void	ft_str_procent(t_list *cell)
{
	char	arg_procent;
	int		len;

	len = 1;
	arg_procent = '%';
	if (cell->width >= len)
	{
		ft_write_procent(cell, arg_procent);
		cell->length = cell->width;
	}
	else
	{
		write(1, &arg_procent, 1);
		cell->length = len;
	}
}

void	ft_write_procent(t_list *cell, char arg_procent)
{
	if (cell->minus == 1)
	{
		write(1, &arg_procent, 1);
		ft_write_zero_and_void(cell, 1);
	}
	if (cell->zero == 1)
	{
		ft_write_zero_and_void(cell, 0);
		write(1, &arg_procent, 1);
	}
	if (cell->minus == 0 && cell->zero == 0)
	{
		ft_write_zero_and_void(cell, 1);
		write(1, &arg_procent, 1);
	}
}

void	ft_write_zero_and_void(t_list *cell, int flag)
{
	int		len2;

	len2 = cell->width - 1;
	if (flag == 0)
	{
		while (len2 > 0)
		{
			write(1, "0", 1);
			len2--;
		}
	}
	if (flag == 1)
	{
		while (len2 > 0)
		{
			write(1, " ", 1);
			len2--;
		}
	}
}
