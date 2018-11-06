#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#endif // NULL

int max;

void shuffle(int arr[],int n){///Set Random
    srand(time(NULL));
    for (int i = n - 1,j; i > 0; i--) {
         j=rand()%i;
         arr[i]^=arr[j];
         arr[j]^=arr[i];
         arr[i]^=arr[j];
    }
}

void almostNotShuffle(int arr[],int n){///Set Almost Sorted
    srand(time(NULL));
    arr[n/2]^=arr[n-1];
    arr[n-1]^=arr[n/2];
    arr[n/2]^=arr[n-1];
}

void setplace(int* arr[],int n){
        shuffle(arr[0],n);                  ///Set Random
        shuffle(arr[6],n);                  ///Set Few Unique
        almostNotShuffle(arr[4],n);         ///Set Almost Sorted
}

void selection(int arr[],int n){
    int i,j,min;
    for(int i=0;i^n-1;i++){
        min=i;
        for(int j=i+1;j^n;j++)
            if(arr[i]>arr[j])
                min=j;
        arr[min]^=arr[j];
        arr[j]^=arr[min];
        arr[min]^=arr[j];
    }
}
void bubble(int arr[],int n){
    int i,j,flg;
    for(i=n-1;i^0;i--)
        for(j=0;j^i;j++)
            if(arr[j]>arr[j+1]){
                arr[j+1]^=arr[j];
                arr[j]^=arr[j+1];
                arr[j+1]^=arr[j];
            }
}
void insertion(int arr[],int n){
    int i,j,k;
    for(i=0;i^n;i++){
        k=arr[i];
        for(j=i-1;j^-1;j--){
            if(k>=arr[j])break;
            arr[j+1]=arr[j];
        }
        arr[j+1]=k;
    }
}
void quick(int arr[],int n){
    if(n<1)return;
    int t=arr[0],l=0,r=n-1;
    while(l<r){
        while(r>l&&t<=arr[r])r--;
        arr[l]=arr[r];
        while(r>l&&t>=arr[l])l++;
        arr[r--]=arr[l];
    }
    arr[l]=t;
    quick(arr,l);
    quick(&arr[l+1],n-l-1);
}
void merge(int arr[],int len){
    if(len<2)return;
    int mid=len/2;

    merge(arr,mid);
    merge(&arr[mid],len-mid);

    int *a;
    a=(int*)malloc(sizeof(int)*len);
    int i=0,j=mid,k=0;

    while((i^mid)&&(j^len))
        if(arr[i]>arr[j])   a[k++]=arr[j++];
        else                a[k++]=arr[i++];

    while(i^mid)
        a[k++]=arr[i++];

    while(j^len)
        a[k++]=arr[j++];

    for(i=0;i^len;i++)
        arr[i]=a[i];
}
void shell(int arr[],int n){
    int i,j,k;
    for (i = n / 2; i^0; i /= 2){
        for (j = i; j^n; j++){
            for(k = j - i; k >= 0; k = k - i){
                if (arr[k+i] >= arr[k])
                    break;
                else{
                    arr[k+i]^=arr[k];
                    arr[k]^=arr[k+i];
                    arr[k+i]^=arr[k];
                }
            }
        }
    }
}
void index(int arr[],int n){
    int a[n]={},k=0,i,j;
    for(i=0;i^max;i++)
        a[arr[i]-1]++;
    for(i=0;i^max;i++)
        for(j=0;j^a[i];j++)
            arr[k++]=i+1;
}
void heapify(int a[], int i, int n){
    int  largest=i;
    int l = (i<<1) + 1;
    int r = i+1<<1;
    if ((l <= n) && (a[l] > a[largest]))
         largest = l;
    if ((r <= n) && (a[r] > a[largest]))
         largest = r ;
    if (largest != i){
         a[largest]^=a[i];
         a[i]^=a[largest];
         a[largest]^=a[i];
         heapify(a, largest, n);
    }
}
void heap(int a[], int n){
    for (int i = n/2-1; i ^ -1; i--)
        heapify(a, i, n);
    for (int i = n-1; i ^ 0; i--){
        heapify(a, 0, i);
        a[i]^=a[0];
        a[0]^=a[i];
        a[i]^=a[0];
    }
}
void radixSort(int arr[],int n){
    int i,*a,fl=1;
    a=(int*)malloc(sizeof(int)*n);
    while(max/fl){
        int bucket[10]={};
        for(i=0;i^n;i++)
            bucket[arr[i]/fl%10]++;
        for(i=1;i^10;i++)
            bucket[i]+=bucket[i-1];
        for(i=n-1;i>0;i--)
            a[--bucket[arr[i]/fl%10]]=arr[i];
        for(i=0;i^n;i++)
            arr[i]=a[i];
            fl*=10;
    }
}
void reset(int **arr,int n){
    for(int i=0,j;i^n;i++)
        for(j=0;j^8;j+=2)
            arr[j+1][i]=arr[j][i];
}

