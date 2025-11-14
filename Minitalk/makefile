CLIENT = client
SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCE_DIR = ./src
OBJECT_DIR = obj
PRINTF_DIR = ./Ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

SRCS_S := server.c  #$(SOURCE_DIR)/)
OBJS_S := server.o #$(SRCS:$(SOURCE_DIR)/%.c=$(OBJECT_DIR)/%.o) 

SRCS_C := client.c ft_aux.c #$(SOURCE_DIR)/)
OBJS_C := client.o ft_aux.o #$(SRCS:$(SOURCE_DIR)/%.c=$(OBJECT_DIR)/%.o) 

all: $(PRINTF_LIB) $(CLIENT) $(SERVER)

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c
	@mkdir -p $(OBJECT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF_LIB): 
	make -C $(PRINTF_DIR)

$(CLIENT): $(PRINTF_LIB) $(OBJECT_DIR)/client.o $(OBJECT_DIR)/ft_aux.o 
	$(CC) $(CFLAGS) $(OBJECT_DIR)/client.o $(OBJECT_DIR)/ft_aux.o -o $@ $(PRINTF_LIB)

$(SERVER): $(PRINTF_LIB) $(OBJECT_DIR)/server.o
	$(CC) $(CFLAGS) $(OBJECT_DIR)/server.o -o $@ $(PRINTF_LIB)

clean:
	rm -rf $(OBJECT_DIR)
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(CLIENT)
	rm -f $(SERVER)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re