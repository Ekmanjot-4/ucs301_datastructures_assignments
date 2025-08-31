#include <iostream>
using namespace std;

void transpose(int sparse[][3], int nz) {
    for (int i = 0; i < nz; i++) {
        int temp = sparse[i][0];
        sparse[i][0] = sparse[i][1];
        sparse[i][1] = temp;
    }
}

void multiply(int sparse1[][3], int nz1, int row1,
              int sparse2[][3], int nz2, int row2, int col2) {
    transpose(sparse2, nz2);  
    int res[nz1 * nz2][3];
    int k = 0;

    for (int i = 0; i < nz1; i++) {
        for (int j = 0; j < nz2; j++) {
            if (sparse1[i][1] == sparse2[j][1]) 
            {  
                int r = sparse1[i][0];
                int c = sparse2[j][0];
                int val = sparse1[i][2] * sparse2[j][2];

                int found = 0;
                for (int x = 0; x < k; x++) {
                    if (res[x][0] == r && res[x][1] == c) {
                        res[x][2] += val;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    res[k][0] = r;
                    res[k][1] = c;
                    res[k][2] = val;
                    k++;
                }
            }
        }
    }

    cout << "Resultant Matrix:" << endl;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            int found = 0;
            for (int x = 0; x < k; x++) {
                if (res[x][0] == i && res[x][1] == j) {
                    cout << res[x][2] << " ";
                    found = 1;
                    break;
                }
            }
            if (!found) cout << "0 ";
        }
        cout << endl;
    }
}

int main() {
    int nz1, nz2;
    int row1, row2, col1, col2;

    cout << "Enter the number of rows and columns in matrix 1: ";
    cin >> row1 >> col1;
    cout << "Enter the number of rows and columns in matrix 2: ";
    cin >> row2 >> col2;

    cout << "Enter the number of non-zero elements in matrix 1: ";
    cin >> nz1;
    int sparse1[nz1][3];
    cout << "Enter triplets (row col value) for matrix 1:" << endl;
    for (int i = 0; i < nz1; i++) {
        cin >> sparse1[i][0] >> sparse1[i][1] >> sparse1[i][2];
    }

    cout << "Enter the number of non-zero elements in matrix 2: ";
    cin >> nz2;
    int sparse2[nz2][3];
    cout << "Enter triplets (row col value) for matrix 2:" << endl;
    for (int i = 0; i < nz2; i++) {
        cin >> sparse2[i][0] >> sparse2[i][1] >> sparse2[i][2];
    }

    if (col1 == row2) {
        multiply(sparse1, nz1, row1, sparse2, nz2, row2, col2);
    } else {
        cout << "Matrix multiplication not possible!" << endl;
    }

    return 0;
}
