#include "class.cpp"
int main()
{
    int type;
    cout << "Select type of value" << endl;
    cout << "int - 1" << endl;
    cout << "double - 2" << endl;
    cout << "string - 3" << endl;
    cout << "Enter type: ";
    cin >> type;
    if (type == 1)
    {
	int fsize;
	cout << "Enter initial size of hash table:";
	cin >> fsize;
	HashMap<int> h(fsize);
	string filename;
	cout << "Enter filename:";
	cin >> filename;
	ifstream fin(filename);
	if (!fin.is_open())
	{
	    cout << "Can't open the file!" << endl;
	    fin.close();
	    return 1;
	}
	string key;
	int value;
	while (fin >> key >> value)
	{
	    h.renew(key, value);
	}
	fin.close();
	h.inform();
	int cntrl = 1;
	while (cntrl != 0)
	{
	    cout << "Enter the command:";
	    cin >> cntrl;
	    if (cntrl == 1)
	    {
		cout << "Enter key:";
		cin >> key;
		cout << "Enter value:";
		cin >> value;
		h.renew(key, value);
    	    }
    	    if (cntrl == 2)
    	    {
		cout << "Enter key:";
		cin >> key;
		h.get(key);
    	    }
    	    if (cntrl == 3)
    	    {
		cout << "Enter key:";
		cin >> key;
		h.deleteNode(key);
    	    }
    	    if (cntrl == 4)
    	    {
		cout << "size: " << h.sizeofMap() << endl;
    	    }
    	    if (cntrl == 5)
    	    {
		h.display();
    	    }
    	    if (cntrl == 6)
    	    {
		h.inform();
    	    }
    	    if (cntrl == 7)
    	    {
		cout << "Capacity: " << h.capacityofMap() << endl;
    	    }
    	    if (cntrl == 8)
    	    {
		cout << "Fullness: " << h.fullness() << endl;
    	    }
    	    if ((cntrl > 8) || (cntrl < 0))
    	    {
		cout << "Wrong command!" << endl;
    	    }
	}
	return 0;
    }
    else
    {
	if (type == 2)
	{
    	    int fsize;
    	    cout << "Enter initial size of hash table:";
    	    cin >> fsize;
    	    HashMap<double> h(fsize);
    	    string filename;
    	    cout << "Enter filename:";
    	    cin >> filename;
    	    ifstream fin(filename);
    	    if (!fin.is_open())
    	    {
		cout << "Can't open the file!" << endl;
		fin.close();
		return 1;
    	    }
    	    string key;
    	    double value;
    	    while (fin >> key >> value)
    	    {
		h.renew(key, value);
    	    }
    	    fin.close();
    	    h.inform();
    	    int cntrl = 1;
    	    while (cntrl != 0)
    	    {
		cout << "Enter the command:";
		cin >> cntrl;
		if (cntrl == 1)
		{
		    cout << "Enter key:";
		    cin >> key;
		    cout << "Enter value:";
		    cin >> value;
		    h.renew(key, value);
		}
		if (cntrl == 2)
		{
		    cout << "Enter key:";
		    cin >> key;
		    h.get(key);
		}
		if (cntrl == 3)
		{
		    cout << "Enter key:";
		    cin >> key;
		    h.deleteNode(key);
		}
		if (cntrl == 4)
		{
		    cout << "size: " << h.sizeofMap() << endl;
		}
		if (cntrl == 5)
		{
		    h.display();
		}
		if (cntrl == 6)
		{
		    h.inform();
		}
		if (cntrl == 7)
		{
		    cout << "Capacity: " << h.capacityofMap() << endl;
		}
		if (cntrl == 8)
		{
		    cout << "Fullness: " << h.fullness() << endl;
		}
		if ((cntrl > 8) || (cntrl < 0))
		{
		    cout << "Wrong command!" << endl;
		}
    	    }
    	    return 0;
	}
	else
	{
    	    if (type == 3)
    	    {
		int fsize;
		cout << "Enter initial size of hash table:";
		cin >> fsize;
		HashMap<string> h(fsize);
		string filename;
		cout << "Enter filename:";
		cin >> filename;
		ifstream fin(filename);
		if (!fin.is_open())
		{
		    cout << "Can't open the file!" << endl;
		    fin.close();
		    return 1;
		}
		string key;
		string value;
		while (fin >> key >> value)
		{
		    h.renew(key, value);
		}
		fin.close();
		h.inform();
		int cntrl = 1;
		while (cntrl != 0)
		{
		    cout << "Enter the command:";
		    cin >> cntrl;
		    if (cntrl == 1)
		    {
			cout << "Enter key:";
			cin.ignore();
			getline(cin,key);
			cout << "Enter value:";
			getline(cin,value);
			h.renew(key, value);
		    }
		    if (cntrl == 2)
		    {
			cout << "Enter key:";
			cin >> key;
			h.get(key);
		    }
		    if (cntrl == 3)
		    {
			cout << "Enter key:";
			cin >> key;
			h.deleteNode(key);
		    }
		    if (cntrl == 4)
		    {
			cout << "size: " << h.sizeofMap() << endl;
		    }
		    if (cntrl == 5)
		    {
			h.display();
		    }
		    if (cntrl == 6)
		    {
			h.inform();
		    }
		    if (cntrl == 7)
		    {
			cout << "Capacity: " << h.capacityofMap() << endl;
		    }
		    if (cntrl == 8)
		    {
			cout << "Fullness: " << h.fullness() << endl;
		    }
		    if ((cntrl > 8) || (cntrl < 0))
		    {
			cout << "Wrong command!" << endl;
		    }
	    }
	    return 0;
    	    }
    	    else
    	    {
		cout << "Wrong command!" << endl;
		return 1;
    	    }
	}
    }
}