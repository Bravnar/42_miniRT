#include "main.h"

typedef enum s_err
{
	NO_ERR,
	ACL_MISSING,
	TOO_MANY_R,
	TOO_MANY_A,
	TOO_MANY_C,
	A_RATIO_RANGE,
	C_VECTOR_RANGE,
	C_FOV_RANGE,
	L_BRIGHT_RANGE,
	UKNOWN_ID,
	R_OVER_PARAM,
	A_OVER_PARAM,
	C_OVER_PARAM,
	L_OVER_PARAM,
	SP_OVER_PARAM,
	PL_OVER_PARAM,
	PL_VECTOR_RANGE,
	CY_VECTOR_RANGE,
//	MORE_TO_BE_ADDED,
}	t_err;

#define M_ACL_MISSING		"Missing key parameters (A, C, L)"
#define M_TOO_MANY_R		"Too many R-parameters"
#define M_TOO_MANY_A		"Too many A-parameters"
#define	M_TOO_MANY_C		"Too many C-parameters"	
#define	M_A_RATIO_RANGE		"A: ratio out of range (0.0 / 1.0)"
#define	M_C_VECTOR_RANGE	"C: vector out of range (-1.0 / 1.0)"
#define	M_C_FOV_RANGE		"C: FOV out of range (0 / 180)"
#define	M_L_BRIGHT_RANGE	"L: Brightness out of range (0.0 / 1.0)"
#define	M_UKNOWN_ID			"Unknown identifier in file"
#define	M_R_OVER_PARAM		"Too many arguments in R"
#define	M_A_OVER_PARAM		"Too many arguments in A"
#define	M_C_OVER_PARAM		"Too many arguments in C"
#define	M_L_OVER_PARAM		"Too many arguments in L"
#define	M_SP_OVER_PARAM		"Too many arguments in sp"
#define	M_PL_OVER_PARAM		"Too many arguments in pl"
#define	M_PL_VECTOR_RANGE	"pl: vector out of range (-1.0 / 1.0)"
#define	M_CY_VECTOR_RANGE	"cy: vector out of range (-1.0 / 1.0)"

void	err_quit(char *msg)
{
	ft_fprintf(2, "Error:\t%s\n", msg);
	exit(1);
}

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
}
