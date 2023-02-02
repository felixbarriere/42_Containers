NAME = Containers

SRCS = 	main.cpp \
		srcs_main/vec_constructors.cpp \
		srcs_main/vec_assign.cpp \
		srcs_main/vec_insert.cpp \
		srcs_main/vec_modifiers.cpp \
		srcs_main/vec_pushpop.cpp \
		srcs_main/vec_resize.cpp \
		srcs_main/map_size.cpp \

OBJS_PATH = objects/

OBJS = ${addprefix ${OBJS_PATH}, ${SRCS:.cpp=.o}}

CC = c++

CFLAGS = -Wall -Werror -Wextra -DLIB=ft -std=c++98 -MMD -MP

all:		$(NAME)

$(NAME):	$(OBJS)
		${CC} $(OBJS) -o $(NAME)


-include $(OBJS_PATH)/*.d

${OBJS_PATH}%.o: ${SRCS_PATH}%.cpp
		@mkdir -p $(@D)
		${CC} ${CFLAGS} -c $< -o $@ ${INCLUDES}

clean:
		rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f -r ${OBJS_PATH}

re: fclean all

.PHONY: all clean fclean re