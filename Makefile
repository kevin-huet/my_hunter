##
## EPITECH PROJECT, 2018
## f
## File description:
## f
##

NAME	= my_hunter

CC	= gcc

RM	= rm -f \
	rm -f sources/*.o

SRCS	= ./game/button.c \
	./game/sound.c \
	./game/option.c \
	./game/print_game.c \
	./game/pause.c \
	./game/my_getnbr.c \
        ./game/game.c \
	./game/game_over.c \
	./game/scoreboard.c \
        ./game/initialise.c \
	./game/event.c \
	./game/text.c \
        ./game/key.c \
        ./game/main.c \
        ./game/menu.c \
        ./game/setwindow.c \
        ./game/texture.c \
	./game/destroy.c \
	./game/my_putstr.c

OBJS	= $(SRCS:.c=.o)

LIB = -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LIB)
	 mv game/*.o sources/
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all
