
#include<bits/stdc++.h>
#include"speechManager.h"
using namespace std;
int main()
{
	SpeechManager sm;

	srand((unsigned int)time(NULL));
	int choice = 0;
	
	while (true)
	{
		sm.show_Meun();
		cout << "choice" << endl;
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
