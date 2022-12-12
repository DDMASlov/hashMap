#include "hashMap.hpp"
template <typename V>
class HashNode {
public:
    V value;
    string key;
    int fr;
    HashNode()
    {
    this->fr = 0;
    }
};
template <typename V>
class HashMap
{
public:
    HashNode<V>* arr;
    int capacity;
    int size;
    class iterator
    {
	HashNode<V> *n;
	HashMap<V> *m;
	public:
	    iterator(HashNode<V> *n,HashMap<V> *m)
	    {
		this-> n = n;
		this->m = m;
    	    }
    	    iterator(const iterator &b)
    	    {
		this->n = b.n;
		this->m = b.m;
    	    }
    	    const V &operator*()
    	    {
		return n->value;
    	    }
    	    const string &operator-()
    	    {
		return n->key;
    	    }
    	    void operator++(int)
    	    {
		if(n == m->end().n)
		    n = NULL;
		else
		    n = m->findfirst(n);
    	    }
    	    bool operator!=(const iterator &r)
	    {
		return n != r.n;
	    }
    	    bool operator==(const iterator &r)
	    {
    		return n == r.n;
	    }
    	    bool notnul()
    	    {
		return n != NULL;
    	    }
    };
    HashNode<V>* findfirst(HashNode<V>* n)
    {
	int cntrl = 0;
	int adr = 0;
	for(int i = 0;i < capacity;i++)
	{
	    if(cntrl == 1)
	    {
		if(arr[i].fr == 1)
		{
		    adr = i;
		    i = capacity;
		}
    	    }
    	    if(&arr[i] == n)
    	    {
		cntrl = 1;
	    }

	}
	return  &arr[adr];
    }
    iterator begin()
    {
	int adr = 0;
	int cntrl = 0;
	for(int i = 0;i < capacity;i++)
	{
    	    if(arr[i].fr == 1)
    	    {
		adr = i;
		i = capacity;
		cntrl = 1;
    	    }
	}
	if(cntrl == 1)
	    return iterator(&arr[adr],this);
	else
	    return iterator(NULL,this);
    }
    iterator end()
    {
	int adr = 0;
	for(int i = capacity - 1;i > 0;i--)
	{
	    if(arr[i].fr == 1)
    	    {
		adr = i;
		i = 0;
    	    }
	}
	return iterator(&arr[adr],this);
    }
    HashMap()
    {
	capacity = 20;
	size = 0;
	arr = new HashNode<V>[capacity];
	for (int i = 0; i < capacity; i++)
        arr[i].fr = 0;
    }
    HashMap(int sizeofmap)
    {
	capacity = sizeofmap;
	size = 0;
	arr = new HashNode<V>[capacity];
	for (int i = 0; i < capacity; i++)
    	    arr[i].fr = 0;
    }
    ~HashMap()
    {
	delete[] arr;
    }
    int hashCode(string key)
    {
	int h = 0;
	int k = 2;
	for (char c : key)
	{
	    int x = (int)(c - ' ' + 1);
	    h = (h + k * x) % capacity;
	    k = k * k;
	}
	return h;
    }
    void insertNode(string key, V value)
    {
	int hashIndex = hashCode(key);
	while ((arr[hashIndex].fr == 1) && (arr[hashIndex].key != key)) 
	{
	    hashIndex++;
	    hashIndex %= capacity;
	}
	if ((arr[hashIndex].fr == 0) || (arr[hashIndex].fr == -1))
	{
	    size++;
	    arr[hashIndex].key = key;
	    arr[hashIndex].value = value;
	    arr[hashIndex].fr = 1;
	}
	return;
    }
    HashNode<V>* getarr()
    {
	return arr;
    }
    void deleteNode(string key)
    {
	int hashIndex = hashCode(key);
	for(int i =0;i<capacity;i++)
	{
    	    if (arr[hashIndex].key == key)
    	    {
		arr[hashIndex].fr = -1;
		size--;
		return;
    	    }
    	    hashIndex++;
    	    hashIndex %= capacity;
	}
	return;
    }
    void get(string key)
    {
	int hashIndex = hashCode(key);
	int counter = 0;
	while (arr[hashIndex].fr == 1)
	{
	    if (counter++ > capacity)
		return;
    	    if (arr[hashIndex].key == key)
    	    {
		cout << "Value:" << arr[hashIndex].value << endl;
		return;
    	    }
    	    hashIndex++;
    	    hashIndex %= capacity;
	}
	cout << "Key is not found!" << endl;
	return;
    }
    int sizeofMap()
    {
	return size;
    }
    int capacityofMap()
    {
	return capacity;
    }
    bool isEmpty()
    {
	return size == 0;
    }
    void display()
    {
        for(auto it = begin();it.notnul();it++)
        {
            cout << "key = " << -it << " value = " << *it << endl;
        }
	return;
    }
    double fullness()
    {
	return double(size) / capacity;
    }
    void renew(string key, V value)
    {
	if (fullness() > 0.7)
	{
	    int new_capacity = 2 * capacity;
	    HashNode<V>* zamena = new HashNode<V>[capacity];
	    int zamena_cap = capacity;
	    for (int i = 0; i < capacity; i++)
	    {
		if (arr[i].fr == 1)
		{
		    zamena[i].key = arr[i].key;
		    zamena[i].value = arr[i].value;
		    zamena[i].fr = 1;
		}
		else
		{
		    zamena[i].fr = 0;
		}
    	    }
	    delete[] arr;
	    arr = new HashNode<V>[new_capacity];
	    capacity = new_capacity;
	    cout << endl << "------------" << endl << "Changed capacity: " << capacity << endl << "--------" << endl;
	    size = 0;
	    for(int i = 0;i < capacity;i++)
    	    {
		arr[i].fr = 0;
    	    }
	    for (int i = 0; i < zamena_cap; i++)
    	    {
		if (zamena[i].fr == 1)
		{
		    insertNode(zamena[i].key, zamena[i].value);
		}
    	    }
    	    delete[] zamena;
	}
	insertNode(key, value);
    }
    void inform()
    {
	cout << endl << "----------" << endl;
	cout << "Add pair(key,value) - 1" << endl;
	cout << "Find value by it's key- 2" << endl;
	cout << "Delete pair(key,value) - 3" << endl;
	cout << "Get the number of pairs(key,value) - 4" << endl;
	cout << "Display the hash table - 5" << endl;
	cout << "Get commands - 6" << endl;
	cout << "Get the capacity - 7" << endl;
	cout << "Get fullness - 8" << endl;
	cout << "Quit - 0" << endl;
	cout << "----------" << endl;
    }
};