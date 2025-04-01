
## Directories
OBJDIR  := obj
PRINTF_DIR := ft_printf   

# Library
PRINTF_LIBA    := $(PRINTF_DIR)/libftprintf.a  
PRINTF_LIBINC  := -I$(PRINTF_DIR) 

# Compiler
CC      := cc
CFLAGS  := -Wall -Wextra -Werror

# Executable
NAME    := push_swap

# Source and Object Files
SRCS := src/0_main.c src/1_createstack.c src/2_sort_big.c \
        src/3_sort_few.c src/push_to_a.c src/push_to_b.c \
        src/utils_index.c src/utils_input.c src/utils_list.c \
        src/utils_operations.c src/utils_sort.c \
        src/z_free_functions.c src/z_split.c
OBJS    := $(SRCS:src/%.c=$(OBJDIR)/%.o)

# Rules
all: $(PRINTF_LIBA) $(NAME)

$(NAME): $(OBJS) $(PRINTF_LIBA)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIBINC) -L$(PRINTF_DIR) -lftprintf -o $(NAME)

# Ensures object files are compiled into obj/.
$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Creates the obj directory if it doesn't exist.
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Build ft_printf static library
$(PRINTF_LIBA):
	@make -C $(PRINTF_DIR)

clean:
	@rm -rf $(OBJDIR) 
	@make -C $(PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re