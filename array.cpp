#include <iostream>

using namespace std;

int main(){

    int m[4][4];

    m[0][0] = 10;
    m[3][3] = 10;
    for(int i = 0; i<4; i++ ){
        for(int j = 0 ; j<4 ; j++){
            cout<<m[i][j];
        }
        cout<<endl;
    }
    return 0;
}