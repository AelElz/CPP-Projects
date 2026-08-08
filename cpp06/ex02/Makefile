NAME		= identify

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
INCS		= -Iincludes
RM			= rm -f

SRCS		= srcs/main.cpp \
			  srcs/Base.cpp \
			  srcs/A.cpp \
			  srcs/B.cpp \
			  srcs/C.cpp

OBJS		= $(SRCS:.cpp=.o)

HEADERS		= includes/Base.hpp \
			  includes/A.hpp \
			  includes/B.hpp \
			  includes/C.hpp

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o:		%.cpp $(HEADERS)
			$(CXX) $(CXXFLAGS) $(INCS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
