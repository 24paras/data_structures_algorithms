#include <iostream>
using namespace std;


bool isExtra(char ch)
{
    if (ch == '!' || ch == '@' || ch == '^' || ch == '\'' )
        return true;
    return false;
}
int main()
{
    string s = "PaRaS!nghHJ@in^!!sdxshgbg'";
    replace_if(s.begin(), s.end(), isExtra, ' ');
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << s << endl;

    return 0;
}