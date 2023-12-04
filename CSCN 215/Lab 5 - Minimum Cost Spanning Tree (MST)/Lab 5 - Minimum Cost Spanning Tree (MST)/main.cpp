#include <iostream>
#include <vector>
#include <fstream>
#include "MST.h"

using namespace std;

int main() {

    cout << "Carson Kramer -- Lab 5 Programming Assignment CSCN 215 -- Minimum Cost Spanning Tree (MST)" << endl << endl;

    int number_of_nodes;
    fstream file("input.txt");

    // Read the number of nodes
    file >> number_of_nodes;

    vector<vector<int>> adjacency_matrix;

    for (int row = 0; row < number_of_nodes; row++)
    {
        // Make a temp array vector to store the values in current row
        vector<int> current_row;
        for (int col = 0; col < number_of_nodes; col++)
        {
            // Create temp value
            int value;

            // Set temp value to current input file value at that position
            file >> value;

            // Add to end of temp array
            current_row.push_back(value);
        }

        // Add the populated vector values to our adjacency matrix
        adjacency_matrix.push_back(current_row);
    }

    // Smart pointer use
    std::unique_ptr<MST> min_span_tree(new MST(adjacency_matrix));

    // Print out number of vertices
    int nodes = adjacency_matrix.size();
    cout << "Number of vertices is " << nodes << endl;

    // Print out number of edges
    int edges = 0;
    for (int i = 0; i < nodes; i++) {
        for (int j = i; j < nodes; j++) {
            int value = adjacency_matrix[i][j];
            // if the value is not equal to 0 then we add 1 else its just 0
            edges += value != 0;
        }
    }
    cout << "Number of edges is " << edges << endl;

    // Print out initial matrix
    cout << "Matrix is:" << std::endl;
    min_span_tree->print_info();
    cout << endl << endl;

    // Start the MST at vertex 0
    fstream mst_file1("mst1.txt");
    mst_file1 << "Begin MST 1 starting at Vertex 0" << endl;
    cout << "Begin MST 1 starting at Vertex 0" << endl;
    min_span_tree->start_operation(0, &mst_file1);
    min_span_tree->print_info();
    min_span_tree->print_info(&mst_file1);
    mst_file1 << "End of MST 1" << endl << endl;
    cout << "End of MST 1" << endl << endl;


    std::unique_ptr<MST> min_span_tree2(new MST(adjacency_matrix));

    // Start the MST at vertex 4
    fstream mst_file2("mst2.txt");
    mst_file2 << "Begin MST 2 starting at Vertex 4" << endl;
    cout << "Begin MST 2 starting at Vertex 4" << endl;
    min_span_tree2->start_operation(4, &mst_file2);
    min_span_tree2->print_info();
    min_span_tree2->print_info(&mst_file2);
    mst_file2 << "End of MST 2" << endl << endl;
    cout << "End of MST 2" << endl << endl;


    std::unique_ptr<MST> min_span_tree3(new MST(adjacency_matrix));

    // Start the MST at vertex 2
    fstream mst_file3("mst3.txt");
    mst_file3 << "Begin MST 3 starting at Vertex 2" << endl;
    cout << "Begin MST 3 starting at Vertex 2" << endl;
    min_span_tree3->start_operation(2, &mst_file3);
    min_span_tree3->print_info();
    min_span_tree3->print_info(&mst_file3);
    mst_file3 << "End of MST 3" << endl << endl;
    cout << "End of MST 3" << endl << endl;

    system("pause");
    return 0;
}