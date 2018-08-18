#include<stdio.h>
#include <math.h>
#define SIZE 10
void bucketSort(int a[], int n)
{
    int h,i, j, k, buckets[SIZE];

    for(i = 0; i < SIZE; ++i)
        buckets[i] = 0;

    for(i = 0; i < n; ++i)
        ++buckets[a[i]];

    for(i = 0, j = 0; j < SIZE; ++j)
        for(k = buckets[j]; k > 0; --k)
            a[i++] = j;

}

void fillBuckets(int a[], int size, int n, int count, int buckets[count][size]) {

int y,x,i;
    for(x=0;x<count;x++){
        for(y=0; y<size; y++){
            buckets[x][y] = 0;

        }
    }
    for(i=0; i<n; i++){
        x = ceil((a[i]/SIZE));

        for(y=0; y<SIZE; y++){
            if(buckets[x][y] ==0){
                buckets[x][y] = a[i];
                break;
            }
        }
    }
}

int main()
{
    int i, a[] = {3, 6, 40, 1, 4, 3, 2, 1, 5,9,0,11,32}, n = 13;

    int minValue = a[0];
    int maxValue = a[0];
    for (i = 1; i < n; i++)
    {
        if (a[i] < minValue)
        {
            minValue = a[i];
        }
        else if (a[i] > maxValue)
        {
            maxValue = a[i];
        }
    }

    int bucketCount = ceil(ceil(sqrt((SIZE))));

    int numberOfValues = ceil(((double)n / bucketCount));

    bucketSort(a, n);

    int buckets[bucketCount][numberOfValues],x;
    fillBuckets(a, numberOfValues,n, bucketCount,buckets);

    printf("\n\nAfter sorting bidimensional:\n");
    for(i = 0; i < bucketCount; ++i){
        for(x=0;x<numberOfValues;x++){
                printf("X = %d ", i);
                printf("Y = %d ", x);
                printf("%d \n", buckets[i][x]);
        }
    }


    return 0;
}
