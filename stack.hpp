#ifndef STACK_H_
#define STACK_H_

template <typename T>
class Node {
	public:
		T data;
		Node *prevNode;

		Node(T data) {
			this->data = data;
		};
		~Node() {

		};
};

template <typename T>
class stack  
{
	private:
		Node<T> *mTopNode = nullptr;
		int size = 0;
	public:

		stack();
		~stack();
		void push(T element);
		void pop();
		T* top();
        bool empty();

};


template<typename T>
stack<T>::stack()
{
    
}

template<typename T>
stack<T>::~stack()
{
    Node<T> *temp = this->mTopNode;
    while(temp != nullptr) {
        this->mTopNode = temp->prevNode;
        delete temp;
		temp = this->mTopNode;
    }
}

template<typename T>
void stack<T>::push(T element) {
    Node<T> *newNode = new Node<T>(element);
    Node<T> *temp = this->mTopNode;
    this->mTopNode = newNode;
    this->mTopNode->prevNode = temp;
    this->size++;
}

template<typename T>
void stack<T>::pop() {
    Node<T> *temp = this->mTopNode;
    if(temp != nullptr) {
        this->mTopNode = temp->prevNode;
        delete temp;
        this->size--;
    } else {
        std::cout << "empty" << std::endl;
    }
}

template<typename T>
T* stack<T>::top() {
    if(size>0) {
        return &this->mTopNode->data;
    } else {
        return nullptr;
    }
}

template<typename T>
bool stack<T>::empty() {
    if(size>0) {
        return false;
    } else {
        return true;
    }
}
#endif // STACK_H_
