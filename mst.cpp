#include <iostream>
#include <math.h>
#include <iterator>

using namespace std;

struct Node
{
    int x;
    int y;
};

int distance(Node node_1, Node node_2)
{
    return sqrt(pow((node_1.x - node_2.x), 2) + pow((node_1.y - node_2.y), 2));
}

int get_min(int array[])
{
    int min = 0;
    int len = array.size();

    for (int i = 1; i < len; i++)
    {
        if (array[0] > array[i])
        {
            min = i;
        }
    }
    
    return min;
}

int main()
{
    FILE *graph_data;
    graph_data = fopen("graph.txt", "r");

    int graph_num;
    fscanf(graph_data, "%i", &graph_num);
    
    for (int i = 0; i <= graph_num ; i++)
    {
       int node_num;
       fscanf(graph_data, "%i", &node_num);

       cout << "Graph: " << i << endl;

        struct Node node_list[node_num];
        for (int i = 0; i < node_num; i++)
        {
            int x;
            int y;

            fscanf(graph_data, "%i %i", &x, &y);
            node_list[i] = {x,y};            
        }

        struct Node path[node_num];
        int node_distance[node_num];
        for (int i = 0; i < node_num ; i++)
        {
            for (int j = 0; j < node_num; i++)
            {
                if (i == j)
                {
                    
                }
                else
                {
                    node_distance[j] = distance(node_list[i], node_list[j]);
                }
            }
            int min = get_min(node_distance);
            cout << "(" << node_list[i].x << "," << node_list[i].y << ") -->"
                 << "(" << node_list[min].x << "," << node_list[min].y << ")"
                 << endl;
                        
        }
                

    }
    
    fclose(graph_data);

    return 0;
}
