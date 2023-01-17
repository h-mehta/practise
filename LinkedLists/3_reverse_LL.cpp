
/*

Reeverse the LL in-place

*/

using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

LinkedList *reverseLinkedList(LinkedList *head) {
  // Write your code here.
  LinkedList *front = head;
  LinkedList *last = nullptr;
  LinkedList *back = front;

  while(back->next!=last){
    back = back->next;
  }

  while(front != back){
      //cout << front->value << "\t" << back->value << endl;
      int temp = back->value;
      back->value = front->value;
      front->value = temp;
    
      last = back;
      if(front->next!=last){
        front = front->next;
      }else{
        break;
      }
      back = front;
      while(back->next != last){
        back = back->next;
      }
  }
  
  return head;
}

