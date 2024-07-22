# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smuravyev <smuravyev@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 16:33:12 by smuravye          #+#    #+#              #
#    Updated: 2024/06/25 14:23:31 by smuravyev        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Folders -------------------------------------------------------------------- #

SOURCEDIR			=	srcs
OBJECTDIR			=	objs
HEADERDIR			=	includes

# Files ---------------------------------------------------------------------- #

SRCS				=	$(shell	find $(SOURCEDIR) -name '*.c')
OBJS				=	$(SRCS:$(SOURCEDIR)%.c=$(OBJECTDIR)%.o)
NAME				=	my_lib.a

# Compilation ---------------------------------------------------------------- #

CC					=	gcc
CFLAGS				=	-Wall	-Wextra	-Werror

# Commands ------------------------------------------------------------------- #

RM					=	rm	-rf
MV					=	mv
MKDIR				=	mkdir
AR					=	ar	rcs

# Colors --------------------------------------------------------------------- #

BG_GREEN = \\033[46m
NO_COLOR = \\033[0m

# Source Folder -------------------------------------------------------------- #

ARRUTILSDIR			=	arr_utils
CONVERTERDIR		=	converter
GNLDIR				=	gnl
ISDIR				=	is
LINKEDLISTDIR		=	linked_list
MEMORYDIR			=	memory
PRINTFDIR			=	printf
PUTDIR				=	put
STRINGDIR			=	string
GARBAGEDIR			=	garbage

# Rules --------------------------------------------------------------------- #

all:					$(NAME)

$(NAME):				$(OBJS)
							@$(AR)	$(NAME)	$(OBJS)
							@ranlib	$(NAME)
							@echo "\n\no------------------------------------o"
							@echo "|          MY_LIB_COMPILED           |"
							@echo "o------------------------------------o"

$(OBJECTDIR)/%.o:		$(SOURCEDIR)/%.c
							@mkdir	-p	$(@D)
#								@mkdir -p $(OBJECTDIR)
#								@mkdir -p $(OBJECTDIR)/$(ARRUTILSDIR)
#								@mkdir -p $(OBJECTDIR)/$(CONVERTERDIR)
#								@mkdir -p $(OBJECTDIR)/$(GNLDIR)
#								@mkdir -p $(OBJECTDIR)/$(ISDIR)
#								@mkdir -p $(OBJECTDIR)/$(LINKEDLISTDIR)
#								@mkdir -p $(OBJECTDIR)/$(MEMORYDIR)
#								@mkdir -p $(OBJECTDIR)/$(PRINTFDIR)
#								@mkdir -p $(OBJECTDIR)/$(PUTDIR)
#								@mkdir -p $(OBJECTDIR)/$(STRINGDIR)
#								@mkdir -p $(OBJECTDIR)/$(GARBAGEDIR)
							@echo "$(BG_GREEN) $(NO_COLOR)\c"
#							@printf	"\033[KCompiling libft -----------> $<\r"
							@$(CC) $(CFLAGS) -I $(HEADERDIR) -c $< -o $@


clean:
								@$(RM)	$(OBJECTDIR)
								@echo "All the .o files have been deleted!"

fclean:					clean
								@$(RM)	$(NAME)
								@echo "MY_LIB.a has been deleted successfully!"

re:						fclean all
								@echo "MY_LIB.a has been cleaned and reset!"

.PHONY:					all clean fclean re
