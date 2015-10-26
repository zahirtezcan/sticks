#include <iostream>
#include <random>

std::random_device RandomDevice;
std::default_random_engine RandomEngine(RandomDevice());
std::uniform_int_distribution<int> LengthDistribution(0, 9);

struct Node 
{
	char Value;
	Node* Next;
};

struct LoopyList
{
	Node* Head;
	Node* Loop;
};

LoopyList Generate(int n, int l)
{
	if (n == 0) {
		return { nullptr, nullptr };
	}

	char value = 'a';

	Node* head = new Node { value , nullptr };
	Node* loopend = nullptr;
	Node* current = head;
	if (l == 0) loopend = current;

	--n;
	++value;

	while (n) {

		current->Next = new Node { value, nullptr };
		current = current->Next;
		value = (value + 1) % ('z' - 'a') + 'a';
		--n;
		--l;
		if (l == 0) loopend = current;	
	}

	current->Next = loopend;

	if (loopend) {
		loopend->Value = std::toupper(loopend->Value);
	}

	return { head, loopend };
}

void Print(Node* head, int n, int l)
{
	int k = n;
	while (n && head) {
		std::cout << head->Value;
		--n;
		head = head->Next;
	}
	std::cout << std::endl;
	
	for (int i = 0; i < k; ++i) {
		std::cout << (i % 10);
	}

	if (k <= 0) std::cout << "<null>";
	std::cout << std::endl;
	
	for (int i = 0; i < k; ++i) {
		if (i != l) std::cout << "-";
		else std::cout << "^";
	}
	std::cout << std::endl;

}

LoopyList GenerateRandom()
{
	int n = LengthDistribution(RandomEngine);
	int l = std::uniform_int_distribution<int>(-n, n)(RandomEngine);

	auto result = Generate(n, l);

	Print(result.Head, n, l);

	return result;
}


bool HasLoop(Node* head)
{
	if (!head || !head->Next) return false;

	Node* dbl = head;
	Node* sng = head;
	
	while (dbl && dbl->Next) {
		dbl = dbl->Next;
		if (dbl == sng) return true;

		dbl = dbl->Next;
		if (dbl == sng) return true;

		sng = sng->Next;
	}
	
	
	return false;
}

Node* GetLoopNode(Node *head)
{
	if (!head || !head->Next) return nullptr;

	Node* dbl = head;
	Node* sng = head;
	int counter = 0;
	
	while (dbl && dbl->Next) {
		dbl = dbl->Next;
		++counter;	
		if (dbl == sng) break;

		dbl = dbl->Next;
		++counter;	
		if (dbl == sng) break;

		sng = sng->Next;
	}

	if (!dbl || !dbl->Next) return nullptr;

	if (counter % 2 == 0) {
		sng = sng->Next;
	}

	sng = sng->Next;
	
	while (head != sng) {
		head = head->Next;
		sng = sng->Next;
	}	
	
	return head;
}

template<typename T>
void DisplayResult(const T& result, const T& expected) {
	std::cout << "\33[7";
	if (result != expected) {
		std::cout << ";31";
	}
	std::cout << "m";
	std::cout << "Result: " << result;
	std::cout << "  Expected: " << expected;
	std::cout << "\33[0m";
	std::cout << std::endl;
}

void TestLoop()
{
	LoopyList ll = GenerateRandom();
	bool hasLoop = HasLoop(ll.Head);
	bool expected = ll.Loop != nullptr;
	DisplayResult(hasLoop, expected);
}

void TestLoopNode()
{
	LoopyList ll = GenerateRandom();
	Node* loopNode = GetLoopNode(ll.Head);
	DisplayResult(loopNode, ll.Loop);
}

int main()
{
	for (int i = 0; i < 100; ++i) {
		TestLoopNode();
	}
}

