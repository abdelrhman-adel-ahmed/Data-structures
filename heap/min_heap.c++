class minheap
{
public:
    int size = 0;
    vector <int>v = { -1 };
    int l(int index) { return index * 2; }
    int r(int index) { return (index * 2) + 1; }
    int p(int index) { return index / 2; }
public:
    void correct_up(int index)
    {
        if (index == 1)return;
        if (v[index] < v[index / 2])
            swap(v[index], v[index / 2]);
        correct_up(index / 2);
    }
    void correct_down(int index)
    {
        if (index > size)return;
        int swapid = index;
        if (l(index) <= size && v[index] > v[l(index)])
            swapid = l(index);
        if (r(index) <= size && v[swapid] > v[r(index)])
            swapid = r(index);
        if (swapid != index) {
            swap(v[swapid], v[index]);
            correct_down(swapid);
        }
    }
    void insert(int data)
    {
        if (size +1 >= v.size())v.push_back(0);
        v[++size] = data;
        correct_up(size);
    }
    void delte() {
        swap(v[1], v[size--]);
        //.pop_back();
        correct_down(1);
    }
    int get_min()
    {
        int min = v[1];
        swap(v[1], v[size--]);
        v.pop_back();
        delte();
        return min;
    }
    void print()
    {
        //cout << size << endl;
        for (int i = 1; i <= size; i++)
            cout << v[i] << " ";
        cout << endl;
    }
    void heap_sort()
    {
        while (size)
        {
            delte();
        }
        for (int i = 1; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    //not complete yet
    void correct_after()
    {
        size = v.size() - 1;
        correct_down(1);
    }
   
};