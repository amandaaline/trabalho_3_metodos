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
 int main(int argc, char const *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    
} 