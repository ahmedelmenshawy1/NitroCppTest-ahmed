CXX = g++ -std=c++17
GOOGLE_TEST_INC = -I third_party/googletest/googletest/include -I third_party/googletest/googlemock/include
CXXFLAGS = -I include
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.cpp=obj/%.o)
TARGET = nitroTask.exe

# Unit test files
TEST_SRC = $(wildcard unit_test/*.cpp)
TEST_OBJ = $(TEST_SRC:unit_test/%.cpp=obj/%.o)

# Directories
OBJ_DIR = obj

# Create the obj directory if it doesn't exist
$(OBJ_DIR):
	mkdir $(OBJ_DIR)

# Build main executable
all: $(TARGET)

# Clean and build main executable
build_run: $(TARGET) run  

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Build object files in the obj directory
$(OBJ_DIR)/%.o: src/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@


test: $(TEST_OBJ) $(OBJ)
	@echo "Running unit tests..."
	$(CXX) $(TEST_OBJ) obj/Rectangle.o obj/RectangleIntersection.o -Lthird_party/googletest/build/lib -lgtest -lgtest_main -lgmock -o test_nitroTask.exe -DUNIT_TEST -mconsole
	@./test_nitroTask.exe test.json
	del /Q test_nitroTask.exe
	@echo "Unit tests finished."



# The following rule builds object files for the unit test files
obj/%.o: unit_test/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(GOOGLE_TEST_INC) -c $< -o $@

# Clean the build (object files and executables)
clean:
	if exist $(OBJ_DIR)\*.o del /Q $(OBJ_DIR)\*.o
	if exist $(TARGET) del /Q $(TARGET)

# Run the main executable
run:
	@echo Running $(TARGET)... 
	@./$(TARGET) *.json

.PHONY: all clean run test