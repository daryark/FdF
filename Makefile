include extras/ascii_art.sh
include extras/colors.sh

#*compilation
NAME = fdf
SRC =	main.c \
		error_check.c map.c parsing.c

OBJ = $(addprefix $(OBJ_F), $(SRC:%.c=%.o))
VPATH = $(SRC_F) $(SRC_F)utils/
SRC_F = src/
OBJ_F = obj/
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror -g $(DEPFLAGS)
DEPFLAGS = -MP -MMD

#*libs
LIBFT_F = libft
LIBFLAGS = -L$(LIBFT_F) -lft -I$(LIBFT_F) -I$(LIBFT_F)/src/ft_printf/ -I$(LIBFT_F)/src/get_next_line/
LIBFT_GIT = https://github.com/daryark/libft.git
#* maps
MAPS_F = maps
MAPS_URL = https://cdn.intra.42.fr/document/document/21662/maps.zip
MAPS_ARCH = maps.zip
MLX_ARCH = minilibx.tgz
#* OS dependent flags
UNAME = $(shell uname -s)
ifeq ($(UNAME), Darwin)
	#*MacOS
  CC_FLAGS += -D OSX
  MLX_F = mlx-osx
  MLX_URL = https://cdn.intra.42.fr/document/document/21664/minilibx_mms_20191025_beta.tgz
  MLX_LIBS = -L$(MLX_F) -framework OpenGL -framework AppKit
else
	#*Linux
  CC_FLAGS += -D LINUX
  MLX_F = mlx-linux
  MLX_URL = https://cdn.intra.42.fr/document/document/21665/minilibx-linux.tgz
  MLX_LIBS = -L$(MLX_F) -lXext -lX11
endif



.SILENT:
all: $(NAME)

run: $(NAME)
# ./$(NAME) m maps/*
	./$(NAME) maps/elem-col.fdf

install: $(MLX_F) $(MAPS_F) $(LIBFT_F)

$(NAME): $(OBJ) | install
	$(MAKE) -C $(LIBFT_F)
	$(CC) -o $@ $(OBJ) $(MLX_LIBS) $(LIBFLAGS)
# @echo "$(MAGENTA)$$ASCII_ART$(RESET_COLOR)"
	@echo "$(GREEN)\n———————————————✣ FDF COMPILED ✣————————————\n$(RESET_COLOR)"

$(OBJ_F)%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CC_FLAGS) -o $@ -c $<
	@printf "$(GREEN). $(RESET_COLOR)"

# #* set up mlx lib

$(MLX_F):
	echo "$(GREEN)\n\nDownloading $(MLX_F) ...$(RESET_COLOR)"
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
	rm -rf $(OBJ_F)
	@echo "$(YELLOW)\n CLEAN FDF		🧹✨$(RESET_COLOR)"

fclean:	clean
	rm -f $(NAME)
	@echo "$(YELLOW)FCLEAN FDF		🧹✨\n$(RESET_COLOR)"

re:		fclean all

uninstall:
	rm -rf $(MAPS_F)
	rm -rf $(MLX_F)
	rm -rf $(LIBFT_F)

.PHONY:	all clean fclean re run uninstall

#  -g flag in cc flags is helpful when you need to debug program
# as it allows to trace execution of the program back to the original source code.

#preprocessor definition, define macros name, used in .h files depending on OS
#   CC_FLAGS += -D OSX

# -s silent, -S show-error, -o output download into MLX_ARCH, from MLX_URL
# curl -sS -o $(MLX_ARCH) $(MLX_URL)

# $(CC) -o $@ $(OBJ) $(MLX_LIBS) $(LIBFLAGS) - the libs included in the proj, must always be written after the final object that needs these libs,
#  so the compiler can go and search further in the line for the path where these needed libs are located and find them

#-I is used to specify where to find the .h files for the library. You need this to include the library's function declarations and definitions in your code.
#-L is used to specify where to find the compiled library (.a, .dylib, .lib) files. You need this so that the linker knows where to find the actual code for the library functions.
#-l is used to specify which library to link against, NAME (without lib (libft.a => -lft)). You need this so that the linker knows which library file to include in the final executable.


# bonus: $(OBJS_BONUS)


# 	@$(MAKE) -C $(MLX) 
# 	@$(MAKE) -C $(PRINTF) 
# 	@$(MAKE) -C $(GNL)
# 	@$(MAKE) -C $(LFT)
# 	@$(CC) $(CC_FLAGS) -O3 -L$(MLX) $(MLX_FLAGS) -o $(NAME) 
# 	@echo "${green}OK Bonus part${reset}"
# 	# //$(PRINTF)/libftprintf.a $(GNL)/get_next_line.a $(LFT)/libft.a -o $(NAME) $(OBJS_BONUS)
# TRY in the process, if -g helps!?