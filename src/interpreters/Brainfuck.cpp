#include "Brainfuck.h"

#include <format>
#include <iostream>
#include <stdexcept>
#include <vector>

void Brainfuck::interpret(const std::string& instructionSet) {
    std::vector<int> memory = std::vector<int>(30000);
    int p = 0;

    for(int i = 0; i < instructionSet.size(); i++) {
        switch(instructionSet[i]) {
            case '>': {
                p++;
                if(p > memory.size() - 1) {
                    throw std::runtime_error(std::format("Pointer out of bounds. Index: {0}", p));
                }
                break;
            }
            case '<': {
                p--;
                if(p < 0) {
                    throw std::runtime_error(std::format("Pointer out of bounds. Index: {0}", p));
                }
                break;
            }
            case '+': {
                memory[p]++;
                if(memory[p] > 255) {
                    memory[p] = 0;
                }
                break;
            }
            case '-': {
                memory[p]--;
                if(memory[p] < 0) {
                    memory[p] = 255;
                }
                break;
            }
            case '.': {
                std::cout << static_cast<char>(memory[p]);
                break;
            }
            case ',': {
                char c;
                std::cin >> c;
                memory[p] = c;
                break;
            }
            case '[': {
                if(memory[p] == 0) {
                    std::vector<char> bracketStack = std::vector<char> { '[' };
                    while(bracketStack.size() > 0) {
                        i++;
                        if(instructionSet[i] == '[') {
                            bracketStack.push_back(instructionSet[i]);
                        } else if(instructionSet[i] == ']' && bracketStack.back() == '[') {
                            bracketStack.pop_back();
                        }
                    }
                }
                break;
            }
            case ']': {
                if(memory[p] != 0) {
                    std::vector<char> bracketStack = std::vector<char> { ']' };
                    while(bracketStack.size() > 0) {
                        i--;
                        if(instructionSet[i] == ']') {
                            bracketStack.push_back(instructionSet[i]);
                        } else if(instructionSet[i] == '[' && bracketStack.back() == ']') {
                            bracketStack.pop_back();
                        }
                    }
                }
                break;
            }
        }
    }
}
