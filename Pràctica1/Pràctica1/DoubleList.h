#ifndef _DoubleList_H_
#define _DoubleList_H_
#include <assert.h>
template <class TYPE>

struct node
{
	TYPE data;
	node<TYPE>* next;
	node<TYPE>* previous;
};

template<class TYPE>

class DoubleList
{
private:
	node<TYPE>* start;
	node<TYPE>* end;

public:
	DoubleList()
	{
		node<TYPE>* start(NULL);
		node<TYPE>* end(NULL);
	}

	void Add(int number)  //Adds a node to the last position of the list
	{
		node<TYPE>* tmp1 = start;
		node<TYPE>* tmp2 = end; //Saving where does end pointing bcause we'll need it later and it has to be rewritten
		node<TYPE>* new_node = new node<TYPE>; //Creating the new node that has to be added to the list
		if (start != NULL && end != NULL) //Making sure list DOES exist
		{
			end = number; //Now the end of the list points the new node (it's been rewrited where it was pointing)
			new_node->next = NULL; //The next of the node now points NULL
			new_node->previous = tmp2; //The previous of the node now points where end was pointing
			while (tmp1->next != NULL) //We join the next of the node that was the last to the node which is now the last one
				tmp1 = tmp1->next;
		}
		else //In case start is NULL and so end is, it creates the new node at the beginning of the list
		{
			tmp1->next = new_node;
			tmp2->previous = new_node;
		}
	}

	bool Erase(node<TYPE>* eraseNode) //Erases the node given wherever it is (beginning, end or in the middle of the list)
	{
		if (eraseNode != NULL && start != NULL && end != NULL) //Making sure the node given isn't NULL and so aren't start & end
		{
			if (eraseNode != start && eraseNode != end) //Case where the node to erase is in the middle of the list
			{
				node<TYPE>* tmp1 = start;
				node<TYPE>* tmp2 = end;
				while (tmp1 && tmp1->next != eraseNode) //Getting to the node through next
				{
					tmp1 = tmp1->next;
				}
				if (tmp1)
				{
					tmp1->next = eraseNode->next; //Excluding the node from the "next chain"
				}
				while (tmp2 && tmp2->previous != eraseNode) //Getting to the node through previous
				{
					tmp2 = tmp2->previous;
				}
				if (tmp2)
				{
					tmp2->previous = eraseNode->previous; //Excluding the node from the "previous chain" and so from the list
				}
				else return;
			}
			else //Cases where the node is either at the beginning or at the end
			{
				if (start == eraseNode) //When the node is at the beginning
				{
					start = start->next;
				}
				else //When the node is at the end
				{
					end = end->previous;
				}
			}
			delete eraseNode; //Finally, we erase the node given
		}
		return true; //Returning the job is done
	}

	void EraseAll()
	{
		if (start != NULL && end != NULL) //Making sure we have something to erase
		{
			node<TYPE>* tmpNext1 = start;
			node<TYPE>* tmpNext2;
			node<TYPE>* tmpPrev1 = end;
			node<TYPE>* tmpPrev2;
			while (tmpNext1 != NULL) //Erasing, one by one, the next of the nodes of the list
			{
				tmpNext2 = tmpNext1;
				tmpNext1 = tmpNext1->next;
				delete tmpNext2;
			}
			while (tmpNext1 != NULL) //Erasing, one by one, the previous of the nodes of the list
			{
				tmpPrev2 = tmpPrev1;
				tmpPrev1 = tmpPrev1->previous;
				delete tmpPrev2;
			}
			delete tmpNext1; //Erasing the temporal nodes
			delete tmpPrev1;
			start = NULL; //Setting start and end to NULL as they should be at the end of this function
			end = NULL;
		}
		else{}
	}

	int Count() const //Returns the amount of nodes there are in the list
	{
		node<TYPE>* tmpNext = start;
		node<TYPE>* tmpPrev = end;
		int resultNext = 0;
		int resultPrev = 0;
		while (tmpNext != NULL)
		{
			tmpNext = tmpNext->next;
			resultNext++;
		}
		while (tmpPrev != NULL)
		{
			tempPrev = tmpPrev->previous;
			resultPrev++;
		}
		//I count both ways, to the left and to the right, and then I compare the results so there're no problems with the list
		assert(resultNext == resultPrev); //Make sure both results are equal
		return result; //Returning the obtained result
	}

};

#endif _DoubleList_H_