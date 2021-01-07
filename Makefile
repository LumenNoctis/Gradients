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


O_DIR = objs/

FILENAMES = 							\
	$(addprefix Lerp/, $(LERP_FILES))	\
	$(addprefix SDT/, $(SDT_FILES))		\
	gradient							\
	main								\
	utils								\


SRCS = $(addprefix srcs/, $(addsuffix .c, $(FILENAMES)))
OBJS = $(addprefix objs/, $(addsuffix .o, $(FILENAMES)))

$(SRCS): %.c
	@echo $<

# $()%.o: %.c
# 	echo $(SRCS)
# 	@/bin/mkdir -p $(O_DIR)$(dir $<)
# 	gcc $(FLAGS) -c $(INCL) $< -o $@

all : $(SRCS)

# $(NAME):$(OBJS)
# 	gcc $(FLAGS) $(INCL) $(LIB) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)
	rm -rf $(O_DIR)

fclean : clean
	rm -rf $(NAME)

push : clean
	git add .
	git commit -m "$(MSG)"
	git push origin master

re : fclean all

.PHONY : $(NAME) clean fclean push re
