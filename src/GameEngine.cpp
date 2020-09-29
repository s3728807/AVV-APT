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

    introducePlayers();

    for (int i = 1; i < 6; i++)
    {
        //checks if bag is empty
        bagCheck();

        //checks if factories are empty
        factoryCheck();


        ui->print("");
        ui->print("=== Start Round ===");

        //checks to see if factories and dump are empty
        while(!board->emptyFactories() || !board->emptyDump())
        {
            //std::cout<<"start round"<<std::endl;
            findPlayerTurn();

            printFactory();

            printMosaic();

            while (!playerAction())
            {}
            //std::cout<<"end of round"<<std::endl;
            board->getPlayers()->head->setTurn(false);
            board->getPlayers()->head->next->setTurn(true);
            //std::cout<<"end of player swap"<<std::endl;
        }//a round
    }//entire game

}

bool GameEngine::playerAction()
{
    bool ret = true;
    std::string action = ui->input();
    std::vector<std::string> input;
    input = parseLine(action, ' ');

    if ((input.at(0).compare("turn")) == 0)
    {
        if (validTurn(std::stoi(input.at(1)), input.at(2)[0], std::stoi(input.at(3))))
        {
            board->factory2Mosaic(std::stoi(input.at(1)), char2Col(input.at(2)[0]), std::stoi(input.at(3)));
        }
        else
        {
            ret = false;
        }
        
    }
    else if ((input.at(0).compare("save")) == 0)
    {
        //TODO
    }
    else
    {
        ui->print("Invalid input");
        ret = false;
    }

    return ret;
}

bool GameEngine::validTurn(int f, char c, int p)
{
    bool ret = true;
    if (f < 0 || f > 5)
    {
        ui->print("That is not a valid Factory");
        ret = false;
    }
    else if (p < 1 || p > 5)
    {
        ui->print("That is not a valid Row");
        ret = false;
    }
    else if (!validColor(c))
    {
        ui->print("That is not a valid Color");
        ret = false;
    }
    else if ((board->getFactories()+f)->findColor(char2Col(c)) == 0)
    {
        ui->print("That color is not in the Factory");
        ret = false;
    }
    return ret;
}

bool GameEngine::validColor(char c)
{
    return ::tolower(c) == 'r' || ::tolower(c) == 'b' || ::tolower(c) == 'u' || ::tolower(c) == 'l' || ::tolower(c) == 'y';
}

Colors GameEngine::char2Col(char c)
{
    Colors color = Colors();
    if (::tolower(c) == 'r')
    {
        color = RED;
    }
    else if (::tolower(c) == 'b')
    {
        color = DARKBLUE;
    }
    else if (::tolower(c) == 'u')
    {
        color = BLACK;
    }
    else if (::tolower(c) == 'l')
    {
        color = LIGHTBLUE;
    }
    else if (::tolower(c) == 'y')
    {
        color = YELLOW;
    }

    return color;
}

void GameEngine::introducePlayers()
{
    ui->print("Starting a New Game");
    ui->print("Enter a name for player 1");
    std::string p1Name;
    p1Name = ui->input();

    bool sameName = true;
    std::string p2Name;
    while (sameName)
    {
        ui->print("Enter a name for player 2");
        p2Name = ui->input();
        if (p2Name.compare(p1Name) == 0)
        {
            ui->print("You can't have the same name");
        }
        else
        {
            sameName = false;
        }
        
    }

    board->newGame(p1Name, p2Name);

    ui->print("Player 1: " + p1Name + " and Player 2: " + p2Name + " ready to play.");
}

void GameEngine::findPlayerTurn()
{
    while(!board->getPlayers()->head->isTurn())
    {
        board->getPlayers()->head = board->getPlayers()->head->next;
    }
}

void GameEngine::bagCheck()
{
    if (board->getBag()->empty())
    {
        //ui->print("empty bag");
        board->refillBag();
    }
}

void GameEngine::factoryCheck()
{
    if (board->emptyFactories() && board->emptyDump())
    {
        //ui->print("empty factories");
        board->refillFactories();
        board->addFirstTile();
    }
}

void GameEngine::printFactory()
{
    std::string output;
    ui->print("");
    ui->print("TURN FOR PLAYER: "+board->getPlayers()->head->getName());
    ui->print("Factories: ");

    for (int x = 0; x<6; x++)
    {
        output = std::to_string(x).append(": ");
        output.append(ui->printFactory((board->getFactories()+x)->getContent()));
        ui->print(output);
    }
}

void GameEngine::printMosaic()
{
    std::string output;
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
}

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
    
}

std::vector<std::string> GameEngine::parseLine(std::string str, char delim) {
    std::vector<std::string> res;
    std::stringstream s(str);

    while(s.good()) {
        std::string sub;
        getline(s, sub, delim);

        if (sub.size() > 0)
            res.push_back(sub);
    }

    return res;
}