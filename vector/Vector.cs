 class List<T>
    {
        T[] Arr = new T[3];
        int Position;
        public int Length { get { return Arr.Length; } }
        public void Add(T data)
        {
            if (Position == Arr.Length)
                Expand();
            Arr[Position++] = data;
        }

        public T Get(int index)
        {
            return Arr[index];
        }

        public void Display()
        {
            for(int i =0;i<Position;i++)
            {
                Console.WriteLine(Arr[i]);
            }
        }
        void Expand()
        {
            T[] temp = new T[Arr.Length * 2];
            Array.Copy(Arr, temp, Arr.Length);
            Arr = temp;
        }
    }
