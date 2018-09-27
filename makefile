TARGET = $(MAKECMDGOALS)

# g++ compile flags
CXXFLAGS += -std=c++17

$(TARGET):$(TARGET).o
	$(CXX) $^ -o $@
	@./$(TARGET) # after compile, run the program