class BstNode {

private:
    int data;
    BstNode* left;
    BstNode* right;
    BstNode* root = NULL;
    int count = 0;
    queue <BstNode*>q;

 private:
    BstNode * insert_node(BstNode * root, BstNode * node) {
        if (root == NULL) {
            root = node;
        }
        else if(root->data==node->data)return root;
        else if (node->data < root->data) {
            root->left = insert_node(root->left, node);
        }
        else {
            root->right = insert_node(root->right, node);
        }
        return root;
    }    /*return -1 if we in the leaf because the height of the leaf node is 0 so
    we return -1 for left and -1 for right -> max(-1,-1)+1 -> 0 so for the
    leaf nodes we return 0 as the height of that node*/
    int find_height(BstNode* node)
    {
        if (node == NULL)
            return -1;
        else return max(find_height(node->left), find_height(node->right)) + 1;

    }
    /*
    * <root><left><right>
    * base case is there is no node present else
    * 1- we print the value at the node we at
    * 2-recursive call to the left sub-tree
    * after that get finished (reach the leaf node of current left sub-tree)
    * 3-recursive call to the current right sub-tree
    */
    void bfs_preorder(BstNode* root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        bfs_preorder(root->left);
        bfs_preorder(root->right);
    }
    /* <left><root><right>
    * 1-we go left tell we hit the leaf of that sub tree
    * 2-then print the root of that sub tree
    * 3-then go right ,and then repeate go left again tell we hit a leaf print ...
    */
    void bfs_inorder(BstNode* root)
    {
        if (root == NULL)
            return;
        bfs_inorder(root->left);
        cout << root->data << " ";
        bfs_inorder(root->right);
    }
    /* <left><right><root>
    */
    void bfs_postorder(BstNode* root)
    {
        if (root == NULL)
            return;
        bfs_postorder(root->left);
        bfs_postorder(root->right);
        cout << root->data << " ";
    }
    bool recursive_search(BstNode* root, int data)
    {
        if (root == NULL) return false;
        else if (root->data == data) return true;
        else if (data > root->data)
            return recursive_search(root->right, data);
        else
            return recursive_search(root->left, data);

    }
    BstNode* get_address(BstNode* root, int data)
    {
        if (root == NULL)return root;
        else if (data == root->data)return root;
        else if (data <= root->data)
            return get_address(root->left, data);
        else
            return get_address(root->right, data);
    }
    BstNode* del(BstNode* root, int data)
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
                return root;
            }
            //one childern (and its left child)
            else if (root->right == NULL)
            {
                BstNode* node = root;
                root = root->left;
                delete node;
            }
            //one childern (and its right child)
            else if (root->left == NULL)
            {
                BstNode* node = root;
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
                BstNode* min = find_min(root->right);
                root->data = min->data;
                root->right = del(root->right, min->data);
            }
        }
        return root;
    }
    BstNode* get_succssor(BstNode* root, int data)
    {
        BstNode* current = get_address(root, data);
        //not found
        if (current == NULL) return NULL;

        //node has right sub-tree
        if (current->right != NULL)
        {
            // we can also use while loop to get the address of left most node 
            return find_min(current->right);
        }
        //node has no right_sub tree
        /*
        * we start from the root if we go left then this the first ancestor we could have
        * then if we go left again then this is the depest ancestor we get so far ,and
        so one .
        ** he idea is inorder goes <left><root><right> so we need to find the first node 
          *that our node will be in its left ,that mean it will get printed after our node
        */
        else
        {
            BstNode* ancestor = root;
            BstNode* sucssor = NULL;
            while (ancestor != current)
            {
                if (current->data < ancestor->data)
                {
                    sucssor = ancestor;
                    ancestor = ancestor->left;
                }
                else ancestor = ancestor->right;
            }
            return sucssor;
        }


    }

public:
    /* each call to the function we can either explicitly set the root pointer
    * to point to the right node ,by set the return value equal to the left or
    * right pointer ,or implicitly do that by pass the pointer by refrence so it
    * get changed automatically each time we modify it
    */
    /*
    void insert_node(BstNode*& root,BstNode*& node)
    {
        if (root == NULL) {
            root = node;
        }
        else if(root->data==node->data)return;
        else if (node->data < root->data) {
           insert_node(root->left,node);
        }
        else {
            insert_node(root->right, node);
        }
    }
    */

    void insert(int data)
    {
        BstNode* node = new BstNode();
        node->data = data;
        node->right = NULL;
        node->left = NULL;
        root = insert_node(root, node);
        count++;
    }
    bool rec_search(int data)
    {
        bool res = recursive_search(root, data);
        return res;
    }
    BstNode* find_min(BstNode* root)
    {
        if (root == NULL)return NULL;
        while (root->left != NULL) root = root->left;
        return root;
    }
    BstNode* find_max(BstNode* root)
    {
        if (root == NULL)return NULL;
        while (root->right != NULL) root = root->right;
        return root;
    }

    BstNode* get_root() { return root; }
    bool search(int data)
    {
        bool res = recursive_search(root, data);
        return res;
    }

    int size() { return count; }

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
    int tree_height()
    {
        int res = find_height(root);
        return res;
    }

    int node_height(int data)
    {
        BstNode* node = NULL;
        node = get_node_address(data);
        int height = find_height(node);
        return height;
    }
    void BFS_traverse()
    {
        if (root == NULL)
        {
            cout << "shit is real" << endl;
            return;
        }
        BstNode* temp = root;
        int res = 0;
        q.push(temp);
        while (!(q.empty()))
        {
            // cout << q.front()->data<<" ";
            // if (q.front()->left != NULL)
            //     q.push(q.front()->left);
            // if (q.front()->right != NULL)
            //     q.push(q.front()->right);
            // q.pop();
         //you can make a current pointer and avoid calling front extra two times
            BstNode* current = q.front();
            cout << current->data << " ";
            if (current->left != NULL)
                q.push(current->left);
            if (current->right != NULL)
                q.push(current->right);
            q.pop();

        }
        cout << endl;
    }
    void DFS_preorder() { bfs_preorder(root);  cout << endl; }
    void DFS_inorder() { bfs_inorder(root);  cout << endl; }
    void DFS_postorder() { bfs_postorder(root); cout << endl; }
    BstNode* get_node_address(int data)
    {
        return get_address(root, data);
    }

    int Get_succssor(int data)
    {
        int res = 0;
        res = get_succssor(root, data)->data;
        return res;
    }
    void Delete(int data)
    {
        root = del(root, data);
    }


};
