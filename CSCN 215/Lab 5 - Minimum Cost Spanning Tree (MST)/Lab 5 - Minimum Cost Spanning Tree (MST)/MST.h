#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <fstream>

#pragma once

typedef std::pair<int, std::pair<int, int>> edge_pair;

template <typename K, typename V>
bool compare_pairs_by_first_min(const std::pair<K, V>& lhs, const std::pair<K, V>& rhs)
{
    return lhs.first < rhs.first;
}

class MST {
private:
    int nodes;
    std::vector<std::vector<int>> adjacency_matrix;
public:
    MST(std::vector<std::vector<int>>& adjacency_matrix) {
        this->adjacency_matrix = adjacency_matrix;
        nodes = adjacency_matrix.size();
    }

    void print_info(std::ostream* output = &std::cout) {
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                *output << adjacency_matrix[i][j] << " ";
            }
            *output << std::endl;
        }
    }

    void start_operation(int current_vertex, std::ostream* output) {
        // Initalize the 2D matrix of all zeros
        std::vector<std::vector<int>> new_matrix(nodes, std::vector<int>(nodes, 0));

        // Create a priority queue
        std::vector<edge_pair> edges;
        std::unordered_set<int> ignore_index;
        std::unordered_set<int> visited_vertices;

        // Loop until all vetices are visited
        while (visited_vertices.size() != nodes) {

            // Insert all values into the priority queue before we decide which one to take
            for (int i = 0; i < nodes; i++) {
                int value = adjacency_matrix[current_vertex][i];
                // If we have a value that is not 0 and we have not visited it yet then we add it to the queue
                if (value != 0 && ignore_index.find(i) == ignore_index.end()) {
                    // insert the value and the index
                    std::pair<int, int> indices = std::make_pair(current_vertex, i);

                    edges.push_back(std::make_pair(value, indices));

                    // orgzanize the queue
                    std::push_heap(edges.begin(), edges.end(), compare_pairs_by_first_min<int, std::pair<int, int>>);
                }
            }

            // Get the top value from the queue
            edge_pair top = edges.back();
            std::pop_heap(edges.begin(), edges.end(), compare_pairs_by_first_min<int, std::pair<int, int>>);


            // print out
            int top_row = top.second.first;
            int top_column = top.second.second;
            std::cout << "Add edge " << top_row << " to " << top_column << std::endl;
            *output << "Add edge " << top_row << " to " << top_column << std::endl;

            // add the value into the new matrix (2 places because of the way it is mirrored)
            new_matrix[top_row][top_column] = top.first;
            new_matrix[top_column][top_row] = top.first;


            // add the index to the ignore list and remove all elements from the queue that have that index
            ignore_index.insert(top_row);
            ignore_index.insert(top_column);

            visited_vertices.insert(top_row);
            visited_vertices.insert(top_column);

            // Remove all elements from the queue that have the index by adding to a vector
            std::vector<int> to_remove_list;
            for (int i = 0; i < edges.size(); i++) {
                int current_column = edges[i].second.second;
                if (current_column == current_vertex || current_column == top_column) {
                    to_remove_list.push_back(i);
                }
            }

            // Run through the temp vector and remove all elements from the queue
            int remove_count = 0;
            for (int remove_i : to_remove_list) {
                edges.erase(edges.begin() + remove_i - remove_count);
                remove_count++;
            }

            current_vertex = top_column;

            // Remake the heap
            std::make_heap(edges.begin(), edges.end(), compare_pairs_by_first_min<int, std::pair<int, int>>);
        }
        adjacency_matrix = new_matrix;
        
        *output << std::endl;
        std::cout << std::endl;
    }
};