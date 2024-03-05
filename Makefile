SRC_CLIENT = $(shell find ./Client/sources -name '*.cpp' ! -path './Client/sources/save_game_example/*')
# SRC_CLIENT = $(shell find ./Client/sources/ -name '*.cpp' ! -path './Client/sources/games/*')

OBJ_CLIENT = $(SRC_CLIENT:.cpp=.o)

NAME_CLIENT = pokemon

CXX = g++ -O2 -g
CFLAGS= -std=c++17 -g -I./include -I./include/raylib
LDFLAGS=-lraylib -ldl -lm -lrt -lX11
SOURCES=./src/*.cpp

SFML_LIB = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

INCLUDE_CLIENT = -I./Client/includes

# Additional flags for dependency generation
DEPFLAGS = -MMD -MP

all: $(NAME_CLIENT)

$(NAME_CLIENT): $(OBJ_CLIENT)
	@echo "\033[1;33mCompilation of $(NAME_CLIENT)\033[0m"
	$(CXX) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(INCLUDE_CLIENT) $(SFML_LIB) $(LDFLAGS) -lpthread
	@echo "\033[1;32mCompilation done\033[0m"

# Rule to compile source files and generate dependency files
%.o: %.cpp
	$(CXX) $(DEPFLAGS) -c $< -o $@

clean: clean_client

clean_client:
	@echo "\033[1;31mCleaning $(NAME_CLIENT) objects\033[0m"
	rm -f $(OBJ_CLIENT)
	rm -f $(OBJ_CLIENT:.o=.d)

fclean: clean fclean_client

fclean_client:
	@echo "\033[1;31mCleaning $(NAME_CLIENT)\033[0m"
	rm -f $(NAME_CLIENT)

re: fclean all

# Include dependency files
-include $(OBJ_CLIENT:.o=.d)

.PHONY: all clean fclean re clean_client fclean_client