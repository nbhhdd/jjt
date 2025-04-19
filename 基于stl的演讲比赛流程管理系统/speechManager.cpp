//���ļ��ṹ����ͷ�ļ�
#include"speechManager.h"
#include"speaker.h"
//��ݵ���SpeechManager�еĺ������߷���
SpeechManager::SpeechManager()
{
	//��ʼ
	this->initSpeech();
	//����ѡ��
	this->createSpeaker();
	//���������¼
	this->loadRecord();
}
//�ڶ๦�ܶ��������������������ú������Ǹ���������׳����⡢
//����ʵ��SpeechManager�������show_Meun�˵����ܡ�
void SpeechManager::show_Meun()
{
	cout << "**********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ�����  *************" << endl;
	cout << "*************  1.��ʼ�ݽ�����    *************" << endl;
	cout << "*************  2.�鿴�����¼    *************" << endl;
	cout << "*************  3.��ձ�����¼    *************" << endl;
	cout << "*************  4.�˳���������    *************" << endl;
	cout << "**********************************************" << endl;
	cout << endl;

}


//�˳�����
void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��";
	system("pause");
	exit(0);
	//exit(0)��ʾ���������˳�������0֮�⣬������������������쳣�˳����磺exit(1),exit(-1)��
}
//��ʼ��

