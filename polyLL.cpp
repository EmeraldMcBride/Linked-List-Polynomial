#include <fstream>
#include <iostream>


using namespace std;


struct Node {                                       /* struct of node */
  int coef;
  int exp;
  Node* next;
};

void printList(Node *head)
{
  Node * temp = head;
  while(temp -> next != NULL){
    cout << temp->coef << endl << temp ->exp << endl << endl;
  temp = temp -> next;
  }}



int main() {
  ifstream myReadFile;                              /* declare file writer and file reader */
  ofstream myWriteFile("newPoly.txt");              /* declare file name to write to */
  Node *poly1 = new Node();                         /* declare pointer used for populating first linked list */
  Node *head1 = new Node();

  myReadFile.open("poly1.txt");                     /* Open the first polynomial file */
  int n = 0;
  int lines = 0;
  int num = 0;
  int first = 1;
  string s;
  while (myReadFile >> s) {                          /* determines how many elements are in the file */
    lines++;
  }
  myReadFile.clear();
  myReadFile.seekg(0, ios::beg);                    /* reset the pointer to the top of the file */
  while (!myReadFile.eof()) {                       /* create an array out of the file contents */
    if(n==0){
      myReadFile >> poly1 -> coef;
      if (first == 1)
	head1 = poly1;
      first--;
      n++;
    }      else if (n==1){
      myReadFile >> poly1 -> exp;
      if(poly1 -> exp == 0)
        poly1 -> exp = 1;
      poly1 -> next = new Node();
      poly1 = poly1->next;
      n--;
    }}
  
  myReadFile.close();
  printList(head1);

  Node *poly2 = new Node();                       /* declare pointer used for populating second list */
  Node *head2 = new Node();

  myReadFile.open("poly2.txt");                     /* Open the first polynomial file */
  int n2 = 0;
  int lines2 = 0;
  first = 1;
  string s2;
  while (myReadFile >> s2) {                          /* determines how many elements are in the file */
    lines2++;
  }
  myReadFile.clear();
  myReadFile.seekg(0, ios::beg);                    /* reset the pointer to the top of the file */
  while (!myReadFile.eof()) {                       /* create an array out of the file contents */
    if(n2==0){
      myReadFile >> poly2 -> coef;
      if (first == 1)
        head2 = poly2;
      first--;
      n2++;
    }      else if (n2==1){
      myReadFile >> poly2 -> exp;
      if(poly2 -> exp == 0)
        poly2 -> exp = 1;
      poly2 -> next = new Node();
      poly2 = poly2->next;
      n2--;
    }}

  myReadFile.close();
  printList(head2);
 


  Node *num1 = head1;                          
  Node *num2 = head2;
  Node *num3 = new Node();
  cout << num1 << endl;
  cout << num2 << endl;
  cout << num3 << endl;
  int add = 0;
  while (num1 != NULL || num2 != NULL) {                            /* check that both lists still have nodes left */
    if (num1 == NULL) {                                             /* if first list is empty add node from second list */
      myWriteFile << num2->coef << endl << num2->exp << endl;
      num2 = num2->next;
    }
    else if (num2 == NULL) {                                        /* if second list is empty add node from first list */
      myWriteFile << num1->coef << endl << num1->exp << endl;
      num1 = num1->next;
    }
    else {
      if (num1->exp == num2->exp) {                                 /* if both lists have nodes and equal exp on the pointed node add coef and add node*/
	add = num1->coef + num2->coef;
	myWriteFile << add << endl << num1->exp << endl;
	num1 = num1->next;
	num2 = num2->next;
      }
      else if (num1->exp < num2->exp) {                             /* both lists have nodes but node1 exp > node2 exp, add node1 */
	myWriteFile << num1->coef << endl << num1->exp << endl;
	num1 = num1->next;
      }
      else if (num1->exp > num2->exp) {                             /* both lists have nodes but node1 exp < node2 exp, add node2 */
	myWriteFile << num2->coef << endl << num2->exp << endl;
	num2 = num2->next;
      }
    }
  }
  myWriteFile.close();
} 
