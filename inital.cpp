#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>

using namespace std;



int main(int argc, const char *argv[])
{
    ifstream in;
    in.open("data.txt");
    string line;

    float max_x = 0, min_x = 0, max_y = 0, min_y = 0;
    while(getline(in, line))
    {
        string str_x = "";
        string str_y = "";
        bool is_x = false;
        bool is_y = false;
        for(int i = 0; i< line.size(); i++)
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
        if(x > max_x)
            max_x = x;
        if(x < min_x)
            min_x = x;
        if(y > max_y)
            max_y = y;
        if(y < min_y)
            min_y = y;
        cout << "x=  " << x << " y= " << y << endl;
    }
    
    cout << "max_x = " << max_x << " max_y = " << max_y << endl;
    cout << "min_x = " << min_x << " min_y = " << min_y << endl; 

    in.close();

    return 0;
}
