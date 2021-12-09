#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    string str;
    getline(cin, str);

    const char symbol_one_time = '(';
    const char symbol_many_times = ')';

    const int seen_many_times = -1;
    map<char, int> last_seen_symbol_pos;
    for (int i = 0; i < str.size(); ++i)
    {
        char c = tolower(str[i]);
        
        if (last_seen_symbol_pos.count(c) == 0)
        { // symbol was not seen yet
            last_seen_symbol_pos[c] = i;
            str[i] = symbol_one_time;
            continue;
        }
        int& pos = last_seen_symbol_pos[c];
        if (pos == seen_many_times)
        { // symbol was seen many times
            str[i] = symbol_many_times;
        }
        else
        { // symbol already was seen one time and this (i) is second time
            str[pos] = symbol_many_times;
            str[i] = symbol_many_times;
            pos = seen_many_times;
        }
    }

    cout << str << endl;
    
    return 0;
}
