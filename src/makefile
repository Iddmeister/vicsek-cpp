CC = g++
CFLAGS = -std=c++17
SRC = main.cpp
EXEC = vicsek
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@;

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC);

all:
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC);
