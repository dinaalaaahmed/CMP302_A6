#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void minTeam(bool friendships[][15], bool issued[], int N,int j, int i, int size, bool& m) {

    if (size == N) {
        if (friendships[0][i] || i==0) 
            m = true;
        size = 1;
        i = 0;
        return;
    }


    for (int j = 0; j < N; j++)
        if (!issued[j] && friendships[i][j]) {
            issued[j] = true;
            size++;  
            minTeam(friendships, issued, N, j+1 ,j, size, m);
            issued[j] = false;
            size--;
        }
}


int main() {
    int N, numberOfEdges;
    bool friendships[15][15]; int num1, num2; bool issued[15];
    cin >> N >> numberOfEdges;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            friendships[i][j] = 0;

        }
        issued[i] = false;
    }

    for (int i = 0; i < numberOfEdges; i++) {
        cin >> num1 >> num2;
        friendships[num1][num2] = 1;
        friendships[num2][num1] = 1;

    }
    issued[0] = true;
    bool result = 0;
    minTeam(friendships, issued, N, 0, 0,1, result);
    cout << result;
    return 0;
}

