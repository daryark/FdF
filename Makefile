NAME = fdf

MLX_FLAGS	= 	-lmlx -framework OpenGL -framework AppKit
CC_FLAGS	=	-Wall -Wextra -Werror -g
INC			=	-Ilibft/	-Ift_printf/
LIBS		=	-Lprev_projects/libft -lft	-Lprev_projects/ft_printf -lftprintf

MLX 		= 	MiniLibX/

SRCS		=	main.c	read_file.c	draw.c	\
				./prev_projects/get_next_line/get_next_line.c	./prev_projects/get_next_line/get_next_line_utils.c

SRCS_F			= src/
OBJS_F			= obj/

OBJS			=	$(SRCS:.c=.o)
OBJS_P			=	$(addprefix $(OBJS_F), $(OBJS))


GREEN = \033[0;32m
MAGENTA	= \033[0;35m
RED = \033[0;31m
RESET_COLOR = \033[0m


all:$(NAME)

$(NAME): $(OBJS_P)
	@cd $(MLX); make 
	@cc $(CC_FLAGS)  -L$(MLX) $(MLX_FLAGS) -o $(NAME) $(OBJS_P) $(LIBS)
	@echo "$(GREEN)Main part compiled successfully ! 🎉 $(MAGENTA)FDF$(RESET_COLOR)"
# @$(MAKE) -C $(PRINTF) 
# @$(MAKE) -C $(GNL)
# @$(MAKE) -C $(LFT)
# @cc $(CC_FLAGS) -O3 -L$(MLX) $(MLX_FLAGS) $(PRINTF)/libftprintf.a $(GNL)/get_next_line.a $(LFT)/libft.a -o $(NAME) $(OBJS_P)

$(OBJS_F)%.o: $(SRCS_F)%.c Makefile fdf.h
	@mkdir -p $(OBJS_F)
	@echo "$(MAGENTA)Working on: $(RESET_COLOR)$<"
	@cc $(CC_FLAGS) -c $< -o $@


# $(OBJS_F_B)%.o: $(SRCS_B)%.c Makefile so_long.h
# 	@mkdir -p $(OBJS_F_B)
# 	@echo "${magenta}Working on: ${reset} $<"
# 	@cc $(CC_FLAGS) -O3 -c $< -o $@


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
# @rm -rf $(OBJS_F_B)
	@$(MAKE) clean -C $(	) 
# @$(MAKE) fclean -C $(PRINTF) 
# @$(MAKE) fclean -C $(GNL)
# @$(MAKE) fclean -C $(LFT)

fclean:	clean
	@rm -rf $(NAME)

re:		fclean all

.PHONY:	all clean fclean re

#  -g flag in cc flags is helpful when you need to debug program
# as it allows to trace execution of the program back to the original source code.
# TRY in the process, if -g helps!?