#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
ifstream in_data1;
ofstream out_data1;
using namespace std;

class graphColoring {

public:

    int **adjacencyMatrix;
    int uNode = 0;
    int newColor = 0;
    int numNodes = 0;

    ~graphColoring() {
        for (int k = 0; k < numNodes; k++) {
            delete[] adjacencyMatrix[k];
        }
        delete[] adjacencyMatrix;
    }

    graphColoring(ifstream &data) {
        data >> numNodes; //store first number to numNodes
        cout << "Number of Nodes: " << numNodes;

        loadMatrix(data);
        out_data1 << "Initial Matrix:" << endl;
        printMatrix();
        colorGraph();
    }

    void colorGraph() {

        //STEP 5: repeat steps 1-3 until all nodes are colored
        while (!checkAllColored()) {

            //STEP 1:
            newColor++;

            //STEP 2 & 3:
            for (int j = 0; j < numNodes; j++) {
                //find uncolored node
                if (adjacencyMatrix[j][j] == 0) {
                    if (checkAdjacencyValid(j, newColor)) {
                        adjacencyMatrix[j][j] = newColor;
                    }
                }

            }
        }
        //STEP 4:
        out_data1 << "Number of colors used: " << newColor << endl;
        out_data1 << "Final Matrix: " << endl;
        printMatrix();

    }

    bool checkAdjacencyValid(int currentNode, int currentColor) {
        for (int i = 0; i < numNodes; i++) {
            if (adjacencyMatrix[currentNode][i] == -1 || adjacencyMatrix[i][currentNode] == -1) {
                if (adjacencyMatrix[i][i] == currentColor) return false;
            }
        }
        return true;
    }

    bool checkAllColored() {
        for (int i = 0; i < numNodes; i++) {
            if (adjacencyMatrix[i][i] == 0) return false;
        }
        return true;
    }

    void printMatrix() {
        for (int i = 0; i < numNodes; i++) {
            out_data1 << endl;
            for (int k = 0; k < numNodes; k++) {
                if (adjacencyMatrix[i][k] == -1) {
                    out_data1 << setw(4) << "X" << " ";
                } else
                    out_data1 << setw(4) << adjacencyMatrix[i][k] << " ";
            }
        }
        out_data1 << endl << endl << endl;


    }

    void loadMatrix(ifstream &data) {

        int row = 0, col = 0;

        adjacencyMatrix = new int *[numNodes]();

        for (int i = 0; i < numNodes; ++i) {
            adjacencyMatrix[i] = new int[numNodes]();
        }

        out_data1 << "Input Pairs: " << endl;

        while (!data.eof()) {
            data >> row;
            data >> col;
            out_data1 << "<" << row << ", " << col << "> ";
            out_data1 << "<" << col << ", " << row << ">" << endl;
            adjacencyMatrix[row - 1][col - 1] = -1;
            adjacencyMatrix[col - 1][row - 1] = -1;
        }
        out_data1 << endl;
    }
};

int main(int argc, char *argv[]) {

    in_data1.open(argv[1]);
    out_data1.open(argv[2]);

    graphColoring graph(in_data1);

    in_data1.close();
    out_data1.close();

    return 0;
}