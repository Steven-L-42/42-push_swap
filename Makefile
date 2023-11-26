NAME				=	push_swap

FLAGS				=	-Wall -Wextra -Werror

#COMPILE				=	cc -fsanitize=address -fno-omit-frame-pointer

COMPILE				=	cc

COLOR_RESET			=	\033[0m
COLOR_CYAN			=	\033[36m
COLOR_GREEN			=	\033[32m
COLOR_RED			=	\033[31m

SRCS_FOLDER			=	srcs/

INCLUDE				=	libft/

SRCS				=	main.c check_input.c median.c rotate.c sorting.c push.c sort_three.c sort_five.c swap.c utils.c

OBJS				=	$(addprefix $(SRCS_FOLDER),$(SRCS:.c=.o))

$(NAME): 			$(INCLUDE) $(OBJS)
					@cd $(INCLUDE) && make
					@$(COMPILE) $(FLAGS) -o $(NAME) $(OBJS) -L$(INCLUDE) -lft
					@echo "$(COLOR_CYAN)Kompilierung abgeschlossen: $(NAME)$(COLOR_RESET)"

%.o: %.c
					@$(COMPILE) $(FLAGS) -c $< -o $@
					@echo "$(COLOR_GREEN)Kompilierung abgeschlossen: $@$(COLOR_RESET)"

all: 				$(NAME)

clean:
					@echo "$(COLOR_RED)Cleanup Push_Swap.$(COLOR_RESET)"
					@rm -f $(OBJS)
					@echo "$(COLOR_RED)Cleanup Libft.$(COLOR_RESET)"
					@cd $(INCLUDE) && make clean
					@echo "$(COLOR_GREEN)Cleanup completed.$(COLOR_RESET)"

fclean: 			clean
					@echo "$(COLOR_RED)Removal Push_Swap.$(COLOR_RESET)"
					@rm -f $(NAME)
					@echo "$(COLOR_RED)Removal Libft.$(COLOR_RESET)"
					@cd $(INCLUDE) && make fclean
					@echo "$(COLOR_GREEN)Removal completed.$(COLOR_RESET)"

re: 				fclean all