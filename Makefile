# ==== cube3d_parser Makefile ====
NAME = parser
CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

# Dossier pour les fichiers objets
OBJ_DIR = obj

# Répertoires
SRC_DIR = src

# Fichiers principaux
SRCS = main.c

# Fichiers d'exécution
SRCS += $(SRC_DIR)/checker/path.c

# Les .o gardent la même structure de dossiers dans obj/
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Créer les sous-dossiers nécessaires dans obj/
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	@echo "🧩 Linking $(NAME)..."
	@$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "✅ Build complete!"

clean:
	@echo "🧹 Cleaning object files..."
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "🗑  Removing $(NAME)..."
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re