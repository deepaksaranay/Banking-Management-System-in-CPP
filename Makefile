# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I./include
LDFLAGS = 

# Directories
SRCDIR = src
INCDIR = include
DATADIR = data
OBJDIR = obj

# Source files
SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/Bank.cpp $(SRCDIR)/Account.cpp $(SRCDIR)/Customer.cpp
OBJECTS = $(OBJDIR)/main.o $(OBJDIR)/Bank.o $(OBJDIR)/Account.o $(OBJDIR)/Customer.o

# Output executable
EXECUTABLE = banking

# Default target
all: $(DATADIR) $(OBJDIR) $(EXECUTABLE)

# Create data directory
$(DATADIR):
	@mkdir -p $(DATADIR)

# Create object directory
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Link the executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)
	@echo "Build successful! Run './$(EXECUTABLE)' to start the application."

# Compile main.cpp
$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile Bank.cpp
$(OBJDIR)/Bank.o: $(SRCDIR)/Bank.cpp $(INCDIR)/Bank.h $(INCDIR)/Account.h $(INCDIR)/Customer.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile Account.cpp
$(OBJDIR)/Account.o: $(SRCDIR)/Account.cpp $(INCDIR)/Account.h $(INCDIR)/Customer.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile Customer.cpp
$(OBJDIR)/Customer.o: $(SRCDIR)/Customer.cpp $(INCDIR)/Customer.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	@rm -rf $(OBJDIR) $(EXECUTABLE)
	@echo "Clean completed!"

# Clean everything including data
clean-all: clean
	@rm -rf $(DATADIR)
	@echo "All data cleaned!"

# Help
help:
	@echo "Available targets:"
	@echo "  make         - Build the project"
	@echo "  make clean   - Remove build artifacts"
	@echo "  make clean-all - Remove build artifacts and data"
	@echo "  make help    - Show this help message"

.PHONY: all clean clean-all help
