//多文件结构调用头文件
#include"speechManager.h"
#include"speaker.h"
//快捷调用SpeechManager中的函数或者方法
SpeechManager::SpeechManager()
{
	//初始
	this->initSpeech();
	//创建选手
	this->createSpeaker();
	//加载往届记录
	this->loadRecord();
}
//在多功能多类里面进行如果不声明该函数是那个里面的容易出问题、
//这里实现SpeechManager类里面的show_Meun菜单功能。
void SpeechManager::show_Meun()
{
	cout << "**********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛  *************" << endl;
	cout << "*************  1.开始演讲比赛    *************" << endl;
	cout << "*************  2.查看往届记录    *************" << endl;
	cout << "*************  3.清空比赛记录    *************" << endl;
	cout << "*************  4.退出比赛程序    *************" << endl;
	cout << "**********************************************" << endl;
	cout << endl;

}


//退出功能
void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用";
	system("pause");
	exit(0);
	//exit(0)表示程序正常退出；除了0之外，其他参数均代表程序异常退出，如：exit(1),exit(-1)。
}
//初始化

void SpeechManager::initSpeech()
{
	//保证容器为空
	this->v1.clear();
	this->v2.clear();
	this->win.clear();
	this->m_speaker.clear();
	this->m_index = 1;
	//初始化记录容器
	this->m_Record.clear();
}
//创建选手
void SpeechManager::createSpeaker()
{
	//一共12个人
	string nameseed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameseed.size(); i++)
	{
		string name = "选手";
		name += nameseed[i];
		SpeaKer sp;
		sp.m_name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0;
		}
		//存编号
		this->v1.push_back(i + 10001);
		this->m_speaker.insert(make_pair(i + 10001, sp));
	}
}
void SpeechManager::startSpeech()
{

	//第一轮开始比赛
	while (this->m_index <= 2)
	{
		this->speechDraw();
		this->speechContest();
		this->showScore();
		this->m_index++;
	}
	this->saveRecord();
	//在每次比赛完以后要重置比赛容器，
	//初始化
	this->initSpeech();
	//创建选手
	this->createSpeaker();
	//加载往届记录
	this->loadRecord();
	//初始记录容器

	cout << "本届比赛完毕!" << endl;
	system("pause");
	system("cls");
}
	//2.比赛

	//3.显示晋级结果

	//第二轮比赛


	//1.抽签

	void SpeechManager::speechDraw()  
	{
		//第一轮比赛
		cout << "第" << this->m_index << "轮比赛选手正在抽签" << endl;
		cout << "--------------------------------------" << endl;
		cout << "抽签后演讲顺序如下：";
		//1.抽签
		if (this->m_index == 1)//判断第几轮
		{
			random_shuffle(v1.begin(), v1.end());
			for (auto it : v1)
			{
				cout << it << " ";
			}
		}
		else
		{
			random_shuffle(v2.begin(), v2.end());
			for (auto it : v2)
			{
				cout << it << " ";
			}
			cout << endl;
		}
		cout << "-------------------------------------" << endl;
		system("pause");
		cout << endl;
		//按任意键继续
	}
	//2.比赛
	void SpeechManager::speechContest()
	{
		cout <<"--------------------- "<<"第" << m_index << "轮比赛正式开始"<<"-----------------"<<endl;
		cout << "成绩如下" << endl;
		//准备零时容器存放小组成绩
		multimap<double, int, greater<double>> gourpScore;
		int num = 0;//记录人数6人一组
		vector<int> v_src;//比赛容器
		//判断第几轮
		if (m_index == 1)
		{
			v_src = v1;
		}
		else
		{
			v_src = v2;
		}
		//遍历所有选手比赛
		for (auto it : v_src)
		{
			num++;
			//评委打分
			deque<double> d;
			for (int i = 0; i < 10; i++)
			{
				double score = (rand() % 401 + 600) / 10.f;
				//cout << score << " ";
				d.push_back(score);
			}
			//cout << endl;
			//降序排列
			sort(d.begin(), d.end(), greater<double>());
			//去除最高分去除最低分
			d.pop_back();
			d.pop_front();
			//累加总分
			double sum = accumulate(d.begin(), d.end(), 0.0f);
			//平均分
			double avg = sum / (double)d.size();
			//打印平均分
			//cout << "编号:" << it << "姓名:" << this->m_speaker[it].m_name << "平均分:" << avg << endl;
			//将平均分放到map容器里面去
			this->m_speaker[it].m_score[this->m_index - 1] = avg;
			//将打分数据存到临时数据里面
			gourpScore.insert(make_pair(avg, it));
			//每6个人取出前三名
			if (num % 6 == 0)
			{
				cout << "第" << num / 6 << "小组比赛名次:" << endl;
				for (auto a : gourpScore)
				{
					cout << "编号:" << a.second << "姓名:" << this->m_speaker[a.second].m_name << " 成绩:" << this->m_speaker[a.second].m_score[this->m_index - 1] << endl;
				}
				//取出前三名晋级刀第二轮
				int count = 0;
				for (auto i : gourpScore)
				{
					if (count >=3) break;
					if (this->m_index == 1)
					{
						v2.push_back(i.second);
					}
					else
					{
						win.push_back(i.second);
					}
					count++;
				}
				gourpScore.clear();
			}
		}
		cout << "-----------------------" <<"第"<< this->m_index << "轮比赛完毕" << "-----------------------" << endl;
		system("pause");
	}

	//3.显示得分结果
	void SpeechManager::showScore()
	{
		cout << "-------------------第" << this->m_index << "轮晋级选手信息如下:-------------------" << endl;
		vector<int> v;
		if (this->m_index == 1)
		{
			v = v2;
		}
		else
		{
			v = win;
		}
		for (auto i : v)
		{
			cout << "选手:" << i << "姓名:" << this->m_speaker[i].m_name << "得分:" << m_speaker[i].m_score[this->m_index - 1] << endl;
		}
		cout << endl;
		system("pause");
		system("cls");
		//this->show_Meun();
	}

	//1.保存分数
	void SpeechManager::saveRecord()
	{
		ofstream ofs;//
		         //文件名
		ofs.open("speech.csv", ios::out | ios::app);//用追加的方式写文件
		//将每个人数据写入到文件中
		for (auto it : win)
		{
			ofs << it << "," << this->m_speaker[it].m_score[1]<< ",";
		}
		ofs << endl;
		ofs.close();
		cout << "记录已经保存" << endl;
		//只要里面有记录了，就应该告诉showRecord,防止因为存放记录文件名被修改出现问题
		this->fileIsEmpty = false;
	}

	void SpeechManager::loadRecord()
	{
		ifstream ifs("speech.csv", ios::in);//输入流对象 读取文件
		if (!ifs.is_open())//判断文件是否打开成功
		{
			this->fileIsEmpty = true;
			cout << "文件不存在！" << endl;
			ifs.close();
			return;
		}
		char ch;
		ifs >> ch;//读取单个字符
		if (ifs.eof())
		{
			cout << "文件为空" << endl;
			this->fileIsEmpty = true;
			ifs.close();
			return;
		}
		//文件不为空
		this->fileIsEmpty = false;
		ifs.putback(ch);//读取单个字符放回去
		string data;
		int index = 0;//表示第几届比赛
		//将字符读到data字符中
		while (ifs >> data)
		{

			//cout << data << endl;
	
			vector<string> v;
			int pos = -1;
			int start = 0;
			while (true)
			{
				pos = data.find(",", start);//从0开始查找","
					if (pos == -1)
					{
						break;
					}
					string tmp = data.substr(start, pos - start);//找到了截取
					//cout << tmp << endl;
					v.push_back(tmp);
					start = pos + 1;
			}
			this->m_Record.insert(make_pair(index, v));
			index++;
		}
		ifs.close();
		/*for (auto it : m_Record)
		{
			cout << it.first<<"编号 " << it.second[0] <<"分数" << it.second[1] << endl;
		}*/
	}
	void SpeechManager::showRecord()
	{
		if (this->fileIsEmpty == true)
		{
			cout << "文件不存在" << endl;

		}
		else
		{
			for (int i = 0; i < this->m_Record.size(); i++)
			{
				cout << "第" << i + 1 << "届" << endl;
				cout << "冠军编号:" << this->m_Record[i][0] << "得分:" << this->m_Record[i][1] << " " << endl;
				cout << "亚军编号:" << this->m_Record[i][2] << "得分:" << this->m_Record[i][3] << " " << endl;
				cout << "季军编号:" << this->m_Record[i][4] << "得分:" << this->m_Record[i][5] << " " << endl;
			}
		}
		system("pause");
		system("cls");
	}
void SpeechManager::clearRecord()
	{
	cout << "确认清空？" << endl;
	cout << "1-确认  2-返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//打开模式ios::trunc 如果存在删除文件并重新创建
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		//初始化属性
		this->initSpeech();
		//创建选手
		this->createSpeaker();
		//获取往届记录
		this->loadRecord();
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
	}
SpeechManager::~SpeechManager()
{

}