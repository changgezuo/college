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
const int BUCKET_NUM = 10;

struct ListNode{
    explicit ListNode(int i=0):mData(i),mNext(NULL){}
    ListNode* mNext;
    int mData;
};

ListNode* insert(ListNode* head,int val){
    ListNode dummyNode;
    ListNode *newNode = new ListNode(val);
    ListNode *pre,*curr;
    dummyNode.mNext = head;
    pre = &dummyNode;
    curr = head;
    while(NULL!=curr && curr->mData<=val){
        pre = curr;
        curr = curr->mNext;
    }
    newNode->mNext = curr;
    pre->mNext = newNode;
    return dummyNode.mNext;
}


ListNode* Merge(ListNode *head1,ListNode *head2){
    ListNode dummyNode;
    ListNode *dummy = &dummyNode;
    while(NULL!=head1 && NULL!=head2){
        if(head1->mData <= head2->mData){
            dummy->mNext = head1;
            head1 = head1->mNext;
        }else{
            dummy->mNext = head2;
            head2 = head2->mNext;
        }
        dummy = dummy->mNext;
    }
    if(NULL!=head1) dummy->mNext = head1;
    if(NULL!=head2) dummy->mNext = head2;

    return dummyNode.mNext;
}

void BucketSort(int n,int arr[]){
    vector<ListNode*> buckets(BUCKET_NUM,(ListNode*)(0));
    for(int i=0;i<n;++i){
        int index = arr[i]/BUCKET_NUM;
        ListNode *head = buckets.at(index);
        buckets.at(index) = insert(head,arr[i]);
    }
    ListNode *head = buckets.at(0);
    for(int i=1;i<BUCKET_NUM;++i){
        head = Merge(head,buckets.at(i));
    }
    for(int i=0;i<n;++i){
        arr[i] = head->mData;
        head = head->mNext;
    }
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