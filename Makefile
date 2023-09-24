# *********************************************************************************************************** #
#                                                                                                             #
#                                                               :::::::::: ::::::::   :::::::: :::::::::::    #
#    Makefile                                                  :+:       :+:    :+: :+:    :+:    :+:         #
#                                                             +:+       +:+        +:+           +:+          #
#    By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+           #
#                                                           +#+              +#+ +#+   +#+#    +#+            #
#    Created: 2023/09/24 17:47:50 by camillia              #+#       #+#    #+# #+#    #+#    #+#             #
#    Updated: 2023/09/24 17:47:50 by camillia             ########## ########   ######## ###########          #
#                                                                                                             #
# *********************************************************************************************************** #


CC	=	gcc

CFLAGS	=	-o $(NAME) -g3 -Wall -Wextra

LIBS	=	-lcsfml-audio -lcsfml-graphics -lcsfml-window -lcsfml-system -lpthread

SRC	=	$(wildcard *.c src/*.c src/utils/*.c)

OBJ	=	$(patsubst %.c, %.o, $(SRC))

NAME	=	Doomdepthc

all:
	make $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(LIBS)
	make clean

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean	all
