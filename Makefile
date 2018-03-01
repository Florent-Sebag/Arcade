##
## Makefile for h in /home/sebag/Bureau/TEK2/cpp_arcade/pacman/
##
## Made by Florent Sebag
## Login   <florent.sebag@epitech.eu>
##
## Started on  Fri Mar 24 17:01:24 2017 Florent Sebag
## Last update Sun Apr  9 23:49:03 2017 Florent Sebag
##

LDFLAGS =

CC	=	g++

CPPFLAGS	=	-W -Wall -Wextra -Werror -I./include -g3 -std=c++14 -L./lib -L./games -g3 -lmenu -I./Menu/include $(NCURSES_FLAGS) $(SFML_FLAGS)

LIBFLAGS = -c -W -Wall -Wextra -Werror -fpic -std=c++14 -I./../../include

CLIBFLAGS =  -shared

SRC	= src/main.cpp \
			src/load_lib.cpp \
						./Menu/src/menu.cpp \
					 ./Menu/src/menu_ncurses.cpp \
					 ./Menu/src/menu_sfml.cpp \

OBJ	=	$(SRC:.cpp=.o)

NAME	=	arcade



LIB_PACMAN = lib_arcade_pacman.so

PACMAN_SRC = Pacman.cpp \
					Fantom.cpp \
					Character.cpp \
					ia.cpp \
					protocole_pacman.cpp

PACMAN_FLAGS = -g3

OBJ_PACMAN	=	$(PACMAN_SRC:.cpp=.o)



LIB_SNAKE = lib_arcade_snake.so

SNAKE_SRC = direction.cpp \
						 error_move.cpp \
						 move.cpp \
						 snake.cpp \
						 protocole_snake.cpp
						#  map.cpp

SNAKE_FLAGS = -g3

OBJ_SNAKE	=	$(SNAKE_SRC:.cpp=.o)



LIB_NCURSES = lib_arcade_ncurses.so

GRAPHIC_NCURSES_SRC = Gui.cpp

NCURSES_FLAGS = -lncurses

OBJ_NCURSES	=	$(GRAPHIC_NCURSES_SRC:.cpp=.o)



LIB_SFML = lib_arcade_sfml.so

GRAPHIC_SFML_SRC = lib_sf.cpp

SFML_FLAGS = -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system -g3

OBJ_SFML	=	$(GRAPHIC_SFML_SRC:.cpp=.o)



LIB_OGL = lib_arcade_opengl.so

GRAPHIC_OGL_SRC = lib_opengl.cpp

OGL_FLAGS = $(SFML_FLAGS) -lglfw3 -lrt -lm -lXrandr -lXrender -lXi -lGL -lm -lpthread -ldl -ldrm -lXdamage -lXfixes -lX11-xcb -lxcb-glx -lxcb-dri2 -lXxf86vm -lXext -lX11 -lxcb -lXau -lXdmcp  -lGLU

OBJ_OGL	=	$(GRAPHIC_OGL_SRC:.cpp=.o)



ALL_LIB	=	-l_arcade_pacman -l_arcade_snake -l_arcade_ncurses -l_arcade_sfml -l_arcade_opengl



MENU_SRC = ./src/menu.cpp \
					 ./src/menu_ncurses.cpp \
					 ./src/menu_opengl.cpp \
					 ./src/menu_sfml.cpp

MENU_FLAGS =  -lmenu -I./include $(NCURSES_FLAGS) $(OGL_FLAGS)

OBJ_MENU = $(MENU_SRC:.cpp=.o)

all:		$(NAME)

libpacman:
		cd Game/Pacman_src && $(CC) $(LIBFLAGS) $(PACMAN_SRC)
		cd Game/Pacman_src && $(CC) $(CLIBFLAGS) $(OBJ_PACMAN) -o ./../../games/$(LIB_PACMAN)

libsnake:
		cd Game/Snake_src && $(CC) $(LIBFLAGS) $(SNAKE_SRC)
		cd Game/Snake_src && $(CC) $(CLIBFLAGS) $(OBJ_SNAKE) -o ./../../games/$(LIB_SNAKE)

libncurses:
		cd Graphic/ncurses && $(CC) $(LIBFLAGS) $(GRAPHIC_NCURSES_SRC) $(NCURSES_FLAGS)
		cd Graphic/ncurses && $(CC) $(CLIBFLAGS) $(OBJ_NCURSES) -o ./../../lib/$(LIB_NCURSES) $(NCURSES_FLAGS)

libsfml:
		cd Graphic/sfml && $(CC) $(LIBFLAGS) $(GRAPHIC_SFML_SRC) $(SFML_FLAGS)
		cd Graphic/sfml && $(CC) $(CLIBFLAGS) $(OBJ_SFML) -o ./../../lib/$(LIB_SFML) $(SFML_FLAGS)

libogl:
		cd Graphic/opengl && $(CC) $(LIBFLAGS) $(GRAPHIC_OGL_SRC) $(OGL_FLAGS)
		cd Graphic/opengl && $(CC) $(CLIBFLAGS) $(OBJ_OGL) -o ./../../lib/$(LIB_OGL) $(OGL_FLAGS)

Game:	libpacman libsnake libncurses libsfml libogl $(OBJ)
		$(CC) $(OBJ) -o $(NAME) -L./lib -ldl $(ALL_LIB) $(CPPFLAGS)

$(NAME): libpacman libsnake

clean:
		rm -f $(OBJ)
		cd Game/Pacman_src && rm -f $(OBJ_PACMAN)
		cd Game/Snake_src && rm -f $(OBJ_SNAKE)
		cd Graphic/ncurses && rm -f $(OBJ_NCURSES)
		cd Graphic/sfml && rm -f $(OBJ_SFML)
		cd Graphic/opengl && rm -f $(OBJ_OGL)

fclean:		clean
		rm -f $(NAME)
		cd lib && rm -f $(LIB_NCURSES) $(LIB_SFML) $(LIB_OGL)
		cd games && rm -f $(LIB_PACMAN) $(LIB_SNAKE)

re:		fclean all
