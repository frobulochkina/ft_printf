#include "ft_printf.h"

int		ft_str_s(t_list *cell, va_list arg)
{
	char	*arg_type;
	int		len;

	arg_type = 0;
	if (cell->zero == 1)
		cell->zero = 0;
	while (1)
	{
		arg_type = va_arg(arg, char *);
		if (arg_type == NULL)
			arg_type = "(null)";
		len = (int)ft_strlen(arg_type);
		if (cell->pres == -1 || cell->pres >= len)
		{
			ft_s_lenght_in_struct_and_write(arg_type, cell, len);
			break ;
		}
		if (cell->pres < len)
			ft_s_lenght_in_struct_and_write_two(arg_type, cell, len);
		break ;
	}
	return (0);
}

void	ft_write_s(t_list *cell, int len2, char *arg_type, int len)
{
	if (cell->minus == 1)
	{
		write(1, arg_type, len);
		while (len2 > 0)
		{
			write(1, " ", 1);
			len2--;
		}
	}
	else
	{
		while (len2 > 0)
		{
			write(1, " ", 1);
			len2--;
		}
		write(1, arg_type, len);
	}
}

void	ft_s_lenght_in_struct_and_write(char *arg_type, t_list *cell, int len)
{
	int		len2;

	if (cell->pres == -1 || cell->pres >= len)
	{
		if (cell->width <= cell->pres)
		{
			if (cell->pres >= len && cell->width <= len)
				cell->length = len;
			if (cell->width >= len)
				cell->length = cell->width;
		}
		else if ((cell->width == 0 && cell->pres <= 0) || cell->width < len)
			cell->length = len;
		else
			cell->length = cell->width;
		len2 = cell->width - len;
		ft_write_s(cell, len2, arg_type, len);
	}
}

void	ft_s_lenght_in_struct_and_write_two(char *arg_type,
		t_list *cell, int len)
{
	int		len2;

	if (cell->pres < len)
	{
		len = cell->pres;
		if (cell->width >= cell->pres && cell->width >= len)
			cell->length = cell->width;
		if (cell->pres > cell->width && cell->pres >= len)
			cell->length = len;
		len2 = cell->width - len;
		ft_write_s(cell, len2, arg_type, len);
	}
}
