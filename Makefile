# plain simple Makefile to build exprtest

CXX = g++
LEX = flex
YACC = bison

CXXFLAGS = -W -Wall -Wextra -ansi -g -std=c++11
LDFLAGS = 

HEADERS = driver.h parser.h scanner.h expression.h \
    y.tab.h FlexLexer.h location.hh position.hh stack.hh

all: exprtest

# Generate scanner and parser

parser.cc: parser.yy
	$(YACC) -o parser.cc --defines=parser.h parser.yy

scanner.cc: scanner.ll
	$(LEX) -o scanner.cc scanner.ll

# Implicit rule to compile c++ files

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Link executable

exprtest: exprtest.o parser.o scanner.o driver.o expression.o
	$(CXX) $(LDFLAGS) -o $@ exprtest.o parser.o scanner.o driver.o expression.o

clean:
	rm -f exprtest *.o *~

extraclean: clean
	rm -f parser.cc parser.h scanner.cc
