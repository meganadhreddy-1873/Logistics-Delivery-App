#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define INF 9999

// Structure for adjacency list node
typedef struct Node {
    int dest;
    int weight;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    int numVertices;
    char locations[MAX][50];
    Node* adjList[MAX];
} Graph;

// Create graph
Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = 0;

    for (int i = 0; i < MAX; i++)
        graph->adjList[i] = NULL;

    return graph;
}

// Find index of location
int getIndex(Graph* graph, char name[]) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (strcmp(graph->locations[i], name) == 0)
            return i;
    }
    return -1;
}

// Add location
void addLocation(Graph* graph) {
    char name[50];
    printf("Enter location name: ");
    scanf("%s", name);

    if (getIndex(graph, name) != -1) {
        printf("Location already exists!\n");
        return;
    }

    strcpy(graph->locations[graph->numVertices], name);
    graph->numVertices++;
    printf("Location added successfully.\n");
}

// Add route
void addRoute(Graph* graph) {
    char src[50], dest[50];
    int weight;

    printf("Enter source: ");
    scanf("%s", src);
    printf("Enter destination: ");
    scanf("%s", dest);
    printf("Enter distance: ");
    scanf("%d", &weight);

    int s = getIndex(graph, src);
    int d = getIndex(graph, dest);

    if (s == -1 || d == -1) {
        printf("Invalid locations!\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = d;
    newNode->weight = weight;
    newNode->next = graph->adjList[s];
    graph->adjList[s] = newNode;

    printf("Route added successfully.\n");
}

// Display graph
void displayGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%s -> ", graph->locations[i]);
        Node* temp = graph->adjList[i];
        while (temp) {
            printf("%s(%d) ", graph->locations[temp->dest], temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Search location
void searchLocation(Graph* graph) {
    char name[50];
    printf("Enter location name: ");
    scanf("%s", name);

    if (getIndex(graph, name) != -1)
        printf("Location found.\n");
    else
        printf("Location not found.\n");
}

// Update route
void updateRoute(Graph* graph) {
    char src[50], dest[50];
    int newWeight;

    printf("Enter source: ");
    scanf("%s", src);
    printf("Enter destination: ");
    scanf("%s", dest);
    printf("Enter new distance: ");
    scanf("%d", &newWeight);

    int s = getIndex(graph, src);
    int d = getIndex(graph, dest);

    Node* temp = graph->adjList[s];
    while (temp) {
        if (temp->dest == d) {
            temp->weight = newWeight;
            printf("Route updated successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Route not found.\n");
}

// Delete route
void deleteRoute(Graph* graph) {
    char src[50], dest[50];

    printf("Enter source: ");
    scanf("%s", src);
    printf("Enter destination: ");
    scanf("%s", dest);

    int s = getIndex(graph, src);
    int d = getIndex(graph, dest);

    Node* temp = graph->adjList[s];
    Node* prev = NULL;

    while (temp) {
        if (temp->dest == d) {
            if (prev)
                prev->next = temp->next;
            else
                graph->adjList[s] = temp->next;

            free(temp);
            printf("Route deleted successfully.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Route not found.\n");
}

// Dijkstra
void shortestPath(Graph* graph) {
    char src[50], dest[50];
    printf("Enter source: ");
    scanf("%s", src);
    printf("Enter destination: ");
    scanf("%s", dest);

    int s = getIndex(graph, src);
    int d = getIndex(graph, dest);

    int dist[MAX], visited[MAX];

    for (int i = 0; i < graph->numVertices; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[s] = 0;

    for (int i = 0; i < graph->numVertices; i++) {
        int min = INF, u;

        for (int j = 0; j < graph->numVertices; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        Node* temp = graph->adjList[u];
        while (temp) {
            if (dist[u] + temp->weight < dist[temp->dest])
                dist[temp->dest] = dist[u] + temp->weight;
            temp = temp->next;
        }
    }

    printf("Shortest distance: %d\n", dist[d]);
}

// MAIN
int main() {
    Graph* graph = createGraph();
    int choice;

    while (1) {
        printf("\n1. Add Location\n2. Add Route\n3. Display Graph\n");
        printf("4. Update Route\n5. Delete Route\n6. Search Location\n");
        printf("7. Find Shortest Path\n8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addLocation(graph); break;
            case 2: addRoute(graph); break;
            case 3: displayGraph(graph); break;
            case 4: updateRoute(graph); break;
            case 5: deleteRoute(graph); break;
            case 6: searchLocation(graph); break;
            case 7: shortestPath(graph); break;
            case 8: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
