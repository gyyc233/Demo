#pragma once
#include <list>
//观察者模式经典实现
//一个对象行为的改变，其相关联的对象都会得到通知，并自动产生对应的行为。这在软件设计模式中，即是观察者模式。
//观察者模式建立了一种一对多的联动，一个对象改变时将自动通知其他对象，其他对象将作出反应。
//观察者模式中，发生改变的对象称为“观察目标”，被通知的对象称为“观察者”。一个观察目标可以有很多个观察者。

//定义对象之间的一种一对多的依赖关系，使得每当一个对象状态发生改变时，其相关依赖对象都得到通知并被自动更新。

//观察者模式又被称为发布-订阅模式（Publish-Subscribe）、模型-视图模式（Model-View）、源-监听器模式（Source-Listener）、从属者模式（Dependents）。 

// 抽象观察者
class Observer
{
public:
	// 声明响应更新方法
	virtual void update() = 0;
};

// 具体观察者
class ConcreteObserver :public Observer
{
public:
	// 实现响应更新方法
	void update() {
		// 具体操作
	}
};

// 抽象目标
class Subject
{
public:
	// 添加观察者
	void attach(Observer* obs) {
		obsList.push_back(obs);
	}
	// 移除观察者
	void detach(Observer* obs) {
		obsList.remove(obs);
	}
	// 声明通知方法
	virtual void notify() = 0;
protected:
	// 观察者列表
	std::list<Observer*>obsList;
};

// 具体目标
class ConcreteSubject :public Subject
{
public:
	// 实现通知方法
	void notify() {
		// 具体操作
		// 遍历通知观察者对象
		for (auto i = obsList.begin(); i != obsList.end(); ++i) {
			auto a = *i;
			a->update();
		}
	}
};
