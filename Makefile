OBJECTS = file1.o file2.o
TARGET  = a.out

CXX      = g++
CXXFLAGS = -Os
CPPFLAGS =
LDFLAGS  =

LD  = $(CXX)

$(TARGET): $(OBJECTS)
	$(LD) $(OBJECTS) $(LDFLAGS) -o $(TARGET)

.PHONY: clean
clean:
	@rm -rf $(OBJECTS) $(TARGET) core

%.o: %.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $<

%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $<

%.o: %.C
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $<
