OUT = harl

SRC = Harl.cpp main.cpp
SRC_OBJS = $(SRC:.cpp=.o)
FLAGS = -Wall -Wextra -Werror -g -std=c++98
CPP = c++

all: $(OUT)

$(OUT): $(SRC_OBJS)
	$(CPP) $(FLAGS) $(SRC_OBJS) -o $(OUT)

$(SRC_OBJS): %.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(SRC_OBJS)

fclean: clean
	rm -f $(OUT)

re: fclean all
