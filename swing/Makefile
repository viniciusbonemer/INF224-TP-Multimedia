JFLAGS = -g
JC = javac

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

.PHONY : all run clean

clean:
	@$(RM) $(patsubst %,'%',$(wildcard *.class))
