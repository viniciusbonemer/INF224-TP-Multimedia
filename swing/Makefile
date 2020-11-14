JFLAGS = -g
JC = javac

DOCS := docs

RM := rm -f

SOURCES := $(wildcard *.java)
CLASSES := $(patsubst %.java,%.class,$(notdir $(SOURCES)))

EXE := Main

.SUFFIXES: .java .class

.java.class:
	$(JC) $(JFLAGS) $*.java

all: $(CLASSES)

run: all
	java $(EXE)

.PHONY : all run docs clean

docs :
	@( cat Doxyfile ; echo "OUTPUT_DIRECTORY=$(DOCS)" ) | doxygen - > /dev/null 2>&1 && echo "Documentation generated at $(DOCS)"

clean:
	@$(RM) $(patsubst %,'%',$(wildcard *.class))
