ID$@IR =
IDIR = 
CC= g++ 
CFLAGS=-I$(IDIR) -ftest-coverage -fprofile-arcs -lgtest -lgtest_main -fpermissive
 ODIR=
LDIR =
DIR_TESTS=
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
 $(TEST_EXE) : $(TESTS) leitor_arquivo.cpp
	$(CC) -o $@ --coverage $^ $(CFLAGS)
 program: $(PROGRAM) 
 test: $(TEST_EXE)
	mv $(LDIR)/*.gcno $(ODIR)
 run: 
	./$(PROGRAM) 
 run_test:
	/Test./$()
 .PHONY: clean
 gcov:
	gcov $(TEST_DIR)/$(PROGRAM).gcda
 clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
 clean_coverage:
	rm -f $(ODIR)/*.gcno $(ODIR)/*.gcda
 clean_all:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ && rm -f $(ODIR)/*.gcno $(ODIR)/*.gcda
