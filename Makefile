NAME = libftprintf.a

CC = gcc

INCLUDE = -I ./includes/

CFLAGS = -Wall -Wextra -Werror $(INCLUDE)

RM = rm -rf 

SRCDIR = ./srcs/

SRCNAME = ft_printf.c\
		  set_info.c\
		  info_case_c.c\
		  ft_putchar.c\
		  ft_is_strchr.c\
			ft_atoi.c

SRCS = $(addprefix $(SRCDIR),$(SRCNAME))

OBJS = $(SRCS:.c=.o)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

all:		$(NAME)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

main:			
			gcc -Wall -Wextra -Werror main.c libftprintf.a
			./a.out

.RHONY:		all clean fclean re
