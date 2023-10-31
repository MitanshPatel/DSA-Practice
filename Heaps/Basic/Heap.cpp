#include<stdio.h>
#include<stdlib.h>

int size =0;

void swap(int *a, int *b){
    int temp=*b;
    *b=*a;
    *a=temp;
}

//Max Heap
void heapify(int array[], int size, int i){
    if(size==1){
        printf("Single element in heap");
    }
    else{
        int largest=i;
        int l=2*i+1;  //this array position contains left child of i th array posn
        int r=2*i+2;  //this array position contains right child of i th array posn

        if(l<size && array[l]>array[largest]){  //if left child of parent root is bigger than parent root
            largest=l;
        }
        if(r<size && array[r]>array[largest]){  //if right child of parent root is bigger than parent root
            largest=r;
        }

        //largest will hold the index of array with higest value of children[either left or right] + parent root

        if(largest!=i){  // heap feature not satisfied. child is bigger than parent
            swap(&array[i], &array[largest]);  //swapping child with parent, such that parent becomes bigger and child becomes lower
            heapify(array,size,largest); // if there happens a swap in height 1 and 2, then we have to check if it is a heap for height 2 and 3 again. so recursion is used
        }
    }
}

void insert(int array[], int newNum){
    if(size==0){
        array[0]=newNum;
        size+=1;
    }

    else{
        array[size]=newNum;  //new number is added at last position of array
        size+=1;
        for(int i=size/2-1;i>=0;i--){  //all upper roots of tree are at start of array(from start to middle posn). so heapify is used to check if it is heap or not by checking if its both child are smaller than parent
            heapify(array,size,i);  //to check if it satisfies heap
        }
    }
}

void deleteRoot(int array[],int num){
    int i;  //we want the value of i afterwards. so it is not defined in for loop
    for(i=0;i<size;i++){
        if(num==array[i]){
            break;  //found the position in array to be deleted
        }
    }

    swap(&array[i],&array[size-1]); //replacing deleted element with last element. so deleted element goes to last position
    size-=1;  //to remove deleted posn i.e at last posn 
    for(int i=size/2-1;i>=0;i--){  //now checking if it satisfies heap or not
        heapify(array,size,i);
    }
}

void printArray(int array[],int size){
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
  int array[10];

  insert(array, 3);
  insert(array, 4);
  insert(array, 9);
  insert(array, 5);
  insert(array, 2);

  printf("Max-Heap array: ");
  printArray(array, size);

  deleteRoot(array, 4);

  printf("After deleting an element: ");

  printArray(array, size);
}