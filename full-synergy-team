#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool isCorrect(int i, bool array[15], bool friendships[][15], int N) {
    for (int j = 0; j < N; j++)
        if (array[j] && !friendships[i][j])
            return 1;
    return 0;
}
void minTeam(bool friendships[][15], bool issued[], int N, int& result, bool array[15]) {
    int size = 0;
    for (int k = 0; k < N; k++) {
        issued[k] = true;
        array[k] = 1;
        size++;
        for (int j = 0; j < N; j++)
            if ((k!=j) && !issued[j] && !isCorrect(j, array, friendships, N)) {
                issued[j] = true;
                array[j] = 1;
                size++;
            }
        if (size > result)
            result = size;
        for (int i = 0; i < N; i++) {
             array[i] = 0;
            issued[i] = false;
        }
        size = 0;
    }
}


int main() {
    int N, numberOfEdges;
    bool friendships[15][15]; int num1, num2; bool issued[15];
    bool array[15];
    cin >> N >> numberOfEdges;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            friendships[i][j] = 0;
            
        }
        array[i] = 0;
        issued[i] = false;
    }

    for (int i = 0; i < numberOfEdges; i++) {
        cin >> num1 >> num2;
        friendships[num1][num2] = 1;
        friendships[num2][num1] = 1;

    }

    int result = 1;
    minTeam(friendships, issued, N, result, array);
    cout << result;
    return 0;
}

