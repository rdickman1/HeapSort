#include<iostream>
#include "heapFuncts.h"
using namespace std;

void sortHeap(double nodes[], int size){

    for(int i = size/2; i >= 0; i--){
        makeHeap(nodes, i, size);
    }

    for(int i = size; i > 0; i--){
        double temp = nodes[i];
        nodes[i] = nodes[0];
        nodes[0] = temp;

        makeHeap(nodes, 0, i);
    }
}

void makeHeap(double nodes[], int root, int size){
    
    int max = root;
    int left = leftChild(root);
    int right = rightChild(root);

    if(nodes[right] > nodes[max] && size > right){
        max = right;
    }

    else if(nodes[left] > nodes[max] && size > left){
        max = left;
    }

    if(root != max){
        double temp = nodes[max];
        nodes[max] = nodes[root];
        nodes[root] = temp;

        makeHeap(nodes, max, size);
    }


}

int leftChild(int root){
    return (2 * root + 1);
}

int rightChild(int root){
    return (2 * root + 2);
}