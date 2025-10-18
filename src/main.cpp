#include "Brainfuck.h"

#include <format>
#include <functional>
#include <iostream>

void runTest(std::string testCase, std::function<void()> fn, std::string expected) {
    std::cout << testCase << std::endl;
    std::cout << std::format("Expected:\t{0}\nActual:\t\t", expected);
    fn();
    std::cout << std::endl << std::endl;
}

int main(int argc, char* args[]) {
    std::function<void()> bf1 = []() {
        std::string instructionSet = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.";
        Brainfuck::interpret(instructionSet);
    };

    runTest("Brainfuck - Test #01", bf1, "Hello World!");

    // -------------------------

    std::function<void()> bf2 = []() {
        std::string instructionSet = "+++++++++++>+>>>>++++++++++++++++++++++++++++++++++++++++++++>++++++++++++++++++++++++++++++++<<<<<<[>[>>>>>>+>+<<<<<<<-]>>>>>>>[<<<<<<<+>>>>>>>-]<[>++++++++++[-<-[>>+>+<<<-]>>>[<<<+>>>-]+<[>[-]<[-]]>[<<[>>>+<<<-]>>[-]]<<]>>>[>>+>+<<<-]>>>[<<<+>>>-]+<[>[-]<[-]]>[<<+>>[-]]<<<<<<<]>>>>>[++++++++++++++++++++++++++++++++++++++++++++++++.[-]]++++++++++<[->-<]>++++++++++++++++++++++++++++++++++++++++++++++++.[-]<<<<<<<<<<<<[>>>+>+<<<<-]>>>>[<<<<+>>>>-]<-[>>.>.<<<[-]]<<[>>+>+<<<-]>>>[<<<+>>>-]<<[<+>-]>[<+>-]<<<-]";
        Brainfuck::interpret(instructionSet);
    };

    runTest("Brainfuck - Test #02", bf2, "<Fibbonaci numbers under 100>");
}
