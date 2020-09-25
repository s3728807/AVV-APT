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

    board->newGame(p1Name, p2Name);

    ui->print("Player 1: " + p1Name + " and Player 2: " + p2Name + " ready to play.");
    
    bool gamePlaying = true;

    std::string input;
    std::string print;
    std::string output;

    while (gamePlaying) {
        if (board->getBag()->empty())
        {
            //ui->print("empty bag");
            board->refillBag();
        }

        if (board->emptyFactories())
        {
            //ui->print("empty factories");
            board->refillFactories();
        }

        ui->print("");
        ui->print("=== Start Round ===");

        //checks to see if factories and dump are empty
        while(!board->emptyFactories() || !board->emptyDump())
        {
            //find the right players turn
            while(!board->getPlayers()->head->isTurn())
            {
                board->getPlayers()->head = board->getPlayers()->head->next;
            }

            ui->print("");
            ui->print("TURN FOR PLAYER: "+board->getPlayers()->head->getName());
            ui->print("Factories: ");

            for (int x = 0; x<6; x++)
            {
                output = std::to_string(x).append(": ");
                output.append(ui->printFactory((board->getFactories()+x)->getContent()));
                ui->print(output);
            }
            

            ui->print("");
            output = "Mosaic for ";
            ui->print(output.append(board->getPlayers()->head->getName()).append(":"));

            for (int x = 0; x<5; x++)
            {
                output = std::to_string(x+1).append(": ");
                output.append(ui->printPatternLine(board->getPlayers()->head->getMosaic()->getPatternLine()+x));
                output.append(" || ");
                output.append(ui->printWall(board->getPlayers()->head->getMosaic()->getWall()[x]));
                ui->print(output);
            }

            output = "Broken: ";
            output.append(ui->printFactory(board->getPlayers()->head->getFloor()->getContent()));
            ui->print(output);

            ui->input();
        }
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