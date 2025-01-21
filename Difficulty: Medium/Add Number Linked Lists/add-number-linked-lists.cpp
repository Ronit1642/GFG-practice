//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
   Node*reverse (Node*first){
        Node*temp = first;
        Node*prev = NULL;
        while(temp){
            temp = temp->next ;
            first ->next = prev;
            prev= first;
            first =temp;
        }
        return prev;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        while(num1->data == 0){
            num1 = num1->next;
        }
        while(num2->data == 0){
            num2 = num2->next;
        }
        num1 = reverse(num1);
        num2 = reverse(num2);
        
        Node*ans = new Node(-1);
        Node*ansHead = ans;
        
        int carry = 0;
        while(num1 && num2){
            // int sum = num1->data + num2->data + carry;
            int sum = (num1 ? num1->data : 0) + (num2 ? num2->data : 0) + carry;
            int digit = sum%10;
            carry = sum / 10 ;
            Node*newNode = new Node(digit);
            ans->next = newNode;
            ans = newNode;
            num1 = num1->next;
            num2 = num2->next;
            
        }
        while(num1){
            int sum = num1->data + carry;
            
            int digit = sum%10;
            carry = sum / 10 ;
            Node*newNode = new Node(digit);
            ans->next = newNode;
            ans = newNode;
            num1 = num1->next;
            
        }
        while(num2){
            int sum = num2->data + carry;
            
            int digit = sum%10;
            carry = sum / 10 ;
            Node*newNode = new Node(digit);
            ans->next = newNode;
            ans = newNode;
            num2 = num2->next;
        }
        if(carry > 0){
            Node*newNode = new Node(carry);
            ans->next = newNode;
            ans = newNode;
        }
        return reverse(ansHead->next);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends