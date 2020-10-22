SOURCES := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,%.o,$(notdir $(SOURCES)))

CXX := c++
CXXFLAGS := -std=c++11 -Wall -Werror -g

LDLIBS :=
LDFLAGS :=

EXE := main
DEPEND := $(subst .cpp,.d,$(SOURCES))

DOCS := docs

RM := rm -rf

all : $(EXE)

run : $(EXE)
	./$(EXE)

$(EXE) : $(OBJS)
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

.PHONY : docs clean

docs :
	@( cat Doxyfile ; echo "OUTPUT_DIRECTORY=$(DOCS)" ) | doxygen - > /dev/null 2>&1 && echo "Documentation generated at $(DOCS)"

clean :
	@$(RM) $(OBJS) $(EXE) $(DEPEND)

-include $(DEPEND)
