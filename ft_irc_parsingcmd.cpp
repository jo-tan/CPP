#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <numeric>
#include <sstream>


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

std::string cmdArgToString(const std::vector<std::string> &cmdVector){
    std::string ret;

    if (cmdVector.size() <= 1){
        return ret;
    }
    ret = std::accumulate(cmdVector.begin() + 1, cmdVector.end(), std::string(""), [](const std::string &a, const std::string &b)
    {return a.empty()? b: a + " " + b;});

    return ret;
}

std::string cmdVecToString(const std::vector<std::string> &cmdVector){
    std::string ret;

    if (cmdVector.size() <= 1){
        return ret;
    }
    std::ostringstream tmp;
    for(size_t i = 1; i < cmdVector.size(); ++i){
        if (i > 1){
            tmp << " ";
        }
        tmp << cmdVector[i];
    }
    return ret = tmp.str();
}

int main(){

    std::string command = "NICK bonjour    commont ca   va         ?";

    std::vector<std::string> cmdTable = parseCommand(command);
    for(int i = 0; i < cmdTable.size(); ++i)
        std::cout << "string{" << cmdTable[i] << "}: " << i << std::endl;

//     std::string test = cmdArgToString(cmdTable);
//     std::cout << "TEST STRING:" << test << std::endl;

//     std::string oss = cmdVecToString(cmdTable);
//     std::cout << "OSS STRING:" << oss << std::endl;

}