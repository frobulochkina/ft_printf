#include "ft_printf.h"

int		ft_write_str_flag(char *str, t_list *cell, va_list ap)
{
	int		i;
	int		max;
	int		len;

	i = 0;
	len = 0;
	max = cell->pos;
	while (str[i] != 0 && i < max)
	{
		if (str[i] == '%')
		{
			len = ft_putstr_printf(ap, cell);
			break ;
		}
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}

int		ft_putstr_printf(va_list ap, t_list *cell)
{
	int		lenght;

	lenght = 0;
	if (cell->type == 's')
		ft_str_s(cell, ap);
	if (cell->type == 'c')
		ft_str_c(cell, ap);
	if (cell->type == 'd' || cell->type == 'i')
		ft_str_d_i(cell, ap);
	if (cell->type == 'u')
		ft_str_u(cell, ap);
	if (cell->type == 'x')
		ft_str_x(cell, ap);
	if (cell->type == 'X')
		ft_str_big_x(cell, ap);
	if (cell->type == 'p')
		ft_str_p(cell, ap);
	if (cell->type == '%')
		ft_str_procent(cell);
	return (lenght);
}
