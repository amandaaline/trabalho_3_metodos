#include <iostream>
#include "leitor_arquivo.hpp"

/**
 * @brief Programa principal
 * @param argc 
 * @param argv 
 * @return int 
 */

int main(int argc, char const *argv[])
{
    int totalLinha = 0;
    int contadorLinhasCodigo = 0;
    int contadorLinhasSemCodigo = 0;

    fstream arquivoProg;
    string leituraArquivo = "first_program.cpp";
    verificaArquivo(&arquivoProg, leituraArquivo);
    verificaLinhas(&arquivoProg, totalLinha);
    arquivoProg.clear(); //volta
    arquivoProg.seekg(0, ios::beg);
    contagemBrancoComentario(&arquivoProg, contadorLinhasSemCodigo);
    contadorLinhasCodigo = totalLinha - contadorLinhasSemCodigo;
    // Imprimir os valores
    cout << "Total de linhas:" << totalLinha << endl;
    cout << "Linhas de codigo util:" << contadorLinhasCodigo << endl;
    cout << "Linhas comentadas ou sem codigo util:" << contadorLinhasSemCodigo << endl;

    return 0;
}