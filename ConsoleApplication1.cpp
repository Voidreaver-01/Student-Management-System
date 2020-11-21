#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int a = 0;
class score
{
public:
	score(float a, float b, float c, float d);


	float getChinaese()
	{
		return Chinaese;
	}
	float getMath()
	{
		return Math;
	}
	float getEnglish()
	{
		return English;
	}
	float getRationale()
	{
		return Rationale;
	}
	friend class student;
private:
	float Chinaese;
	float Math;
	float English;
	float Rationale;

};
class student : public score
{
public:
	student(string Name, string ID, float a, float b, float c, float d);
	string getName()
	{
		return name;
	}
	string getID()
	{
		return StudengID;
	}
private:
	string name;
	string StudengID;
};
vector<student>STUDENT;
score::score(float a, float b, float c, float d)
{
	Chinaese = a;
	Math = b,
		English = c;
	Rationale = d;
}
student::student(string Name, string ID, float a, float b, float c, float d) :score(a, b, c, d)
{
	name = Name;
	StudengID = ID;

}
bool operator==(class student s, class student st)
{
	if (s.getName() == st.getName())
	{
		return true;
	}
	else
	{
		return false;
	}
}
//录入信息（视为增加学生信息）
void Inputinformation()
{
	string name, ID;
	float j, b, c, d;
	cout << "依次输入学生的姓名、学号、语文、数学、英语、综合科目成绩" << endl;
	cin >> name >> ID;
	cin >> j >> b >> c >> d;
	student STU(name, ID, j, b, c, d);
	STUDENT.push_back(STU);
	a++;
	cout << "学生信息添加成功" << endl;
}

//查询学生信息


//（2）查询所有成绩
void queryall()
{
	cout << "    姓名    " << "         学号        " << "    语文     "
		<< "     数学     " << "       英语        " << "       综合成绩     " << endl;
	for (int i = 0; i < a; i++)
	{
		cout << STUDENT[i].getName() << STUDENT[i].getID() << STUDENT[i].getChinaese()
			<< STUDENT[i].getMath() << STUDENT[i].getEnglish()
			<< STUDENT[i].getRationale() << endl;
	}
}
//(3)查询语文成绩
void queryChinaese()
{
	cout << "     姓名    " << "            " << "    语文     " << endl;
	for (int i = 0; i < a; i++)
	{
		cout << STUDENT[i].getName() << "        " << STUDENT[i].getChinaese() << endl;
	}
}
//（4）查询数学成绩
void queryMath()
{
	cout << "     姓名    " << "            " << "    数学     " << endl;
	for (int i = 0; i < a; i++)
	{
		cout << STUDENT[i].getName() << "        " << STUDENT[i].getMath() << endl;
	}
}
//（5）查询英语成绩
void queryEnglishe()
{
	cout << "     姓名    " << "            " << "    英语     " << endl;
	for (int i = 0; i < a; i++)
	{
		cout << STUDENT[i].getName() << "        " << STUDENT[i].getEnglish() << endl;
	}
}
//（6）查询理科综合成绩
void queryRationale()
{
	cout << "     姓名    " << "            " << "    综合科目     " << endl;
	for (int i = 0; i < a; i++)
	{
		cout << STUDENT[i].getName() << "        " << STUDENT[i].getRationale() << endl;
	}
}
//（7）查询个人成绩（按照姓名查询）
void queryByName()
{
	string name;
	cout << "请输入要查询的学生的姓名" << endl;
	cin >> name;
	cout << "    姓名    " << "         学号        " << "    语文     "
		<< "     数学     " << "       英语        " << "       综合成绩     " << endl;
	for (int i = 0; i < a; i++)
	{
		string answer = STUDENT[i].getName();
		if (answer == name)
		{
			cout << STUDENT[i].getName() << STUDENT[i].getID() << STUDENT[i].getChinaese()
				<< STUDENT[i].getMath() << STUDENT[i].getEnglish()
				<< STUDENT[i].getRationale() << endl;

			return;
		}
	}
}
//（1）查询界面
void queryinterface()
{
	if (a == 0)
	{
		cerr << "请先录入成绩。" << endl;
		return;
	}
	int mychoose;
	cout << endl;
	cout << "                 1:查询所有成绩                " << endl;
	cout << "                 2:查询语文成绩                " << endl;
	cout << "                 3:查询数学成绩                " << endl;
	cout << "                 4:查询英语成绩                " << endl;
	cout << "                 5:查询理科综合成绩                " << endl;
	cout << "                 6:查询个人成绩（按姓名查询）                " << endl;
	cout << endl;
	cout << "输入选择。" << endl;
	cin >> mychoose;
	if (mychoose == 1)
	{
		queryall();
	}
	else if (mychoose == 2)
	{
		queryChinaese();
	}
	else if (mychoose == 3)
	{
		queryMath();
	}
	else if (mychoose == 4)
	{
		queryEnglishe();
	}
	else if (mychoose == 5)
	{
		queryRationale();
	}
	else if (mychoose == 6)
	{
		queryByName();
	}
	else
	{
		return;
	}

}

