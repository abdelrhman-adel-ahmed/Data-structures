//top down (memoization)
int arr[20]; //mainly it should be the same size as x
int f2(int x)
{
     if (x <= 1)return x;
    else if (arr[x] != 0)
        return arr[x];
    arr[x] = f2(x - 1) + f2(x - 2);
    return arr[x];
        
}
//buttoum up (tabulation)
int f1(int i) 
{
    int arr[12]; //mainly it should  i+1 in size
    arr[0] = 0;
    arr[1] = 1;
    for (int x = 2; x <= i; x++)
    {
        arr[x] = arr[x - 1] + arr[x - 2];
    }
    return arr[i];
}
long long ff(long long x)
{
    long long  f1 = 0;
    long long  f2 = 1;
    long long res;
    if (x <= 1)return x;
    else {
        for (long long i = 2; i <= x; i++)
        {
            res = f1 + f2;
            f1 = f2;
            f2 = res;
        }
    }
    return res;
}
