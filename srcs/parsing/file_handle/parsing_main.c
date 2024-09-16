#include "main.h"

int	check_file_name(char *name)
{
	size_t	length;
	char	*tested_string;

	length = ft_strlen(name);
	tested_string = ft_strstr(name + length - 3, ".rt");
	if (ft_strlen(tested_string) > 3)
		return (0);
	if (!tested_string)
		return (0);
	return (1);
}

t_file	parse_file(char *filename)
{
	t_file	file;

	file.fd = -1;
	file.parse = NULL;
	if (!check_file_name(filename))
		err_template(M_WRONG_EXT, filename);
	ft_bzero(&file.count, sizeof(t_count));
	read_rt(filename, &file);
	check_count(&file);
	check_params(&file);
	return (file);
}
