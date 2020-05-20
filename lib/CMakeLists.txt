
add_library(simpleLibrary
        Triangle.cpp
        Hailstone.cpp
        Awards.cpp
#                Turtle.cpp
#                MockTurtle.cpp
        ../lamda.cpp ../Chatbot.h ../a4.cpp ../letter_hist.cpp ../mycat_2bugs.cpp)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})

