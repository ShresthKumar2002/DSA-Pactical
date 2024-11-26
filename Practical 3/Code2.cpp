#include <iostream>
#include <vector>

const int MAX_SIZE = 100;

struct Element {
    int row, col, val;
};

void countingSortTranspose(Element transposed[], int count[], int n) {
    Element output[MAX_SIZE];

    for (int i = 0; i < n; ++i)
        ++count[transposed[i].row + 1];

    for (int i = 1; i < MAX_SIZE; ++i)
        count[i] += count[i - 1];

    for (int i = 0; i < n; ++i) {
        output[count[transposed[i].row]++] = transposed[i];
    }

    for (int i = 0; i < n; ++i)
        transposed[i] = output[i];
}

void transposeSparseMatrix(const Element sparseMatrix[], Element transposed[], int numElements) {
    int count[MAX_SIZE] = {0};

    for (int i = 0; i < numElements; ++i) {
        transposed[i].row = sparseMatrix[i].col;
        transposed[i].col = sparseMatrix[i].row;
        transposed[i].val = sparseMatrix[i].val;
    }

    countingSortTranspose(transposed, count, numElements);
}

void multiplySparseMatrices(const Element matA[], const Element matB[], Element result[], int nonZeroA, int nonZeroB, int &nonZeroResult, int rowsA, int colsB, int commonDim) {
    Element transposedB[MAX_SIZE];
    transposeSparseMatrix(matB, transposedB, nonZeroB);

    nonZeroResult = 0;
    for (int i = 0; i < nonZeroA; ++i) {
        for (int j = 0; j < nonZeroB; ++j) {
            if (matA[i].col == transposedB[j].col) {
                int r = matA[i].row;
                int c = transposedB[j].row;
                bool found = false;
                for (int k = 0; k < nonZeroResult; ++k) {
                    if (result[k].row == r && result[k].col == c) {
                        result[k].val += matA[i].val * transposedB[j].val;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    result[nonZeroResult].row = r;
                    result[nonZeroResult].col = c;
                    result[nonZeroResult].val = matA[i].val * transposedB[j].val;
                    ++nonZeroResult;
                }
            }
        }
    }
}

int main() {
    // Sparse matrix A in 3-column form: (row, col, value)
    Element matA[] = {
        {0, 0, 1},
        {0, 2, 2},
        {1, 1, 3}
    };
    int nonZeroA = 3;
    int rowsA = 2, commonDim = 3;

    // Sparse matrix B in 3-column form: (row, col, value)
    Element matB[] = {
        {0, 0, 4},
        {1, 2, 5},
        {2, 0, 6}
    };
    int nonZeroB = 3;
    int colsB = 3;

    Element result[MAX_SIZE];
    int nonZeroResult = 0;

    std::cout << "First Sparse Matrix (row, col, value):" << std::endl;
    for (int i = 0; i < nonZeroA; ++i) {
        std::cout << "(" << matA[i].row << ", " << matA[i].col << ", " << matA[i].val << ")" << std::endl;
    }
    std::cout << "\nSecond Sparse Matrix (row, col, value):" << std::endl;
    for (int i = 0; i < nonZeroB; ++i) {
        std::cout << "(" << matB[i].row << ", " << matB[i].col << ", " << matB[i].val << ")" << std::endl;
    }

    multiplySparseMatrices(matA, matB, result, nonZeroA, nonZeroB, nonZeroResult, rowsA, colsB, commonDim);

    // Print the result matrix
    std::cout << "\nResultant Sparse Matrix (row, col, value):" << std::endl;
    for (int i = 0; i < nonZeroResult; ++i) {
        std::cout << "(" << result[i].row << ", " << result[i].col << ", " << result[i].val << ")" << std::endl;
    }

    return 0;
}
