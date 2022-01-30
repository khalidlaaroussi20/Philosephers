NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra
SRCS =ft_strjoin.c ft_strlcat.c  ft_strlcpy.c ft_atoi.c ft_strlen.c ft_bzero.c ft_memchr.c ft_strmapi.c \
ft_calloc.c ft_memcmp.c ft_strncmp.c ft_isalnum.c ft_memcpy.c ft_strnstr.c ft_isalpha.c ft_memmove.c ft_strrchr.c  \
ft_isascii.c ft_memset.c ft_strtrim.c ft_isdigit.c ft_putchar_fd.c ft_substr.c ft_isprint.c ft_putendl_fd.c ft_tolower.c \
ft_itoa.c ft_putnbr_fd.c ft_toupper.c ft_putstr_fd.c  ft_split.c ft_strchr.c  ft_strdup.c ft_striteri.c
BONUS = ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
ft_lstsize_bonus.c ft_lstnew_bonus.c ft_lstmap_bonus.c ft_lstlast_bonus.c
BONUSOBJCTFILE = $(BONUS:.c=.o)
SRCSO = $(SRCS:.c=.o)


all:$(NAME)
$(NAME):$(SRCSO)
	ar rcs $(NAME) $(SRCSO) 
clean:
	rm -f $(SRCSO)
	rm -f $(BONUSOBJCTFILE)
fclean:clean
	rm -f $(NAME)
bonus:$(BONUSOBJCTFILE)
	ar rcs $(NAME) $(BONUSOBJCTFILE)
re:fclean all bonus
