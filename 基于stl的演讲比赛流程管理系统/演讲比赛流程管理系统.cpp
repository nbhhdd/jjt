//����������
//��������1.�ṩ�˵��������û����� 2.���ݽ��������̿��� 3.���ļ��Ķ�д����
//��Ҫ��������ϵͳ����
#include<bits/stdc++.h>
#include"speechManager.h"
using namespace std;
int main()
{
	//�������������
	SpeechManager sm;

	//���ÿ�����ݶ���һ�������

	//�������������
	srand((unsigned int)time(NULL));
	//����12��
	//
	// for (auto s : sm.m_speaker)
	//{
		//cout << "ѡ�ֱ��"<<s.first << "    ѡ������"<<s.second.m_name << "    ѡ�ֳɼ�"<<s.second.m_score[0]<<endl;
	//}
	//for (map<int,SpeaKer>::iterator it=sm.m_speaker.begin();it!=sm.m_speaker.end();it++)
	//{
		//cout << "ѡ�ֱ��:" << it->first << "ѡ������;" << it->second.m_name <<"����:"<<it->second.m_score[0]<< endl;
	//}
	//sm.show_Meun();
	//�������������û�������
	int choice = 0;
	
	//��֤�ظ�����ϵͳ��ֻ����0��ʱ���˳�ϵͳ
	while (true)
	{
		sm.show_Meun();//������������ܱ�֤������˵��ٴγ���
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1://��ʼ����
			sm.startSpeech();
			break;
		case 2://�鿴��¼
			sm.showRecord();
			break;
		case 3://��ռ�¼
			sm.clearRecord();
			break;
		case 0://�˳�����
			sm.exitSystem();
			break;
		default:
			system("cls");//����
			break;
		}
	}
	
	//�����������а����������
	cout << "hello world" << endl;
	system("pause");
	return 0;
}