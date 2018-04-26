set(spct_DIR ./../../SpeectInstaller/install/include/speect/engine)
include(${spct_DIR}/SpeectConf.cmake)
include_directories(${SPCT_INCLUDE_DIRS})

find_library(despeect libspct.so HINTS ${spct_DIR}/../../../lib)
########################################################################Speect_config
add_executable(
    Speect_config
    Command_setspeectconfig.cpp
    )

target_link_libraries(
    Speect_config
    gtest_main
    Command
    SpeectWrapper
    ${despeect}
    )
add_test(
    NAME
        Speect_config
    COMMAND
        Speect_config
    )
########################################################################Relation_Name
add_executable(
    Relation_Name
    Relation_Name.cpp
    )

target_link_libraries(
    Relation_Name
    gtest_main
    Command
    SpeectWrapper
    ${despeect}
    )
add_test(
    NAME
        Relation_Name
    COMMAND
        Relation_Name
    )
########################################################################Item_Name
add_executable(
    Item_Name
    Item_Name.cpp
    )

target_link_libraries(
    Item_Name
    gtest_main
    Command
    SpeectWrapper
    ${despeect}
    )
add_test(
    NAME
        Item_Name
    COMMAND
        Item_Name
    )
########################################################################

