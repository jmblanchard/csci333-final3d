#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

int main(int argc, char *argv[]) {
    if (argc == 3) {
        char *filename = argv[1];
        int threshhold = atoi(argv[2]);
        std::string line;
        std::ifstream file(filename);
        std::map<std::string, int> names;
        std::map<std::string, int>::iterator it;

        if (file.is_open()) {
            while (!file.eof()) {
                std::getline(file, line);

                if (names.count(line) == 1) {
                    names[line] = names[line]+1;
                } else {
                    names[line] = 1;
                }
            }

            file.close();
        }
        names.erase("");

        // print nice names
        std::cout << "NICE LIST\n";
        for (it = names.begin(); it != names.end(); ++it) {
            if ((*it).second >= threshhold) {
                std::cout << (*it).first << "\n";
            }
        }

        // print naughty names
        std::cout << "\n\nNAUGHTY LIST\n";
        for (it = names.begin(); it != names.end(); ++it) {
            if ((*it).second < threshhold) {
                std::cout << (*it).first << "\n";
            }
        }
    }

    return 0;
}
