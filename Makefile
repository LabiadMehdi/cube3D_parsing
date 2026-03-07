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
SRCS += $(SRC_DIR)/checker/path.c \
		$(SRC_DIR)/checker/file_content.c \
		$(SRC_DIR)/filler/data_filler.c \
		$(SRC_DIR)/filler/check_parsed.c \
		$(SRC_DIR)/filler/parse_colors.c \
		$(SRC_DIR)/filler/parse_elements.c \
		$(SRC_DIR)/filler/parse_map.c \
		$(SRC_DIR)/filler/parse_textures.c \
		$(SRC_DIR)/filler/utils.c

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
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re