
## Directories
SRCDIR  := src
OBJDIR  := obj
PRINTF_DIR := ft_printf   # Directory containing ft_printf implementation

# Library
PRINTF_LIBA    := $(PRINTF_DIR)/libftprintf.a  # Assuming ft_printf is built into a static library
PRINTF_LIBINC  := -I$(PRINTF_DIR)  # Include directory for ft_printf headers

# Compiler
CC      := cc
CFLAGS  := -Wall -Wextra -Werror

# Executable
NAME    := push_swap

# Source and Object Files
SRCS    := $(wildcard $(SRCDIR)/*.c) 
OBJS    := $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Rules
all: $(PRINTF_LIBA) $(NAME)

$(NAME): $(OBJS) $(PRINTF_LIBA)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIBINC) -L$(PRINTF_DIR) -lftprintf -o $(NAME)

# Ensures object files are compiled into obj/.
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
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