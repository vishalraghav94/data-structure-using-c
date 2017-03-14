#include <stdio.h>
#define MAX 100
int arr[MAX];
int binarysearch ( int );
int size;
int main()
{
    int pos , i , ele;
    printf("Enter the Size of the array : ");
    scanf("%d" , &size);
    printf("\nEnter the array element ( sorted in inc. order ) : ");
    for (i=0; i<size; i++) {
        scanf("%d" , &arr[i]);
    }
    printf("\nEnter the element to be found : ");
    scanf("%d" , &ele);
    pos = binarysearch(ele);
    if (pos == -1) {
        printf("\nElement not found");
        return 0;
    }
    printf("\nPosition = %d" , pos );
    return 0;
}
int binarysearch ( int num )
{
    int *start , *mid , *end , position;
    start = arr;
    mid = (arr + size/2);
    end = (arr+(size-1));
    while (1) {
        if ( num < (*mid)) {
            end = mid;
            mid = (mid - (end-start)/2);
            if (end == mid) {
                if (num == (*mid)) {
                position = end - arr;
                return ++position;
                }
                else if (num == (*start))
                {
                    position = start - arr;
                    return ++position;
                }
                else
                    return -1;
            }
        }
        else if (num > (*mid))
        {
            start = mid;
            mid = ( mid + (end - start)/2);
            if (start == mid) {
                if (num == (*mid)) {
                    position = start - arr;
                    return ++position;
                }
                else if (num == (*end))
                {
                    position = end - arr;
                    return ++position;
                }
                else
                    return -1;
            }
        }
        else
        {
            position = mid - arr;
            return ++position;
        }
            }
}