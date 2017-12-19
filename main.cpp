#include<iostream>
#include"LinkedList.hpp"

#define TYPE std::string
#define cout std::cout
#define endl std::endl

bool test(LinkedList<TYPE>::Node* node)
{
	if(node->data=="Hello")
		return true;
	return false;
}
bool print(LinkedList<TYPE>::Node* node)
{
	cout<<node->data<<endl;
	return false;
}

int main(int argc,char *argv[])
{
	LinkedList<TYPE>* a=new LinkedList<TYPE>;
	LinkedList<TYPE>& b=*a;

	b+="Hello";
	b+="world";
	b+="fuck";

	b.insert("Haha",b.search(test));

	b.search(print);

	delete a;
    return 0;
}
