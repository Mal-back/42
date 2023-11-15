FILES = srcs/ft_atoi.c	srcs/ft_isalpha.c	srcs/ft_itoa.c	srcs/ft_memmove.c	srcs/ft_putnbr_fd.c srcs/ft_strdup.c	srcs/ft_strlcpy.c	srcs/ft_strnstr.c	srcs/ft_tolower.c	srcs/ft_bzero.c	srcs/ft_isascii.c	srcs/ft_memchr.c	srcs/ft_memset.c	srcs/ft_putstr_fd.c	srcs/ft_striteri.c	srcs/ft_strlen.c	srcs/ft_strrchr.c	srcs/ft_toupper.c	srcs/ft_calloc.c	srcs/ft_isdigit.c	srcs/ft_memcmp.c	srcs/ft_putchar_fd.c	srcs/ft_split.c	srcs/ft_strjoin.c	srcs/ft_strmapi.c	srcs/ft_strtrim.c	srcs/ft_isalnum.c	srcs/ft_isprint.c	srcs/ft_memcpy.c	srcs/ft_putendl_fd.c	srcs/ft_strchr.c	srcs/ft_strlcat.c	srcs/ft_strncmp.c	srcs/ft_substr.c srcs/ft_lstnew_bonus.c srcs/ft_lstadd_front_bonus.c srcs/ft_lstsize_bonus.c srcs/ft_lstlast_bonus.c srcs/ft_lstadd_back_bonus.c srcs/ft_lstdelone_bonus.c srcs/ft_lstclear_bonus.c srcs/ft_lstiter_bonus.c srcs/ft_lstmap_bonus.c 

BONUS_FILES = srcs/def_padding_bonus.c srcs/driver_bonus.c \
srcs/fill_padding_bonus.c srcs/int_handling_bonus.c srcs/itoa_base_bonus.c \
srcs/itoa_ptr_bonus.c srcs/lchexa_handling_bonus.c srcs/ptr_handling_bonus.c \
srcs/str_handling_bonus.c srcs/uchexa_handling_bonus.c \
srcs/unsgnd_int_handling_bonus.c srcs/char_handling_bonus.c \
srcs/malloc_secure_bonus.c

OBJECTS = ${FILES:.c=.o}

BONUS_OBJ = ${BONUS_FILES:.c=.o}

CC = cc -Wall -Wextra -Werror

NAME = libftprintf.a

all : ${NAME}	

${NAME} : ${OBJECTS} 
	ar rcs $@ $^

%.o:%.c
	
	${CC} -c $< -o $@ -I includes/ -g3

bonus : ${BONUS_OBJ} ${OBJECTS}
	ar rcs ${NAME} $^
clean :
	rm -f ${OBJECTS} ${BONUS_OBJ}

fclean : 		clean
	rm -f ${NAME} ${BONUS_OBJ}

re : fclean all

.PHONY : all re fclean clean
