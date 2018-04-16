
set(spct_DIR ./../../SpeectInstaller/install/include/speect/engine)
include(${spct_DIR}/SpeectConf.cmake)
include_directories(${SPCT_INCLUDE_DIRS})

find_library(despeect libspct.so HINTS ${spct_DIR}/../../../lib)

add_executable(
    Command_SpeectConfig
    Command_setspeectconfig.cpp
    )

	
target_link_libraries(
    Command_SpeectConfig
    gtest_main
    Command
    SpeectWrapper
    ${despeect}
    )

add_test(
  NAME
	Test_SetSpeectConfig
  COMMAND
    	Command_SpeectConfig
  )

add_executable(
	Test2
	Command_setspeectconfig.cpp
)

target_link_libraries(
    Test2
    gtest_main
    Command
    SpeectWrapper
    ${despeect}
    )

add_test(
  NAME
	Test_NonHoPalleDiScrivereCodiceOra
  COMMAND
    	Test2
  )
