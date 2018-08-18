#include<stdio.h>
#include <math.h>
#define SIZE 10
int compare( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return -1;
     else return 1;
}

void fillBuckets(int a[], int size, int n, int count, int buckets[count][size]) {

int y,x,i;
    for(x=0;x<count;x++){
        for(y=0; y<size; y++){
            buckets[x][y] = 0;

        }
    }
    for(i=0; i<n; i++){
        x = ceil(sqrt(a[i]/SIZE));
        if(x > size)
            x = size + 1;
        for(y=0; y < SIZE; y++){
            if(buckets[x][y] ==0){
                buckets[x][y] = a[i];
                break;
            }
        }
    }
}

int main()
{
    int i, a[] = {3, 200,  12,  4, 3, 2, 1, 500,9,11,22,32}, n = 12;
    printf("Values : ");
    for(i=0;i<n;i++){
        if(i==0){
            printf("{ %d", a[i] );
        }else{
            printf(", %d", a[i] );
        }
    }
    printf("}. \n");

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

    int bucketCount = ceil(sqrt((SIZE))) + 1;

    int numberOfValues = ceil(((double)n / bucketCount));

    qsort( a, n, sizeof(int), compare );

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
