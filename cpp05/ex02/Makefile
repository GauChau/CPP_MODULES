OUT = ex02

SRC = Bureaucrat.cpp main.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
SRC_OBJS = $(SRC:.cpp=.o)
OBJ_FOLDER = obj/
OBJ_FOLDED = $(addprefix $(OBJ_FOLDER), $(SRC_OBJS))
FLAGS = -Wall -Wextra -Werror -g -std=c++98 
CPP = c++

all: $(OUT)

$(OUT): $(OBJ_FOLDED)
	$(CPP) $(FLAGS) $(OBJ_FOLDED) -o $(OUT)

$(OBJ_FOLDER)%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FOLDED)

fclean: clean
	rm -f $(OUT)

re: fclean all
