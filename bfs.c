#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100

typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} queue;

void initialiseQueue(queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(queue *q) {
    return (q->front == -1);
}

void enqueue(queue *q, int value) {
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(queue *q) {
    int value = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        initialiseQueue(q);
    }
    return value;
}

void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int start_vertex, bool visited[MAX_VERTICES], int num_vertices) {
    queue q;
    initialiseQueue(&q);
    printf("bfs traversal:");
    printf("%d", start_vertex);
    visited[start_vertex] = true;
    enqueue(&q, start_vertex);
    while (!isEmpty(&q)) {
        int current_vertex = dequeue(&q);
        for (int i = 0; i < num_vertices; i++) {
            if (graph[current_vertex][i] == 1 && !visited[i]) {
                printf("%d", i);
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    int num_vertices;
    printf("enter the number of vertices:");
    scanf("%d", &num_vertices);
    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("enter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    bool visited[MAX_VERTICES];
    for (int i = 0; i < num_vertices; i++) {
        visited[i] = false;
    }
    bfs(graph, 0, visited, num_vertices);
    return 0;
}