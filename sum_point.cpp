#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>

using namespace std;

void sum_point(const string &filename)
{
    ifstream in;
    in.open(filename.c_str());
    
    double sum_x = 0;
    double sum_y = 0;
    int points = 0;
    string line;
    while(getline(in, line))
    {
        string str_x, str_y;
        int pos = line.find(" ");
        str_x = line.substr(0, pos);
        str_y = line.substr(pos + 1);
        double x = atof(str_x.c_str());
        double y = atof(str_y.c_str());
        sum_x += x;
        sum_y += y;
        points++;
    }

    cout << "the sum points is " << points << endl;
    cout << "the sum x is " << sum_x << " the sum y is " << sum_y << endl;


    in.close();
}

int main(int argc, const char *argv[])
{
    sum_point(argv[1]);
    return 0;
}
