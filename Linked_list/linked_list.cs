 class Node
        {
        public int data;
        public Node next;
        public Node head = null;

        public void Insert(int data)
        {
            Node temp = new Node();
            temp.data = data;
            temp.next = null;
            if (head==null)
            {
                head = temp;
                return;

            }
            Node temp2 = head;
            while(temp2.next!=null)
            {
                temp2 = temp2.next;
            }
            temp2.next = temp;
        }
        void recursive_display(ref Node head)
        {
            if (head == null)
            {
                return;
            }
            Console.Write(head.data);
            recursive_display(ref head.next);
        }
        public void Display()
        {

            recursive_display(ref head);
            Console.WriteLine();
        }
        public void Delete(int data)
        {
            if (head.data ==data)
            {
                Node temp2 = head.next;
                head= temp2;
                return;
            }
            Node next_node = head;
            while (next_node.next != null &&next_node.next.data !=data )
            {
                next_node = next_node.next;
            }
            if (next_node.next !=null)
                next_node.next = next_node.next.next;
        }

        public bool Find(int data)
        {
            Node temp = head;
            while (temp.next !=null && temp.data!=data)
            {
                temp = temp.next;
            }
            if (temp.data == data)
                return true;
            else
                return false;


        }
    }
