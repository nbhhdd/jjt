#pragma once//防止头文件重复编译，重复包含
#include<iostream>
#include"Speaker.h"
#include<map>
#include<vector>
using namespace std;
//设计演讲比赛管理类
//1.创建基本步骤。
//2.实现基本功能，成员函数实现(在头文件声明，在源文件实现)
	//功能一.菜单功能
class SpeechManager
{
	//构造函数和析构函数的创建
	public:
		
		//无参构造器
		SpeechManager();

		//菜单功能
		void show_Meun();
		//初始化，保证每次询问清除以前的数据
		void initSpeech();
		//创建选手
		void createSpeaker();
		//退出功能
		void exitSystem();
		//创建比赛流程功能,控制整个流程。
		void startSpeech();

		//抽签功能
		void speechDraw();
		//演讲比赛功能
		// 比赛流程分析抽签-开始演讲比赛-显示2第一轮比赛结果-抽签-开始演讲比赛-显示前三名结果-保存分数
		//析构函数
		//比赛功能
		void speechContest();

		//展示比赛结果
		void showScore();
		//保存比赛结果
		void saveRecord();
		//查看记录分数
		void loadRecord();

		//显示往届得分
		void showRecord();

		//清空记录功能实现
		void clearRecord();
		~SpeechManager();
		//成员属性
		//比赛选手容器
		vector<int> v1;
		//第一轮晋级的选手
		vector<int> v2;
		//胜利前三名
		vector<int> win;
		//存放编号以及对应的具体选手容器
		map<int, SpeaKer> m_speaker;
		//记录比赛轮次
		int m_index;
		//文件为空的标致
		bool fileIsEmpty;
		//往届记录
		map<int, vector<string>> m_Record;
};
