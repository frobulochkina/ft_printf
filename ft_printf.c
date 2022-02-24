#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	t_list			cell;
	va_list			arg;
	int				res;

	res = 0;
	va_start(arg, str);
	cell = ft_struct();
	res = ft_before_end_str(res, cell, str, arg);
	va_end(arg);
	return (res);
}

int		ft_before_end_str(int res, t_list cell, const char *str, va_list arg)
{
	int		i;
	char	*new_str;
	int		len_befor_percent;

	i = 0;
	new_str = (char *)str;
	while (str[i] != '\0' && i < (int)ft_strlen(str))
	{
		len_befor_percent = ft_search_type(&new_str[i], &cell, i);
		if (ft_fill_struct(&new_str[len_befor_percent + i], &cell, arg) == -1)
		{
			va_end(arg);
			return (-1);
		}
		ft_write_str_flag(&new_str[i], &cell, arg);
		i = cell.pos + 1;
		res += (len_befor_percent + cell.length);
		cell = ft_struct();
	}
	return (res);
}
