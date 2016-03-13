#include<cstdlib>
#define DefaultSize 20

template<class T>
class MinHeap
{
public:
	MinHeap(int sz=DefaultSize);
	MinHeap(T arr[],int n);
	~MinHeap(){delete [] heap;}
	bool Insert(const T &x);
	bool RemoveMin(T &x);
	bool IsEmpty(){return currentSize==0;}
	bool IsFull(){return currentSize==maxHeapSize;}
	void MakeEmpty(){currentSize=0;}
private:
	T *heap;
	int currentSize;
	int maxHeapSize;
	void siftDown(int start,int m);
	void siftUp(int start);
};


template<class T>
MinHeap<T>::MinHeap(int sz)
{
	maxHeapSize=(sz>DefaultSize)?sz:DefaultSize;
	heap=new T[maxHeapSize];
	if(heap==NULL)
	{
		cerr<<"¶Ñ´¢´æ·ÖÅä´íÎó£¡"<<endl;
		exit(1);
	}
	currentSize=0;
}


template<class T>
MinHeap<T>::MinHeap(T arr[],int n)
{
	maxHeapSize=(n>DefaultSize)?n:DefaultSize;
	heap=new T[maxHeapSize];
	if(heap==NULL)
	{
		cerr<<"¶Ñ´¢´æ·ÖÅä´íÎó£¡"<<endl;
		exit(1);
	}
	for(int i=0;i<n;i++)
		heap[i]=arr[i];
	currentSize=n;
	int currentPos=(currentSize-2)/2;
	while(currentSize>=0)
	{
		siftDown(currentPos,currentSize);
		currentPos--;
	}
}


template<class T>
void MinHeap<T>::siftDown(int start,int m)
{
	int i=start;
	int j=2*i+1;
	T temp=heap[i];
	while(j<=m)
	{
		if(j<m && heap[j]>heap[j+1]) j++;
		if(heap[j]>=temp) break;
		else
		{
			heap[i]=heap[j];
			i=j;
			j=2*j+1;
		}
	}
	heap[i]=temp;
}


template<class T>
void MinHeap<T>::siftUp(int start)
{
	int j=start;
	int i=(j-1)/2;
 	T temp=heap[j];
	while(j>0)
	{
		if(temp>=heap[i]) break;
		else
		{
			heap[j]=heap[i];
			j=i;
			i=(i-1)/2;
		}
	}
	heap[j]=temp;
}

template<class T>
bool MinHeap<T>::Insert(const T &x)
{
	if(currentSize==maxHeapSize) 
	{
		cerr<<"Heap Full"<<endl;
		return false;
	}
	heap[currentSize]=x;
	siftUp(currentSize);
	currentSize++;
	return true;
}


template<class T>
bool MinHeap<T>::RemoveMin(T &x)
{
	if(currentSize==0) 
	{
		cout<<"Heap empty"<<endl;
		return false;
	}
	x=heap[0];
	heap[0]=heap[currentSize-1];
	currentSize--;
	siftDown(0,currentSize-1);
	return true;
}