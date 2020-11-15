
###               ###
###   11-15-2020   ###
 ###              ###
//abdelrhman adel
_____________________________________________________________________________________________________________________________
class avl
{
public:
    avl* right;
    avl* left;
    avl* root = NULL;
    int data;
    
    //insert and update height each time 
   void insert(avl*& root,avl*&node)
    {
        if (root == NULL)root=node;
        else if (node->data > root->data)insert(root->right, node);
        else if (node->data < root->data)insert(root->left, node);
        balance(root);
    }
    int find_height(avl* node)
    {
       if (node == NULL)
           return -1;
       else return max(find_height(node->left), find_height(node->right)) + 1;
   
    }
    int balance_factor(avl*node)
    {
        return (find_height(node->right) - find_height(node->left));
    }
  void rotate_left(avl*& node)
    {
        avl* temp=node;
        avl* temp1 = temp->right;
        temp->right = temp1->left;
        temp1->left = temp;
        node = temp1;
    }
   void rotate_right(avl*& node)
    {
        avl* temp = node;
        avl* temp1 = temp->left;
        temp->left = temp1->right;
        temp1->right = temp;  
        node = temp1;
    }
  void balance(avl*& node)
    {
        switch (balance_factor(node))
        {
        case -2:
            if (balance_factor(node->left) == 1)rotate_left(node->left);
            rotate_right(node);
            break;
        case 2:
            if (balance_factor(node->right) == -1)rotate_right(node->right);
             rotate_left(node);
            break;
        }

    }
    avl* find_min(avl* node)
    {
        if (node == NULL)return NULL;
        while (node->left != NULL)node = node->left;
        return node;
    }
    avl *del(avl*& root, int data)
    {
        if (root == NULL) return root;
        else if (root->data > data) root->left = del(root->left, data);
        else if (root->data < data) root->right = del(root->right, data);
        else
        {
            // no childern (leaf node)
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
            }
            //one childern (and its left child)
            else if (root->right == NULL)
            {
                avl* node = root;
                root = root->left;
                delete node;
            }
            //one childern (and its right child)
            else if (root->left == NULL)
            {
                avl* node = root;
                root = root->right;
                delete node;
            }
            /*two childern , we will take the min elemnt in the right sub-tree
            * 1- take the min element in the right sub tree
            * 2- copy it value to the node we want to delete
            * 3- delete the duplicate
            * ---------------------------------------------------------------
            * we can also find max element in the left sub tree and follow same logic
            * (draw a tree and see what happen when we want to delete a node that have
            two childern ,and for more clarity draw a whole sub trees to see what happens)
             */
            else
            {
                avl* min = find_min(root->right);
                root->data = min->data;
                root->right = del(root->right, min->data);
            }
        }
        if(root!=NULL)
            balance(root);
        return root;
    }
     void BFS(avl* root)
    {
        if (root == NULL)cout << "SHIT IS EMPTY!\n";
        queue<avl*>q;
        q.push(root);
        while (!q.empty())
        {
            avl* current = q.front();
            cout << current->data << " ";
            if (current->left != NULL)
                q.push(current->left);
            if (current->right != NULL)
                q.push(current->right);
            q.pop();
        }
        cout << endl;
    }
     void insert(int data)
    {
        avl* node = new avl();
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        insert(root, node);
    }
    void preorder(avl*root)
     {
         if (root == NULL)return;
         cout << root->data<<" ";
         preorder(root->left);
         preorder(root->right);
     }
    };
