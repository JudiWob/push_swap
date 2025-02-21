
# Directories
SRCDIR  := src
OBJDIR  := obj
LIBDIR  := libft

# Library
LIBNAME := ft
LIBA    := $(LIBDIR)/lib$(LIBNAME).a
#Hey, also check the lib/ folder when looking for header files.
LIBINC  := -I$(LIBDIR)
#where to find the compiled library and how to link it.
LIBLINK := -L$(LIBDIR) -l$(LIBNAME)  # Link with libft

# Compiler
CC      := gcc
CFLAGS  := -Wall -Wextra -Werror

# Executable
NAME    := pushswap

# Source and Object Files
SRCS    := $(wildcard $(SRCDIR)/*.c) 
#OBJS    := $(SRCS:.c=.o)
OBJS := $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Rules
all: $(LIBA) $(NAME)

$(NAME): $(OBJS) $(LIBA)
	$(CC) $(CFLAGS) $(OBJS) $(LIBLINK) -o $(NAME)

#Ensures object files are compiled into obj/.
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

#Creates the obj directory if it doesn't exist.
$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIBA):
	@make -C $(LIBDIR)
	
clean:
	@rm -rf $(OBJDIR) 
	@make -C $(LIBDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re