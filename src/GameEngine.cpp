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

    ui->print("Starting a New Game");
    ui->print("Enter a name for player 1");
    std::string p1Name;
    p1Name = ui->input();
    ui->print("Enter a name for player 2");
    std::string p2Name;
    p2Name = ui->input();
    ui->print("Player 1: " + p1Name + " and Player 2: " + p2Name + " ready to play.");
    
    bool gamePlaying = true;
    
    //temporary game board
    std::string tempGameBoard;
    tempGameBoard.append("Factories:\n");
    tempGameBoard.append("O : F\n");
    tempGameBoard.append("1: R Y Y U\n");
    tempGameBoard.append("2: R B B B\n");
    tempGameBoard.append("3: B L L L\n");
    tempGameBoard.append("4: R R U U\n");
    tempGameBoard.append("5: R Y B L\n");

    std::string tempMosaic;
    tempMosaic.append("1:     . || .....\n");
    tempMosaic.append("2:    .. || .....\n");
    tempMosaic.append("3:   ... || .....\n");
    tempMosaic.append("4:  .... || .....\n");
    tempMosaic.append("5: ..... || .....\n");
    tempMosaic.append("broken:\n");



    while (gamePlaying) {
        ui->print("Turn for Player: " + p1Name);
        ui->print(tempGameBoard);
        ui->print("Mosaic for " + p1Name);
        ui->print(tempMosaic);

        ui->input();
        ui->print("turn successful\n");

        ui->print("Turn for Player: " + p2Name);
        ui->print(tempGameBoard);
        ui->print("Mosaic for " + p2Name);
        ui->print(tempMosaic);
        
        ui->input();
        ui->print("turn successful\n");
    }

};

void GameEngine::menu() {
    
    std::string menu;
    std::string studentInfo;
    std::string input;
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

    ui->print("Welcome to Azul!");
    ui->print("----------------");

    running = true;
    while (running) {

        ui->print(menu);
        input = ui->input();
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
        } 
        if (input == "1") {
            run();
        } else if (input == "2") {
            //TODO load game
        } else if (input == "3") {
            ui->print("-----------------------------------");
            ui->print("Credits:\n" + studentInfo);
            ui->print("-----------------------------------");
        } else if (input == "4") {
            running = false;
        } else {
            ui->print("Invalid selection, please select a value from the menu.");
        }

    }
    
};