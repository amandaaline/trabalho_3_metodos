#include <iostream>
#include <boost/algorithm/string.hpp>
#include "leitor_arquivo.hpp"

using namespace std;

int verificaArquivo(fstream *arquivoProg, string arquivoStr)
{
    arquivoProg -> fstream::open(arquivoStr, fstream::in | fstream::out);
    
    if (arquivoProg -> is_open())
         return 0;

    else
         return -1;
    
}

int verificaLinhas(fstream *arquivoProg, int &posLinha)
{
    posLinha = 0;
    string testando;

    if (arquivoProg -> is_open())
    {
        while (!arquivoProg -> eof())
        {
            getline(*arquivoProg, testando);
            posLinha++;
        }
        return 0;
    }

    else
        return -1;
}

int contagemBrancoComentario(fstream *arquivoProg, int &posLinha)
{
    posLinha = 0;
    string buscarLinha;
    string temp;
    int pString = 0;
    int comentarioP = 0;
    int comentarioG = 0; 

    if (arquivoProg -> is_open()) {
        while (!arquivoProg -> eof()) {        
            getline(*arquivoProg, buscarLinha);
            temp = buscarLinha;
            boost::erase_all(temp, " "); 
            comentarioP = buscarLinha.find("//");
            comentarioG = buscarLinha.find("/*");

            if (comentarioG != -1 && comentarioP != -1){
                if (comentarioP < comentarioG){
                    posLinha++;
                    pString = buscarLinha.find("\\");
                    if (pString != -1){
                        while (pString != -1){                     
                            posLinha++;
                            getline(*arquivoProg, buscarLinha);
                            pString = buscarLinha.find("\\");
                        }
                    }
                }
                else if (comentarioP > comentarioG)
                {
                    posLinha++;
                    pString = buscarLinha.find("*/");
                    if (pString == -1){
                        while (pString == -1){                        
                            posLinha++;
                            getline(*arquivoProg, buscarLinha);
                            pString = buscarLinha.find("*/");
                        }
                    }
                }
            }
            else if (comentarioG != -1 && comentarioP == -1) {            
                posLinha++;
                pString = buscarLinha.find("*/");
                if (pString == -1){               
                    while (pString == -1){                    
                        posLinha++;
                        getline(*arquivoProg, buscarLinha);
                        pString = buscarLinha.find("*/");
                    }
                }
            }
            else if (comentarioG == -1 && comentarioP != -1){                
                    posLinha++;
                    pString = buscarLinha.find("\\");
                    if (pString != -1){
                        while (pString != -1){
                            posLinha++;
                            getline(*arquivoProg, buscarLinha);
                            pString = buscarLinha.find("\\");
                        }
                    }
                
                }
            else if (temp.size() == 0){
                posLinha++;
            }
        }
        return 0;
    }
    else
        return -1;
}
