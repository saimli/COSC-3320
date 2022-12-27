#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
using namespace std;

struct node
{
  int data;
  int* matrix;
  node* left;
  node* right;
  int height;
};

class BST
{
  private:
    int size_0 = pow(2, 20);
    int size_1 = pow(2, 19) + pow(2, 20);
    int size_2 = pow(2, 18) + pow(2, 17);
    int node_count = 0;
    int insert_count = 0;
    int delete_count = 0;
    node* root;
    node* insert(int x, node* t)
    {
      int remainder = x % 3;
      if (t == NULL)
      {
        insert_count++;
        t = new node;
        t->data = x;
        node_count++;
        t->height = 0;

        t->left = t->right = NULL;
        if (remainder == 0)
          t->matrix = new int[size_0];
        else if (remainder == 1)
          t->matrix = new int[size_1];
        else
          t->matrix = new int[size_2];
      }
      else if (x < t->data)
      {
        t->left = insert(x, t->left);
        if (height(t->left) - height(t->right) == 2)
        {
          if (x < t->left->data)
            t = singleRightRotate(t);
          else
            t = doubleRightRotate(t);
        }
      }
      else if (x > t->data)
      {
        t->right = insert(x, t->right);
        if (height(t->right) - height(t->left) == 2)
        {
          if (x > t->right->data)
            t = singleLeftRotate(t);
          else
            t = doubleLeftRotate(t);
        }
      }
      t->height = max(height(t->left), height(t->right)) + 1;
      return t;
    }

    node* singleRightRotate(node*& t)
    {
      if (t == NULL || t->left == NULL)
        return t;
      else
      {
        node* u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(height(t->left), height(t->right)) + 1;
        u->height = max(height(u->left), t->height) + 1;
        return u;
      }
      return t;
    }

    node* singleLeftRotate(node*& t)
    {
      if (t == NULL || t->right == NULL)
        return t;
        
      else
      {
        node* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right)) + 1;
        u->height = max(height(t->right), t->height) + 1;
        return u;
      }
      return t;
    }

    node* doubleLeftRotate(node*& t)
    {
      t->right = singleRightRotate(t->right);
      return singleLeftRotate(t);
    }

    node* doubleRightRotate(node*& t)
    {
      t->left = singleLeftRotate(t->left);
      return singleRightRotate(t);
    }

    node* findMin(node* t)
    {
      if (t == NULL)
        return NULL;
      else if (t->left == NULL)
        return t;
      else
        return findMin(t->left);
    }

    node* findMax(node* t)
    {
      if (t == NULL)
        return NULL;
      else if (t->right == NULL)
        return t;
      else
        return findMax(t->right);
    }

    node* remove(int x, node* t)
    {
      node* temp;
      // Element not found
      if (t == NULL)
        return NULL;
      // Searching for element
      else if (x < t->data)
        t->left = remove(x, t->left);
      else if (x > t->data)
        t->right = remove(x, t->right);
      // Element found w/ 2 children
      else if (t->left && t->right)
      {
        temp = findMin(t->right);
        t->data = temp->data;
        t->right = remove(t->data, t->right);
      }
      // With one or zero child
      else
      {
        temp = t;
        if (t->left == NULL)
            t = t->right;
        else if (t->right == NULL)
            t = t->left;
        delete[] temp->matrix;
        delete temp;
        delete_count++;
        node_count--;
      }
      if (t == NULL)
        return t;
      t->height = max(height(t->left), height(t->right)) + 1;
      // If node is unbalanced
      // If left node is deleted, right case
      if (height(t->left) - height(t->right) == 2)
      {
        // right right case
        if (height(t->left->left) - height(t->left->right) == 1)
          return singleLeftRotate(t);
        // right left case
        else
          return doubleLeftRotate(t);
      }
      // If right node is deleted, left case
      else if (height(t->right) - height(t->left) == 2)
      {
        // left left case
        if (height(t->right->right) - height(t->right->left) == 1)
          return singleRightRotate(t);
        // left right case
        else
          return doubleRightRotate(t);
      }
      return t;
  }

  int height(node* t)
    {return (t == NULL ? -1 : t->height);}

  int getBalance(node* t)
  {
    if (t == NULL)
      return 0;
    else
      return height(t->left) - height(t->right);
  }
  void inorder(node* t)
  {
    if (t == NULL)
      return;
    inorder(t->left);
    cout << t->data << " ";
    inorder(t->right);
  }

  public:
    BST() {root = NULL;}
    void insert(int x) {root = insert(x, root);}
    void remove(int x) {root = remove(x, root);}
    void display()
      {
        inorder(root);
        cout << endl;
      }
    int getcount() {return node_count;}
    int insertcount() {return insert_count;}
    int deletecount() {return delete_count;}
    void setcount() {insert_count = 0;}
};

int main(int argc, char* argv[])
{
  srand((unsigned int)time(0));
  double initial_insertion = 0;
  double insertion = 0;
  double deletion = 0;
  double start, stop, time;
  int* num_array = new int[200000];
  int counter = 0;
  for (int i = 0; i < 200000; i++)
  {
    num_array[i] = rand() % 299 + 1;
  }
  BST node;
  int j = 0;
  start = clock();
  while (node.getcount() < 50)
  {
    j++;
    node.insert(num_array[j]);
  }
  stop = clock();
  time = (stop - start);
  initial_insertion += time;
  
  // resets insert count to 0
  node.setcount(); 
  for (int i = 0; i < 100000; i++)
  {
    while (node.getcount() < 50)
    {
      j++;
      start = clock();
      node.insert(num_array[j]);
      stop = clock();
    }
    time = (stop - start);
    insertion += time;
    while (node.getcount() >= 50)
    {
      start = clock();
      node.remove(num_array[j]);
      stop = clock();
    }
    time = (stop - start);
    deletion += time;
  }
  cout << "Average Initial Insertion time: " << setprecision(5) << 
  initial_insertion / 50.00 << " ms." << endl;
  cout << "Average Insertion time: " << setprecision(5) << 
  insertion / node.insertcount() << " ms." << endl;
  cout << "Average Deletion time: " << setprecision(5) << 
  deletion / node.deletecount() << " ms." << endl;
}
