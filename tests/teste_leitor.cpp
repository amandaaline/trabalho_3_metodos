#include "../src/leitor_arquivo.cpp"
#include <fstream>
#include <gtest/gtest.h>

using namespace std;

TEST(verifica_funcionamento_arquivo, leitura)
{
    fstream arquivoProg;
    string testando = "first_program.cpp";
    EXPECT_EQ(0, verificaArquivo(&arquivoProg,testando));
    EXPECT_EQ(1, arquivoProg.is_open());
} 

TEST(lerLinhas, contadorLinha)
{
    int posLinha = 0;
	fstream arquivoProg;
    string testando = "first_program.cpp";
    EXPECT_EQ(-1, verificaLinhas(&arquivoProg, posLinha));
    EXPECT_EQ(0, verificaArquivo(&arquivoProg, testando));
    EXPECT_EQ(1, arquivoProg.is_open());
    EXPECT_NE(-1, verificaLinhas(&arquivoProg,posLinha));
    EXPECT_NE(0, posLinha);
}
 TEST(localiza_comentario, comentario)
{
    int posLinha = 0;
    fstream arquivoProg;

    string testando = "first_program.cpp";
    EXPECT_EQ(-1, contagemBrancoComentario(&arquivoProg, posLinha));
    verificaArquivo(&arquivoProg,testando);
    EXPECT_NE(-1,contagemBrancoComentario(&arquivoProg,posLinha));
}

 int main(int argc, char **argv)
{
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}
