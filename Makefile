
#Color:

RED		= \033[0;31m
DEFAULT	= \033[0;39m
PINK	= \033[1;35m
BLUE	= \033[1;34m

#make file :

SRC_DIR		= code
OBJ_DIR		= obj
SRC_DIR		= code
NAME		= pipex
LIBFT		= libft/libft.a
FT_PRINTF	= printf_dir/ft_printf.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

#cmd:
PRINTF		= printf

#src&obj:
SRC = main.c utils_pie.c ft_pipe.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
#make

all : $(NAME)

$(NAME) : creat_dir do_libc $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)
		@$(PRINTF) "\r%100s\r$(BLUE)$(NAME) is up to date!$(DEFAULT)\n"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(PRINTF) "\rCompiling $(BLUE)$<$(DEFAULT)..."

bonus : all

do_libc : 
	@make all -C libft/
	@make all -C printf_dir/

creat_dir :
	@mkdir -p $(OBJ_DIR)


clean :
	@make clean -C libft
	@make clean -C printf_dir
	@$(PRINTF) "$(PINK)Cleaning $(NAME) ... $(DEFAULT)\n"
	@$(RM) -r $(OBJ_DIR)
	@$(RM) -r $(OBJ_GNL_DIR)
	@$(PRINTF) "$(RED) Objects_files removed successfully. $(DEFAULT)\n"

fclean: clean
	@$(RM) -r $(BIN_DIR)
	@$(RM) $(LIBFT)
	@$(RM) $(FT_PRINTF)
	@$(PRINTF) "$(RED) $(FT_PRINTF) removed successfully. $(DEFAULT)\n";
	@$(PRINTF) "$(RED) $(LIBFT) removed successfully. $(DEFAULT)\n";
	@$(PRINTF) "$(RED) $(NAME) removed successfully. $(DEFAULT)\n"
	
re : fclean 
	@make all
