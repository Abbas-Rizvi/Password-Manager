CXX       := g++
CXX_FLAGS := -std=c++20

BIN     := bin
SRC     := src
INCLUDE := include
LIB     := sqlite3
LIBRARIES   :=
EXECUTABLE  := main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	@echo "Executing..."
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	@echo "Building..."
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -l $(LIB) $^ -o $@ $(LIBRARIES)

clean:
	@echo "cleaning"
	-rm $(BIN)/*

