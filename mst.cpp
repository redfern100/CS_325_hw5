#include <iostream>
#include <math.h>

using namespace std;

struct Node
// a node on the graph
{
    int x; // x coordinate of the node
    int y; // y coordinate of the node
};

int distance(Node node_1, Node node_2)
// calulcate the distance between two nodes via the distacne formula
{
    return round(sqrt(pow((node_2.x - node_1.x), 2) +
                 pow((node_2.y - node_1.y), 2)));
}

int main()
{
    // open and read data from a file
    FILE *graph_data;
    graph_data = fopen("graph.txt", "r");

    int graph_num;
    fscanf(graph_data, "%i", &graph_num);
    
    // iterate over each graph in the data set
    for (int i = 0; i < graph_num ; i++)
    {
        int node_num;
        fscanf(graph_data, "%i", &node_num);

        cout << "Graph: " << i + 1 << endl;

        int node_array[node_num][node_num]; // weight of all node connections in the graph
        struct Node node_list[node_num]; // list of all nodes in the graph

        // iterate over each node in the graph
        for (int j = 0; j < node_num; j++)
        {
            int x;
            int y;
            
            fscanf(graph_data, "%i %i", &x, &y);

            node_list[j] = {x,y}; // assign node x and y data in the node list
        }

        // generate table of the weight of each node connection
        for (int j = 0; j < node_num; j++)
        {
            for (int k = 0; k < node_num; k++)
            {
                node_array[j][k] = distance(node_list[j], node_list[k]);
            }
        }

        // find node connections with the least weight to generate a mst
        int weight = 0;
        for(int j = 0; j < node_num; j++)
        {
            int min = node_array[j][0];
            for (int k = 1; k < node_num; k++)
            {
                // check if the node is refering to itself
                if (j != k)
                {
                    // check if the min is greater then the current distance
                    if(min >= node_array[j][k])
                    {
                        min = node_array[j][k]; // update the min
                    }
                }
            }
                weight += min; // add least weight to total weight of mst
        }

        cout << "MST weight: " << weight << endl << endl;
    }

    fclose(graph_data);

    return 0;
}
