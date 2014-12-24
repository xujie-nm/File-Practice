#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <math.h>

using namespace std;

#define CENTER_X 831.701991
#define CENTER_Y 3660.15561

float dis_point(float x, float y)
{
    return (sqrt(pow((x - CENTER_X), 2) + pow((y - CENTER_Y), 2)));
}

void dis_avg(const string &filename)
{
    ifstream in;
    in.open(filename.c_str());
    
    double dis_sum = 0;
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
        dis_sum += dis_point(x, y);
        points++;
    }

    cout << "dis_sum is " << dis_sum  << "  points is "<< points << endl;
    cout << "avg_dis is " << dis_sum / points << endl;

    in.close();
}

int main(int argc, const char *argv[])
{
    dis_avg(argv[1]); 
    return 0;
}
