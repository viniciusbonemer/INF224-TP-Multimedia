CXX := c++
CXXFLAGS := -std=c++11 -Wall -Werror -g -O2

LDLIBS := -lpthread
LDFLAGS :=

SERVER := server
CLIENT := client

DOCS := docs

RM := rm -rf

SOURCES := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,%.o,$(notdir $(SOURCES)))

DEPEND := $(subst .cpp,.d,$(SOURCES))

all : $(SERVER) $(CLIENT)

run : $(SERVER)
	./$(SERVER)

$(SERVER) : OBJS := $(filter-out $(CLIENT).o, $(OBJS))
$(CLIENT) : OBJS := $(filter-out $(SERVER).o, $(OBJS))

$(SERVER) $(CLIENT) : $(OBJS)
	${CXX} -o $@ ${CXXFLAGS} ${LDFLAGS} ${OBJS} ${LDLIBS}

# -M : Like -MD, but also implies -E and writes to stdout by default
#      -MD : Write a depfile containing user and system headers
#      -E : Only run the preprocessor
# -MM : Like -MMD, but also implies -E and writes to stdout by default
#       -MMD : Write a depfile containing user headers
# -MF <file> : Write depfile output from -MMD, -MD, -MM, or -M to <file>
# -MP : Create phony target for each dependency (other than main file)
%.d : %.cpp
	@$(CXX) $(CXXFLAGS) -MM -MF $@ -MP $<

.PHONY : all run docs clean

docs :
	@( cat Doxyfile ; echo "OUTPUT_DIRECTORY=$(DOCS)" ) | doxygen - > /dev/null 2>&1 && echo "Documentation generated at $(DOCS)"

clean :
	@$(RM) $(OBJS) $(SERVER) $(CLIENT) $(DEPEND)

-include $(DEPEND)
