class max_heap
{
public:
    int size = 0;
    //first place in the vector is dangling ,to keep our equtions right (0 * _ =0)
    vector<int>v = { -1 };
    int p(int index) { return index >> 1; }// index/2
    int l(int index) { return index << 1; }; //index *2
    int r(int index) { return (index << 1) + 1; } //index *2 +1
public:

    bool is_empty() { return size == 0; }
    void correct_up(int index)
    {
        if (index == 1)return;

        //if the node is greater than its parent
        if (v[index] > v[index / 2])
            swap(v[index], v[index / 2]);
        correct_up(index / 2);
    }

    void correct_down(int index)
    {
        /* 1-get the left index
        *  2- check if it bigger than the parent ,if it bigger change swapid to the left
        *  3- now check the right with the left ,if it bigger then we will swap the parent with it
        *  4- we stop when there is no element bigger than the parent meaning it reach the correct place
        *  5- or the index is bigger than the size we return to previous call meaning we try to reach node
        * outside the array.
       */
       //if (index > size)return;    
        int swapid = index;

        if (l(index) <= size && v[index] < v[l(index)])
            swapid = l(index);

        if (r(index) <= size && v[swapid] < v[r(index)])
            swapid = r(index);
        if (swapid != index)
        {
            swap(v[index], v[swapid]);
            correct_down(swapid);
        }

    }
    void insert_item(int item)
    {
        //make space for out new entry ,if there is not space
        if (size + 1 >= v.size()) v.push_back(0);
        //update the size and put our new item in that index
        v[++size] = item;
        correct_up(size);
    }
    void delet()
    {
        swap(v[1], v[size--]);
        correct_down(1);
    }
    void print()
    {
        for (int i = 1; i < v.size(); i++)
            cout << v[i] << " ";
        if (v.size() == 1)cout << v[1];
        cout << "\n";
    }
    int get_max()
    {
        return v[1];
    }
    int extract_max()
    {
        int max = v[1];
        delet();
        return max;
    }
    void heap_sort()
    {
        while (size)
        {
            delet();
        }
        for (int i = 1; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    //take a vector and max_heapify it complexity is o(n)
     void max_heapify(vector<int>& a, int index)
    {
        int l = index * 2;
        int r = index * 2 + 1;
        int length = a.size() - 1;
        int swapid = index;
        if (index == 0)return;
         
        if (l <= length && a[l] > a[index])
            swapid = l;
        if (r <= length && a[r] > a[swapid])
            swapid = r;
        if (index != swapid) {
            swap(a[index], a[swapid]);
            max_heapify(a, swapid);
        }
        max_heapify(a, swapid-1);
    }

};

