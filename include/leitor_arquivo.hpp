#include <iostream>
#include <boost/algorithm/string.hpp>
#include <fstream>

using namespace std;
/**
 * @brief Funcao que le as linhas de um arquivo
 * @param arquivoProg 
 * @param leituraArquivo 
 * @return int 
 */
int verificaArquivo(fstream *arquivoProg, string leituraArquivo);

/**
 * @brief Funcao para identificar o total de linhas do programa
 * @param arquivoProg 
 * @param posLinha 
 * @return int 
 */

int verificaLinhas(fstream *arquivoProg, int &posLinha);

/**
 * @brief Funcao para contar salto de linha e comentarios
 * @param arquivoProg 
 * @param posLinha 
 * @return int 
 */

int contagemBrancoComentario(fstream *arquivoProg, int &posLinha);



