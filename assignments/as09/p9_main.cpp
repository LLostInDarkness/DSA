/*
  Rebecca Negrete
  rnegrete
  rnegrete0454@gmail.com
  Assignmnent 9: Floyd-Warshall

  Tested & Works, no mem leaks found

  Purpose: Read from STDIN complete directed edges on each line of input,
           formatted as this: source/start node, destination/end node, and
           weight of said edge.  Outputs a final destination matrix and parent
           matrix.
*/

#include <string>
#include <iostream>
#include <vector>
#include <limits.h>
#include <sstream>
#include <algorithm>

// is the max value an integer can have/hold, thought this was better than 99999
const int MAX_VAL = INT_MAX;

std::vector<std::vector<int>> matrixEdges(std::vector<std::string>&edge_inputs) {
  int max_vec = 0;
  std::vector<std::tuple<int, int, int>> edges;

  for (std::string& edge : edge_inputs) {
    std::string line = edge;
    replace(line.begin(), line.end(), ',', ' ');

    std::stringstream num_inputs(line);
    int start_node, end_node, weight;

    if (num_inputs >> start_node >> end_node >> weight) {
      // pushes back the three variables in a vector
      edges.push_back({start_node, end_node, weight});
      // gets max value
      max_vec = std::max(max_vec, std::max(start_node, end_node));
    }
  }

  // accounts for the vector being 0 indexed
  int n = max_vec + 1;
  std::vector<std::vector<int>> graph(n, std::vector<int>(n, MAX_VAL));

  for (int i = 0; i < n; i++) {
    graph[i][i] = 0;
  }

  for (auto& [start_node, end_node, weight] : edges) {
    graph[start_node][end_node] = weight;
  }

  return graph;
}

void results(const std::vector<std::vector<int>>& d_vals, const std::vector<std::vector<int>>& p_vals) {
    int n = d_vals.size();
    int start;
    bool distance = false;

    for (int i = 0; i < n && !distance; i++) {
        for (int j = 0; j < n && !distance; j++) {
            if ((i == 0 || j == 0) && d_vals[i][j] != MAX_VAL 
                 && d_vals[i][j] != 0) {
                distance = true;
            }
        }
    }

    if (distance) {
      start = 0;
    } else {
      start = 1;
    }

    int end = n;

    // print distance matrix (D)
    std::cout << "D";
    for (int j = start; j < end; j++) {
        std::cout << " " << j << ":";
    }
    std::cout << "\n";

    for (int i = start; i < end; i++) {
        std::cout << i << ":";
        for (int j = start; j < end; j++) {
            std::cout << " ";
            if (i == j || d_vals[i][j] == MAX_VAL || d_vals[i][j] == 0) {
                std::cout << ".";
            } else {
                std::cout << d_vals[i][j];
            }
        }
        std::cout << "\n";
    }

    std::cout << "\n";

    // print parent/predecessor matrix (P)
    std::cout << "P";
    for (int j = start; j < end; j++) {
        std::cout << " " << j << ":";
    }
    std::cout << "\n";

    for (int i = start; i < end; i++) {
        std::cout << i << ":";
        for (int j = start; j < end; j++) {
            std::cout << " ";

            // if no edge from i to j or if no shorter path is found
            if (i == j || p_vals[i][j] == -1) {
                std::cout << ".";
            } else {
                std::cout << p_vals[i][j];
            }
        }
        std::cout << "\n";
    }
}

void floydWarshall(std::vector<std::vector<int>>&graph) {
  int n = graph.size();

  // used to create distance matrix
  std::vector<std::vector<int>> d_vals = graph;

  // used to create parent/predecessor matrix
  std::vector<std::vector<int>> p_vals(n, std::vector<int>(n, -1));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && graph[i][j] != MAX_VAL) {
        p_vals[i][j] = i;
      }
    }
  }

  for (int a = 0; a < n; a++) {
    for (int b = 0; b < n; b++) {
      for (int c = 0; c < n; c++) {
        if (d_vals[b][a] != MAX_VAL && d_vals[a][c] != MAX_VAL &&
            d_vals[b][a] + d_vals[a][c] < d_vals[b][c]) {
          d_vals[b][c] = d_vals[b][a] + d_vals[a][c];
          p_vals[b][c] = p_vals[a][c];
        }
      }
    }
  }

  results(d_vals, p_vals);
}

int main() {
  std::string line;
  std::vector<std::string> edge_inputs;

  while (std::getline(std::cin, line)) {
    edge_inputs.push_back(line);
  }

  std::vector<std::vector<int>>graph = matrixEdges(edge_inputs);

  std::cout << std::endl;
  floydWarshall(graph);
}