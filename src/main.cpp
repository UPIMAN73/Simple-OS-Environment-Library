//#include "system/math.h"
#include "commands/command.h"



int main() {
    std::string command = "";
    Active_Console = true;
    while (Active_Console) {
        Printf("Command: ");
        std::getline(std::cin, command);
        runCommand(split(command, " "));
        Println("\n");
    }
    return 0;
}
