OUT = ex02
SRC = Account.cpp tests.cpp
SRC_OBJS = $(SRC:.cpp=.o)
FLAGS = -Wall -Wextra -arch arm64
CC = c++

all: $(OUT)

$(OUT): $(SRC_OBJS)
	$(CC) $(FLAGS) $(SRC_OBJS) -o $(OUT)

$(SRC_OBJS): %.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(SRC_OBJS)

fclean: clean
	rm -f $(OUT)

re: fclean all