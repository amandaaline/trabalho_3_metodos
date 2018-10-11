#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ifstream arquivoProg;

int verificaArquivo(fstream *, string);
int verificaComentario(fstream *, int &);
int verificaLinhas(fstream *arquivoProg, int &posLinha);