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

int verificaComentario(fstream * arquivoProg, int &posLinha)
{
    int var1;
    int var2;
    string testando;
    if(arquivoProg->is_open())
    {
        std::getline(*arquivoProg, testando);
        var1 = testando.find("/*");
        var2 = testando.find("//");
     
        if(var1 != -1 || var2 != -1)
            return 0;
            
         else
			return -1;       
    }
    
    else {
        cout << "nao ha arquivo" << endl;
        return -1;
    }
}