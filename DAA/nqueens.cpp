// pastebin.com/deenFDkZ

#include <iostream>
#include <vector>
using namespace std;

int count;
vector<int> solution;

bool canPlace(int row) {
    int col = solution[row];
    for(int i = 1; i < row; i++) {
        // if they are in same column
        // or in diagonals
//        (1, 2) (1, 3) (1, 4)
//        (2, 2) (2, 3)
//        (3, 2)
        if((solution[i] == col) || abs(solution[i] - col) == abs(row - i)) {
            return false;
        }
    }

    return true;
}

void printSolution(int n) {
    count++; // increment no of solutions
    cout << "Solution " << count << ": " << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(solution[i] == j) {
                cout << "Q ";
            } else {
                cout << "* ";
            }
        }
        cout << endl;
    }
}

void nqueens(int n) {
    int row = 1;

    while(row != 0) {
        solution[row]++;  // by default we place the queen at first column

        // we are not at end && we cant place queen at col
        while((solution[row] <= n) && !canPlace(row)) {
            solution[row]++;
        }

        if(solution[row] <= n) {
            // if we are at last row we found
            if(row == n) {
                printSolution(n);
            } else {
                row++;
            }
        } else {
            solution[row] = 0;
            row--; // backtrack
        }
    }
}

int main() {

    int n;
    cout << "Number of N queens: ";
    cin >> n;

    count = 0;
    solution.resize(n+1, 0);

    nqueens(n);

    cout << "No of possible solutions: " << count << endl;

    return 0;
}
