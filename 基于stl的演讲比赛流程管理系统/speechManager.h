#pragma once//��ֹͷ�ļ��ظ����룬�ظ�����
#include<iostream>
#include"Speaker.h"
#include<map>
#include<vector>
using namespace std;
//����ݽ�����������
//1.�����������衣
//2.ʵ�ֻ������ܣ���Ա����ʵ��(��ͷ�ļ���������Դ�ļ�ʵ��)
	//����һ.�˵�����
class SpeechManager
{
	//���캯�������������Ĵ���
	public:
		
		//�޲ι�����
		SpeechManager();

		//�˵�����
		void show_Meun();
		//��ʼ������֤ÿ��ѯ�������ǰ������
		void initSpeech();
		//����ѡ��
		void createSpeaker();
		//�˳�����
		void exitSystem();
		//�����������̹���,�����������̡�
		void startSpeech();

		//��ǩ����
		void speechDraw();
		//�ݽ���������
		// �������̷�����ǩ-��ʼ�ݽ�����-��ʾ2��һ�ֱ������-��ǩ-��ʼ�ݽ�����-��ʾǰ�������-�������
		//��������
		//��������
		void speechContest();

		//չʾ�������
		void showScore();
		//����������
		void saveRecord();
		//�鿴��¼����
		void loadRecord();

		//��ʾ����÷�
		void showRecord();

		//��ռ�¼����ʵ��
		void clearRecord();
		~SpeechManager();
		//��Ա����
		//����ѡ������
		vector<int> v1;
		//��һ�ֽ�����ѡ��
		vector<int> v2;
		//ʤ��ǰ����
		vector<int> win;
		//��ű���Լ���Ӧ�ľ���ѡ������
		map<int, SpeaKer> m_speaker;
		//��¼�����ִ�
		int m_index;
		//�ļ�Ϊ�յı���
		bool fileIsEmpty;
		//�����¼
		map<int, vector<string>> m_Record;
};
