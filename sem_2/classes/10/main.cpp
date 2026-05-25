#include <iostream>
#include <string>
#include "Money.h"
#include "File_work.h"

int main() {
    Money m;
    std::string file;
    int cmd, resp;

    do {
        std::cout << "1. Make file" << std::endl;
        std::cout << "2. Read file" << std::endl;
        std::cout << "3. Delete from file" << std::endl;
        std::cout << "4. Add to file" << std::endl;
        std::cout << "5. Increase file" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "> ";
        std::cin >> cmd;

        switch (cmd) {
            case 1:
                std::cout << "Enter name of file:" << std::endl;
                std::cout << "> ";
                std::cin >> file;
                resp = make_file(file);

                if (resp < 0) {
                    std::cout << "Can`t make file!" << std::endl;
                }
                break;

            case 2:
                std::cout << "Enter name of file:" << std::endl;
                std::cout << "> ";
                std::cin >> file;
                resp = print_file(file);

                if (resp < 0) {
                    std::cout << "Can`t read file!" << std::endl;
                }
                else if (resp == 0) {
                    std::cout << "File is empty" << std::endl;
                }
                break;

            case 3:
                std::cout << "Enter name of file:" << std::endl;
                std::cout << "> ";
                std::cin >> file;
                std::cout << "Enter parameters of object:" << std::endl;
                std::cin >> m;

                resp = del_from_file(file, m);

                if (resp < 0) {
                    std::cout << "Can`t open file!" << std::endl;
                }
                else if (resp == 0) {
                    std::cout << "File is empty" << std::endl;
                }
                else {
                    std::cout << "Objects were deleted" << std::endl;
                }
                break;

            case 4:
                int pos;
                int k;
                std::cout << "Enter name of file:" << std::endl;
                std::cout << "> ";
                std::cin >> file;
                std::cout << "Enter count of object:" << std::endl;
                std::cin >> k;
                std::cout << "Enter insertion number: ";
                std::cin >> pos;

                resp = add_to_file(file, pos, k);

                if (resp < 0) {
                    std::cout << "Can`t open file!" << std::endl;
                }
                else if (resp == 0) {
                    add_to_end(file, k);
                    std::cout << "Object was added" << std::endl;
                }
                else {
                    std::cout << "Object was added" << std::endl;
                }
                break;

            case 5:
                std::cout << "Enter name of file:" << std::endl;
                std::cout << "> ";
                std::cin >> file;
                Money m;
                std::cout << "Enter parameters of object:" << std::endl;
                std::cin >> m;

                resp = increase_file(file, m);

                if (resp < 0) {
                    std::cout << "Can`t open file!" << std::endl;
                }
                else if (resp == 0) {
                    std::cout << "Nothing was changed" << std::endl;
                }
                else {
                    std::cout << "Objects were changed" << std::endl;
                }
                break;
        }
    } while(cmd != 0);


    return 0;
}