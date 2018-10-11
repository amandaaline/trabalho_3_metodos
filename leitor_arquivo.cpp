#include <iostream>
#include <fstream>

using namespace std;

ifstream arquivoProg;

int verificaArquivo(fstream *arquivoProg, string arquivoStr)
{
    arquivoProg->fstream::open(arquivoStr,fstream::in | fstream::out);

    if(arquivoProg->is_open())
        return 0;
      
    else
        return -1;
    
} 