#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX 10

// Edge structure
typedef struct Edge {
    int dest;
    int weight;
    struct Edge* next;
} Edge;

// Node structure
typedef struct Node {
    char name[50];
    Edge* head;
} Node;

Node graph[MAX];
int nodeCount = 0;

// 🔹 Add Node (CREATE)
void addNode() {
    if (nodeCount >= MAX) {
        printf("Maximum nodes reached!\n");
        return;
    }

    printf("Enter location name: ");
    scanf("%s", graph[nodeCount].name);
    graph[nodeCount].head = NULL;

    printf("Node added with index %d\n", nodeCount);
    nodeCount++;
}

// 🔹 Add Edge (CREATE)
void addEdge() {
    int src, dest, weight;

    printf("Enter source index: ");
    scanf("%d", &src);

    printf("Enter destination index: ");
    scanf("%d", &dest);

    printf("Enter distance: ");
    scanf("%d", &weight);

    if (src >= nodeCount || dest >= nodeCount) {
        printf("Invalid indices!\n");
        return;
    }

    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->dest = dest;
    newEdge->weight = weight;
    newEdge->next = graph[src].head;
    graph[src].head = newEdge;

    printf("Route added successfully!\n");
}

// 🔹 Display Graph (READ)
void displayGraph() {
    printf("\nGraph Representation:\n");

    for (int i = 0; i < nodeCount; i++) {
        printf("%d (%s): ", i, graph[i].name);

        Edge* temp = graph[i].head;
        while (temp != NULL) {
            printf(" -> %d (%d)", temp->dest, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

// 🔹 Update Edge (UPDATE)
void updateEdge() {
    int src, dest, newWeight;

    printf("Enter source and destination: ");
    scanf("%d %d", &src, &dest);

    Edge* temp = graph[src].head;

    while (temp != NULL) {
        if (temp->dest == dest) {
            printf("Enter new distance: ");
            scanf("%d", &newWeight);
            temp->weight = newWeight;
            printf("Updated successfully!\n");
            return;
        }
        temp = temp->next;
    }

    printf("Edge not found!\n");
}

// 🔹 Delete Edge (DELETE)
void deleteEdge() {
    int src, dest;

    printf("Enter source and destination: ");
    scanf("%d %d", &src, &dest);

    Edge *temp = graph[src].head, *prev = NULL;

    while (temp != NULL) {
        if (temp->dest == dest) {
            if (prev == NULL)
                graph[src].head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Route deleted successfully!\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Edge not found!\n");
}

// 🔹 Search Node
void searchNode() {
    char name[50];

    printf("Enter location name: ");
    scanf("%s", name);

    for (int i = 0; i < nodeCount; i++) {
        if (strcmp(graph[i].name, name) == 0) {
            printf("Location found at index %d\n", i);
            return;
        }
    }

    printf("Location not found!\n");
}

// 🔹 Dijkstra Algorithm (Shortest Path)
void dijkstra(int start) {
    int dist[MAX], visited[MAX];

    for (int i = 0; i < nodeCount; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int i = 0; i < nodeCount - 1; i++) {
        int min = INT_MAX, u = -1;

        for (int j = 0; j < nodeCount; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        Edge* temp = graph[u].head;

        while (temp != NULL) {
            int v = temp->dest;

            if (!visited[v] && dist[u] + temp->weight < dist[v]) {
                dist[v] = dist[u] + temp->weight;
            }

            temp = temp->next;
        }
    }

    printf("\nShortest distances from node %d:\n", start);
    for (int i = 0; i < nodeCount; i++) {
        printf("To %d (%s): %d\n", i, graph[i].name, dist[i]);
    }
}

// 🔹 Main Function (Menu Driven)
int main() {
    int choice;

    do {
        printf("\n--- Logistics Route Optimization ---\n");
        printf("1. Add Location\n");
        printf("2. Add Route\n");
        printf("3. Display Graph\n");
        printf("4. Update Route\n");
        printf("5. Delete Route\n");
        printf("6. Search Location\n");
        printf("7. Find Shortest Path\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addNode();
                break;
            case 2:
                addEdge();
                break;
            case 3:
                displayGraph();
                break;
            case 4:
                updateEdge();
                break;
            case 5:
                deleteEdge();
                break;
            case 6:
                searchNode();
                break;
            case 7: {
                int start;
                printf("Enter starting node index: ");
                scanf("%d", &start);

                if (start < nodeCount)
                    dijkstra(start);
                else
                    printf("Invalid index!\n");
                break;
            }
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 8);

    return 0;
}
