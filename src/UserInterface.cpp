#include "../headers/UserInterface.h"
#include <string>
#include <iostream>

using namespace Azul;

UserInterface::UserInterface() {
    

};

UserInterface::~UserInterface() {

};

void UserInterface::print(std::string input) {

    std::cout << input << std::endl;
    
};

std::string UserInterface::input() {
    std::string input;
    std::cout << ">";
    getline(std::cin, input);
    return input;
};