include extras/ascii_art.sh
include extras/colors.sh

# links for downloads
MAPS_URL = https://cdn.intra.42.fr/document/document/21662/maps.zip
MLX_OSX = https://cdn.intra.42.fr/document/document/21666/minilibx_macos_sierra_20161017.tgz
# MLX_OSX = https://cdn.intra.42.fr/document/document/21664/minilibx_mms_20191025_beta.tgz;
MLX_LINUX = https://cdn.intra.42.fr/document/document/21665/minilibx-linux.tgz
LIBFT_GIT = https://github.com/daryark/libft.git
# flags, + for downloaded libs to include
MLX_LIBS_OSX =  -L$(MLX_F) -lmlx -I$(MLX_F)/mlx.h -framework OpenGL -framework AppKit
MLX_LIBS_LINUX = -L$(MLX_F) -lmlx_Linux -I$(MLX_F)/mlx.h -lXext -lX11
LIBFLAGS = -L$(LIBFT_F) -lft -I$(LIBFT_F) -I$(LIBFT_F)/src/ft_printf/ -I$(LIBFT_F)/src/get_next_line/
CC_FLAGS = -Wall -Wextra -Werror -O3 -g $(DEPFLAGS)
DEPFLAGS = -MP -MMD
CC = gcc
# maps
MAPS_F = maps
MAPS_ARCH = maps.zip
MLX_ARCH = minilibx.tgz

# libs
LIBFT_F = libft
# OS dependent flags for libs
UNAME = $(shell uname -s)
ifeq ($(UNAME),Darwin)
	#*MacOS
  CC_FLAGS += -DOSX
  MLX_F = mlx-osx
  MLX_URL = $(MLX_OSX)
  MLX_LIBS = $(MLX_LIBS_OSX)
else
	#*Linux
  CC_FLAGS += -DLINUX
  MLX_F = mlx-linux
  MLX_URL = $(MLX_LINUX)
  MLX_LIBS = $(MLX_LIBS_LINUX)
endif

#*COMPILATION
NAME = fdf
SRC =	main.c \
		map.c utils.c setters.c px_position.c \
		window.c draw_line_algorithm.c menu.c	\
		hooks.c \
		print_map_helper.c

OBJ = $(addprefix $(OBJ_F), $(SRC:%.c=%.o))
VPATH = $(SRC_F) $(SRC_F)utils/ $(SRC_F)move/ $(SRC_F)draw/
SRC_F = src/
OBJ_F = obj/



.SILENT:
all: $(NAME)

run: $(NAME)
# ./$(NAME) m maps/*
	./$(NAME) maps/42.fdf

jul: $(NAME)
	./$(NAME) maps/julia.fdf

install: $(MLX_F) $(MAPS_F) $(LIBFT_F)

$(NAME): $(OBJ) $(MLX_F) $(LIBFT_F) $(MAPS_F)
	$(MAKE) -C $(LIBFT_F)
	@if [ ! -d "$(MLX_F)" ] || [ ! -f "$(MLX_F)/libmlx.a" ]; then \
		echo "$(GREEN)\nCompiling $(MLX_F) ...$(RE)"; \
		$(MAKE) -C $(MLX_F) > /dev/null 2>&1; \
		echo "$(GREEN)\n$(MLX_F) compiled$(RE)"; \
	fi
	$(CC) -o $@ $(OBJ) $(MLX_LIBS) $(LIBFLAGS) 
	@echo "$(GREEN)$$ASCII_ART\n\n———————————————✣ FDF COMPILED ✣————————————\n$(RE)"

$(OBJ_F)%.o: %.c fdf.h
	mkdir -p $(@D)
	$(CC) $(CC_FLAGS) -o $@ -c $<
	@printf "$(GREEN). $(RE)"


$(LIBFT_F):
	echo "$(GREEN)\nDownloading $(LIBFT_F) ...$(RE)"
	git clone $(LIBFT_GIT) $(LIBFT_F)

$(MLX_F):
	echo "$(GREEN)\n\nDownloading $(MLX_F) ...$(RE)"
	@curl -sS -o $(MLX_ARCH) $(MLX_URL)
	@tar -xvf $(MLX_ARCH) -C ./ > /dev/null
	rm $(MLX_ARCH)
	mv minilibx* $(MLX_F)

$(MAPS_F):
	if	[ ! -d "$(MAPS_F)" ]; then \
			echo "$(GREEN)\nDownloading $(MAPS_F) ...$(RE)"; \
			curl -sS -o $(MAPS_ARCH) $(MAPS_URL); \
			unzip -qq $(MAPS_ARCH); \
			rm $(MAPS_ARCH); \
			rm -r __MACOSX; \
			mv test_maps $@; \
		fi

clean:
	clear;
	rm -rf $(OBJ_F)
	$(MAKE) -C $(LIBFT_F) fclean;
	$(MAKE) -C $(MLX_F) clean;
	@echo "$(YELLOW)\n CLEAN FDF		🧹✨$(RE)"

fclean:	clean
	rm -f $(NAME)
	@echo "$(YELLOW)FCLEAN FDF		🧹✨\n$(RE)"

re:	fclean all

uninstall:
	rm -rf $(MAPS_F)
	rm -rf mlx*/
	rm -rf $(LIBFT_F)

.PHONY:	all clean fclean re run uninstall install

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