class avl
{
public:
    avl* right;
    avl* left;
    avl* root = NULL;
    int data;
    int height;
    int factor;
    
    //insert and update height each time 
   void insert(avl*& root,avl*&node)
    {
        if (root == NULL)root=node;
        else if (node->data > root->data)insert(root->right, node);
        else if (node->data < root->data)insert(root->left, node);
        root->height = find_height(root);
        root->factor = balance_factor(root);
        balance(root);
       // return root;

    }
    int find_height(avl* node)
    {
       if (node == NULL)
           return -1;
       else return max(find_height(node->left), find_height(node->right)) + 1;
   
    }
   // void update_Height()
   // {
   //   height = max((left != nullptr ? left->height : 0), (right != nullptr ? right->height : 0)) + 1;
   // }

    //find balance factor (right_sub_tree height - left_sub_tree height)
    int balance_factor(avl*node)
    {
        return (find_height(node->right) - find_height(node->left));
    }
  void rotate_left(avl*& node)
    {
        avl* temp=node;
        avl* temp1 = temp->left;
        temp->left = temp1->right;
        temp1->right = temp;
       // temp->factor = balance_factor(temp);
       // temp1->factor = balance_factor(temp1);
       //temp->update_Height();
       //temp1->update_Height();
        node = temp1;
    }
   void rotate_right(avl*& node)
    {
        avl* temp = node;
        avl* temp1 = temp->left;
        temp->left = temp1->right;
        temp1->right = temp;
        //temp->factor = balance_factor(temp);
        //temp1->factor = balance_factor(temp1);
       // temp->update_Height();
       // temp1->update_Height();
        node = temp1;
    }
    void balance(avl*& node)
    {
        //int bal_fac = balance_factor(node);
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
        //node->height = find_height(node);
        insert(root, node);
    }

};

int main()
{
   
    avl av;
    av.insert(10);
    av.insert(20);
    //cout << av.find_height(av.root)<<endl;
    av.insert(5);
    av.insert(4);   
    //av.insert(25);
    //av.insert(40);
    av.insert(3);
    av.insert(2);
    //cout << av.balance_factor(av.root->left) << endl;
     av.BFS(av.root);
     cout << av.find_height(av.root) << endl;
    // cout <<av.balance_factor(av.root->left->left->left);
     //cout << av.find_height(av.root->right)<<endl;
    //av.bdf(av.root);
    //cout << av.root->right->data;
}
