PATHSRC		=		src

NAME		=		my_hunter

INCLUDE		=		-I include
SRC			=		$(PATHSRC)/input_manager.c				\
					$(PATHSRC)/object/background.c					\
					$(PATHSRC)/object/duck.c				\
					$(PATHSRC)/object/game.c				\
					$(PATHSRC)/object/player.c				\
					$(PATHSRC)/text/menu_text.c				\
					$(PATHSRC)/text/title_text.c			\
					$(PATHSRC)/menu/play_menu.c				\
					$(PATHSRC)/menu/pause_menu.c			\
					$(PATHSRC)/menu/score_menu.c			\
					$(PATHSRC)/levels/level_1.c

MAIN		=		$(PATHSRC)/main.c

CFLAGS		=		$(INCLUDE)

LIB			=		-L lib/ -lmy
CLIB		=		-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

OBJ			=		$(SRC:%.c=%.o)
OBJMAIN		=		$(MAIN:%.c=%.o)

$(NAME):		$(OBJ) $(OBJMAIN)
				gcc -o $(NAME) $(OBJ) $(OBJMAIN) $(INCLUDE) $(LIB) $(CLIB)

all:			$(NAME)
clean:
				$(RM) -rf $(OBJ) $(OBJMAIN)
fclean:			clean
				$(RM) -rf $(NAME)
re:				fclean all