#include <bits/stdc++.h>
#include <ctime>
using namespace std;
#define MAX 30000
long long compare;  // 比较次数
long long move1; // 移动次数
int SequenceSearch(int e[], int len, int key) {
    for(int i = 0; i < len; i++)
        if(++compare && e[i] == key)
            return i;
    ++compare;
    return -1;
}
int BinarySearch(int e[], int len, int key) {
    int high,low,mid;
    high = len - 1;
    low = 0;
    while(low <= high) {
        mid = (low + high) >> 1;
        ++compare;
        if (key == e[mid])
        return  mid;
        else if (key > e[mid]) low = mid + 1;
        else high = mid - 1;
    }
    ++compare;
    return  -1;
}
void StraightInsertSort(int e[], int len) {
    int i, j;
    for(i = 1; i < len; i++) {
        int temp = e[i];
        ++move1;
        for(j = i - 1; j >= 0; j--) {
            if(++compare && e[j] > temp) {
                e[j + 1] = e[j];
                ++move1;
            }
            else break;
        }
        e[j + 1] = temp;
        ++move1;
    }
}
void QuickSort(int a[], int first, int end) {
    int i = first, j = end,temp = a[first];
    while(i < j) {
        while(++compare && i < j && a[j] >= temp) j--;
        a[i] = a[j];
        ++move1;
        while(++compare && i<j && a[i] <= temp) i++;
        a[j] = a[i];
        ++move1;
    }
    a[i]=temp;
    if(first < i - 1) QuickSort(a,first,i-1);
    if(end > i + 1) QuickSort(a, i + 1, end);
}
void Merge(int e[],int a[],int first,int m,int end) {
    int i = first, j = m + 1, k = first;
    while(i <= m && j <= end) {
        ++compare;
        ++move1;
        if(e[i] <= e[j]) a[k++] = e[i++];
        else a[k++] = e[j++];
    }
    while(i <= m && ++move1) a[k++]=e[i++];
    while(j <= end && ++move1) a[k++]=e[j++];
}
void MergeSort(int e[],int a[],int first,int end) {
    int m;
    int bak[MAX];
    if(first == end) a[first] = e[first];
    else {
        m = (first + end) >> 1;
        MergeSort(e, bak, first, m);
        MergeSort(e, bak, m + 1, end);
        Merge(bak, a, first, m, end);
    }
    for(m = 0; m <= end; m++) e[m]=a[m];
}

void HeapSort(int e[],int len) {
    void sift(int e[],int l,int m);
    int temp;
    for(int i = len / 2 - 1; i >= 0; i--)
    sift(e, i, len);
    for(int i = len - 1; i >= 1; i--) {
        move1 += 2;
        temp = e[i];
        e[i] = e[0];
        e[0] = temp;
        sift(e, 0, i - 1);
    }
}
void sift(int e[],int l,int m) {
    int i,j,x;
    i = l;
    j = 2 * i + 1;
    x = e[i];
    while(j <= m) {
        if(j < m && ++compare && e[j] < e[j + 1])
        j++;
        if(++compare && x < e[j]) {
            ++move1;
            e[i] = e[j];
            i = j;
            j = 2 * i + 1;
        }
        else j=m+1;
    }
    e[i] = x;
    ++move1;
}

int main()
{
    int i;
    int n;
    int table[MAX], table1[MAX];
    int key;
    int pos;
    clock_t st,ed;
    
    scanf("%d", &n);
    
    srand(time(NULL));
    for(i=0; i<n; i++)
    {
        table[i] = rand();
        table1[i] = table[i];
    }
    for (i = 0; i < n; i++) {
        printf("%d ", table[i]);
    }
    printf("\n\n");      
    printf("\t\tkey = ");
    scanf("%d", &key);
    st = clock();
    compare = 0;
    pos = SequenceSearch(table, n, key);
    ed = clock();
    printf("\t\tSequence Searching \n");
    printf("----------------------------------------\n");
    printf("Analysis details : \n");
    if(pos == -1) {    
        printf("\tsearch %d fail.\n", key);
        printf("\trun : %f time.\n", (double)(ed - st) / CLOCKS_PER_SEC);
        printf("\tcompare : %lld times.", compare);
        
    }
    else {
        printf("\tsearch %d success.\n", key);
        printf("\trun : %f time.\n", (double)(ed - st) / CLOCKS_PER_SEC);
        printf("\tcompare : %lld times.", compare);
        
    }
    printf("\n\n"); 
    
    for(i = 0; i < n; i++)
        table1[i] = table[i];
    compare = move1 = 0;
    st = clock();
    StraightInsertSort(table1, n);
    ed = clock();
    printf("\t\tStraight Insert Sorting \n");
    printf("----------------------------------------\n");
    printf("Analysis details : \n");
    printf("\trun : %f time.\n", (double)(ed - st) / CLOCKS_PER_SEC);
    printf("\tcompare : %lld times.\n", compare);
    printf("\tmove1    : %lld times.\n\n", move1);
    for(i = 0; i < n; i++)
        table1[i] = table[i];
    compare = move1 = 0;
    st = clock();
    MergeSort(table1, table, 0, n-1);
    ed = clock();
    printf("\t\tMerge Sorting \n");
    printf("----------------------------------------\n");
    printf("Analysis details : \n");
    printf("\trun : %f time.\n", (double)(ed - st) / CLOCKS_PER_SEC);
    printf("\tcompare : %lld times.\n", compare);
    printf("\tmove1    : %lld times.\n\n", move1);
    for(i = 0; i < n; i++)
        table1[i] = table[i];
    compare = move1 = 0;
    st = clock();
    HeapSort(table1, n);
    ed = clock();
    printf("\t\tHeap Sorting \n");
    printf("----------------------------------------\n");
    printf("Analysis details : \n");
    printf("\trun : %f time.\n", (double)(ed - st) / CLOCKS_PER_SEC);
    printf("\tcompare : %lld times.\n", compare);
    printf("\tmove1    : %lld times.\n\n", move1);
    for(i = 0; i < n; i++)
        table1[i] = table[i];
    compare = move1 = 0;
    st = clock();
    QuickSort(table1, 0, n-1);
    ed = clock();
    printf("\t\tQuick Sorting \n");
    printf("----------------------------------------\n");
    printf("Analysis details : \n");
    printf("\trun : %f time.\n", (double)(ed - st) / CLOCKS_PER_SEC);
    printf("\tcompare : %lld times.\n", compare);
    printf("\tmove1    : %lld times.\n\n", move1);

    compare = 0;
    sort(table1, table1 + n);
    st = clock();
    pos = BinarySearch(table1, n, key);
    ed = clock();
    printf("\t\tBinary Searching \n");
    printf("----------------------------------------\n");
    printf("Analysis details : \n");
    if(pos == -1) {    
        printf("\tsearch %d fail.\n", key);
        printf("\trun : %f time.\n", (double)(ed - st) / CLOCKS_PER_SEC);
        printf("\tcompare : %lld times.", compare);
    }
    else {
        printf("\tsearch %d success.\n", key);
        printf("\trun : %f time.\n", (double)(ed - st) / CLOCKS_PER_SEC);
        printf("\tcompare : %lld times.", compare);
    }
    printf("\n\n");
    return 0;

}
