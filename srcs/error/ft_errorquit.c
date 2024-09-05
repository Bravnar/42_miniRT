#include "main.h"

/* NEW */
char	*simple_replace(char *str, char what, char with)
{
	char *copy;
	int	i;

	i = 0;
	copy = ft_strdup(str);
	while (copy[i])
	{
		if (copy[i] == what)
			copy[i] = with;
		i++;
	}
	return (copy);
}

/* NEW */
void	err_template(char *msg, char *line)
{
	char *e_line;

	e_line = NULL;
	if (line)
		e_line = simple_replace(line, '\t', ' ');
	ft_fprintf(2, BOLD_RED"%s\n"RESET, ERRLINE);
	ft_fprintf(2, BOLD_RED"ParseError\n\n"RESET);
	if (e_line)
	{
		if (ft_strlen(e_line) > 20)
		{
			ft_fprintf(2, BOLD_WHITE"In line:\t"RESET);
			ft_fprintf(2, "%s\n", e_line);
		}
		else
		{
			ft_fprintf(2, BOLD_WHITE"Error Location:\t"RESET);
			ft_fprintf(2, "%s\n\n", e_line);
		}
		free(e_line);
	}
	ft_fprintf(2, BOLD_ORANGE"%s\n"RESET, msg);
	ft_fprintf(2, BOLD_RED"%s\n"RESET, ERRLINE);
	exit(1);
}

/* OLD */
void	err_quit(char *msg)
{
	ft_fprintf(2, BOLD_RED"Error:\t"RESET);
	ft_fprintf(2, BOLD_YELLOW"%s\n"RESET, msg);
	exit(1);
}

/* OLD */
void	err_handler(t_err code)
{
	if (code == ACL_MISSING)
		err_quit(M_ACL_MISSING);
	if (code == TOO_MANY_R)
		err_quit(M_TOO_MANY_R);
	if (code == TOO_MANY_A)
		err_quit(M_TOO_MANY_A);
	if (code == TOO_MANY_C)
		err_quit(M_TOO_MANY_C);
	if (code == A_RATIO_RANGE)
		err_quit(M_A_RATIO_RANGE);
	if (code == C_VECTOR_RANGE)
		err_quit(M_C_VECTOR_RANGE);
	if (code == C_FOV_RANGE)
		err_quit(M_C_FOV_RANGE);
	if (code == L_BRIGHT_RANGE)
		err_quit(M_L_BRIGHT_RANGE);
	if (code == UKNOWN_ID)
		err_quit(M_UKNOWN_ID);
	if (code == R_OVER_PARAM)
		err_quit(M_R_OVER_PARAM);
	if (code == A_OVER_PARAM)
		err_quit(M_A_OVER_PARAM);
	if (code == C_OVER_PARAM)
		err_quit(M_C_OVER_PARAM);
	if (code == L_OVER_PARAM)
		err_quit(M_L_OVER_PARAM);
	if (code == SP_OVER_PARAM)
		err_quit(M_SP_OVER_PARAM);
	if (code == PL_OVER_PARAM)
		err_quit(M_PL_OVER_PARAM);
	if (code == PL_VECTOR_RANGE)
		err_quit(M_PL_VECTOR_RANGE);
	if (code == CY_VECTOR_RANGE)
		err_quit(M_CY_VECTOR_RANGE);
	if (code == INVALID_NUMBER)
		err_quit(M_INVALID_ENTRY);
	if (code == OPEN_FAILED)
		err_quit(M_OPEN_FAILED);
	if (code == WRONG_EXT)
		err_quit(M_WRONG_EXT);
	if (code == NO_ARGS)
		err_quit(M_NO_ARGS);
	if (code == INVALID_SEP)
		err_quit(M_INVALID_SEP);
}
