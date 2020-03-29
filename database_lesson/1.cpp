#include <bits/stdc++.h>
using namespace std;
struct student {//学生的存储结构
    string student_id, student_name, sex, cla;//学生id，学生姓名，学生性别，班级
    student() {}
    student(string id, string name, string sex, string cla) {
        this->student_id = id;
        this->student_name = name;
        this->sex = sex;
        this->cla = cla;
    }
};
struct lesson {//课程的存储结构
    string lesson_id, lesson_name;//课程id，课程名称
    double point;//学分
    lesson() {}
    lesson(string id, string name, double point) {
        this->lesson_id = id;
        this->lesson_name = name;
        this->point = point;
    }
};
struct choose {//选课信息的存储结构
    string student_id, lesson_id;//选课学生名称，选课名称
    double grade;//成绩
    choose() {}
    choose(string sid, string lid, double grade) {
        this->student_id = sid;
        this->lesson_id = lid;
        this->grade = grade;
    }
};
vector<student> stu;
vector<lesson> les;
vector<choose> cho;
inline void stu_enter(int n) {//读入n个学生
    ifstream in("student.txt");//student.txt是存储学生信息的文件
    for (int i = 1; i <= n; i++) {
        student now;
        in >> now.student_id >> now.student_name >> now.sex >> now.cla;
        stu.push_back(now);
    }
    in.close();
}
inline void les_enter(int n) {//读入n个课程
    ifstream in("lesson.txt");//lesson.txt是存储课程信息的文件
    for (int i = 1; i <= n; i++) {
        lesson now;
        in >> now.lesson_id >> now.lesson_name >> now.point;
        les.push_back(now);
    }
    in.close();
}
inline void choose_enter(int n) {//读入n个选课信息
    ifstream in("choose.txt");//choose.txt是选课信息的文件
    for (int i = 1; i <= n; i++) {
        choose now;
        in >> now.student_id >> now.lesson_id;
        now.grade = 0;
        cho.push_back(now);
    }
    in.close();
}
inline bool modify_grade(string stu_id, string les_id, double grade) {//修改某位学生某个课程成绩
    bool flag = false;
    for (int i = 0; i < cho.size(); i++) {
        if (cho[i].student_id == stu_id && cho[i].lesson_id == les_id) {
            cho[i].grade = grade;
            flag = true;
            break;
        }
    }
    return flag;//返回是否修改成功
}
inline void modify_bat(int n) {
    ifstream in("score.txt");//score.txt是批量修改成绩的文件
    for (int i = 1; i <= n; i++) {
        choose now;
        in >> now.student_id >> now.lesson_id >> now.grade;
        modify_grade(now.student_id, now.lesson_id, now.grade);
    }
    in.close();
}
inline void query_stu(string stu_id) {//查询学生id为stu_id的学生
    bool flag = false;
    for (int i = 0; i < stu.size(); i++) {
        if (stu[i].student_id == stu_id) {
            cout << "学号:" <<stu[i].student_id << " 姓名:" << stu[i].student_name << " 性别:" << stu[i].sex << " 班级:" << stu[i].cla << '\n';
            flag = true;
            break;
        }
    }
    if (!flag) cout << "没有查询到学号为" << stu_id << "的学生" << '\n';
}
inline void query_les(string les_id) {//查询课程编号为les_id的课程
    bool flag = false;
    for (int i = 0; i < les.size(); i++) {
        if (les[i].lesson_id == les_id) {
            cout << "课程编号:" <<les[i].lesson_id << " 课程名称:" << les[i].lesson_name << " 学分:" << les[i].point << '\n';
            flag = true;
            break;
        }
    }
    if (!flag) cout << "没有查询到课程编号为" << les_id << "的课程" << '\n';
}
inline void query_cho(string stu_id) {//查询选课信息
    bool flag = false;
    for (int i = 0; i < stu.size(); i++) {
        if (stu[i].student_id == stu_id) {
            cout << stu[i].student_name << "的选修课程为:" << '\n';
            flag = true;
            break;
        }
    }
    if (!flag) {//没有找到该学生
        cout << "没有学号为" << stu_id << "的学生" << '\n';
        return;
    }
    int num = 0;
    for (int i = 0; i < cho.size(); i++) {
        if (cho[i].student_id == stu_id) {
            bool flag = false;
            for (int j = 0; j < les.size(); j++) {
                if (les[j].lesson_id == cho[i].lesson_id) {
                    flag = true;
                    cout << ++num << ". 课程名称: " << les[j].lesson_name << " 成绩: " << cho[i].grade << " 学分: " << les[j].point << '\n';
                    break;
                }
            }
            if (!flag) cout << "课程编号为" << cho[i].lesson_id << "的课程信息有误，请检查输入文件\n";
        }
    }
}
inline void query_avg(string stu_id) {//查询加权平均分
    bool flag = false;
    for (int i = 0; i < stu.size(); i++) {
        if (stu[i].student_id == stu_id) {
            cout << stu[i].student_name << "的平均分为: ";
            flag = true;
            break;
        }
    }
    if (!flag) {
        cout << "没有学号为" << stu_id << "的学生" << '\n';
        return;
    }
    double totgrade = 0, totpoint = 0;
    for (int i = 0; i < cho.size(); i++) {
        if (cho[i].student_id == stu_id) {
            for (int j = 0; j < les.size(); j++) {
                if (les[j].lesson_id == cho[i].lesson_id) {
                    totgrade += cho[i].grade * les[j].point;
                    totpoint += les[j].point;
                    break;
                }
            }
        }
    }
    cout << totgrade / totpoint << '\n';
}
inline bool del_stu(string stu_id) {//删除学生
    bool flag = false;
    for (auto it = stu.begin(); it != stu.end(); it++) {
        if (it->student_id == stu_id) {
            stu.erase(it);
            flag = true;
            break;
        }
    }
    return flag;//返回是否删除成功
}
int main() {
    char option[10];
    printf("===================================\n\n");
    printf("=========== 0. 退出系统 ===========\n\n");
    printf("========= 1. 录入学生信息 =========\n\n");
    printf("========= 2. 录入课程信息 =========\n\n");
    printf("========= 3. 录入选课信息 =========\n\n");
    printf("========= 4. 批量导入成绩 =========\n\n");
    printf("========= 5. 修改个人成绩 =========\n\n");
    printf("========= 6. 查询学生信息 =========\n\n");
    printf("========= 7. 查询课程信息 =========\n\n");
    printf("========= 8. 查询学生成绩 =========\n\n");
    printf("========= 9. 删除学生信息 =========\n\n");
    printf("===================================\n");
    printf("请输入要操作的选项前的数字: ");
    while (~scanf("%s", option)) {
        if (option[0] == '0') break;//退出
        if (option[0] == '1') {
            printf("输入要录入的学生数量:");
            int n; scanf("%d", &n);
            stu_enter(n); //录入n个学生
            puts("录入成功");
        }
        if (option[0] == '2') {
            printf("输入要录入的课程数量:");
            int n; scanf("%d", &n);
            les_enter(n); //录入n门课程
            puts("录入成功");
        }
        if (option[0] == '3') {
            printf("输入要录入的选课信息数量:");
            int n; scanf("%d", &n);
            choose_enter(n); //录入n个选课信息
            puts("录入成功");
        }
        if (option[0] == '4') {
            printf("输入要批量修改成绩的数量:");
            int n; scanf("%d", &n);
            modify_bat(n);
            puts("修改成功");
        }
        if (option[0] == '5') {
            choose now;
            printf("输入要修改的学生学号:");
            cin >> now.student_id;
            printf("输入课程编号:");
            cin >> now.lesson_id;
            printf("输入修改后的成绩");
            cin >> now.grade;
            bool flag = modify_grade(now.student_id, now.lesson_id, now.grade);
            if (flag) {
                puts("修改成功");
            }
            else {
                puts("修改失败");
            }
        }
        if (option[0] == '6') {
            printf("输入要查询的学生学号:");
            string id;
            cin >> id;
            query_stu(id);
        }
        if (option[0] == '7') {
            printf("输入要查询的课程编号:");
            string id;
            cin >> id;
            query_les(id);
        }
        if (option[0] == '8') {
            printf("输入要查询成绩的学生学号:");
            string id;
            cin >> id;
            printf("查询所有成绩Y/查询平均成绩N?\n");
            string flag;
            cin >> flag;
            if (flag == "Y") {
                query_cho(id);
            }
            else {
                query_avg(id);
            }
        }
        if (option[0] == '9') {
            printf("输入要删除的学生学号");
            string id;
            cin >> id;
            bool flag = del_stu(id);
            if (flag) {
                puts("删除成功");
            }
            else {
                puts("删除失败");
            }
        }
        printf("\n请输入要操作的选项前的数字:");
    }
    
    

    return 0;
}
