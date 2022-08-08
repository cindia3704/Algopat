
/*
    작성자: 김지수
    작성일: 2022/08/09
    SWEA -- 기초 Partial Sort (12372번)
*/

#define MAX 100002
using namespace std;

struct User {
   int id;
   int income;
};

class Heap {
   #define parent (i>>1)
   #define left (i<<1)
   #define right (i<<1|1)

   User data[MAX];
   int size;
public: 
   Heap() = default;
   void init() {
      size = 0;
   }
   int getSize() {
      return size;
   }
   void push(int id, int income) {
      User u;
      u.id = id;
      u.income = income;
      data[++size] = u;
      for (int i = size; parent != 0 && (data[parent].income < data[i].income || (data[parent].income == data[i].income && data[parent].id > data[i].id));i>>=1) {
         User temp = data[parent];
         data[parent] = data[i];
         data[i] = temp;
      }
   }

   User top() {
      if (size == 0) {
         User n;
         n.id = -1;
         n.income = -1;
         return n;
      }
      return data[1];
   }

   void pop() {
      data[1] = data[size--];
      for (int i = 1; left <= size;) {
         const int maxChild = (left == size || (data[left].income > data[right].income || (data[left].income == data[right].income && data[left].id < data[right].id))) ? left : right;

         if (data[maxChild].income > data[i].income || (data[maxChild].income == data[i].income && data[maxChild].id < data[i].id)) {
            User temp = data[maxChild];
            data[maxChild] = data[i];
            data[i] = temp;
            i = maxChild;
         }
         else {
            break;
         }
      }
   }

};

Heap h;

void init()
{
   h.init();
}

void addUser(int uID, int height)
{
   h.push(uID, height);
}

int getTop10(int result[10])
{
   int cnt = 0;
   Heap t = h;
   for (int i = 0; i < 10; i++) {
      User temp = t.top();
      if (temp.id != -1) {
         result[i] = temp.id;
         t.pop();
         cnt++;
      }
      else {
         break;
      }
   }
   return cnt;
}