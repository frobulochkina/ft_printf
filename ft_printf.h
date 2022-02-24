#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	int		zero;
	int		minus;
	int		width;
	int		pres;
	char	type;
	int		pos;
	int		length;
}				t_list;

t_list			ft_struct(void);
int				ft_str_big_x(t_list *cell, va_list arg);
void			ft_write_big_x(t_list *cell, unsigned int arg_big_x, int len);
void			ft_putnbr_hex_big_x(unsigned int nb);
void			ft_str_c(t_list *cell, va_list arg);
void			ft_write_c(t_list *cell, char *arg_type_c);
int				ft_str_d_i(t_list *cell, va_list arg);
void			ft_write_d_i(t_list *cell, char *arg_type,
		int arg_int, int len);
void			ft_write_d_i_else(t_list *cell, char *arg_type,
		int arg_int, int len);
void			ft_not_width_d_i(char *arg_type, t_list *cell,
		long arg_type_int, int len);
void			ft_str_d_i_zero(t_list *cell);
int				ft_str_p(t_list *cell, va_list arg);
void			ft_write_p_and_pres_zero(t_list *cell);
void			ft_write_p(unsigned long arg_type_p, int len2);
void			ft_write_p_one(t_list *cell);
void			ft_write_else_p(t_list *cell, int len2,
		unsigned long arg_type_p);
void			ft_search_width(char *str, t_list *cell, va_list ap, int pos);
int				ft_search_pres(char *str, t_list *cell, va_list arg);
int				ft_srch_pres(char *str, t_list *cell, va_list arg, int i);
int				ft_search_type(char *str, t_list *cell, int i);
void			ft_len_befor_procent(char *str, int pos_str,
		t_list *cell, int i);
int				ft_fill_struct(char *str, t_list *cell, va_list ap);
int				ft_search_flag_minus(char *str, t_list *cell);
size_t			ft_strlen(const char *str);
char			ft_putchar(char c);
void			ft_write_len2(int len2, int flag);
size_t			ft_putnbr_i(unsigned int len);
char			*ft_itoa_x(unsigned int n);
int				ft_atoi_for_ft_printf(char *str);
int				ft_write_str_flag(char *str, t_list *cell, va_list ap);
int				ft_putstr_printf(va_list ap, t_list *cell);
int				ft_printf(const char *str, ...);
int				ft_before_end_str(int res, t_list cell,
		const char *str, va_list arg);
void			ft_str_procent(t_list *cell);
void			ft_write_procent(t_list *cell, char arg_procent);
void			ft_write_zero_and_void(t_list *cell, int flag);
int				ft_str_s(t_list *cell, va_list arg);
void			ft_write_s(t_list *cell, int len2, char *arg_type, int len);
void			ft_s_lenght_in_struct_and_write(char *arg_type,
		t_list *cell, int len);
void			ft_s_lenght_in_struct_and_write_two(char *arg_type,
		t_list *cell, int len);
int				ft_str_u(t_list *cell, va_list arg);
void			ft_write_u(t_list *cell, unsigned int arg_u,
		int len, char *arg_type);
int				ft_str_x(t_list *cell, va_list arg);
void			ft_write_x(t_list *cell, unsigned int arg_x, int len);
void			ft_not_width_x_big_x(t_list *cell, long arg_x,
		int len, int flag);
void			ft_putnbr_hex_x(unsigned long nb);
size_t			ft_putnbr_i_x(unsigned long len);

#endif
