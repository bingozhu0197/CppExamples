TARGET = $(MAKECMDGOALS)

# g++ compile flags
CXXFLAGS += -std=c++14

$(TARGET):$(TARGET).o
	$(CXX) $^ -o $@
	@$(RM) $(TARGET).o
	@./$(TARGET) # after compile, run the program