#include <iostream>

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

void transposeSparseMatrix(const Element sparseMatrix[], Element transposed[], int numElements, int numRows) {
    int count[MAX_SIZE] = {0};

    for (int i = 0; i < numElements; ++i) {
        transposed[i].row = sparseMatrix[i].col;
        transposed[i].col = sparseMatrix[i].row;
        transposed[i].val = sparseMatrix[i].val;
    }

    countingSortTranspose(transposed, count, numElements);
}

int main() {
    Element sparseMatrix[] = {
        {0, 1, 10},
        {0, 3, 12},
        {1, 2, 11},
        {2, 0, 14},
        {3, 2, 18}
    };
    int numElements = 5;
    int numRows = 4;
    Element transposed[5];

    transposeSparseMatrix(sparseMatrix, transposed, numElements, numRows);
    std::cout << "Original Sparse Matrix (row, col, value):" << std::endl;
    for (int i = 0; i < numElements; ++i) {
        std::cout << "(" << sparseMatrix[i].row << ", " << sparseMatrix[i].col << ", " << sparseMatrix[i].val << ")" << std::endl;
    }

    std::cout << "Transposed Sparse Matrix (row, col, value):" << std::endl;
    for (int i = 0; i < numElements; ++i) {
        std::cout << "(" << transposed[i].row << ", " << transposed[i].col << ", " << transposed[i].val << ")" << std::endl;
    }

    return 0;
}
