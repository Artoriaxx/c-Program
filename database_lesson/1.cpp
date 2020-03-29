#include <bits/stdc++.h>
using namespace std;
struct student {//ѧ���Ĵ洢�ṹ
    string student_id, student_name, sex, cla;//ѧ��id��ѧ��������ѧ���Ա𣬰༶
    student() {}
    student(string id, string name, string sex, string cla) {
        this->student_id = id;
        this->student_name = name;
        this->sex = sex;
        this->cla = cla;
    }
};
struct lesson {//�γ̵Ĵ洢�ṹ
    string lesson_id, lesson_name;//�γ�id���γ�����
    double point;//ѧ��
    lesson() {}
    lesson(string id, string name, double point) {
        this->lesson_id = id;
        this->lesson_name = name;
        this->point = point;
    }
};
struct choose {//ѡ����Ϣ�Ĵ洢�ṹ
    string student_id, lesson_id;//ѡ��ѧ�����ƣ�ѡ������
    double grade;//�ɼ�
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
inline void stu_enter(int n) {//����n��ѧ��
    ifstream in("student.txt");//student.txt�Ǵ洢ѧ����Ϣ���ļ�
    for (int i = 1; i <= n; i++) {
        student now;
        in >> now.student_id >> now.student_name >> now.sex >> now.cla;
        stu.push_back(now);
    }
    in.close();
}
inline void les_enter(int n) {//����n���γ�
    ifstream in("lesson.txt");//lesson.txt�Ǵ洢�γ���Ϣ���ļ�
    for (int i = 1; i <= n; i++) {
        lesson now;
        in >> now.lesson_id >> now.lesson_name >> now.point;
        les.push_back(now);
    }
    in.close();
}
inline void choose_enter(int n) {//����n��ѡ����Ϣ
    ifstream in("choose.txt");//choose.txt��ѡ����Ϣ���ļ�
    for (int i = 1; i <= n; i++) {
        choose now;
        in >> now.student_id >> now.lesson_id;
        now.grade = 0;
        cho.push_back(now);
    }
    in.close();
}
inline bool modify_grade(string stu_id, string les_id, double grade) {//�޸�ĳλѧ��ĳ���γ̳ɼ�
    bool flag = false;
    for (int i = 0; i < cho.size(); i++) {
        if (cho[i].student_id == stu_id && cho[i].lesson_id == les_id) {
            cho[i].grade = grade;
            flag = true;
            break;
        }
    }
    return flag;//�����Ƿ��޸ĳɹ�
}
inline void modify_bat(int n) {
    ifstream in("score.txt");//score.txt�������޸ĳɼ����ļ�
    for (int i = 1; i <= n; i++) {
        choose now;
        in >> now.student_id >> now.lesson_id >> now.grade;
        modify_grade(now.student_id, now.lesson_id, now.grade);
    }
    in.close();
}
inline void query_stu(string stu_id) {//��ѯѧ��idΪstu_id��ѧ��
    bool flag = false;
    for (int i = 0; i < stu.size(); i++) {
        if (stu[i].student_id == stu_id) {
            cout << "ѧ��:" <<stu[i].student_id << " ����:" << stu[i].student_name << " �Ա�:" << stu[i].sex << " �༶:" << stu[i].cla << '\n';
            flag = true;
            break;
        }
    }
    if (!flag) cout << "û�в�ѯ��ѧ��Ϊ" << stu_id << "��ѧ��" << '\n';
}
inline void query_les(string les_id) {//��ѯ�γ̱��Ϊles_id�Ŀγ�
    bool flag = false;
    for (int i = 0; i < les.size(); i++) {
        if (les[i].lesson_id == les_id) {
            cout << "�γ̱��:" <<les[i].lesson_id << " �γ�����:" << les[i].lesson_name << " ѧ��:" << les[i].point << '\n';
            flag = true;
            break;
        }
    }
    if (!flag) cout << "û�в�ѯ���γ̱��Ϊ" << les_id << "�Ŀγ�" << '\n';
}
inline void query_cho(string stu_id) {//��ѯѡ����Ϣ
    bool flag = false;
    for (int i = 0; i < stu.size(); i++) {
        if (stu[i].student_id == stu_id) {
            cout << stu[i].student_name << "��ѡ�޿γ�Ϊ:" << '\n';
            flag = true;
            break;
        }
    }
    if (!flag) {//û���ҵ���ѧ��
        cout << "û��ѧ��Ϊ" << stu_id << "��ѧ��" << '\n';
        return;
    }
    int num = 0;
    for (int i = 0; i < cho.size(); i++) {
        if (cho[i].student_id == stu_id) {
            bool flag = false;
            for (int j = 0; j < les.size(); j++) {
                if (les[j].lesson_id == cho[i].lesson_id) {
                    flag = true;
                    cout << ++num << ". �γ�����: " << les[j].lesson_name << " �ɼ�: " << cho[i].grade << " ѧ��: " << les[j].point << '\n';
                    break;
                }
            }
            if (!flag) cout << "�γ̱��Ϊ" << cho[i].lesson_id << "�Ŀγ���Ϣ�������������ļ�\n";
        }
    }
}
inline void query_avg(string stu_id) {//��ѯ��Ȩƽ����
    bool flag = false;
    for (int i = 0; i < stu.size(); i++) {
        if (stu[i].student_id == stu_id) {
            cout << stu[i].student_name << "��ƽ����Ϊ: ";
            flag = true;
            break;
        }
    }
    if (!flag) {
        cout << "û��ѧ��Ϊ" << stu_id << "��ѧ��" << '\n';
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
inline bool del_stu(string stu_id) {//ɾ��ѧ��
    bool flag = false;
    for (auto it = stu.begin(); it != stu.end(); it++) {
        if (it->student_id == stu_id) {
            stu.erase(it);
            flag = true;
            break;
        }
    }
    return flag;//�����Ƿ�ɾ���ɹ�
}
int main() {
    char option[10];
    printf("===================================\n\n");
    printf("=========== 0. �˳�ϵͳ ===========\n\n");
    printf("========= 1. ¼��ѧ����Ϣ =========\n\n");
    printf("========= 2. ¼��γ���Ϣ =========\n\n");
    printf("========= 3. ¼��ѡ����Ϣ =========\n\n");
    printf("========= 4. ��������ɼ� =========\n\n");
    printf("========= 5. �޸ĸ��˳ɼ� =========\n\n");
    printf("========= 6. ��ѯѧ����Ϣ =========\n\n");
    printf("========= 7. ��ѯ�γ���Ϣ =========\n\n");
    printf("========= 8. ��ѯѧ���ɼ� =========\n\n");
    printf("========= 9. ɾ��ѧ����Ϣ =========\n\n");
    printf("===================================\n");
    printf("������Ҫ������ѡ��ǰ������: ");
    while (~scanf("%s", option)) {
        if (option[0] == '0') break;//�˳�
        if (option[0] == '1') {
            printf("����Ҫ¼���ѧ������:");
            int n; scanf("%d", &n);
            stu_enter(n); //¼��n��ѧ��
            puts("¼��ɹ�");
        }
        if (option[0] == '2') {
            printf("����Ҫ¼��Ŀγ�����:");
            int n; scanf("%d", &n);
            les_enter(n); //¼��n�ſγ�
            puts("¼��ɹ�");
        }
        if (option[0] == '3') {
            printf("����Ҫ¼���ѡ����Ϣ����:");
            int n; scanf("%d", &n);
            choose_enter(n); //¼��n��ѡ����Ϣ
            puts("¼��ɹ�");
        }
        if (option[0] == '4') {
            printf("����Ҫ�����޸ĳɼ�������:");
            int n; scanf("%d", &n);
            modify_bat(n);
            puts("�޸ĳɹ�");
        }
        if (option[0] == '5') {
            choose now;
            printf("����Ҫ�޸ĵ�ѧ��ѧ��:");
            cin >> now.student_id;
            printf("����γ̱��:");
            cin >> now.lesson_id;
            printf("�����޸ĺ�ĳɼ�");
            cin >> now.grade;
            bool flag = modify_grade(now.student_id, now.lesson_id, now.grade);
            if (flag) {
                puts("�޸ĳɹ�");
            }
            else {
                puts("�޸�ʧ��");
            }
        }
        if (option[0] == '6') {
            printf("����Ҫ��ѯ��ѧ��ѧ��:");
            string id;
            cin >> id;
            query_stu(id);
        }
        if (option[0] == '7') {
            printf("����Ҫ��ѯ�Ŀγ̱��:");
            string id;
            cin >> id;
            query_les(id);
        }
        if (option[0] == '8') {
            printf("����Ҫ��ѯ�ɼ���ѧ��ѧ��:");
            string id;
            cin >> id;
            printf("��ѯ���гɼ�Y/��ѯƽ���ɼ�N?\n");
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
            printf("����Ҫɾ����ѧ��ѧ��");
            string id;
            cin >> id;
            bool flag = del_stu(id);
            if (flag) {
                puts("ɾ���ɹ�");
            }
            else {
                puts("ɾ��ʧ��");
            }
        }
        printf("\n������Ҫ������ѡ��ǰ������:");
    }
    
    

    return 0;
}
