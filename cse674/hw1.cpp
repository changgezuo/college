//sort algorithm
#include <iostream>
#include <vector>

using namespace std;

//bubble sort
//time complexityO(n^2),space compelxity O(1)
void bubbleSort_1(vector<int>&v){
    if(v.empty())return ;
    int temp;
    // the times that need to be arraneg
    for (int i = 0; i < v.size() - 1; ++i) {
        for (int j = 0; j < v.size() - 1; j++) {
            if (v[j + 1] < v[j]) {
                swap(v[j+1],v[j]);
            }
        }
    }
}

// improved bubble sort
void bubbleSort_2(vector<int>&v){
    if (v.size()<=1)return;

    for (int i = 0; i < v.size() - 1; ++i){
        bool bChanged = false;
        for (int j = 0; j < v.size() - 1; j++){
            if (v[j + 1] < v[j]){
                swap(v[j+1],v[j]);
                bChanged = true;
            }
        }
        // if flag is false means during this traversal all elment are sorted
        if (false == bChanged){
            break;
        }
    }
}

// selection sort
void selectionSort(vector<int> &v){
    if(v.size()<2)return;
    for (int i = 0; i < v.size(); i++){
        int minIndex=i;
        for (int j=i+1; j<v.size();++j){
            if(v[j]<v[i])minIndex=j;
        }
        swap(v[i],v[minIndex]);
    }
}
//insert sort
void insertionSort(vector<int>&arr){
    for(int i=1;i<arr.size();i++){
        int key=arr[i];
        int j=i-1;
        while((j>=0) && (key<arr[j])){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
// 希尔排序
vector<int> ShellSort(vector<int> list){
    vector<int> result = list;
    int n = result.size();
    for (int gap = n >> 1; gap > 0; gap >>= 1){
        for (int i = gap; i < n; i++){
            int temp = result[i];
            int j = i - gap;
            while (j >= 0 && result[j] > temp){
                result[j + gap] = result[j];
                j -= gap;
            }
            result[j + gap] = temp;
        }
        for (int i = 0; i < result.size(); i++){
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return result;
}

// 快速排序的division函数
int division(vector<int> &list, int left, int right){
    // 以最左边的数(left)为基准
    int base = list[left];
    while (left < right) {
        // 从序列右端开始，向左遍历，直到找到小于base的数
        while (left < right && list[right] >= base)
            right--;
        // 找到了比base小的元素，将这个元素放到最左边的位置
        list[left] = list[right];

        // 从序列左端开始，向右遍历，直到找到大于base的数
        while (left < right && list[left] <= base)
            left++;
        // 找到了比base大的元素，将这个元素放到最右边的位置
        list[right] = list[left];
    }

    // 最后将base放到left位置。此时，left位置的左侧数值应该都比left小；
    // 而left位置的右侧数值应该都比left大。
    list[left] = base;
    return left;
}
int parition(int A[],int low,int high){
    int pivot=A[low];
    while(low<high){
        while(low<high&&A[high]>=pivot)--high;
        A[low]=A[high];
        while(low<high&&A[low]<=pivot)++low;
        A[high]=A[low];
    }
    A[low]=pivot;
    return low;
}
void QuickSort(int A[], int low, int high){
    if(low<high){
        int pivot=parition(A,low,high);
        QuickSort(A,low,pivot-1);
        QuickSort(A,pivot+1,high);
    }
}
// 快速排序
void QuickSort(vector<int> &list, int left, int right){
    // 左下标一定小于右下标，否则就越界了
    if (left < right) {
        // 对数组进行分割，取出下次分割的基准标号
        int base = division(list, left, right);

        // 对“基准标号“左侧的一组数值进行递归的切割，以至于将这些数值完整的排序
        QuickSort(list, left, base - 1);

        // 对“基准标号“右侧的一组数值进行递归的切割，以至于将这些数值完整的排序
        QuickSort(list, base + 1, right);
    }
}


// 堆排序的初始化函数
void HeapAdjust(vector<int> &list, int parent, int length){
    int temp = list[parent];					// temp保存当前父节点
    int child = 2 * parent + 1;					// 先获得左孩子

    while (child < length){
        // 如果有右孩子结点，并且右孩子结点的值大于左孩子结点，则选取右孩子结点
        if (child + 1 < length && list[child] < list[child + 1]){
            child++;
        }

        // 如果有右孩子结点，并且右孩子结点的值大于左孩子结点，则选取右孩子结点
        if (temp >= list[child]){
            break;
        }

        // 把孩子结点的值赋给父结点
        list[parent] = list[child];

        // 选取孩子结点的左孩子结点,继续向下筛选
        parent = child;
        child = 2 * parent + 1;
    }
    list[parent] = temp;
}

// 堆排序
vector<int> HeadSort(vector<int> list){
    int length = list.size();
    // 循环建立初始堆
    for (int i = length / 2; i >= 0; i--){
        HeapAdjust(list, i, length);
    }

    // 进行n-1次循环，完成排序
    for (int i = length - 1; i > 0; i--){
        // 最后一个元素和第一元素进行交换
        int temp = list[i];
        list[i] = list[0];
        list[0] = temp;

        // 筛选 R[0] 结点，得到i-1个结点的堆
        HeapAdjust(list, 0, i);
        cout << "第" << length - i << "趟排序:";
        for (int i = 0; i < list.size(); i++){
            cout << list[i] << " ";
        }
        cout << endl;
    }
    return list;
}
void maxHeapify(int arr[],int start,int end){
    int dad=start,son=dad*2+1;
    while(son<=end){
        if(son+1<=end&&arr[son]<arr[son+1])son++;
        if(arr[dad]>arr[son]){
            return;
        }
        else {
            swap(arr[dad],arr[son]);
            dad=son;
            son=dad*2+1;
        }
    }
}
void heapsort(int arr[],int n){
    for(int i=n/2-1;i>=0;--i){
        maxHeapify(arr,i,n-1);
    }
    for(int i=n-1;i>-;--i){
        swap(arr[0],arr[i]);
        maxHeapify(arr,0,i-1);
    }
}
void merge(int input[],int left,int mid,int right,int tmp[]){
    int i=left,j=mid+1,k=left;
    while(i<=mid&&j<=right){
        if(input[i]<=input[j]){
            tmp[k++]=input[i++];
        }
        else tmp[k++]=input[j++];
    }
    while(i<=mid){
        tmp[k++]=input[i++];
    }
    while(j<=right)tmp[k++]=input[j++];
    while(left<=right){input[left]=tmp[left];left++;}
}
void mergeSort(int input[],int left,int right,int tmp[] ){
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(input,left,mid,tmp);
        mergeSort(input,mid+1,right,tmp);
        merge(input,left,mid,right,tmp);
    }
}
void mergesort(int input[], int n){
    int tmp[n];
    mergeSort(input,0,n-1,tmp);
}


int maxbit(int data[], int n){
    int mx=data[0];
    for(int i=1;i<n;++i)if(data[i]>mx)mx=data[i];
    int d=0;
    while(mx!=0){d++;mx/=10;}
    return d;
}

void radixsort(int data[], int n){
    int d=maxbit(data,n);
    int tmp[n];//tmp array to swap
    int cnt[10];//represent how many numbers in cur digit
    int k=0,radix=1;//to get cur digit
    for(int i=0;i<d;++i){
        for(int j=0;j<10;++j)cnt[j]=0;
        for(int j=0;j<n;++j){
            k=(data[j]/radix)%10;
            cnt[k]++;
        }
        for(int j=1;j<10;++j)cnt[j]=cnt[j-1]+cnt[j];//array the order as cur digit
        for(int j=n-1;j>=0;--j){
            k=(data[j]/radix)%10;
            tmp[cnt[k]-1]=data[j];
            cnt[k]--;
        }
        for(int j=0;j<n;++j)data[j]=tmp[j];
        radix=radix*10;
    }
}
int main(){
    int data[16]={3,44,5,22123,3213,2,7,45,63,323,565,78,80,534,23,5456};
    mergesort(data,16);
    for(int i=0;i<16;++i)printf("%d\n",data[i]);


    return 0;
}