#include<iostream>
#include<vector>
#include "heapFuncts.h"
using namespace std;

void sortHeap(vector<double> nodes){

    // Begin with half the heap
    for(int i = nodes.size()/2 - 1; i >= 0; i--){
        makeHeap(nodes, i, nodes.size());
    }

    // Reposition nodes
    for(int i = nodes.size() - 1; i > 0; i--){
        double temp = nodes[i];
        nodes[i] = nodes[0];
        nodes[0] = temp;

        makeHeap(nodes, 0, i);
    }
}

void makeHeap(vector<double> nodes[], int root, int size){
    
    // Establish leaf positions
    int max = root;
    int left = leftChild(root);
    int right = rightChild(root);

    // Check for max value and swap
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