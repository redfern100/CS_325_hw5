import math

def main():
    data = open("graph.txt", "r")

    region_num = int(data.readline())

    while region_num > 0:
        node_num = int(data.readline())
        edges = []
        vertices = []

        for i in range(0, node_num):
            temp = data.readline()
            split_temp = temp.split()

            vertex = int(split_temp[0])
            edge = int(split_temp[1])

            vertices.append(vertex)
            edges.append(edge)

        edge_max = max(edges)
        vertex_max = max(vertices)


        graph = [[]]
        if vertex_max > edge_max:
            for i in range(0, vertex_max):
                graph.append(0)
                graph[i].append(0)
        else:
            for i in range(0, edge_max):
                graph.append(0)
                graph[i].append(0)

        i = 0

        for i in range(0, node_num):
            graph[1][1] = 2

        region_num -= 1

if __name__ == "__main__":
    main()
