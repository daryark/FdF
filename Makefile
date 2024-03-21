RED	= \033[0;31m
GREEN =	\033[0;32m
MAGENTA	= \033[0;35m
RESET_COLOR = \033[0m

NAME = fdf

CC_FLAGS = -Wall -Wextra -Werror -fsanitize=address -g

#* different flags for linux and mac
MLX = MiniLibX/
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/
LIBFLAGS = -L$(LIBFT) -lft


SRC =	main.c \
		read_file.c utils.c \
		draw.c 
OBJ = $(addprefix $(OBJ_F), $(OBJS))

VPATH = $(SRC_F)/draw $(SRC_F)/utils $(SRC_F)/dynamic
SRCS_F = src/
OBJ_F = obj/
 

.SILENT:
all: $(NAME)

$(NAME): $(OBJS_P)
	@cd $(MLX); make 
	@cd $(PREV_F)/ft_printf; make
	@cd $(PREV_F)/libft; make
	@cc $(CC_FLAGS) -L$(MLX) $(MLX_FLAGS) -o $(NAME) $(OBJS_P) $(LIBS)  
	@echo "$(GREEN)Main part compiled successfully ! 🎉 $(MAGENTA)FDF$(RESET_COLOR)"

$(OBJS_F)%.o: %.c Makefile fdf.h
	@mkdir -p $(OBJS_F)
	@echo "$(MAGENTA)Working on: $(RESET_COLOR)$<"
	@cc $(CC_FLAGS) $(INC) -c $< -o $@


# bonus: $(OBJS_BONUS)


# 	@$(MAKE) -C $(MLX) 
# 	@$(MAKE) -C $(PRINTF) 
# 	@$(MAKE) -C $(GNL)
# 	@$(MAKE) -C $(LFT)
# 	@$(CC) $(CC_FLAGS) -O3 -L$(MLX) $(MLX_FLAGS) -o $(NAME) 
# 	@echo "${green}OK Bonus part${reset}"
# 	# //$(PRINTF)/libftprintf.a $(GNL)/get_next_line.a $(LFT)/libft.a -o $(NAME) $(OBJS_BONUS)

clean:
	@rm -rf $(OBJS_F)
	@cd $(PREV_F)/libft; make fclean
	@cd $(PREV_F)/ft_printf; make fclean

fclean:	clean
	@rm -rf $(NAME)

re:		fclean all

.PHONY:	all clean fclean re

#  -g flag in cc flags is helpful when you need to debug program
# as it allows to trace execution of the program back to the original source code.
# TRY in the process, if -g helps!?