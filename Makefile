RED	= \033[0;31m
GREEN =	\033[0;32m
MAGENTA	= \033[0;35m
RESET_COLOR = \033[0m

define ASCII_ART
                                   .--,-``-.
                                  /   /     '.
                         ,---,   / ../        ;       ,---,
                   ,--,,---.'|   \ ``\  .`-    '    ,---.'|
                 ,'_ /||   | :    \___\/   \   :    |   | :
   ,---.    .--. |  | ::   : :         \   :   |    |   | |
  /     \ ,'_ /| :  . |:     |,-.      /  /   /   ,--.__| |
 /    / ' |  ' | |  . .|   : '  |      \  \   \  /   ,'   |
.    ' /  |  | ' |  | ||   |  / :  ___ /   :   |.   '  /  |
'   ; :__ :  | : ;  ; |'   : |: | /   /\   /   :'   ; |:  |
'   | '.'|'  :  `--'   \   | '/ :/ ,,/  ',-    .|   | '/  '
|   :    ::  ,      .-./   :    |\ ''\        ; |   :    :|
 \   \  /  `--`----'   /    \  /  \   \     .'   \   \  /
  `----'               `-'----'    `--`-,,-'      `----'


endef
export ASCII_ART

NAME = fdf

CC = gcc
DEPFLAGS = -MMD -MP
CC_FLAGS = -Wall -Wextra -Werror-g $(DEPFLAGS) 

SRC =	main.c \
		read_file.c utils.c \
		draw.c 
OBJ = $(addprefix $(OBJ_F), $(OBJS))

VPATH = $(SRC_F) $(SRC_F)/draw $(SRC_F)/utils $(SRC_F)/dynamic
SRCS_F = src/
OBJ_F = obj/
 

LIBFT = libft/
LIBFLAGS = -L$(LIBFT) -lft

#specify the name, where the archive will be downloaded from url
ARCH = minilibx.tgz

MLX = $(addprefix $(MLX_F), $(MLX_NAME))

#OS dependent flags
UNAME = $(shell uname -s)
ifeq ($(UNAME), Darwin)
	#MacOS
#preprocessor definition, define macros name, used in .h files depending on OS
CC_FLAGS += -D OSX
MLX_F = mlx-osx/
MLX_NAME = mlx.dylib
MLX_URL = https://cdn.intra.42.fr/document/document/21664/minilibx_mms_20191025_beta.tgz
MLX_LIBS = -lmlx -framework OpenGL -framework AppKit
else
	#Linux
CC_FLAGS += -D LINUX
MLX_F = mlx-linux/
MLX_NAME = libmlx.a
MLX_URL = https://cdn.intra.42.fr/document/document/21665/minilibx-linux.tgz
MLX_LIBS = -lmlx-Linux -Xext -lX11
endif

#maps
MAPS_F = maps
MAPS_URL = https://cdn.intra.42.fr/document/document/21662/maps.zip


.SILENT:
all: $(NAME)

run: $(NAME) maps
# ./$(NAME) m maps/*
	./$(NAME) maps/42.fdf

$(NAME): $(OBJ) $(MLX) $(LIBFT)
	$(MAKE) -C $(MLX)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CC_FLAGS) $(MLX_FLAGS) $(LIBFLAGS) -c $< -o $@
	@echo $(ASCII_ART)
	@echo "$(GREEN)\n——————————————✣ FDF COMPILED ✣————————————\n$(RESET_COLOR)"

$(OBJ_F)%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CC_FLAGS) -c $^ -o $@
	@printf"$(GREEN). $(RESET_COLOR)"

#set up mlx lib
$(MLX):
	rm -rf $(MLX_F)
	@printf "$(MAGENTA)Downloading $(MLX_F) ...$(RESET_COLOR)"
#-s silent, -S show-error, -o output download into ARCH, from MLX_URL
	curl -sS -o $(ARCH) $(MLX_URL)
	mkdir -p $(MLX_F)
	tar -xvf $(ARCH) -C $(MLX_F)
	rm $(ARCH)
	# $(MAKE) -C $(MLX); #*доразобраться с папкой и компиляцией чего куда, и тогда именем папки и executable

clean:
	$(MAKE) -C $(LIBFT) fclean;
	$(MAKE) -C $(MLX) fclean;
	@rm -rf $(OBJ_F)
	@echo "$(YELLOW)\n🧹  CLEAN FDF$(RESET_COLOR)"

fclean:	clean
	rm -f $(NAME)
	@echo "$(YELLOW)🧹🧹 FCLEAN FDF\n$(RESET_COLOR)"

re:		fclean all

.PHONY:	all clean fclean re

#  -g flag in cc flags is helpful when you need to debug program
# as it allows to trace execution of the program back to the original source code.


# bonus: $(OBJS_BONUS)


# 	@$(MAKE) -C $(MLX) 
# 	@$(MAKE) -C $(PRINTF) 
# 	@$(MAKE) -C $(GNL)
# 	@$(MAKE) -C $(LFT)
# 	@$(CC) $(CC_FLAGS) -O3 -L$(MLX) $(MLX_FLAGS) -o $(NAME) 
# 	@echo "${green}OK Bonus part${reset}"
# 	# //$(PRINTF)/libftprintf.a $(GNL)/get_next_line.a $(LFT)/libft.a -o $(NAME) $(OBJS_BONUS)
# TRY in the process, if -g helps!?