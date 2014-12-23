#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <stdlib.h>

using namespace std;

map<int, pair<float, float> > inital(const string &filename)
{
    ifstream in;
    in.open(filename.c_str());
    string line;
    int ID = 0;
    map<int, pair<float, float> > inital1;
    while(getline(in, line))
    {
        string str_x = "";
        string str_y = "";
        bool is_x = false;
        bool is_y = false;
        for (int i = 0; i < line.size(); i++) 
        {
            if(line[i] == '=' && line[i - 1] == 'x')
            {
                is_x = true;
                is_y = false;
            }
            else if(line[i] == '=' && line[i - 1] == 'y')
            {
                is_x = false;
                is_y = true;
            }
            else if(line[i] == 'r')
            {
                is_x = false;
                is_y = false;
                break;
            }
            else if(line[i] == 'c')
            {
                is_x = false;
                is_y = false;
            }

            if(is_x && line[i] != '=')
            {
                str_x += line[i];
            }
            else if(is_y && line[i] != '=')
            {
                str_y += line[i];
            }

        }
        float x = atof(str_x.c_str());
        float y = atof(str_y.c_str());
        inital1.insert(make_pair(ID, make_pair(x, y)));
        ID++;
    }
    in.close();
    return inital1;
}

int main(int argc, const char *argv[])
{
    map<int, pair<float, float> > result;
    result = inital("data.txt");
    for(map<int, pair<float, float> >::iterator it = result.begin(); 
                                  it != result.end(); ++it)
    {
        cout << "ID= " << it->first <<" (x,y) = "<< it->second.first
            << "  " << it->second.second << endl;    
    }

    return 0;
}
