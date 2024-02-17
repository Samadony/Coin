#We try to detect the OS we are running on, and adjust commands as needed
CLEANUP = rm -f
MKDIR = mkdir
TARGET = coin_flipper.exe

#Path Definitions
PATHS = ./
PATHI = ./
PATHB = build/

#determine our source files
SRCS = $(wildcard $(PATHS)*.cpp)
SRC = $(SRCS)

#Files We Are To Work With
OBJS = $(patsubst $(PATHS)%.cpp,$(PATHB)%.o,$(SRCS))
OBJ = $(OBJS)

#Other files we care about
TGT = $(PATHB)/$(TARGET)

#Tool Definitions
CPP = g++
CFLAGS = -I$(PATHI)

build: $(PATHB) $(TGT)
	./$(TGT)

$(PATHB)%.o: $(PATHS)%.cpp
	$(CPP) -c $(CFLAGS) $< -o $@

$(TGT): $(OBJ)
	$(CPP) -o $@ $^

$(PATHB):
	$(MKDIR) $(PATHB)

clean:
	$(CLEANUP) $(PATHB)*.*

all: clean build

.PHONY: all
