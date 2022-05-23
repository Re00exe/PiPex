#COLOR:

BLUE = \033[0;34m
DEFAULT = \033[0;39m
PINK = \033[1;35m


NAME		= ft_printf.a

CC			= gcc
CFLAG	    = -Wall -Wextra -Werror
PRINTF 		= printf
RM			= rm -f

AR			= ar
ARFLAGS     = crs

INCLUDES	= ./ft_printf.h 

SRCS	=	ft_printf.c \
			libcprintfp1.c \
			libcprintfp2.c \

OBJS	=	ft_printf.o \
			libcprintfp1.o \
			libcprintfp2.o \
			
all : $(NAME)

%.o : %.c
	@$(CC) $(CFLAG) -c $< -o $@
	@$(AR) $(ARFLAGS) $(NAME) $@
	@$(PRINTF) "\rCompiling $(BLUE)$<$(DEFAULT)..."
	
clean :
	@$(RM) $(RMFLAG) $(OBJS) $(OBJS_BONUS)

fclean : clean
	@$(RM) $(RMFLAG) $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	@$(PRINTF) "\r%100s\r$(BLUE)$(NAME) is up to date!$(DEFAULT)\n"
.PHONY : clean fclean re