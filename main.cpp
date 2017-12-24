#include<iostream>
#include"FileConverter.hpp"
int main(int argc,char *argv[])
{
	auto File=*new jack::FileConverter<char>(argv[1]);
	auto print=[](auto node){std::cout<<node->data;return false;};
	File.search(print);
	auto search_namespace=[](jack::FileConverter<char>::Node* node)
	{
		const char* str="namespace";
		//for(int i=0;i<)
	};
	return 0;
}
