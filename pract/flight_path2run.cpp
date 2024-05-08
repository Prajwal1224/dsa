#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

void DFS(int vertex, int n, int travelTime[10][10], string cities[], bool visited[])
{
    cout << cities[vertex] << " ";
    visited[vertex] = true;
    for (int i = 0; i < n; ++i)
    {
        if (travelTime[vertex][i] != 0 && !visited[i])
        {
            DFS(i, n, travelTime, cities, visited);
        }
    }
}

void BFS(int vertex, int n, int travelTime[10][10], string cities[])
{
    bool visited[10] = {false};
    queue<int> q;

    cout << "\nBFS Traversal : ";

    q.push(vertex);
    visited[vertex] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << cities[current] << " ";

        for (int i = 0; i < n; i++)
        {
            if (travelTime[current][i] != 0 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

void DisplayGraph(int n, int travelTime[10][10])
{
    cout << "\n\nAdjacency Matrix representation of graph:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << travelTime[i][j] << "\t";
        }
        cout << endl;
    }
}

void Displaylist(int n, int travelTime[10][10], string cities[])
{
    cout << "\n\nAdjacency List representation of graph:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << cities[i] << ": ";
        bool isFirst = true;
        for (int j = 0; j < n; j++)
        {
            if (travelTime[i][j] != 0)
            {
                if (!isFirst)
                {
                    cout << ", ";
                }
                cout << cities[j] << "(" << travelTime[i][j] << ")";
                isFirst = false;
            }
        }
        cout << endl;
    }
}

void Display(int n, string cities[])
{
    cout << "Display Cities" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "city#" << i + 1 << ": " << cities[i] << endl;
    }
}

int main()
{
    int travelTime[10][10] = {0};
    int n, i, j;
    char op;
    int vertex;

    cout << "Enter no. of cities: ";
    cin >> n;

    string cities[n];

    for (i = 0; i < n; i++)
    {
        cout << "Enter city " << i + 1 << ": ";
        cin >> cities[i];
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            cout << "Is there an edge between " << cities[i] << " and " << cities[j] << " (y/n)? ";
            cin >> op;
            if (op == 'y' || op == 'Y')
            {
                cout << "Enter time: ";
                cin >> travelTime[i][j];
                travelTime[j][i] = travelTime[i][j];
            }
        }
    }

    Display(n, cities);
    DisplayGraph(n,travelTime);
    Displaylist(n, travelTime, cities);

    cout << "\nEnter the starting vertex for traversal: ";
    cin >> vertex;

    bool visited[10] = {false};
    cout << "\nDFS Traversal : ";
    DFS(vertex, n, travelTime, cities, visited);
    BFS(vertex, n, travelTime, cities);

    return 0;
}
