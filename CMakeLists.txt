cmake_minimum_required(VERSION 3.13)
project(CMPT135)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

set(CMAKE_CXX_STANDARD 14)


add_executable(Points
#        swapping.cpp
#        pointers.cpp
#        Points.cpp
#        a1
#        a1.cpp
#        a1.cpp
#        a1.h
#        basic_structs.cpp
#        int_vec_class_tutorial1.cpp
#        Main.cpp
#        dequeue.cpp
#        Points.cpp
#        test2.cpp
#        Stringable.cpp
#        color_point.cpp
#        a2.cpp
#        int_vec_test.cpp
#        kbd_events.cpp
#        midtermPractise.cpp
#        doublevec.cpp
#        include/Pet.h include/Dog.h Dog.cpp Pet.cpp
#        a2.cpp
#        inheritance.cpp
#        assigmnent-1.cpp

#        Assignment.cpp
        lamda.cpp
#        3.cpp
#        function_pointer.cpp
#        variant.cpp
#        optional.cpp
#        template.cpp
#        another.cpp
#        test.cpp
#        visit.cpp
#        group.cpp
#        function.cpp
#        Recursion.cpp
#        Exception.cpp

#        a3.cpp
#        CodeReview6.cpp
#        maze.cpp
#        Property.cpp
#        Recursive.cpp
#        Search.cpp

#        a4.cpp
#        constexpr.cpp
#        creational_pattern.cpp
#        Structural_Pattern.cpp
#        Structural_Pattern.cpp
#        a5.cpp
#        letter_hist.cpp
#        mycat_fixed.cpp
#        point_class1.cpp
#        point_class2.cpp
#        int_vec_class_tutorial2.cpp
#        challenge/challenge.cpp
#        "challenge/Challenge2 .cpp"
#        challenge/challenge1.cpp
#        challenge/challenge3.cpp
#        challenge/challenge4.cpp
#        challenge/challenge5.cpp
#        challenge/challenge6.cpp
#        challenge/challenge7.cpp
#        challenge/challenge8.cpp
#        challenge/challenge9.cpp
#        challenge/challenge10.cpp
#        "Rvalue Reference.cpp"
#        string_view.cpp
#        list.cpp
#        list_class.cpp
#        hashing.cpp
#        state.cpp
#        ConversionOperator.cpp
#        decltype.cpp
        )

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${LIBRARY_OUTPUT_PATH})

include_directories(
        ${CMAKE_SOURCE_DIR}/test/lib/googletest/include/
        ${CMAKE_SOURCE_DIR}/test/lib/googlemock/include/
)

add_subdirectory(lib)
add_subdirectory(test)