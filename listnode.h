#ifndef LISTNODE
#define LISTNODE

class ListNode {
private:
	std::string value;
	ListNode *next;
public:
	ListNode(const std::string& value);
	const std::string& getValue() const;
	ListNode* getNext() const;
	friend class LinkedList;
};

#endif