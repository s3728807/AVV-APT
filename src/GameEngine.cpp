#include "../headers/GameEngine.h"

using namespace Azul;

GameEngine::GameEngine() 
{
    board = new GameBoard();
    ui = new UserInterface();
    
};

GameEngine::~GameEngine() {
    delete board;
    delete ui;
};

void GameEngine::run() {

};

void GameEngine::menu() {
    
    std::string menu;
    std::string studentInfo;
    int selection;
    bool running;
    
    //create menu string
    menu.append("Menu\n");
    menu.append("----\n");
    menu.append("1. New Game\n");
    menu.append("2. Load Game\n");
    menu.append("3. Credits\n");
    menu.append("4. Quit\n");
    
    //create credits string with student info
    //student 1
    studentInfo.append("\nStudent 1:\n");
    studentInfo.append("Name: Adam Pacella\n");
    studentInfo.append("Student ID: s3785621\n");
    studentInfo.append("Email: s3785621@student.rmit.edu.au\n");
    //student2
    studentInfo.append("\nStudent 2:\n");
    studentInfo.append("Name: Vincenzo Facchino\n");
    studentInfo.append("Student ID: s3815772\n");
    studentInfo.append("Email: s3815772@student.rmit.edu.au\n");
    //student3
    studentInfo.append("\nStudent 3:\n");
    studentInfo.append("Name: Vincent Villaflores\n");
    studentInfo.append("Student ID: s3728807\n");
    studentInfo.append("Email: s3728807@student.rmit.edu.au\n");

    //ui->print("Welcome to Azul!");
    //ui->print("----------------");
    //std::cout << "Welcome to Azul!" << std::endl;
    //std::cout << "----------------" << std::endl;

    running = true;
    while (running) {

        std::cout << menu << std::endl << "> ";
        std::cin >> selection;
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
        } 
        if (selection == 1) {
            //TODO new game
        } else if (selection == 2) {
            //TODO load game
        } else if (selection == 3) {
            std::cout << std::endl << "-----------------------------------" << std::endl;
            std::cout << "Credits:\n" << studentInfo << std::endl;
            std::cout << "-----------------------------------\n" << std::endl;
        } else if (selection == 4) {
            running = false;
        } else if (selection > 4) {
            std::cout << "Invalid selection, please select a value from the menu." << std::endl;
        }

    }
    
};