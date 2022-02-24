#include "ft_printf.h"

void		ft_search_width(char *str, t_list *cell, va_list ap, int pos)
{
	if (str[pos] != '*')
	{
		if (str[pos] != cell->type || str[pos] != '.')
			cell->width = ft_atoi_for_ft_printf(&str[pos]);
	}
	else if (str[pos] == '*')
	{
		cell->width = va_arg(ap, int);
		if (cell->width < 0)
		{
			cell->minus = 1;
			cell->width *= (-1);
		}
	}
}

int			ft_search_pres(char *str, t_list *cell, va_list arg)
{
	int	i;

	i = 0;
	while (str[i] != '.' && str[i] != cell->type)
		i++;
	if (str[i] == '.' && str[i + 1] == cell->type)
		cell->pres = 0;
	else if (str[i] == '.' && str[i + 1] != cell->type)
		ft_srch_pres(str, cell, arg, i);
	else if (cell->pres >= 0 && cell->zero == 1 && cell->type == 'p')
	{
		cell->pres = -1;
		cell->zero = 0;
	}
	return (0);
}

int			ft_srch_pres(char *str, t_list *cell, va_list arg, int i)
{
	i++;
	if (str[i] != '*')
	{
		if (str[i + 1] == '-')
			return (-1);
		if (str[i] != cell->type)
			cell->pres = ft_atoi_for_ft_printf(&str[i]);
	}
	else if (str[i] == '*')
	{
		cell->pres = va_arg(arg, int);
		if (cell->pres < 0 && (cell->type == 'd' || cell->type == 'i' ||
					cell->type == 'u' || cell->type == 'x' ||
					cell->type == 'X' || cell->type == 's'))
		{
			cell->pres = -1;
			return (0);
		}
		if (cell->pres < 0)
			cell->pres = 0;
	}
	return (0);
}
