#include <iostream>
#include <queue>
using namespace std;

int main() {
  //max-heap
  priority_queue<int> max_heap;
  max_heap.push(3);
  max_heap.push(6);
  max_heap.push(9);
  max_heap.push(4);
  max_heap.push(8);

  cout << "top element: " << max_heap.top() << endl;
  max_heap.pop();
  cout << "top element: " << max_heap.top() << endl;
  max_heap.pop();
  cout << "top element: " << max_heap.top() << endl;
  max_heap.pop();
  cout << "top element: " << max_heap.top() << endl;
  max_heap.pop();
  cout << "top element: " << max_heap.top() << endl;
  max_heap.pop();
  cout << "Size: " << max_heap.size() << endl;
  if(max_heap.empty()) {
          cout << "Max heap is empty" << endl;
  }
  else {
          cout << "Max heap is not empty" << endl;
  }







          //min-heap
        priority_queue<int,vector<int>, greater<int> > min_heap;
        min_heap.push(3);
        min_heap.push(6);
        min_heap.push(9);
        min_heap.push(4);
        min_heap.push(8);

        cout << "top element: " << min_heap.top() << endl;
        min_heap.pop();
        cout << "Size: " << min_heap.size() << endl;
        cout << "top element: " << min_heap.top() << endl;
        min_heap.pop();
        cout << "top element: " << min_heap.top() << endl;
        min_heap.pop();
        cout << "top element: " << min_heap.top() << endl;
        min_heap.pop();
        cout << "top element: " << min_heap.top() << endl;
        min_heap.pop();

          if(min_heap.empty()) {
          cout << "Min heap is empty" << endl;
  }
  else {
          cout << "Min heap is not empty" << endl;
  }

        return 0;
}