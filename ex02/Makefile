NAME	:=  PmergeMe

CC		:=	c++
CPPFLAGS:=	-Wall -Wextra -Werror #-fsanitize=address
CPPFLAG	:=	-std=c++98

SRCS	:=	main.cpp

OBJS	:=	$(SRCS:.cpp=.o)

%.o:%.cpp
	$(CC) $(CPPFLAGS) $(CPPFLAG) -c $< -o $@

all:		$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) $(CPPFLAG) -o $@

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