void SpeechManager::initSpeech()
{
	//��֤����Ϊ��
	this->v1.clear();
	this->v2.clear();
	this->win.clear();
	this->m_speaker.clear();
	this->m_index = 1;
	//��ʼ����¼����
	this->m_Record.clear();
}
//����ѡ��
void SpeechManager::createSpeaker()
{
	//һ��12����
	string nameseed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameseed.size(); i++)
	{
		string name = "ѡ��";
		name += nameseed[i];
		SpeaKer sp;
		sp.m_name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0;
		}
		//����
		this->v1.push_back(i + 10001);
		this->m_speaker.insert(make_pair(i + 10001, sp));
	}
}
void SpeechManager::startSpeech()
{

	//��һ�ֿ�ʼ����
	while (this->m_index <= 2)
	{
		this->speechDraw();
		this->speechContest();
		this->showScore();
		this->m_index++;
	}
	this->saveRecord();
	//��ÿ�α������Ժ�Ҫ���ñ���������
	//��ʼ��
	this->initSpeech();
	//����ѡ��
	this->createSpeaker();
	//���������¼
	this->loadRecord();
	//��ʼ��¼����

	cout << "����������!" << endl;
	system("pause");
	system("cls");
}
	//2.����

	//3.��ʾ�������

	//�ڶ��ֱ���


	//1.��ǩ

	void SpeechManager::speechDraw()  
	{
		//��һ�ֱ���
		cout << "��" << this->m_index << "�ֱ���ѡ�����ڳ�ǩ" << endl;
		cout << "--------------------------------------" << endl;
		cout << "��ǩ���ݽ�˳�����£�";
		//1.��ǩ
		if (this->m_index == 1)//�жϵڼ���
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
		//�����������
	}
	//2.����
	void SpeechManager::speechContest()
	{
		cout <<"--------------------- "<<"��" << m_index << "�ֱ�����ʽ��ʼ"<<"-----------------"<<endl;
		cout << "�ɼ�����" << endl;
		//׼����ʱ�������С��ɼ�
		multimap<double, int, greater<double>> gourpScore;
		int num = 0;//��¼����6��һ��
		vector<int> v_src;//��������
		//�жϵڼ���
		if (m_index == 1)
		{
			v_src = v1;
		}
		else
		{
			v_src = v2;
		}
		//��������ѡ�ֱ���
		for (auto it : v_src)
		{
			num++;
			//��ί���
			deque<double> d;
			for (int i = 0; i < 10; i++)
			{
				double score = (rand() % 401 + 600) / 10.f;
				//cout << score << " ";
				d.push_back(score);
			}
			//cout << endl;
			//��������
			sort(d.begin(), d.end(), greater<double>());
			//ȥ����߷�ȥ����ͷ�
			d.pop_back();
			d.pop_front();
			//�ۼ��ܷ�
			double sum = accumulate(d.begin(), d.end(), 0.0f);
			//ƽ����
			double avg = sum / (double)d.size();
			//��ӡƽ����
			//cout << "���:" << it << "����:" << this->m_speaker[it].m_name << "ƽ����:" << avg << endl;
			//��ƽ���ַŵ�map��������ȥ
			this->m_speaker[it].m_score[this->m_index - 1] = avg;
			//��������ݴ浽��ʱ��������
			gourpScore.insert(make_pair(avg, it));
			//ÿ6����ȡ��ǰ����
			if (num % 6 == 0)
			{
				cout << "��" << num / 6 << "С���������:" << endl;
				for (auto a : gourpScore)
				{
					cout << "���:" << a.second << "����:" << this->m_speaker[a.second].m_name << " �ɼ�:" << this->m_speaker[a.second].m_score[this->m_index - 1] << endl;
				}
				//ȡ��ǰ�����������ڶ���
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
		cout << "-----------------------" <<"��"<< this->m_index << "�ֱ������" << "-----------------------" << endl;
		system("pause");
	}

	//3.��ʾ�÷ֽ��
	void SpeechManager::showScore()
	{
		cout << "-------------------��" << this->m_index << "�ֽ���ѡ����Ϣ����:-------------------" << endl;
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
			cout << "ѡ��:" << i << "����:" << this->m_speaker[i].m_name << "�÷�:" << m_speaker[i].m_score[this->m_index - 1] << endl;
		}
		cout << endl;
		system("pause");
		system("cls");
		//this->show_Meun();
	}

	//1.�������
	void SpeechManager::saveRecord()
	{
		ofstream ofs;//
		         //�ļ���
		ofs.open("speech.csv", ios::out | ios::app);//��׷�ӵķ�ʽд�ļ�
		//��ÿ��������д�뵽�ļ���
		for (auto it : win)
		{
			ofs << it << "," << this->m_speaker[it].m_score[1]<< ",";
		}
		ofs << endl;
		ofs.close();
		cout << "��¼�Ѿ�����" << endl;
		//ֻҪ�����м�¼�ˣ���Ӧ�ø���showRecord,��ֹ��Ϊ��ż�¼�ļ������޸ĳ�������
		this->fileIsEmpty = false;
	}

	void SpeechManager::loadRecord()
	{
		ifstream ifs("speech.csv", ios::in);//���������� ��ȡ�ļ�
		if (!ifs.is_open())//�ж��ļ��Ƿ�򿪳ɹ�
		{
			this->fileIsEmpty = true;
			cout << "�ļ������ڣ�" << endl;
			ifs.close();
			return;
		}
		char ch;
		ifs >> ch;//��ȡ�����ַ�
		if (ifs.eof())
		{
			cout << "�ļ�Ϊ��" << endl;
			this->fileIsEmpty = true;
			ifs.close();
			return;
		}
		//�ļ���Ϊ��
		this->fileIsEmpty = false;
		ifs.putback(ch);//��ȡ�����ַ��Ż�ȥ
		string data;
		int index = 0;//��ʾ�ڼ������
		//���ַ�����data�ַ���
		while (ifs >> data)
		{

			//cout << data << endl;
	
			vector<string> v;
			int pos = -1;
			int start = 0;
			while (true)
			{
				pos = data.find(",", start);//��0��ʼ����","
					if (pos == -1)
					{
						break;
					}
					string tmp = data.substr(start, pos - start);//�ҵ��˽�ȡ
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
			cout << it.first<<"��� " << it.second[0] <<"����" << it.second[1] << endl;
		}*/
	}
	void SpeechManager::showRecord()
	{
		if (this->fileIsEmpty == true)
		{
			cout << "�ļ�������" << endl;

		}
		else
		{
			for (int i = 0; i < this->m_Record.size(); i++)
			{
				cout << "��" << i + 1 << "��" << endl;
				cout << "�ھ����:" << this->m_Record[i][0] << "�÷�:" << this->m_Record[i][1] << " " << endl;
				cout << "�Ǿ����:" << this->m_Record[i][2] << "�÷�:" << this->m_Record[i][3] << " " << endl;
				cout << "�������:" << this->m_Record[i][4] << "�÷�:" << this->m_Record[i][5] << " " << endl;
			}
		}
		system("pause");
		system("cls");
	}
void SpeechManager::clearRecord()
	{
	cout << "ȷ����գ�" << endl;
	cout << "1-ȷ��  2-����" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//��ģʽios::trunc �������ɾ���ļ������´���
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		//��ʼ������
		this->initSpeech();
		//����ѡ��
		this->createSpeaker();
		//��ȡ�����¼
		this->loadRecord();
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
	}
SpeechManager::~SpeechManager()
{

}