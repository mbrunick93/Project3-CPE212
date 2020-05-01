/// IMPLEMENT THE FOLLOWING FUNCTIONS

template<typename Type>
List<Type>::List()
{
    /// initialize the nodes correctly
    _firstNode = NULL;
    _lastNode = NULL;
    _count = 0;
    _iteratorNode = _firstNode;

}

template<typename Type>
List<Type>::~List()
{
    /// delete all data within the list, be sure to account for memory leaks.
    
    if(_firstNode == NULL){
        return;
    }

    
    while (_count != 0 )

        {    
            _iteratorNode = _firstNode;
            _firstNode = _firstNode->nextItem;
            delete _iteratorNode;
            _count--;
    }
        
    

}

template<typename Type>
void List<Type>::AppendItem(const Type &data)
{
    
    Node<Type>  *node = new Node<Type>(data);
    if(_firstNode == NULL){
        _firstNode = node;
        

}
   if(_lastNode != NULL){
       _lastNode->nextItem = node;
      
   }
        _lastNode = node;
        
        _count++;


}

template<typename Type>
bool List<Type>::DeleteItem(const Type &data)
{
   Node <Type> *tmp;
   Node <Type> *prev;
   tmp = _firstNode;
   ResetIterator();
   while(!AtEnd()){
      
        if(_firstNode ->localData == data){
            prev = _firstNode;
            _firstNode = tmp->nextItem;
            prev->nextItem = tmp->nextItem;
            _count--;
            return true;
        }   

        while(&data != IterateItems() && tmp->nextItem != NULL){
            prev = tmp;
            tmp = tmp->nextItem;
        }
        prev->nextItem = tmp->nextItem;
        _count--;
        return true;
   }
    

}
template<typename Type>
unsigned int List<Type>::Count() const
{
    return _count;
}

template<typename Type>
Type& List<Type>::Front()
{
    return &_firstNode->localData;
}

template<typename Type>
Type List<Type>::Front() const
{
    return _firstNode->localData;
}

template<typename Type>
Type& List<Type>::Back()
{
    /// returns a reference to the data in the back of the list.
    return &_lastNode->localData;
}

template<typename Type>
Type List<Type>::Back() const
{
    /// returns a const copy to the data in the back of the list
    return _lastNode->localData;
}

template<typename Type>
Type* List<Type>::IterateItems() const
{

    
    
    Type *temp;
    temp = &_iteratorNode->localData;
    _iteratorNode = _iteratorNode->nextItem;
    return temp;
    /// provides a pointer to the current item at the _iterator pointer.
    /// moves the iterator pointer to the next item.

    
}

template<typename Type>
bool List<Type>::AtEnd() const
{
    /// returns if your iterator pointer is at the end of the list
    if( _iteratorNode == NULL){
        return true;
    }
    else {
        return false;
    }
}

template<typename Type>
void List<Type>::ResetIterator() const
{
    /// resets your iterator pointer to the beginning.
    _iteratorNode = _firstNode;
}
