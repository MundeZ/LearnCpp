#pragma once
#include <iostream>
#include <vector>

constexpr auto SIZE = 10;

class Graph
{
public:
    Graph() : vertexCount(0) // Инициализация vertexCount в списке инициализации
    {
        for (size_t i = 0; i < SIZE; i++)
        {
            for (size_t j = 0; j < SIZE; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    void addVertex(int vnumber);
    void addEdge(int v1, int v2, int weight);
    void showVertexes();
    void showWeight(int v1, int v2);
    void delVertex(int vnumber);
    void delEdge(int v1, int v2);
    void depth(int start);
    void width(int start);
    bool edgeExists(int v1,int v2);
    int findPathCount(int from, int to);
    void find_min_dist_decstr(int vfrom);
    bool vertexExists(int vertexNum);
    void find_min_dist_floyd();
    bool are_adj(int v1, int v2);
    void find_min_way_dps_inner(int current, int target, bool visited[], std::vector<int>& currentPath, std::vector<int>& minPath, int& minDistance);
    int findMinWayDFS(int start, int target);

private:
    void depthInner(int current, bool visited[]);
    void findPathCountInner(int current, bool visited[], int to, int& countPath);
    int matrix[SIZE][SIZE];    // матрица смежности
    int vertexes[SIZE];        // хранилище вершин
    int vertexCount;            // количество добавленных вершин
};

