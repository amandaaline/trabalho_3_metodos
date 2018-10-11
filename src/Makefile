IDIR = ../include
CC= g++ 
CFLAGS=-I$(IDIR) -ftest-coverage -fprofile-arcs -lgtest -lgtest_main -fpermissive
PROGRAM_GCOV = leitor
ODIR=../obj
TEST_ODIR=../tests/obj
LDIR =../src
DIR_TESTS=../tests

TEST_EXE= teste_leitor
LIBS=

PROGRAM = leitor

_HEADERS = leitor_arquivo.hpp
HEADERS = $(patsubst %,$(IDIR)/%,$(_HEADERS))

_OBJECTS = leitor_arquivo.o main.o 
OBJECTS = $(patsubst %,$(ODIR)/%,$(_OBJECTS))

_TESTS = teste_leitor.cpp 
TESTS = $(patsubst %,$(DIR_TESTS)/%,$(_TESTS))


$(ODIR)/%.o: %.cpp $(HEADERS) 
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

$(PROGRAM): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(TEST_EXE) : $(TESTS)
	$(CC) -o $@ --coverage $^ $(CFLAGS)

program: $(PROGRAM) test gcov project

test: $(TEST_EXE)
	cp $(LDIR)/*.gcno $(ODIR)

run: 
	./$(PROGRAM) 

run_test:
	./$(TEST_EXE)
.PHONY: clean

gcov:
	gcov $(PROGRAM_GCOV).gcda

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ $(PROGRAM) $(TEST_EXE)

clean_coverage:
	rm -f *.gcno *.gcda *.gcov

clean_all:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ && rm -f *.gcno *.gcda *.gcov $(PROGRAM) $(TEST_EXE)