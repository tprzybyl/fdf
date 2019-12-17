# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 11:36:22 by tprzybyl     #+#   ##    ##    #+#        #
#    Updated: 2018/12/10 17:28:36 by tprzybyl    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror

SRC = ft_drawline.c main.c ft_entryfile.c ft_images.c\
      ft_error_func.c ft_rendering.c ft_defs.c ft_biomes.c\
      ft_biomebis.c ft_gradient.c ft_model.c ft_printcommands.c\

OBJ = $(subst .c,.o,$(SRC))

LIGHT_PINK = \033[0;38;5;200m

PINK = \033[0;38;5;198m

DARK_BLUE = \033[0;38;5;110m

GREEN = \033[0;38;5;111m

LIGHT_GREEN = \033[0;38;5;121m

FLASH_GREEN = \033[33;32m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(DARK_BLUE)\nFichiers de "$(NAME)" compilés\n"
	@echo "$(LIGHT_GREEN)Compilation des Librairies : "
	@make -C libft/
	@make -C minilibx/
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -I libft/includes -L libft/ -lft -L minilibx/ -lmlx -framework OpenGL -framework AppKit
	@echo "$(FLASH_GREEN)Programme "$(NAME)" compilé et prêt à l'usage !\n"

%.o: %.c fdf.h
	@gcc $(FLAGS) -I libft/includes -o $@ -c $<
	@echo "$(DARK_BLUE).\c"

clean:
	@rm -rf $(OBJ)
	@make -C libft/ clean
	@echo "$(LIGHT_PINK)Suppression des .o de "$(NAME)"\n"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(PINK)Suppression des .o de Libft \n"
	@make -C libft/ fclean
	@echo "$(PINK)Suppression des .o de Minilibx \n"
	@make -C minilibx/ fclean
	@echo "$(PINK)Suppression de" $(NAME)"\n"

re: fclean all
