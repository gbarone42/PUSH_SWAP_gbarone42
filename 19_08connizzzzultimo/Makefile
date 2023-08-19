SRCS =	main.c \
	dup_dig.c \
	error.c \
	error2.c \
	rdx_srt.c \
	func.c \
	func2.c	\
	sort235.c	\
	frees.c	\
	check_ar.c	\
	stck_op.c \
	check_sorted.c	\
	check_at.c \
	list_creation.c \
	list_arch.c


NAME = push_swap

OBJS = $(SRCS:.c=.o) 

CC = gcc -g

CC_FLAGS = -Wall -Werror -Wextra

GREEN='\033[32m'
CORSIVO='\033[3m'
GRAY='\033[2;37m'

.c.o :
	@echo $(CORSIVO) $(GRAY)"                                                                      -    Compiling    - "
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo $(CORSIVO) $(GREEN)"                                                                                                          -   Welcome  -  PUSH_SWAP2   -   gbarone   -   42 \n"$
	@$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME)      

all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all