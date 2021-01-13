NAME = gradient
FLAGS =

LERP_FILES = 		\
		gauss		\
		lerp		\

SDT_FILES = 		\
		SDT_init	\
		SDT			\
		utils		\

INCLUDES = -I incl/ -I ~/.brew/include/
LIB = -L ~/.brew/lib -l SDL2 -l sdl2_image


SRC_DIR = srcs/
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

$(NAME):
	gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(SRCS) $(LIB)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)%.o: %.c
	mkdir -p $(BIN_DIR)$(dir $<)
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@

run: re
	./$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
