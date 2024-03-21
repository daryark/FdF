GREEN = \033[0;32m
MAGENTA	= \033[0;35m
YELLOW = \033[0;33m
RESET_COLOR = \033[0m

SRCS_LIB = 	ft_calloc.c		ft_isdigit.c	ft_memcmp.c		ft_putchar_fd.c	ft_split.c  \
		ft_strjoin.c	ft_strmapi.c	ft_strtrim.c	ft_isalnum.c	ft_toupper.c  \
		ft_isprint.c	ft_memcpy.c		ft_putendl_fd.c	ft_strchr.c		ft_strlcat.c  \
		ft_strncmp.c	ft_substr.c		ft_atoi.c		ft_isalpha.c	ft_itoa.c  \
		ft_putnbr_fd.c	ft_strdup.c		ft_strlcpy.c	ft_strnstr.c	ft_tolower.c  \
		ft_bzero.c		ft_isascii.c	ft_memchr.c		ft_memset.c		ft_putstr_fd.c  \
		ft_striteri.c	ft_strlen.c		ft_strrchr.c	ft_memmove.c 	ft_atol.c \
		ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c	ft_lstclear.c		ft_lstiter.c	ft_lstmap.c \
		ft_abs.c
SRCS_PRINTF = ft_printf.c \
		struct.c	clean_reset.c\
		ft_format_checker.c \
		ft_print_digits.c	\
		ft_print_p.c \
		ft_print_c.c	ft_print_d_i.c \
		ft_print_s.c ft_print_u_x.c
SRCS_GNL = get_next_line_bonus.c get_next_line_utils_bonus.c
#vpath - predefined variable;
#In a Makefile, the VPATH variable serves as a directive for make to search for prerequisite files (such as source files) in additional directories
VPATH = $(SRC_F)lib \
		$(SRC_F)get_next_line \
		$(SRC_F)ft_printf \
			$(SRC_F)ft_printf/utils $(SRC_F)ft_printf/check $(SRC_F)ft_printf/print \

SRC_F = src/
OBJ_F = obj/

OBJS = $(SRCS_LIB:.c=.o)
OBJS += $(SRCS_PRINTF:.c=.o)
OBJS += $(SRCS_GNL:.c=.o)
OBJ_P = $(addprefix $(OBJ_F), $(OBJS))

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror $(DEPFLAGS) -fPIC
DEPFLAGS = -MP -MMD



#silent makes all the command execute on the background event without @ sign
.SILENT: 
all: $(NAME)

$(NAME): $(OBJ_P)
	@ar -rcs $@ $(OBJ_P)
	@echo "$(MAGENTA)\n \
	\n✢ libft \
	\n✢ ft_printf \
	\n✢ get next line \
	\n$(GREEN)\n—————————————✣ LIBFT COMPILED ✣—————————————\n$(RESET_COLOR)"

$(OBJ_F)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GREEN). $(RESET_COLOR)"

clean:
	@rm -rf $(OBJ_F)
	@echo "$(YELLOW)\n☓  CLEAN LIBFT$(RESET_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)☓☓ FCLEAN LIBFT\n$(RESET_COLOR)"

re: fclean all

.PHONY: all clean fclean re bonus

#$@ means the command which starts this rool, the target file for it - $(NAME)
#$^ means all the dependencies for that rool - $(OBJ_P)
#$< means to do for each dependency separately, with the corresponing src file

# .PHONY: means that these name of the commands need to be executed even if files with the same names happen to exist in the directory
