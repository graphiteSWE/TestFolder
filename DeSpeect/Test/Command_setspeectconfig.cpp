#include "gtest/gtest.h"
#include "../Model/Command/header/setspeectconfigcommand.h"
#include "../Model/SpeectWrapper/header/Speect.h"

TEST(Command, setspeectconfigFailure)
{
	Speect s;
    AbstractCommand* temp(new SetSpeectConfigCommand(Configuration::Voice, "aaa.json"));
    EXPECT_EQ(temp->execute(&s), "Initializing Voice Failure Operation status:Failure");
    delete temp;
}

TEST(Command, setspeectconfigSuccess)
{
	Speect s;
    AbstractCommand* temp(new SetSpeectConfigCommand(Configuration::Voice, "./cmu_arctic_slt/voice.json"));
    temp->execute(&s);
    EXPECT_FALSE(s.getUttProcessorNames().empty());
    delete temp;
}
TEST(Command, setspeectconfigSuccess)
{
	Speect s;
    AbstractCommand* temp(new SetSpeectConfigCommand(Configuration::Voice, "./meraka_lwazi2_alta/voice.json"));
    temp->execute(&s);
    EXPECT_FALSE(s.getUttProcessorNames().empty());
    delete temp;
}
TEST(Command, setspeectconfigSuccess)
{
	Speect s;
    AbstractCommand* temp(new SetSpeectConfigCommand(Configuration::Voice, "./meraka_lwazi2_john/voice.json"));
    temp->execute(&s);
    EXPECT_FALSE(s.getUttProcessorNames().empty());
    delete temp;
}