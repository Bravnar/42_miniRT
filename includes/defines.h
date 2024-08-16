#ifndef DEFINES_H
# define DEFINES_H

# define EPSILON	(0.00001)
# define ESC		(65307)
# define LEFT		(65361)
# define RIGHT		(65363)
# define UP			(65362)
# define DOWN		(65364)
# define Q_KEY		(113)
# define PI			(3.1416)
# define WHITESPACE " \t\n\r\f\v"
# define WIN_X_MAX	(3840)
# define WIN_Y_MAX	(2160)
# define P_KEY		(112)

/* Error messages */

# define GOOD_ID			"RACL.pl.sp.cy.cu"
# define GOOD_ID_SINGLE		"RACL"

# define M_NO_ARGS			"No arguments provided, give path to .rt!"
# define M_INVALID_ENTRY	"Invalid number entry, only INT or FLOAT"
# define M_ACL_MISSING		"Missing key parameters (A, C, L)"
# define M_TOO_MANY_R		"Too many R-parameters"
# define M_TOO_MANY_A		"Too many A-parameters"
# define M_TOO_MANY_C		"Too many C-parameters"
# define M_A_RATIO_RANGE	"A: ratio out of range (0.0 / 1.0)"
# define M_C_VECTOR_RANGE	"C: vector out of range (-1.0 / 1.0)"
# define M_C_FOV_RANGE		"C: FOV out of range (0 / 180)"
# define M_L_BRIGHT_RANGE	"L: Brightness out of range (0.0 / 1.0)"
# define M_UKNOWN_ID		"Unknown identifier in file"
# define M_R_OVER_PARAM		"Too many arguments in R"
# define M_A_OVER_PARAM		"Too many arguments in A"
# define M_C_OVER_PARAM		"Too many arguments in C"
# define M_L_OVER_PARAM		"Too many arguments in L"
# define M_SP_OVER_PARAM	"Too many arguments in sp"
# define M_PL_OVER_PARAM	"Too many arguments in pl"
# define M_PL_VECTOR_RANGE	"pl: vector out of range (-1.0 / 1.0)"
# define M_CY_VECTOR_RANGE	"cy: vector out of range (-1.0 / 1.0)"
# define M_WRONG_EXTENSION	"wrong file extension, expected '.rt'"
# define M_OPEN_FAILED		"failed to open file"

#endif