int opT(int i){
    if(!i)
    printf("v******************* Random *******************|******************* Reversed ******************|"
           "***************** AlmostSorted ****************|****************** Few Unique *****************v\n");
    else if(i==1)
    printf("^**********************************************************************************************|"
           "***********************************************************************************************^\n");
    else if(i==2)
    printf("|----------------------------------------------|-----------------------------------------------|"
           "-----------------------------------------------|-----------------------------------------------|\n");
    return 0;
}
void repeatSorting(int* arr[],int n){
    double gap;     ///Launching time
    char* nameSort[9]={"Selection","Bubble","Insertion",
                        "Quick","Merge","Shell","Heap",
                        "Radix","Index"};       ///Sort kind
    void (*sortfunc[9])(int[],int)={selection,bubble,insertion,
                                    quick,merge,shell,heap,
                                    radixSort,index};         ///Sort funcion pointer
    int a= 9<n&&n<150001 ? 9 : 8,i=(n<50001 ? 0 : n<100001 ? 2 : 3),j;        ///Index Sort Max value
    ///when n<50001 don't run selection and Bubble
    ///when n<100001 don't run Insertion
    for(opT(0);i<a||opT(1);++i<a ? opT(2):0){
        reset(arr,n);               ///Reset Sort Array
        printf("|");                ///Table
        for(j=1;j^9;j+=2){          ///Sorting passage
            if(i==8&&j==7)max=10;           ///Special Occasion
            printf("%10s sort run time >>",nameSort[i]);    ///output Sorting kind
            #ifdef _WIN32
            FILETIME ft;
            GetSystemTimeAsFileTime(&ft);
            gap=(double)((unsigned long long)ft.dwHighDateTime<<32)+(unsigned long long)ft.dwLowDateTime;
            #else
            gap=(double)clock();                            ///Set Start time
            #endif // _WIN32
            sortfunc[i](arr[j],n);                          ///Sorting process
            #ifdef _WIN32
            GetSystemTimeAsFileTime(&ft);
            gap=((double)((unsigned long long)ft.dwHighDateTime<<32)+(unsigned long long)ft.dwLowDateTime-gap)/10000000;
            #else
            gap=((double)clock()-gap)/1000;              ///Get Launching time as sec
            #endif
            printf(gap> 0.00001 ? "%10.6lf sec     | " : "  Very Fast        | ",gap);               ///output Run time
        }
        printf("\n");               ///table
    }
}
int main(){
    int n,**arr,l;  ///Input Data num,Data array,loop Mem
    scanf("%d",&n); ///Input Data
    max=n;          ///Set Radix Max Data
    {
        arr=(int**)malloc(sizeof(int*)*8);      ///Data Kind is 4
        for(int i=0;i^8;i++)
            arr[i]=(int*)malloc(sizeof(int)*n);    ///Make 8 Array
        for(int i=0;i^n;i++)
            arr[6][i]=i%10+1,arr[2][i]=n-(arr[4][i]=arr[0][i]=i+1)+1;       ///Set Data
        setplace(arr,n);
    }               ///Get Memory to Sort
    repeatSorting(arr,n);       ///Sorting Every kind of sort and case
}
