#include <iostream>
#include <string>
using namespace std;

int main()
{
    std::string out = "\0";
    int index = 0;
    bool wasSpace = 0;

    char c = '\0';

    while (cin.get(c)) {

        if ((index == 0) || !((c == ' ') && wasSpace)) {
            out.push_back(c);
            index++;
        }

        wasSpace = c == ' ';

        if(c == '\0' || c == '\n')
            break;
    }
    cout << std::out << "\n" << endl;

    return 0;
}