#include<iostream>

using namespace std;

class A
{
public:
	void virtual vFunc() {
		cout << "A.vFunc" << endl;
	}
	void nvFunc()
	{
		cout << "A.nvFunc" << endl;
	}
};

class B :public A
{
public:
	void virtual vFunc() {
		cout << "B.vFunc" << endl;
	}
	void nvFunc()
	{
		cout << "B.nvFunc" << endl;
	}
};

void getP(A* a)
{
	a->vFunc();
}

void getQ(A& a)
{
	a.vFunc();
}

int tmain()
{
	B* pB = new B();
	A* pA = pB;
	pB->vFunc();//    B
	pA->vFunc(); //   B
	pB->nvFunc();  // B
	pA->nvFunc();  // A
	(*pA).vFunc();   // A//B 会去寻找虚函数表
	(*pA).nvFunc(); // B//A 寻址就能寻到pA那么大 所以不能是B
	(*pB).vFunc();  //B
	(*pB).nvFunc(); // B
	getP(pA);       // B
	getQ(*pA);     // B
	return 0;



}

