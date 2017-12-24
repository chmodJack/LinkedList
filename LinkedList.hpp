/*************************************************************************
    > File Name       : LinkedList.hpp
    > Author          : chmodJack
    > Mail            : 158754845@qq.com 
    > GitHub          : https://github.com/chmodJack 
    > Created Time    : 2017年12月21日 星期四 11时32分01秒
    > Description     : Double direction linked list.
*************************************************************************/

#ifndef __LINKEDLIST_HPP__
#define __LINKEDLIST_HPP__

#include<stdio.h>

namespace jack
{

template<typename T>
class LinkedList
{
public:
	typedef struct _Node{struct _Node* last;struct _Node* next;T data;}Node;
public:
	LinkedList(void):m_head(NULL),m_tail(NULL),m_count(0){}
	~LinkedList(void){destroy();}
	//case flag==1:insert the node behind the pointor
	//case flag==-1:insert the node before the pointor
	//return the pointor of the new insert node
	Node* insert(const T& data,Node* position,int flag=1)
	{
		if(position)
		{
			if(flag==1)
			{
				Node* temp=new Node;
				temp->data=data;

				temp->last=position;
				temp->next=position->next;
				position->next=temp;

				if(temp->next)
					temp->next->last=temp;
				else
					m_tail=temp;

				++m_count;
				return temp;
			}
			else if(flag==-1)
			{
				Node* temp=new Node;
				temp->data=data;

				temp->last=position->last;
				temp->next=position;
				position->last=temp;

				if(temp->last)
					temp->last->next=temp;
				else
					m_head=temp;

				++m_count;
				return temp;
			}
			else
			{
				puts("Error flag.");
				return NULL;
			}
		}
		else
		{
			if(0==m_count)
			{
				Node* temp=new Node;
				temp->data=data;
				temp->next=NULL;
				temp->last=NULL;
				m_head=temp;
				m_tail=temp;
				m_count=1;
				return temp;
			}
			else
			{
				puts("Position is NULL.");
				return NULL;
			}
		}
	}
	Node* insertTail(const T& data)
	{
		return insert(data,m_tail,1);
	}
	Node* insertHead(const T& data)
	{
		return insert(data,m_head,-1);
	}
	//pop the node pointed by node pointer out of the list
	bool pop(Node* node)
	{
		if(node)
		{
			if(node->next)
				node->next->last=node->last;
			else
			{
				m_tail=node->last;
				if(m_tail)
					m_tail->next=NULL;
			}
			if(node->last)
				node->last->next=node->next;
			else
			{
				m_head=node->next;
				if(m_head)
					m_head->last=NULL;
			}

			delete node;
			--m_count;
			return true;
		}
		else
			return false;
	}
	bool popHead(void)
	{
		return pop(m_head);
	}
	bool popTail(void)
	{
		return pop(m_tail);
	}
public:
	void destroy(void)
	{
		while(popTail());
	}
	Node* getHead(void)const
	{
		return m_head;
	}
	Node* getTail(void)const
	{
		return m_tail;
	}
	unsigned int getCount(void)const
	{
		return m_count;
	}
public:
	//case flag==1:from head to tail
	//case flag==-1:from tail to head.
	//func:if return value is true,stop the loop,and return the pointer of the sure node
	Node* search(bool (*func)(Node* node),int flag=1)const
	{
		if(0==m_count)
			return NULL;
		Node* temp;
		if(1==flag)
		{
			temp=m_head;
			while(!func(temp))
			{
				if(temp==m_tail)
					return NULL;
				temp=temp->next;
			}
			return temp;
		}
		else if(-1==flag)
		{
			temp=m_tail;
			while(!func(temp))
			{
				if(temp==m_head)
					return NULL;
				temp=temp->last;
			}
			return temp;
		}
		else
		{
			puts("Error flag.");
			return NULL;
		}
	}
public:
	Node* operator()(int index)const
	{
		if(index>=0)
		{
			if(index>=m_count)
				return NULL;
			Node* temp=m_head;
			unsigned int tempIndex=0;
			while(index!=tempIndex)
			{
				temp=temp->next;
				++tempIndex;
			}
			return temp;
		}
		else
		{
			if(-index>m_count)
				return NULL;
			Node* temp=m_tail;
			int tempIndex=-1;
			while(index!=tempIndex)
			{
				temp=temp->last;
				--tempIndex;
			}
			return temp;
		}
	}
	const T& operator[](int index)const
	{
		return ((*this)(index))->data;
	}
	void operator+=(const T& data)
	{
		insertTail(data);
	}
private:
	Node* m_head;
	Node* m_tail;
	unsigned int m_count;
};

};

#endif//__LINKEDLIST_HPP__
