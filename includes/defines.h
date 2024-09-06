#ifndef DEFINES_H
# define DEFINES_H

# define EPSILON	(0.00001)

# ifdef __APPLE__

#  define ESC 53
#  define LEFT 123
#  define RIGHT 124
#  define UP 126
#  define DOWN 125
#  define Q_KEY 12
#  define P_KEY 35
#  define WIN_X_MAX 3840
#  define WIN_Y_MAX 2160

# else

#  define ESC	65307
#  define LEFT	65361
#  define RIGHT	65363
#  define UP	65362
#  define DOWN	65364
#  define Q_KEY	113
#  define P_KEY 112

#  define WIN_X_MAX 3840
#  define WIN_Y_MAX 2160

#  define WIN_X_DEFAULT 500
#  define WIN_Y_DEFAULT 500

# endif

# define PI			(3.1416)
# define WHITESPACE " \t\n\r\f\v"

/* Error messages */

# define GOOD_ID			"RACL.pl.sp.cy.cu"
# define GOOD_ID_SINGLE		"RACL"

#define ERRLINE "-------------------------------------------------------------"

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
# define M_R_OVER_PARAM		"Invalid argument count in R"
# define M_A_OVER_PARAM		"Invalid argument count in A"
# define M_C_OVER_PARAM		"Invalid argument count in C"
# define M_L_OVER_PARAM		"Invalid argument count in L"
# define M_SP_OVER_PARAM	"Too many arguments in sp"
# define M_PL_OVER_PARAM	"Too many arguments in pl"
# define M_PL_VECTOR_RANGE	"pl: vector out of range (-1.0 / 1.0)"
# define M_CY_VECTOR_RANGE	"cy: vector out of range (-1.0 / 1.0)"
# define M_WRONG_EXT		"wrong file extension, expected '.rt'"
# define M_OPEN_FAILED		"failed to open file"
# define M_INVALID_SEP		"number group separated! Remove unnecessary spaces."

#endif
