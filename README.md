# Project-Euler

Compiling with G++

    // Compile & Link with Output-Filename specified
    g++ main.cpp -o mult35

    // Compile and create object code for both files
    // -c = Compiler Stage -o = Output Stage -Wall = with all Warnings
    g++ -c helloWorld.cpp hello.cpp
    // Link those object files together and create Output-File main.exe
    g++ -o main.exe helloWorld.o hello.o