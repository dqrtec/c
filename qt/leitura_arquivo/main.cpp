#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

int main(){
    string line;
    double x ,y ,z;
    int v1,v2,v3;
    string objeto;

    ifstream file("triangulo.obj");
    while (!file.eof()) {
        getline (file,line);
        if(line[0] == 'v'){
            cout<<"v ------------- "<<endl;
            sscanf(line.c_str(), "v %lf %lf %lf\n", &x, &y, &z);
            cout<<x <<" "<<y<<" "<<z<<endl;
        }
        else if(line[0] == 'f'){
            cout<<"f ------------- "<<endl;
            sscanf(line.c_str(), "f %lf %lf %lf\n", &x, &y, &z);
            cout<<x <<" "<<y<<" "<<z<<endl;
        }
        else if(line[0] == 'o'){
            objeto=line;
        }
    }
return 0;
}
