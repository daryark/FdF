NAME = fdf

CC_FLAGS	=	-Wall -Wextra -Werror -g
INC			=	-Ilibft/	-Ift_printf/	-Iget_next_line/

PREV_F		=	prev_projects
LIBS		=	-L$(PREV_F)/ft_printf -lftprintf	-L$(PREV_F)/libft -lft

MLX_FLAGS	= 	-lmlx -framework OpenGL -framework AppKit
MLX 		= 	MiniLibX/

SRCS		=	main.c	read_file.c	draw.c	\
				get_next_line.c	get_next_line_utils.c
VPATH		=	$(SRCS_F)	$(PREV_F)/get_next_line
SRCS_F		=	src/
OBJS_F		=	obj/
OBJS		=	$(SRCS:.c=.o)
OBJS_P		=	$(addprefix $(OBJS_F), $(OBJS))


RED			=	\033[0;31m
GREEN 		=	\033[0;32m
MAGENTA		=	\033[0;35m
RESET_COLOR =	\033[0m


# ! Need to combine libft, gnl, ft_printf to not duplicate the code
# ! and use it in more convenient way in further projects.
all: $(NAME)

$(NAME): $(OBJS_P)
	@cd $(MLX); make 
	@cd $(PREV_F)/libft; make
	@cd $(PREV_F)/ft_printf; make
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