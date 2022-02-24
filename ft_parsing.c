#include "ft_printf.h"

t_list	ft_struct(void)
{
	t_list	cell;

	cell.minus = 0;
	cell.zero = 0;
	cell.width = 0;
	cell.pres = -1;
	cell.type = 0;
	cell.pos = 0;
	cell.length = 0;
	return (cell);
}

int		ft_search_type(char *str, t_list *cell, int i)
{
	int		len_befor_percent;
	int		pos_str;

	pos_str = 0;
	len_befor_percent = 0;
	while (str[pos_str] != '\0')
	{
		if (str[pos_str] == '%')
		{
			pos_str++;
			i++;
			break ;
		}
		pos_str++;
		i++;
		len_befor_percent++;
	}
	if (str[pos_str] == '\0')
	{
		cell->type = 0;
		cell->pos = i;
		return (len_befor_percent);
	}
	ft_len_befor_procent(str, pos_str, cell, i);
	return (len_befor_percent);
}

void	ft_len_befor_procent(char *str, int pos_str, t_list *cell, int i)
{
	while (str[pos_str] != '\0')
	{
		if (str[pos_str] == 's' || str[pos_str] == 'c' || str[pos_str] == 'd' ||
				str[pos_str] == 'i' || str[pos_str] == 'u' ||
				str[pos_str] == 'p' || str[pos_str] == 'x' ||
				str[pos_str] == 'X' || str[pos_str] == '%')
		{
			cell->type = str[pos_str];
			cell->pos = i;
			break ;
		}
		i++;
		pos_str++;
	}
}

int		ft_fill_struct(char *str, t_list *cell, va_list ap)
{
	int pos;

	pos = ft_search_flag_minus(str, cell);
	ft_search_width(str, cell, ap, pos);
	ft_search_pres(str, cell, ap);
	return (pos);
}

int		ft_search_flag_minus(char *str, t_list *cell)
{
	int	i;

	i = 1;
	while (!(str[i] >= '1' && str[i] <= '9') && str[i] != cell->type &&
			str[i] != '.' && str[i] != '*')
	{
		if (str[i] == '0')
			cell->zero = 1;
		else if (str[i] == '-')
		{
			cell->minus = 1;
			cell->zero = 0;
			while (!(str[i] >= '1' && str[i] <= '9') && str[i] != cell->type &&
					str[i] != '.' && str[i] != '*')
				i++;
			return (i);
		}
		i++;
	}
	return (i);
}
