CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Название исполняемого файла
TARGET = pipex

# Путь до директории с библиотекой Libft
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Исходные файлы
SRC = path.c pipex.c errs.c

# Объектные файлы
OBJ = $(SRC:.c=.o)

# Правило для сборки исполняемого файла
$(TARGET): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(TARGET)

# Правило для сборки объектных файлов
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Правило для сборки библиотеки Libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

.PHONY: clean fclean re libft

all:
	$(TARGET)

# Правило для очистки объектных файлов
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

# Правило для очистки всего
fclean: clean
	rm -f $(TARGET)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Правило для пересборки всего
re: fclean all

# Правило для сборки только библиотеки Libft
libft:
	$(MAKE) -C $(LIBFT_DIR)
