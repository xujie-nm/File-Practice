#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <stdlib.h>
using namespace std;

void source_target(const string &filename)
{
    ifstream in_file;
    in_file.open(filename.c_str());
    map<int, int> money_map;

    ofstream out_ID;
    out_ID.open("ID_name.txt");
    
    string source_str = "{source:";
    string value_str = "value:";
    string line; 
    while(in_file >> line)
    {
        size_t source_pos = line.find(source_str);
        if(source_pos == -1)
            continue;
        source_pos += source_str.size();
        string str_ID = "";
        string str_value = "";
        for(int i = source_pos; line[i] != ','; i++)
            str_ID += line[i];
        out_ID << str_ID << endl;

        size_t value_pos = line.find(value_str) + value_str.size();
        for (int i = value_pos; line[i] != '}'; i++)
            str_value += line[i];

        int ID = atoi(str_ID.c_str());
        int value = atoi(str_value.c_str());
        money_map[ID] += value;
    }
    

    ofstream os_file;
    os_file.open("ID AND VALUE.txt");
    for(map<int, int>::iterator it = money_map.begin(); it != money_map.end(); ++it)
        os_file << "ID: "<< it->first <<"  value: "<< it->second << endl;    
    
    os_file.close();
    in_file.close();
}

int main(int argc, const char *argv[])
{
    source_target(string(argv[1]));
    return 0;
}
