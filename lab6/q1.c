#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int size;
    int arr[MAX_SIZE];
} MinHeap;


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap *heap, int index) {
    int parent = (index - 1) / 2;
    if (index && heap->arr[parent] > heap->arr[index]) {
        swap(&heap->arr[parent], &heap->arr[index]);
        heapifyUp(heap, parent);
    }
}

void heapifyDown(MinHeap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;

    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

void insert(MinHeap *heap, int key) {
    if (heap->size == MAX_SIZE) {
        printf("Heap overflow\n");
        return;
    }
    heap->size++;
    int index = heap->size - 1;
    heap->arr[index] = key;

    heapifyUp(heap, index);
}

int extractMin(MinHeap *heap) {
    if (heap->size <= 0)
        return -1;  

    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    heapifyDown(heap, 0);

    return root;
}

void printHeap(MinHeap *heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->arr[i]);
    printf("\n");
}

int main() {
    MinHeap heap;
    heap.size = 0;

    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 5);
    insert(&heap, 3);
    insert(&heap, 7);

    printHeap(&heap);

    printf("Extracted min: %d\n", extractMin(&heap));
    printHeap(&heap);

    return 0;
}
