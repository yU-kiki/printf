NAME = libftprintf.a

CC = gcc

INCLUDE = -I ./includes/

CFLAGS = -Wall -Wextra -Werror $(INCLUDE)

RM = rm -rf 

SRCDIR = ./srcs/

SRCNAME = ft_printf.c\
		  set_info.c\
		  info_case_c.c\
			info_case_s.c\
			info_case_p.c\
			info_case_di.c\
			info_case_u.c\
			info_case_x.c\
		  ft_putchar.c\
			ft_putstr.c\
			ft_strlen.c\
		  ft_is_strchr.c\
			ft_strdup.c\
			ft_strndup.c\
			ft_strjoin.c\
			ft_itoa.c\
			ft_itoa_us.c\
			ft_itoa_hex.c\
			get_digits.c\
			get_digits_base.c\
			ft_atoi.c\
			freeturn.c

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