//修改学生信息
void modifyinformation()
{
	string name;
	cout << "请输入待修改的学生的姓名。" << endl;
	cin >> name;
	string name1, ID;
	float j, b, c, d;
	cout << "请依次输入修改的学生每项个人信息。" << endl;
	cout << "输入顺序位姓名、学号、语文、数学、英语、综合科目成绩" << endl;
	cin >> name1 >> ID;
	cin >> j >> b >> c >> d;
	student STU(name1, ID, j, b, c, d);
	for (int i = 0; i < a; i++)
	{
		string answer = STUDENT[i].getName();
		if (answer == name)
		{
			STUDENT[i] = STU;
			cout << "学生信息修改成功." << endl;
			return;
		}
	}
	cerr << "无名为" + name + "的学生" << endl;
	return;
}

//移除学生信息
//(1)移除界面选择
void removeinterface()
{
	cout << endl;
	cout << "             1:按照学生姓名移除             " << endl;
	cout << "             2:按照学生学号移除             " << endl;
	cout << endl;
}
//(2)按照姓名移除
void RemoveByName()
{
	string name;
	cout << "请输入要学生的姓名" << endl;
	cin >> name;
	for (int i = 0; i < a; i++)
	{
		string answer = STUDENT[i].getName();
		if (answer == name)
		{
			remove(STUDENT.begin(), STUDENT.end(), STUDENT[i]);
			a--;
			cout << "姓名为" + name + "的学生的信息已经被移除" << endl;
			return;
		}
	}
	cerr << "无名为" + name + "的学生" << endl;
	return;
}
//（3）按照学号移除
void RemoveByID()
{
	string ID;
	cout << "请输入要学生的学号" << endl;
	cin >> ID;
	for (int i = 0; i < a; i++)
	{
		string answer = STUDENT[i].getID();
		if (answer == ID)
		{
			remove(STUDENT.begin(), STUDENT.end(), STUDENT[i]);
			a--;
			cout << "学号为" + ID + "的学生的信息已经被移除" << endl;
			return;
		}
	}
	cerr << "无学号为" + ID + "的学生" << endl;
	return;
}
//(4)移除汇总
void removeinformation()
{
	int i;
	if (a == 0)
	{
		cerr << "学生人数为0" << endl;
		return;
	}
	removeinterface();
	cin >> i;
	if (i == 1)
	{
		RemoveByName();
	}
	else
	{
		RemoveByID();
	}
}

//学生操作系统
//查询所有成绩
void Queryallscore(string name)
{
	cout << "    姓名    " << "         学号        " << "    语文     "
		<< "     数学     " << "       英语        " << "       综合成绩     " << endl;
	for (int i = 0; i < a; i++)
	{
		string Name = STUDENT[i].getName();
		if (name == Name)
		{
			cout << STUDENT[i].getName() << STUDENT[i].getID() << STUDENT[i].getChinaese()
				<< STUDENT[i].getMath() << STUDENT[i].getEnglish()
				<< STUDENT[i].getRationale() << endl;
			cout << "继续努力呀！" << endl;
			return;
		}
	}
	cerr << "输入的信息错误，请重新输入." << endl;
}
//学生查询个人信息
void Getstudentinformation()
{
	if (a == 0)
	{
		cerr << "学生个人信息还未录入系统，请联系老师。" << endl;
		return;
	}
	string Name, ID;
	cout << "请依次输入姓名和学号以便查找" << endl;
	cin >> Name >> ID;
	Queryallscore(Name);
}

void Teacherinterface()
{
	int k;
	while (1)
	{
		cout << "            1:录入学生信息             " << endl;
		cout << "            2:查询学生信息             " << endl;
		cout << "            3:修改学生信息             " << endl;
		cout << "            4:移除学生信息             " << endl;
		cout << "            5:退出             " << endl;
		cout << "输入选择。" << endl;
		cin >> k;
		if (k == 1)
		{
			Inputinformation();
		}
		else if (k == 2)
		{
			queryinterface();
		}
		else if (k == 3)
		{
			modifyinformation();
		}
		else if (k == 4)
		{
			removeinformation();
		}
		else
		{
			return;
		}

	}
}
void maininterface()
{
	string password;
	while (1)
	{
		cout << "请输入密码。" << endl;
		cin >> password;
		while (password == "Teacher")
		{
			Teacherinterface();
			break;
		}
		while (password == "Student")
		{
			Getstudentinformation();
			break;
		}
		if (password == "return")
		{
			return;
		}
	}
}

int main()
{

	maininterface();
	return 0;
}