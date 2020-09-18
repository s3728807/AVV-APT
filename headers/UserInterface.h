#ifndef USERINTERFACE
#define USERINTERFACE

namespace Azul
{
    class UserInterface
    {
        public:
            UserInterface();
            ~UserInterface();

            void print(std::string);
            std::string input();

        private:
    };
};
#endif