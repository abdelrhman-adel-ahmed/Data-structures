class Node<T>
        {
        public T data;
        public Node<T> next;
        public Node<T> head = null;

        public void Insert(T data)
        {
            Node<T> temp = new Node<T>();
            temp.data = data;
            temp.next = null;
            if (head==null)
            {
                head = temp;
                return;

            }
            Node<T> temp2 = head;
            while(temp2.next!=null)
            {
                temp2 = temp2.next;
            }
            temp2.next = temp;
        }
        void recursive_display(ref Node<T> head)
        {
            if (head == null)
            {
                return;
            }
            Console.WriteLine(head.data);
            recursive_display(ref head.next);
        }
        public void Display()
        {

            recursive_display(ref head);
        }
        public void Delete(T data)
        {
            if (head.data.Equals(data))
            {
                Node<T> temp2 = head.next;
                head= temp2;
                return;
            }
            Node<T> next_node = head;
            while (next_node.next != null && !EqualityComparer<T>.Default.Equals(next_node.next.data ,data) )
            {
                next_node = next_node.next;
            }
            if (next_node.next !=null)
                next_node.next = next_node.next.next;
        }

        public bool Find(T data)
        {
            Node<T> temp = head;
            while (temp.next !=null && !EqualityComparer<T>.Default.Equals(temp.data,data))
            {
                temp = temp.next;
            }
            if (EqualityComparer<T>.Default.Equals(temp.data ,data))
                return true;
            else
                return false;


        }
    }
