// 18观察者模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Observer.h"
#include "AllyCenter.h"


int main()
{
	//=================================================================================
	////观察者典型实现

	////观察目标
	//Subject* sub = new ConcreteSubject();
	////观察者
	//Observer* obs = new ConcreteObserver();
	////往观察目标中添加观察者
	//sub->attach(obs);
	////观察目标发出通知
	//sub->notify();
	//return 0;
	//====================================================================================



	//和平精英这款游戏吗？四人组队绝地求生，当一个队友发现物资时，可以发消息“我这里有物资”，
	//其余三个队友听到后可以去取物资；
	//当一个队友遇到危险时，也可以发消息“救救我”，其余三个队友得到消息后便立马赶去营救。
	//本例Jungle将用观察者模式来模拟这个过程。

	// 创建一个战队
	AllyCenterController* controller = new AllyCenterController();

	// 创建4个玩家，并加入战队
	Player* Jungle = new Player("Jungle");
	Player* Single = new Player("Single");
	Player* Jianmengtu = new Player("贱萌兔");
	Player* SillyDog = new Player("傻子狗");
	controller->join(Jungle);
	controller->join(Single);
	controller->join(Jianmengtu);
	controller->join(SillyDog);

	printf("\n\n");

	// Jungle发现物资，呼叫队友
	Jungle->call(RESOURCE, controller);

	printf("\n\n");

	// 傻子狗遇到危险，求救队友
	SillyDog->call(HELP, controller);

	printf("\n\n");
	system("pause");
	return 0;
}

//观察者模式实现了稳定的消息更新和传递的机制，通过引入抽象层可以扩展不同的具体观察者角色；
//支持广播通信，所有已注册的观察者（添加到目标列表中的对象）都会得到消息更新的通知，简化了一对多设计的难度；
//符合开闭原则，增加新的观察者无需修改已有代码，在具体观察者与观察目标之间不存在关联关系的情况下增加新的观察目标也很方便。

