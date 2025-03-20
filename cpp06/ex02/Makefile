OUT = ex02

SRC = main.cpp Base.cpp
SRC_OBJS = $(SRC:.cpp=.o)
OBJ_FOLDER = obj
OBJ_FOLDED = $(addprefix $(OBJ_FOLDER)/, $(SRC_OBJS))
FLAGS = -Wall -Wextra  -g -std=c++98
CPP = c++

all: $(OUT)

$(OBJ_FOLDER):
	mkdir -p $(OBJ_FOLDER)

$(OUT): $(OBJ_FOLDED)
	$(CPP) $(FLAGS) $(OBJ_FOLDED) -o $(OUT)

$(OBJ_FOLDER)/%.o: %.cpp | $(OBJ_FOLDER)
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FOLDED)

fclean: clean
	rm -f $(OUT)

re: fclean all
