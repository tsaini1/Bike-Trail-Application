#include <iostream>
#include <vector>
using namespace std;

// MinHeap class
class MinHeap 
{
    private:
        vector<int> heap;

        void percolateUp(int index)                         // helper function
        { 
            int parentIndex = (index - 1) / 2;
            
            while (index > 0 && heap[index] < heap[parentIndex]) 
            {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
                parentIndex = (index - 1) / 2;
            }
        }

        void percolateDown(int index) 
        {
            int childLeft = 2 * (index) + 1;                // index of left child
            int childRight = 2 * (index) + 2;               // index of right child
            int lesserChild;                                // index of lesser of the two

            if (heap.size() < childRight + 1)               // if right child doesn't exist
            {
                if (heap.size() < childLeft + 1)            // if both children don't exist
                    return;
                else                                        // only child Left exists
                {
                    if (heap[index] > heap[childLeft])      // if the parent is greater than the child, swap
                    {
                        swap(heap[index], heap[childLeft]);
                        percolateDown(lesserChild);         // SHOULD percolate new location of original index;
                    }
                }
            }
            else                                            // if both children exists
            {
                if (heap[childLeft] < heap[childRight])     // checks if child left is lesser than child right
                    lesserChild = childLeft;                // if so, lesser child is child left
                else
                    lesserChild = childRight;               // else, lesser child is child right
                
                if (heap[index] > heap[lesserChild])        // if the parent is less than the lesser child, swap
                {
                    swap(heap[index], heap[lesserChild]);
                    index = lesserChild;
                    percolateDown(index);                   // SHOULD percolate new location of original index;
                }
            }
        }

    public:
        MinHeap() {};                                       // Constructor

        void insert(int value) 
        {
            heap.push_back(value);
            percolateUp(heap.size() - 1);                   // gives index of last item of vector
        }

        int extractMin() 
        {
            int extraction = heap[0];
            heap[0] = heap.back();
            heap.pop_back();
            percolateDown(0);                               // gives index of root item of vector
            return extraction;
        }

        void printHeap() 
        {
            for (int i = 0; i < heap.size(); i++) 
            {
                cout << heap[i] << " ";
            }
        }
};
