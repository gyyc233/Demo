#pragma once


#include <iostream>
#include "common.h"
#include "AllyCenter.h"
using namespace std;

//抽象观察者是Observer，声明了发现物资或者需要求救时的呼叫的方法call()，
//具体观察者是Player，即玩家，Player实现了呼叫call()方法，
//并且还定义了取物资come()和支援队友help()的方法。

//本例定义了AllyCenter作为抽象目标，它维护了一个玩家列表playerList，并且定义了加入战队和剔除玩家的方法。
//具体目标是联盟中心控制器AllyCenterController，它实现了通知notify()方法，
//该方法将队友call的消息传达给玩家列表里的其余队友，并作出相应的响应



// 抽象观察者 Observer
class Observer
{
public:
	Observer() {}
	// 声明抽象方法
	virtual void call(INFO_TYPE infoType, AllyCenter* ac) = 0;
	string getName() {
		return name;
	}
	void setName(string iName) {
		this->name = iName;
	}
private:
	string name;
};

// 具体观察者 
class Player :public Observer
{
public:
	Player() {
		setName("none");
	}
	Player(string iName) {
		setName(iName);
	}
	// 实现
	void call(INFO_TYPE infoType, AllyCenter* ac) {
		switch (infoType) {
		case RESOURCE:
			printf("%s :我这里有物资\n", getName().c_str());
			break;
		case HELP:
			printf("%s :救救我\n", getName().c_str());
			break;
		default:
			printf("Nothing\n");
		}
		//广播
		ac->notify(infoType, getName());
	}
	// 实现具体方法
	void help() {
		printf("%s:坚持住，我来救你！\n", getName().c_str());
	}
	void come() {
		printf("%s:好的，我来取物资\n", getName().c_str());
	}
};

