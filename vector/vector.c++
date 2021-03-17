-------------------------------------------------------------------------------------------
//1-first initiate the vector with capacity of 2 
//2- when push an element we check if the size reach the capacity 
//3- if ,go to the allocate fucntion and allocate more memory 
//4- instead of copying all data from old array to new array we move 

// how move work (move fucntion just cast the value to rvalue) then when we go to the copy 
//constructor via the assigment function prameter that copy what it get it will ditermine 
//which copy constrcutor to call depende on what value type it gets its rvalue or lvalue 
//when we allocate new vector space we cast to rvalue using move fucntion that return rvalue
//so we always call the move constructor .
//you can cast your self (vector &&)v1 == move(v1) move fucntino is fucntino that return 
//rvalue refrence and cast the prameter that it get
move(string &&s){
return (string &&)s;
}

//5-then take that moved array and assign it to our original array
//6- we do that extra step because we change the capacity

// * when calling copy constructor ->
//1- perfrom deep copy

// *when calling the assigmnet operator 
//1- make implicit copy by passing the vector by value 
//2-then swap the old values into the new vector.

//* when calling the move constructor 
//1- it move istead of copying */
------------------------------------------------------------------------------------------
template<class T>
class Vector
{

public:
	Vector()
	{
		allocate(2);
	}
	Vector(const Vector& s)//copy constructor
	{
		m_capacity = s.m_capacity;
		m_size = s.m_size;
		m_data = new T[m_capacity];
		for (size_t i = 0; i < m_capacity; i++)
			m_data[i] = s.m_data[i];
	}
	Vector(Vector&& s) //move constructor
	{
		m_capacity = s.m_capacity;
		m_size = s.m_size;
		m_data = s.m_data;
		s.m_data = nullptr;
		s.m_capacity = 0;
		s.m_size = 0;
	}
	Vector& operator=(Vector s)//assigment operator
	{
		
		Swap(*this, s);
		return *this;
	}

	void push_back(const T& value)
	{
		if (m_size >= m_capacity) //if we reach the max of the vector
			allocate(m_capacity + m_capacity /2);

		m_data[m_size] = value; 
		m_size++;
	}
	void push_back(T&& value)
	{
		if (m_size >= m_capacity) //if we reach the max of the vector
			allocate(m_capacity + m_capacity / 2);

		m_data[m_size] = move(value);
		m_size++;
	}
	size_t size() const { return m_size; }
	size_t capacity()const { return m_capacity; }
	const T& operator[] (size_t index)const
	{
		if (index >= m_size) { __debugbreak(); }

		return m_data[index];
	}

	T& operator[](size_t index)
	{
		if (index >= m_size) { __debugbreak(); }

		return m_data[index];
	}

	void display()const
	{
		for (size_t i = 0; i <m_size; i++)
		{
			cout << m_data[i];
		}
		cout << "\n";
	}
	void insert(int index,const T &value)
	{
		push_back(1);
		for (int i =m_size-1; i > index; i--)
		{
			m_data[i] = m_data[i - 1];
		}
		m_data[index] = value;
	}
private:
	void allocate(size_t new_capacity)
	{
		//1- allocate new block
		//2-copy all the data from old block to new block
		//3-delete old block

		// if we shrink the vector(down size the vector)
		if (new_capacity < m_size)
			m_size = new_capacity;

		T* new_block = new T[new_capacity];
		//we dont use memcopy bec for complex types we may need to call the copy constructor and memcopy
		//dont do deep copy or call the copy constructor

		for (size_t i = 0; i < m_size;i++)
			new_block[i] = move(m_data[i]);

		delete[]m_data;
		m_data = new_block;
		m_capacity = new_capacity;
	}

	 void Swap(Vector& first, Vector& second)
	{
		swap(first.m_capacity, second.m_capacity);
		swap(first.m_size, second.m_size);
		swap(first.m_data, second.m_data);
	}
	

private:
	T* m_data=nullptr;
	size_t m_size = 0;
	size_t m_capacity = 0;


};
