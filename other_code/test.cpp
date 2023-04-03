#include <iostream>
using namespace std;

#define n 2

int main() {
    int matA[n][n], matB[n][n], resm1[n][n], resm2[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>matA[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>matB[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            resm1[i][j] = matB[i][j] - matA[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            resm2[i][j] = matB[i][j] + matA[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            swap(resm2[i][j], resm2[j][i]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<resm1[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<resm2[i][j]<<" ";
        }
        cout<<endl;
    }
}