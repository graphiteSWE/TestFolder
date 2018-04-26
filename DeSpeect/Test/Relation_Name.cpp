#include "gtest/gtest.h"
#include "setspeectconfigcommand.h"
#include "../Model/Command/header/commandlist.h"
#include "../Model/SpeectWrapper/header/relation.h"


TEST(Graph, VerifyRelationName){
    Speect* s=new Speect();
    CommandList::CommandBuilder* builder=new CommandList::CommandBuilder(s);
    CommandList* commands;
    commands=builder->LoadConfig(Configuration::Voice, "./cmu_arctic_slt/voice.json").getCommandList();
    commands->executeAll();
    std::string text="hi everybody";
    commands=builder->LoadConfig(Configuration::UtteranceText, text).getCommandList();
    commands->executeAll();
    std::list<std::string> processorList;
    processorList.push_back("Tokenize");
    commands=builder->WithProcessors(processorList).getCommandList();
    commands->executeAll();
    EXPECT_EQ(commands->getRelationNames().front(), "Token");
    delete s;
    delete commands;
    delete builder;
}
