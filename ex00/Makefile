CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
EXE = btc
SRCS = main.cpp	\
		BitcoinExchange.cpp
OBJS_DIR = .objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS)

$(OBJS_DIR)%.o: %.cpp BitcoinExchange.hpp
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(EXE)

re: fclean all

.PHONY: all clean fclean re
