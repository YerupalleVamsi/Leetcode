typedef struct {
    int x, y, cost;
} Node;

typedef struct {
    Node* nodes;
    int size;
    int capacity;
} MinHeap;

// Function to create a min-heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->nodes = (Node*)malloc(capacity * sizeof(Node));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

// Function to swap two nodes in the heap
void swap(Node* a, Node* b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

// Function to insert a node into the min-heap
void insertMinHeap(MinHeap* heap, Node node) {
    if (heap->size == heap->capacity) return; // Heap is full
    heap->nodes[heap->size++] = node;

    // Bubble up
    int i = heap->size - 1;
    while (i > 0 && heap->nodes[i].cost < heap->nodes[(i - 1) / 2].cost) {
        swap(&heap->nodes[i], &heap->nodes[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to extract the minimum node from the min-heap
Node extractMin(MinHeap* heap) {
    Node minNode = heap->nodes[0];
    heap->nodes[0] = heap->nodes[--heap->size];

    // Bubble down
    int i = 0;
    while (i * 2 + 1 < heap->size) {
        int smallest = i * 2 + 1;
        if (smallest + 1 < heap->size && heap->nodes[smallest + 1].cost < heap->nodes[smallest].cost) {
            smallest++;
        }
        if (heap->nodes[i].cost <= heap->nodes[smallest].cost) break;
        swap(&heap->nodes[i], &heap->nodes[smallest]);
        i = smallest;
    }

    return minNode;
}

// Function to check if a position is within bounds
int isValid(int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

int minCost(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    
    // Directions for moving based on grid values
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // right, left, down, up
    
    // Cost matrix initialized to infinity
    int cost[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = INT_MAX;
        }
    }
    
    MinHeap* minHeap = createMinHeap(m * n);
    
    // Start from the top-left corner
    cost[0][0] = 0;
    insertMinHeap(minHeap, (Node){0, 0, 0});
    
    while (minHeap->size > 0) {
        Node current = extractMin(minHeap);
        
        // If we reached the bottom-right corner
        if (current.x == m - 1 && current.y == n - 1) {
            return current.cost; // Return the minimum cost found
        }
        
        // Check possible movements based on current cell's sign
        for (int d = 0; d < 4; d++) {
            int newX = current.x + directions[d][0];
            int newY = current.y + directions[d][1];
            int newCost = current.cost + (grid[current.x][current.y] == d + 1 ? 0 : 1);
            
            if (isValid(newX, newY, m, n) && newCost < cost[newX][newY]) {
                cost[newX][newY] = newCost;
                insertMinHeap(minHeap, (Node){newX, newY, newCost});
            }
        }
    }

    return 1; // In case there is no valid path
}