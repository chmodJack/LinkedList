/*************************************************************************
    > File Name       : FileConverter.hpp
    > Author          : chmodJack
    > Mail            : 158754845@qq.com 
    > GitHub          : https://github.com/chmodJack 
    > Created Time    : 2017年12月21日 星期四 15时12分15秒
    > Description     : 
*************************************************************************/
#ifndef __FILECONVERTER_HPP__
#define __FILECONVERTER_HPP__

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#include"LinkedList.hpp"
namespace jack
{

template<typename T>
class FileConverter:virtual public LinkedList<T>
{
public:
	FileConverter(const char* file,unsigned int buffer_size=32*1024*1024)
	{
		auto buffer=new char[buffer_size];
		auto fd=open(file,O_RDONLY);
		if(-1==fd){perror("open");exit(-1);}

		auto count=read(fd,buffer,buffer_size);
		if(-1==count){perror("read");exit(-1);}
		if(-1==close(fd)){perror("close");exit(-1);}
		for(int i=0;i<count;i++)
			(*this)+=buffer[i];
		delete[] buffer;
	}
	~FileConverter(void)
	{
	}
private:
};

};
#endif//__FILECONVERTER_HPP__
