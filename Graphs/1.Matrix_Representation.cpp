#include <iostream>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    int** Matrix = new int*[n];
    for(int i = 0; i < n; i++) {
        Matrix[i] = new int[n];
        for(int j = 0; j < n; j++) {
            Matrix[i][j] = 0;
        }
    }
    for(int i = 0; i < e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        Matrix[v1][v2] = 1;
         Matrix[v2][v1] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << Matrix[i][j] << " ";
        }
        cout << "\n";
    }
}