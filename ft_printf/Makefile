FILES = srcs/def_padding_bonus.c srcs/driver_bonus.c \
srcs/fill_padding_bonus.c srcs/int_handling_bonus.c srcs/itoa_base_bonus.c \
srcs/itoa_ptr_bonus.c srcs/lchexa_handling_bonus.c srcs/ptr_handling_bonus.c \
srcs/str_handling_bonus.c srcs/uchexa_handling_bonus.c \
srcs/unsgnd_int_handling_bonus.c srcs/char_handling_bonus.c \
srcs/malloc_secure_bonus.c srcs/char_padding_bonus.c \

LIB_FILES = libft/ft_atoi.c libft/ft_isalpha.c  libft/ft_itoa.c libft/ft_memmove.c\
libft/ft_putnbr_fd.c libft/ft_strdup.c libft/ft_strlcpy.c  libft/ft_strnstr.c\
libft/ft_tolower.c  libft/ft_bzero.c libft/ft_isascii.c  libft/ft_memchr.c\
libft/ft_memset.c libft/ft_putstr_fd.c  libft/ft_striteri.c libft/ft_strlen.c\
libft/ft_strrchr.c  libft/ft_toupper.c  libft/ft_calloc.c libft/ft_isdigit.c \
libft/ft_memcmp.c libft/ft_putchar_fd.c libft/ft_split.c  libft/ft_strjoin.c\
libft/ft_strmapi.c libft/ft_strtrim.c  libft/ft_isalnum.c  libft/ft_isprint.c\
libft/ft_memcpy.c libft/ft_putendl_fd.c libft/ft_strchr.c libft/ft_strlcat.c\
libft/ft_strncmp.c  libft/ft_substr.c libft/ft_lstnew_bonus.c \
libft/ft_lstadd_front_bonus.c libft/ft_lstsize_bonus.c libft/ft_lstlast_bonus.c \
libft/ft_lstadd_back_bonus.c libft/ft_lstdelone_bonus.c libft/ft_lstclear_bonus.c \
libft/ft_lstiter_bonus.c libft/ft_lstmap_bonus.c\

OBJECTS = ${FILES:.c=.o}

LIB_OBJ = ${LIB_FILES:.c=.o}

CC = cc -Wall -Wextra -Werror

NAME = libftprintf.a

SUBDIR = libft/

all : ${NAME}

${NAME} : ${OBJECTS} ${LIB_OBJ}	
	make -obj -C ${SUBDIR}
	ar rcs $@ $^

%.o:%.c
	${CC} -c $< -o $@ -I includes/

bonus : all

clean :
	make clean -C ${SUBDIR}
	rm -f ${OBJECTS}

fclean : 		clean
	rm -f ${NAME}

re : fclean all

.PHONY : all re fclean clean bonus
