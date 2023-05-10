class MyCircularQueue
{
private:
    int size = 0;
    int capacity = 0;
    int Front_Index = 0;
    int Rear_Index = -1;
    int* Ds;
public:
    MyCircularQueue(int k)
    {
        capacity = k;
        Ds = new int[capacity];
    }
    bool enQueue(int value)
    {
        if (isFull())
            return false;
        else
        {
            size++;
            Rear_Index = (Rear_Index + 1) % capacity;
            Ds[Rear_Index] = value;
        }
        return true;
    }
    bool deQueue()
    {
        if (isEmpty())
            return false;

        Front_Index = (Front_Index + 1) % capacity;
        size--;
        return true;
    }
    int Front()
    {
        if (isEmpty())
            return -1;

        return Ds[Front_Index];
    }
    int Rear()
    {
        if (isEmpty())
            return -1;

        return Ds[Rear_Index];
    }
    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == capacity;
    }
};
class MyCircularDeque {
private:
    int Front_Index;
    int Rear_Index;
    int* Ds;
    int size;
    int capacity;
public:
    MyCircularDeque(int k)
    {
        capacity = k;
        size = 0;
        Ds = new int[capacity];
    }
    bool insertFront(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            Front_Index = Rear_Index = 0;
        }
        else
        {
            Front_Index -= 1;
            if (Front_Index < 0)
                Front_Index = capacity - 1;
        }
        size++;
        Ds[Front_Index] = value;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            Rear_Index = Front_Index = 0;

        }
        else
        {
            Rear_Index = (Rear_Index + 1) % capacity;
        }
        size++;
        Ds[Rear_Index] = value;
        return true;
    }
    bool deleteFront()
    {
        if (isEmpty())
            return false;
        else
        {

            Front_Index = (Front_Index + 1) % capacity;
            size--;
            return true;
        }
    }
    bool deleteLast()
    {
        if (isEmpty())
            return false;

        Rear_Index--;
        if (Rear_Index == -1)
            Rear_Index = capacity - 1;

        size--;
        return true;
    }
    int getFront()
    {
        if (isEmpty())
            return -1;

        return Ds[Front_Index];
    }
    int getRear()
    {
        if (isEmpty())
            return -1;


        return Ds[Rear_Index];
    }
    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == capacity;
    }
};

