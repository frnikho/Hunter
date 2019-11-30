TESTPATH	=	tests

SRC 		= 	my_compute_factorial_it.c		\
				my_compute_factorial_rec.c 		\
				my_compute_power_it.c			\
				my_compute_power_rec.c 			\
				my_compute_square_root.c 		\
				my_convert_into_integer.c 		\
				my_find_prime_sup.c 				\
				my_getnbr.c 						\
				my_is_prime.c 					\
				my_isalpha.c 					\
				my_islowcase.c 					\
				my_isnum.c 						\
				my_isstrempty.c 					\
				my_isupcase.c 					\
				my_put_nbr.c 					\
				my_putchar.c 					\
				my_putstr.c 						\
				my_revstr.c 						\
				my_show_word_array.c 			\
				my_showmem.c 					\
				my_showstr.c 					\
				my_str_isalpha.c 				\
				my_str_islower.c 				\
				my_str_isnum.c 					\
				my_str_isprintable.c 			\
				my_str_isupper.c 				\
				my_strcapitalize.c 				\
				my_strcat.c 						\
				my_strcmp.c 						\
				my_strcpy.c 						\
				my_strlen.c 						\
				my_strlowcase.c 					\
				my_strncat.c 					\
				my_strncmp.c 					\
				my_strncpy.c 					\
				my_strstr.c 						\
				my_strupcase.c					\
				get_int_length.c

TESTS		=	$(TESTPATH)/test_my_printf.c

OBJ			=	$(SRC:%.c=%.o)
OBJTESTS	=	$(TESTS:%.c=%.o)

NAME		=	libmy.a
TNAME		=	unit_tests

INCLUDE		=	-I include/
CFLAGS		=	$(INCLUDE)
TFLAGS		=	-lcriterion

all:			$(NAME)

$(NAME):		$(OBJ)
				ar rcs $(NAME) $(OBJ)
clean:
				rm -rf $(OBJ) $(OBJTESTS)
fclean:			clean
				rm -rf $(NAME) $(TNAME)
re:				fclean all
test_run:		$(OBJTESTS) $(OBJ)
				gcc -o $(TNAME)	$(OBJTESTS) $(OBJ) $(TFLAGS)
				./unit_tests