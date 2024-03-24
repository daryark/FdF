RED	= \033[0;31m
YELLOW = \033[0;33m
GREEN = \033[0;32m
MAGENTA	= \033[0;35m
RESET_COLOR = \033[0m

define ASCII_ART
		·▄▄▄·▄▄▄▄  ·▄▄▄
		▐▄▄·██▪ ██ ▐▄▄·
		██▪ ▐█· ▐█▌██▪ 
		██▌.██. ██ ██▌.
		▀▀▀ ▀▀▀▀▀• ▀▀▀ 
endef
export ASCII_ART


#*compilation
NAME = fdf

CC = gcc
DEPFLAGS = -MMD -MP
CC_FLAGS = -Wall -Wextra -Werror -g $(DEPFLAGS) 

SRC =	main.c \
		error_check.c
OBJ = $(addprefix $(OBJ_F), $(SRC:%.c=%.o))

VPATH = $(SRC_F) $(SRC_F)utils/
SRC_F = src/
OBJ_F = obj/

#*libs
LIBFT_GIT = https://github.com/daryark/libft.git
LIBFT_F = libft
LIBFLAGS = -L$(LIBFT_F) -lft

#* maps
MAPS_F = maps
MAPS_URL = https://cdn.intra.42.fr/document/document/21662/maps.zip
MAPS_ARCH = maps.zip

#specify the name, where the archive will be downloaded from url
MLX_ARCH = minilibx.tgz
# MLX = $(addprefix $(MLX_F)/, $(MLX_NAME))

#* OS dependent flags
UNAME = $(shell uname -s)
ifeq ($(UNAME), Darwin)
	#MacOS
#preprocessor definition, define macros name, used in .h files depending on OS
CC_FLAGS += -D OSX
MLX_F = mlx-osx
# MLX_NAME = libmlx.dylib
MLX_URL = https://cdn.intra.42.fr/document/document/21664/minilibx_mms_20191025_beta.tgz
MLX_LIBS = -lmlx -framework OpenGL -framework AppKit
else
	#Linux
CC_FLAGS += -D LINUX
MLX_F = mlx-linux
# MLX_NAME = libmlx.a
MLX_URL = https://cdn.intra.42.fr/document/document/21665/minilibx-linux.tgz
MLX_LIBS = -lmlx-Linux -Xext -lX11
endif



.SILENT:
all: $(NAME)

run: $(NAME) $(MAPS_F)
# ./$(NAME) m maps/*
	./$(NAME) maps/42.fdf

$(NAME): $(OBJ) $(MLX_F) | $(MAPS_F)
	@echo "\n"
	$(MAKE) -C $(LIBFT_F)
	$(CC) $(MLX_LIBS) $(LIBFLAGS) -o $@ $<
	@echo "$(MAGENTA)$$ASCII_ART$(RESET_COLOR)"
	@echo "$(GREEN)\n———————————————✣ FDF COMPILED ✣————————————\n$(RESET_COLOR)"

$(OBJ_F)%.o: %.c $(LIBFT_F)
	mkdir -p $(@D)
	$(CC) $(CC_FLAGS) -o $@ -c $<
	@printf "$(GREEN). $(RESET_COLOR)"

# #* set up mlx lib

$(MLX_F):
	echo "$(GREEN)\n\nDownloading $(MLX_F) ...$(RESET_COLOR)"
# -s silent, -S show-error, -o output download into MLX_ARCH, from MLX_URL
	curl -sS -o $(MLX_ARCH) $(MLX_URL)
	tar -xvf $(MLX_ARCH)
	rm $(MLX_ARCH)
	mv minilibx* $(MLX_F)
	$(MAKE) -C $(MLX_F);

$(MAPS_F):
	if	[ ! -d "$(MAPS_F)" ]; then \
			curl -sS -o $(MAPS_ARCH) $(MAPS_URL); \
			unzip $(MAPS_ARCH); \
			rm $(MAPS_ARCH); \
			rm -r __MACOSX; \
			mv test_maps $@; \
		fi

$(LIBFT_F):
	echo "$(GREEN)\n\nDownloading $(LIBFT_F) ...$(RESET_COLOR)"
	git clone $(LIBFT_GIT) $(LIBFT_F)


clean:
	clear;
	$(MAKE) -C $(LIBFT_F) fclean;
	rm -rf $(OBJ_F)
	@echo "$(YELLOW)\n CLEAN FDF		🧹✨$(RESET_COLOR)"

fclean:	clean
	rm -f $(NAME)
	@echo "$(YELLOW)FCLEAN FDF		🧹✨\n$(RESET_COLOR)"

re:		fclean all

uninstall: $(MAPS_F) $(MLX_F) $(LIBFT_F)
	rm -rf $(MAPS_F)
	rm -rf $(MLX_F)
	rm -rf $(LIBFT_F)

.PHONY:	all clean fclean re maps run

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