#include<iostream>
#include"LinkedList.hpp"

#define TYPE std::string
#define cout std::cout
#define endl std::endl

int main(int argc,char *argv[])
{
	auto a=new LinkedList<TYPE>;
	auto b=*a;

	b+="hello";
	b+="world";
	b+="google";

	auto test=[](auto node)
	{
		if(node->data=="world")
			return true;
		else
			return false;
	};
	auto node=b.search(test);
	b.insert("HHHH",node);

	auto print=[](auto node)
	{
		cout<<node->data<<endl;
		return false;
	};
	b.search(print);

	delete a;
    return 0;
}
