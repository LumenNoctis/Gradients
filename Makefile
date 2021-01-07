NAME = gradient
FLAGS = -Wall -Wextra -Werror

LERP_FILES = 		\
		lerp		\

SDT_FILES = 		\
		SDT_init	\
		SDT_render	\
		SDT			\


INCL = -I incl/
LIB = -L ~/.brew/lib -l SDL2 -l sdl2_image


SRC_DIR = src/
BIN_DIR = bin/

FILENAMES = 							\
	$(addprefix Lerp/, $(LERP_FILES))	\
	$(addprefix SDT/, $(SDT_FILES))		\
	gradient							\
	main								\
	utils								\


SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILENAMES)))
OBJS = $(addprefix $(BIN_DIR), $(addsuffix .o, $(FILENAMES)))


all: $(NAME)

$(NAME): $(BIN_DIR) $(OBJS)
	gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(SDL_LIB)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)%.o: %.c
	mkdir -p $(BIN_DIR)$(dir $<)
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
