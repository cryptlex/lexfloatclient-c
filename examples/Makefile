# the compiler: g++ for C++
CXX = g++

# compiler flags:
#  -Wall turns on most, but not all, compiler warnings
CXXFLAGS  = -Wall

LDFLAGS = "-Wl,-rpath,." -L. -lLexFloatClient
#LDFLAGS += -Wl,-Bstatic -lLexFloatClient


# the build target executable:
TARGET = FloatSample

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp $(LDFLAGS)

clean:
	$(RM) $(TARGET)