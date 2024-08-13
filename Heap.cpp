/*笔记：简单实现大顶堆*/
#include <vector>
#include <iostream>
using namespace std;

class MaxHeap {
private:
	vector<int> heap;
	size_t size = 0;
	void heapInsert(int index) {
		while (heap[index] > heap[(index - 1) / 2]) {
			swap(heap[index], heap[(index - 1) / 2]);
			index = ((index - 1) >> 1);
		}
	};
	void heapify(int index) {
		int left = index * 2 + 1;
		while (left < size) {
			int largest = left + 1 < size && heap[left + 1] > heap[left] ? left + 1 : left;
			largest = heap[largest] > heap[index] ? largest : index;
			if (largest == index) {
				break;
			}
			swap(heap[largest], heap[index]);
			index = largest;
			left = index * 2 + 1;
		}
	};
public:
	MaxHeap() {};
	MaxHeap(vector<int> nums) {
		heap = nums;
		size = nums.size();
		for (int i = 0; i < size; i++) {
			heapInsert(i);
		}
	}
	void push(int x) {
		heap.emplace_back(x);
		heapInsert(size++);
	}
	int top()const {
		if (size == 0) {
			throw runtime_error("empty heap");
		}
		return heap.at(0);
	}
	int pop() {
		if (size == 0) {
			throw runtime_error("empty heap");
		}
		int ret = heap.at(0);
		swap(heap.at(0), heap.at(--size));
		heapify(0);
		return ret;
	}
};

/*int main() {
	vector<int> nums = { 3,2,1,2,4,5,7,0,2 };
	MaxHeap heap(nums);
	for(int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout<< endl;
	cout <<"Top: " << heap.top() << endl;
	cout<<"Push: 6" << endl;
	heap.push(6);
	cout << "Pop: " << heap.pop() << endl;
	cout << "Pop: " << heap.pop() << endl;
	cout << "Pop: " << heap.pop() << endl;
	cout << "Pop: " << heap.pop() << endl;
	cout << "Pop: " << heap.pop() << endl;
	cout << "Pop: " << heap.pop() << endl;
	cout << "Pop: " << heap.pop() << endl;
	return 0;
}*/