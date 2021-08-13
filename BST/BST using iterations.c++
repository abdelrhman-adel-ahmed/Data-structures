#include <iostream>
using namespace std;

class BstNode {

private:
    int data;
    BstNode* left;
    BstNode* right;
    BstNode* root = NULL;
    
     /*return -1 if we in the leaf because the height of the leaf node is 0 so 
    we return -1 for left and -1 for right -> max(-1,-1)+1 -> 0 so for the 
    leaf nodes we return 0 as the height of that node*/
    int find_height(BstNode* root)
    {
        if (root == NULL)
            return -1;
        //hegiht of node is the max height of the left subtree ,right subtree (+1) for the edge that connect the node to the max of them 
        else return max(find_height(root->left), find_height(root->right)) + 1;

    }
public:
    /* we want to change the address that the pointer point to ,so we pass the pointer
    as refrence pointer
    */
    void insert_node(BstNode* node) {

        if (root == NULL)
            root = node;
        else
        {
            BstNode* temp = root;
            while (temp != NULL)
            {
                if (node->data <= temp->data && temp->left == NULL)
                {
                    temp->left = node;
                    break;
                }
                else if (node->data <= temp->data)
                {
                    temp = temp->left;
                }
                else if (node->data > temp->data && temp->right == NULL)
                {
                    temp->right = node;
                    break;
                }
                else { temp = temp->right; }
            }
        }

    }
    void insert(int data)
    {
        BstNode* node = new BstNode();
        node->data = data;
        node->right = NULL;
        node->left = NULL;
        insert_node(node);
    }
    bool search(int data)
    {
        if (root == NULL)return false;
        else if (root->data == data)return true;
        else
        {
            BstNode* temp = root;
            while (temp != NULL)
            {
                if (data == temp->data)
                {
                    return true;
                    break;
                }
                else if (data < temp->data && temp->left == NULL)
                {
                    return false;
                }
                else if (data < temp->data && temp->left != NULL)
                {
                    temp = temp->left;
                }
                else if (data > temp->data && temp->right == NULL)
                {
                    return false;
                }
                else if (data > temp->data && temp->right != NULL)
                {
                    temp = temp->right;
                }
            }
        }
    }
   BstNode* get_node_address(int data)
    {
       
       if (root == NULL)return root;
       else if (root->data == data)return root;
       else
       {
           BstNode* temp = root;
           while (temp != NULL)
           {
               if (data == temp->data)
               {
                   return temp;
                   break;
               }
               else if (data < temp->data && temp->left == NULL)
               {
                   return NULL;
               }
               else if (data < temp->data && temp->left != NULL)
               {
                   temp = temp->left;
               }
               else if (data > temp->data && temp->right == NULL)
               {
                   return NULL;
               }
               else if (data > temp->data && temp->right != NULL)
               {
                   temp = temp->right;
               }
           }
       }
    }

    int min_elements()
    {
        BstNode* current = root;
        if (root == NULL) return -1;
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current->data;
    }
    int max_elements()
    {
        BstNode* current = root;
        if (root == NULL) return -1;
        while (current->right != NULL)
        {
            current = current->right;
        }
        return current->data;
    }
    int num_edges() { return count - 1; }
    int num_nodes() { return count; }
    int height()
    {
         int res=find_height(root);
        return res;
    }
    

};


int main()
{


    BstNode* b = new BstNode;
    b->insert(50);
    b->insert(30);
    b->insert(26);


    cout << b->root->data << endl;
    cout << b->root->left->data << endl;
    cout << b->root->left->left->data << endl;
    cout << b->search(1)<<endl;
    cout << b->min_elements();



    // b.insert(20);
    // cout<<b.root<<endl;
    // b.insert(17);
    // b.insert(25);
    // b.insert(16);
    // cout << b.root;



}
