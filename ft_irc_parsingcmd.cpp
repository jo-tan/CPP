#include <iostream>
#include <string>
#include <vector>
#include <set>

bool _validCommand(std::string &command)
{
    std::string theCommand = command.substr(0, command.find(" "));
    static const std::set<std::string> validCommands = {"CAP","NICK","USER","MSG","JOIN", "SAY", "LEAVE", "KICK", "INVITE", "TOPIC", "MODE"};
    return validCommands.find(theCommand) != validCommands.end();
}

std::vector<std::string> _splitCommand(std::string &command)
{
    std::vector<std::string> cmdTable;
    std::string tmp;
    size_t start;
    size_t end = 0;
    while ((start = command.find_first_not_of(' ', end)) != std::string::npos) {
        end = command.find(' ', start);
        cmdTable.push_back(command.substr(start, end - start));
    }
    return cmdTable;
}

std::vector<std::string> parseCommand(std::string &command)
{
    if (_validCommand(command))
        return _splitCommand(command);
    else
        return std::vector<std::string>();
}

int main(){

    std::string command = "NICK test    how is   youur         day";

    std::vector<std::string> cmdTable = parseCommand(command);
    for(int i = 0; i < cmdTable.size(); ++i)
        std::cout << "string{" << cmdTable[i] << "}: " << i << std::endl;
}