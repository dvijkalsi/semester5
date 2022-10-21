// 6.1 Write a program to implementation of Fractional knapsack algorithm. 

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    float ratio;
    float x;
} item;


int compare(const void *a, const void *b) {
    item *x = (item *)a;
    item *y = (item *)b;
    if (x->ratio > y->ratio) return -1;
    if (x->ratio < y->ratio) return 1;
    return 0;
}
float frational_knapsack(item *items, int m, int n) {
    int i;
    float total_value = 0;
    qsort(items, n, sizeof(item), compare);
    for (i = 0; i < n; i++) {
        if (items[i].weight <= m) {
            m -= items[i].weight;
            total_value += items[i].value;
            items[i].x = 1;
        } else {
            items[i].x = (float) m / items[i].weight;
            total_value += items[i].x * items[i].value;
            break;
        }
    }
    return total_value;
}

int main() {
    int n, i, j, capacity;
    item *items;
    float total_value = 0.0;
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    items = (item *)malloc(n * sizeof(item));
    printf("Enter the weight and value of each item: ");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    total_value = frational_knapsack(items, capacity, n);

    printf("Total value: %f", total_value);
    return 0;
}
