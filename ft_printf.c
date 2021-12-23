#include <unistd.h>
#include <stdarg.h>
#define HEX "0123456789abcdef"
#define DEC "0123456789"
int ft_strlen(char *s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
int ft_intlen(long num, int base)
{
	int i = 1;
	while (num >= base || num <= -base)
	{
		num /= base;
		i++;
	}
	return (i);
}
void ft_print_num(long num, char *base)
{
	int baz = ft_strlen(base);
	if (num >= baz)
	{
		ft_print_num(num / baz, base);
	}
	write(1, &base[num % baz], 1);
}
int ft_printf(const char *format, ...)
{
	size_t ret = 0;
	va_list ap;
	unsigned int unum;
	long num;
	int x, i = 0;
	char *s;
	if (!format)
	{
		return (-1);
	}
	if ((format[0]) == '%' && !(format[1]))
	{
		return (-1);
	}
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd')
			{
				num = va_arg(ap, int);
				if (num < 0)
				{
					num *= -1;
					ret += write(1, "-", 1);
				}
				ft_print_num(num, DEC);
				ret += ft_intlen(num, 10);
				i++;
			}
			else if (format[i] == 's')
			{
				x = 0;
				s = (char *)va_arg(ap, char *);
				while (s[x])
				{
					ret += write(1, &(s[x]), 1);
					x++;
				}
				i++;
			}
			else if (format[i] == 'x')
			{
				unum = va_arg(ap, unsigned int);
				ft_print_num(unum, HEX);
				ret += ft_intlen(unum, 16);
				i++;
			}
			else
			{
				ret += write(1, &format[i], 1);
				i++;
			}
		}
		else
		{
			ret += write(1, &format[i], 1);
			i++;
		}
	}
	va_end(ap);
	return (ret);
}