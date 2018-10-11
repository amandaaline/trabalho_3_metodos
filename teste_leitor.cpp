#include <iostream>
#include <gtest/gtest.h>
#include "reader.hpp"

TEST(verifica_funcionamento_arquivo,leitura)
{
    fstream arquivoProg;
    
    string testando = "first_program.cpp";
    EXPECT_EQ(0,verificaArquivo(&arquivoProg,testando));
    EXPECT_EQ(1,arquivoProg.is_open());
} 

TEST(lerLinhas, contadorLinha)
{
    fstream arquivoProg;
    int posLinha;

    string testando = "first_program.cpp";
    EXPECT_EQ(0, verificaArquivo(&arquivoProg, testando));
    EXPECT_EQ(1, arquivoProg.is_open());
    EXPECT_NE(0,verificaLinhas(&arquivoProg,posLinha));
}
 TEST(localiza_comentario, comentario)
{
    int posLinha;
    fstream arquivoProg;

    string testando = "first_program.cpp";
    verificaArquivo(&arquivoProg, testando);
    EXPECT_EQ(-1, verificaComentario(&arquivoProg, posLinha));
}

 int main(int argc, char const *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    
} 