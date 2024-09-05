#include "main.h"

static int	count_digits(int numb)
{
	int	i;

	if (numb == 0)
		return (1);
	i = 0;
	if (numb < 0)
		i++;
	while (numb)
	{
		numb /= 10;
		i++;
	}
	return (i);
}

double	handle_after(char *str, int sign)
{
	double	result;
	double	original;
	double	incr;
	int		digits;
	char	*endptr;

	if (!*str)
		return (0.0);
	original = (double)ft_strtoi(str, &endptr);
	digits = count_digits((int)original);
	incr = (double)pow(10, digits);
	result = original / incr;
	return (result * sign);
}

void	check_sign(char **str, int *sign)
{
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
	}
}

int	check_num(char *str, int *sign)
{
	int	i;
	int	dot_count;

	i = 0;
	dot_count = 0;
	while (ft_isspace(*str))
		str++;
	check_sign(&str, sign);
	if (!ft_isdigit(str[i]))
		return (0);
	while (*str && *str == '0' && *(str + 1) == '0')
		str++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (0);
		if (str[i] == '.')
			dot_count++;
		if (dot_count > 1)
			return (0);
		i++;
	}
	return (1);
}

double	ft_strtod(char *str)
{
	t_conv	stod;
	char	*endptr;

	ft_bzero(&stod, sizeof(stod));
	stod.sign = 1;
	if (!check_num(str, &stod.sign))
		err_template(M_INVALID_ENTRY, str);
	if (!ft_strchr(str, '.'))
		return ((double)ft_strtoi(str, &endptr));
	stod.split = ft_split(str, '.');
	stod.b_result = (double)ft_strtoi(stod.split[0], &endptr);
	if (stod.split[1])
		stod.a_result = handle_after(stod.split[1], stod.sign);
	stod.final_result = stod.b_result + stod.a_result;
	ft_free_arr(stod.split);
	return (stod.final_result);
}
