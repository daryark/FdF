include extras/ascii_art.sh
include extras/colors.sh

#*-------------links for downloads-------------
MAPS_URL = https://cdn.intra.42.fr/document/document/26195/maps.zip
MLX_OSX = https://cdn.intra.42.fr/document/document/21666/minilibx_macos_sierra_20161017.tgz
# MLX_OSX = https://cdn.intra.42.fr/document/document/21664/minilibx_mms_20191025_beta.tgz;
MLX_LINUX = https://cdn.intra.42.fr/document/document/26198/minilibx-linux.tgz
LIBFT_GIT = https://github.com/daryark/libft.git
#* flags
MLX_LIBS_OSX =  -L$(MLX_F) -lmlx -I$(MLX_F)/mlx.h -framework OpenGL -framework AppKit
MLX_LIBS_LINUX = -L$(MLX_F) -lmlx_Linux -I$(MLX_F)/mlx.h -lXext -lX11 -lm
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

#*-------------OS dependent flags for libs-------------
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


#*-------------COMPILATION-------------
NAME = fdf
SRC =	main.c \
		map.c utils.c set_val.c px_position.c center.c error.c clean.c isometric.c \
		window.c draw_line_algorithm.c menu.c \
		hooks.c events.c event_act.c safe_check.c sub_event.c mouse_events.c \
		print_map_helper.c

OBJ = $(addprefix $(OBJ_F), $(SRC:%.c=%.o))
VPATH = $(SRC_F) $(SRC_F)utils/ $(SRC_F)move/ $(SRC_F)draw/
SRC_F = src/
OBJ_F = obj/



.SILENT:
all: $(NAME)

$(NAME): $(MLX_F) $(LIBFT_F) $(MAPS_F) $(OBJ)
	make mlx;
	$(MAKE) -C $(LIBFT_F)
	$(CC) -o $@ $(OBJ) $(MLX_LIBS) $(LIBFLAGS)
	@echo "$(GREEN)$$ASCII_ART\n\n———————————————✣ FDF COMPILED ✣————————————\n$(RE)"

$(OBJ_F)%.o: %.c fdf.h keycode.h Makefile
	mkdir -p $(@D)
	$(CC) $(CC_FLAGS) -o $@ -c $<
	@printf "$(GREEN). $(RE)"

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





#*-------------extra functional-------------
install: $(LIBFT_F) $(MAPS_F) $(MLX_F)

run: $(NAME)
	./$(NAME) extras/pyramide.fdf

jul: $(NAME)
	./$(NAME) maps/julia.fdf


#make mlx
mlx:
	@if [ ! -d "$(MLX_F)" ] || [ ! -f "$(MLX_F)/libmlx.a" ]; then \
		echo "$(GREEN)\nCompiling $(MLX_F) ...$(RE)"; \
		$(MAKE) -C $(MLX_F) > /dev/null 2>&1; \
		echo "$(GREEN)\n$(MLX_F) compiled successfully$(RE)"; \
	fi

#*-------------install (libft from git link, mlx and maps from intra)-------------
$(LIBFT_F):
	if [ ! -d $(LIBFT_F) ]; then \
		echo "$(YELLOW)\nDownloading $(LIBFT_F) ...$(RE)"; \
		git clone $(LIBFT_GIT) $(LIBFT_F); \
	fi

$(MLX_F):
	if [ ! -d $(MLX_F) ]; then \
		echo "$(YELLOW)\n\nDownloading $(MLX_F) ...$(RE)"; \
		curl -sS -o $(MLX_ARCH) $(MLX_URL); \
		tar -xvf $(MLX_ARCH) -C ./ > /dev/null; \
		rm $(MLX_ARCH); \
		mv minilibx* $(MLX_F); \
	fi

$(MAPS_F):
	if	[ ! -d "$(MAPS_F)" ]; then \
			echo "$(YELLOW)\nDownloading $(MAPS_F) ...$(RE)"; \
			curl -sS -o $(MAPS_ARCH) $(MAPS_URL); \
			unzip -qq $(MAPS_ARCH); \
			rm $(MAPS_ARCH); \
			rm -r __MACOSX; \
			mv test_maps $@; \
		fi

.PHONY:	all clean fclean re run uninstall instal mlx






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
