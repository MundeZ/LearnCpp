#include "Graph.h"
#include <vector>

#define VERYBIGINT 1000000

void Graph::addVertex(int vnumber)
{
	vertexes[vertexCount++] = vnumber;
}

void Graph::addEdge(int v1, int v2, int weight)
{
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}

void Graph::showVertexes()
{

	for (size_t i = 0; i < SIZE; i++)
	{
		std::cout << "Vertex: " << vertexes[i] << std::endl;
	}

}

void Graph::showWeight(int v1, int v2)
{
	int weight = matrix[v1][v2];
	std::cout << "Weight: " << weight << std::endl;
}

void Graph::delVertex(int vnumber)
{
    // �������� ������� � ������ �������
    for (int i = 0; i < SIZE; i++)
    {
        matrix[i][vnumber] = 0;
        matrix[vnumber][i] = 0;
    }
    // ������� ������� �� ������ ������
    int foundIndex = -1;
    for (int i = 0; i < vertexCount; i++)
    {
        if (vertexes[i] == vnumber)
            foundIndex = i;
    }
    vertexCount--;
    for (int i = foundIndex; i < vertexCount; i++)
    {
        vertexes[i] = vertexes[i + 1];
    }
}

void Graph::delEdge(int v1, int v2)
{
    matrix[v1][v2] = 0;
    matrix[v2][v1] = 0;
}

void Graph::depthInner(int current, bool visited[])
{
    std::cout << "V" << current << ", ";
    visited[current] = true;
    for (size_t i = 0; i < vertexCount; i++)
    { 
        int vnum = vertexes[i];
        if (matrix[current][vnum] !=0 && !visited[vnum])
        {
            depthInner(vnum, visited);
        }
    }
}

void Graph::depth(int start)
{
    bool visited[SIZE];
    for (size_t i = 0; i < SIZE; i++)
    {
        visited[i] = false;
    }
    depthInner(start, visited);
}

void Graph::find_min_way_dps_inner(int current, int target, bool visited[], std::vector<int>& currentPath, std::vector<int>& minPath, int& minDistance)
{
    std::cout << "V" << current << ", ";
    visited[current] = true;
    currentPath.push_back(current);
    if (current == target)
    {
        int currentDistance = 0;
        for (size_t i = 0; i < currentPath.size() - 1; i++)
        {
            currentDistance += matrix[currentPath[i]][currentPath[i + 1]];
        }
        if (currentDistance < minDistance)
        {
            minDistance = currentDistance;
            minPath = currentPath;
        }
    }
    else
    {
        for (size_t i = 0; i < SIZE; ++i)
        {
            if (matrix[current][i] != 0 && !visited[i])
            {
                find_min_way_dps_inner(i, target, visited, currentPath, minPath, minDistance);
            }
        }
    }

    visited[current] = false;
    currentPath.pop_back();
}


int Graph::findMinWayDFS(int from, int to)
{
    bool visited[SIZE] = { false };
    std::vector<int> currentPath;
    std::vector<int> minPath;
    int minDistance = VERYBIGINT;

    find_min_way_dps_inner(from, to, visited, currentPath, minPath, minDistance);

    std::cout << "\nMin Distance: " << minDistance << "\nMin Path: ";
    for (size_t i = 0; i < minPath.size(); ++i) {
        std::cout << "V" << minPath[i] << " ";
    }
    std::cout << std::endl;
    return minDistance;
}



void Graph::findPathCountInner(int current, bool visited[], int to, int& countPath)
{
    visited[current] = true;

    // ���� �������� �������� �������, ����������� ������� �����
    if (current == to)
    {
        countPath++;
    }

    // ����������� ����� ��� �������� ������
    for (size_t i = 0; i < SIZE; i++)
    {
        if (matrix[current][i] != 0 && !visited[i])
        {
            findPathCountInner(i, visited, to, countPath);
        }
    }

    // ����� ���������� ����������� ������� ������� ����� ���������
    visited[current] = false;
}

int Graph::findPathCount(int from, int to)
{
    bool visited[SIZE];
    for (size_t i = 0; i < SIZE; i++)
    {
        visited[i] = false;
    }
    int countPath = 0;
    findPathCountInner(from, visited, to, countPath);
    return countPath;
}

bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] != 0;
}

void Graph::width(int start)
{
    int queue_to_visit[SIZE]; // ������� ������ ��� ������
    int queueCount = 0;

    bool visited[SIZE]; // ������ ���������� ������
    for (int i = 0; i < SIZE; i++)
        visited[i] = false;

    queue_to_visit[queueCount++] = start; // ������ � ������� ��������� �������
    while (queueCount > 0)
    {
        // ������ �� ������� �������
        int current = queue_to_visit[0];
        queueCount--;
        for (int i = 0; i < queueCount; i++)
        {
            queue_to_visit[i] = queue_to_visit[i + 1];
        }
        visited[current] = true;
        std::cout << "V" << current << " -> ";
        // ����� ������� ������ � ���������� �� � �������
        for (int i = 0; i < SIZE; i++)
        {
            bool alreadyAdded = false;
            for (int j = 0; j < queueCount; j++)
                if (queue_to_visit[j] == i)
                {
                    alreadyAdded = true;
                    break;
                }
            if (!alreadyAdded && edgeExists(current, i) && !visited[i])
                queue_to_visit[queueCount++] = i;
        }
    }
    std::cout << std::endl;
}

bool Graph::vertexExists(int vertexNum)
{
    return (vertexNum >= 0 && vertexNum < SIZE);
}

bool Graph::are_adj(int v1, int v2)
{
    return vertexExists(v1) && vertexExists(v2) && matrix[v1][v2] > 0;
}

void Graph::find_min_dist_decstr(int vfrom)
{
    int distances[SIZE]; // ������ �����
    for (int i = 0; i < SIZE; i++) // ������������� �����
    {
        distances[i] = VERYBIGINT;
    }
    distances[vfrom] = 0;

    bool passed[SIZE]; // �������, ��� ������� ��������
    for (int i = 0; i < SIZE; i++)
    {
        passed[i] = false; // ��� ���������� ����������
    }
    // ��������� ��������� ������� �� �������
    int currentVertexNum = vfrom;
    int min_dist = 0;
    while (min_dist != VERYBIGINT)
    {
        passed[currentVertexNum] = true; // ���������� �������

        for (int i = 0; i < SIZE; i++)
        {
            // ��� ������� ����� ������������� �����
            if (edgeExists(currentVertexNum, i)
                && distances[currentVertexNum] + matrix[currentVertexNum][i] < distances[i])
                distances[i] =
                distances[currentVertexNum] + matrix[currentVertexNum][i];
        }
        min_dist = VERYBIGINT;
        for (int i = 0; i < SIZE; i++)
        {
            // �������� ����� ������� �������
            if (vertexExists(i) && !passed[i] && distances[i] < min_dist) // ����� ����� �������
            {
                min_dist = distances[i];
                currentVertexNum = i;
            }
        }
    }

    for (int i = 0; i < vertexCount; i++) // ����� ����������
    {
        std::cout << "V" << i << ": " << distances[vertexes[i]] << ", ";
    }
    std::cout << std::endl;
}

void Graph::find_min_dist_floyd()
{
    int weights[SIZE][SIZE]; // ������� �����
    // ������������ �������
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i == j)
            {
                weights[i][j] = 0; // ���� �� ����� ���� ����� 0
            }
            else {
                if (!edgeExists(i, j))
                {
                    weights[i][j] = VERYBIGINT; // ���� ����� ���
                }
                else {
                    weights[i][j] = matrix[i][j]; // ���� ����� ����
                }
            }
        }
    }

    for (int k = 0; k < vertexCount; k++) // �������� �� k
    {
        int ck = vertexes[k]; // ������� ����� �������
        for (int i = 0; i < vertexCount; i++)
        {
            if (i == k)
                continue;
            int ci = vertexes[i];
            for (int j = 0; j < vertexCount; j++)
            {
                if (j == k)
                    continue;
                int cj = vertexes[j];
                if (weights[ci][ck] + weights[ck][cj] < weights[ci][cj]) {
                    // �������� �������� �����
                    weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
                }
            }
        }
    }

    for (int i = 0; i < vertexCount; i++)
    {
        // ����� ���� ����������� ����� �� ������� '0'
        std::cout << "V" << i << ": " << weights[0][vertexes[i]] << ", ";
    }
}