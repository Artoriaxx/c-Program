#include <bits/stdc++.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

const int INF = 0x7fffffff;
const int SLOT = 5;
int FCOUNT = 0;


struct FreeTable {
    int fid;
    int headAddress, size;
    FreeTable() {}
    FreeTable(int fid, int headAddress, int size) {
        this->fid = fid;
        this->headAddress = headAddress;
        this->size = size;
    }
    bool operator < (const FreeTable &b) const {
        return headAddress < b.headAddress;
    }
    void show() {
        printf("---%d %d---\n", headAddress, size);
    }
};
vector<FreeTable> freeTable;
unordered_map<int, int> mapAddress;
unordered_map<int, int> mapSize;


struct Resource {
    int rid;
    int success;
    int headAddress, size;
    Resource() {}
    Resource(int rid, int success, int headAddress, int size) {
        this->rid = rid;
        this->success = success;
        this->headAddress = headAddress;
        this->size = size;
    }
    
    void show() {
        printf("---%d %d %d---\n", success, headAddress, size);
    }
};


struct ProcessControlBlock {
    int pid;
    int status;//状态 =0 创建 =1 就绪 =2 正在执行 =3 等待、阻塞 =4 终止
    int waitTime;//等待时间
    int processTime;//已执行时间
    int totTime;//所需总时间
    int lastTime;//上次执行的时间
    Resource r;//申请的内存资源

    ProcessControlBlock() {}
    ProcessControlBlock(int pid, int tt, Resource rr, int sta = 0, int wt = 0, int pt = 0, int lt = 0) {
        this->pid = pid;
        this->status = sta;
        this->waitTime = wt;
        this->processTime = pt;
        this->totTime = tt;
        this->lastTime = lt;
        this->r = rr;
    }

    void ready() { this->status = 1; }
    void run() { this->status = 2; }
    void block() { this->status = 3; }

    bool isEnd() {
        if (status == 4) return true;
        if (processTime >= totTime) {
            this->processTime = totTime;
            this->status = 4;
            return true;
        }
        return false;
    }

};

int PROCESS_COUNT = 0;

vector<ProcessControlBlock> runningQueen;
vector<ProcessControlBlock> readyQueen;
vector<ProcessControlBlock> blockQueen;
vector<ProcessControlBlock> finishMessage;

auto findMin(int reqSize);
void compact();
Resource allocate(int reqSize);
void freeResource(Resource &r);
bool createProcess(int size, int tot);
bool destroyProcess(ProcessControlBlock pcb);
bool blockToWakeup(int op, int optionPid = -1);
void showAll(int op = 1);
void runProcess();
void function1();
void function2();
void function3();
void function4();
void function5();
void function6();
void function7();
void startMenu();


int main() {
    srand(time(NULL));
    startMenu();
    return 0;
}

auto findMin(int reqSize) {
    int mn = INF;
    auto ans = freeTable.end();
    for (auto it = freeTable.begin(); it != freeTable.end(); it++) {
        if (it->size > reqSize) {
            if (it->size < mn) {
                mn = it->size;
                ans = it;
            }
        }
    }
    return ans;
}

void statusChange() {
    for (auto e : readyQueen) e.ready();
    for (auto e : blockQueen) e.block();
    for (auto e : runningQueen) e.run();
}

void compact() {
    statusChange();
    freeTable.clear();
    vector<int> head;
    head.push_back(0);
    for (int i = 1; i <= FCOUNT; i++) {
        head.push_back(mapAddress[i]);
    }
    for (auto e : readyQueen) {
        e.r.headAddress = head[e.r.rid];
        head[e.r.rid] = head[e.r.rid] + e.r.size;
    }
    for (auto e : blockQueen) {
        e.r.headAddress = head[e.r.rid];
        head[e.r.rid] = head[e.r.rid] + e.r.size;
    }
    for (auto e : runningQueen) {
        e.r.headAddress = head[e.r.rid];
        head[e.r.rid] = head[e.r.rid] + e.r.size;
    }
    for (int i = 1; i <= FCOUNT; i++) {
        freeTable.push_back(FreeTable(i, head[i], mapSize[i] - head[i] + 1));
    }
    
    
}

Resource allocate(int reqSize) {
    auto it = findMin(reqSize);
    if (it == freeTable.end()) {
        compact();
        it = findMin(reqSize);
        if (it == freeTable.end()) {
            printf("分配内存失败\n");
            return Resource(0, 0, 0, 0);
        }
        else {
            FreeTable minBlock = *it;
            freeTable.erase(it);
            Resource now = Resource(minBlock.fid, 1, minBlock.headAddress, reqSize);
            minBlock.headAddress += reqSize;
            minBlock.size -= reqSize;
            freeTable.push_back(minBlock);
            printf("成功分配内存, 起始地址为%d, 大小为%d\n", now.headAddress, now.size);
            return now;
        }
    }
    else {
        FreeTable minBlock = *it;
        freeTable.erase(it);
        Resource now = Resource(minBlock.fid, 1, minBlock.headAddress, reqSize);
        minBlock.headAddress += reqSize;
        minBlock.size -= reqSize;
        freeTable.push_back(minBlock);
        return now;
    }
}


void freeResource(Resource &r) {
    FreeTable newBlock = FreeTable(r.rid, r.headAddress, r.size);
    freeTable.push_back(newBlock);
    r = Resource(0, 0, 0, 0);
    printf("成功释放内存，起始地址为%d, 大小为%d\n", newBlock.headAddress, newBlock.size);
}

bool createProcess(int size, int tot) {
    ProcessControlBlock pcb;
    Resource r = allocate(size);
    if (r.size == 0) {
        printf("创建进程失败, 内存空间不足, 请增加增加空闲内存分区\n");
        return false;
    }
    pcb = ProcessControlBlock(++PROCESS_COUNT, tot, r);
    printf("成功创建进程: %d, 所需执行时间为 %d, 申请内存大小为 %d\n", pcb.pid, pcb.totTime, pcb.r.size);
    readyQueen.push_back(pcb);
    pcb.ready();
    printf("该进程成功进入就绪队列\n");
    return true;
}

bool destroyProcess(ProcessControlBlock pcb) {
    pcb.status = 4;
    freeResource(pcb.r);
    printf("进程: %d 已经终止\n", pcb.pid);
    return true;
}


bool blockToWakeup(int op, int optionPid) {
    if (op == 1) {
        // op == 1 全部唤醒
        printf("阻塞队列中的进程即将全部唤醒...\n");
        for (auto e : blockQueen) {
            readyQueen.push_back(e);
            e.run();

            printf("进程: %d 已经从阻塞状态转换为就绪状态\n", e.pid);
        }
        blockQueen.clear();
        return true;
    }
    else {
        // op == 2 单个唤醒
        for (auto it = blockQueen.begin(); it != blockQueen.end(); it++) {
            if (it->pid == optionPid) {
                readyQueen.push_back(*it);
                it->run();
                printf("进程: %d 已经从阻塞状态转换为就绪状态\n", it->pid);
                blockQueen.erase(it);
                return true;
            }
        }
        printf("没有找到id为%d的进程", optionPid);
        return false;
    }
}

void showAll(int op) {
    for (auto e : runningQueen) {
        printf("进程%d: 状态-运行, 已经执行时间%d, 剩余执行时间%d, 总等待时间%d\n", e.pid, e.processTime, e.totTime - e.processTime, e.waitTime);
    }
    for (auto e : blockQueen) {
        printf("进程%d: 状态-阻塞, 已经执行时间%d, 剩余执行时间%d, 总等待时间%d\n", e.pid, e.processTime, e.totTime - e.processTime, e.waitTime);
    }
    for (auto e : readyQueen) {
        printf("进程%d: 状态-就绪, 已经执行时间%d, 剩余执行时间%d, 总等待时间%d\n", e.pid, e.processTime, e.totTime - e.processTime, e.waitTime);
    }
    if (op) {
        for (auto e : finishMessage) {
            printf("进程%d: 状态-运行完毕, 已经执行时间%d, 剩余执行时间%d, 总等待时间%d\n", e.pid, e.processTime, e.totTime - e.processTime, e.waitTime);
        }
    }
}

void runProcess() {
    auto itr = readyQueen.begin();
    int op = 0;
    int nowTime = 0;
    if (readyQueen.empty() && runningQueen.empty()) {
        printf("当前就绪队列为空，请唤醒阻塞中的进程或者添加新进程\n");
        printf("是否唤醒进程？Y/N\n");
        char op[2];
        scanf("%s", op);
        if (op[0] == 'y' || op[0] == 'Y') {
            printf("当前被阻塞的进程如下:\n");
            for (auto e : blockQueen) {
                printf("进程:%d\n", e.pid);
            }
            printf("请输入要唤醒的进程编号:");
            int pid;
            scanf("%d", &pid);
            if (!blockToWakeup(2, pid)) {
                printf("请检查输入的进程编号是否有误\n");
                return;
            }
        }
        else return;
    }
    while (readyQueen.size() > 0 || runningQueen.size() > 0) {
        if (itr == readyQueen.end()) itr = readyQueen.begin();
        if (runningQueen.size() == 0) {
            runningQueen.push_back(*itr);
            itr = readyQueen.erase(itr);
        }
        auto it = runningQueen.begin();
        printf("当前要执行的进程为:%d\n", it->pid);
        printf("1     执行一个时间片\n");
        printf("2     显示\n");
        printf("3     阻塞当前进程\n");
        printf("4     唤醒某个进程\n");
        printf("其他  退出\n");
        printf("请键入操作\n");
        
        while (1) {
            if (_kbhit()) {
                int ch = _getch();
                if (ch == 49) op = 1;//op==1 执行一个时间片 F1
                else if (ch == 50) op = 2;//op==2 显示          F2
                else if (ch == 51) op = 3;//op==2 阻塞当前进程   F3
                else if (ch == 52) op = 4;//op==4 唤醒某个进程   F4
                else op = 5;//op==5 退出          其他
                break;
            }
        }
        if (op == 1) {
                    
            it->processTime += SLOT;
            it->waitTime += nowTime - it->lastTime;
            nowTime += SLOT;
            it->lastTime = nowTime;
            printf("进程%d: 正在执行中...\n", it->pid);
            Sleep(SLOT * 400);
            
            if (it->isEnd()) {
                printf("进程%d: 已经执行完毕\n", it->pid);
                finishMessage.push_back(*it);
                destroyProcess(*it);
                runningQueen.erase(it++);
                continue;
            }
            else{
                printf("进程%d: 已经执行时间%d, 剩余执行时间%d, 总等待时间%d\n", it->pid, it->processTime, it->totTime - it->processTime, it->waitTime);
                it++;
                readyQueen.push_back(runningQueen.back());
                runningQueen.pop_back();
            }
        }
        if (op == 2) {
            showAll();
        }
        if (op == 3) {
            it->block();
            blockQueen.push_back(*it);
            it = runningQueen.erase(it);
        }
        if (op == 4) {
            printf("当前被阻塞的进程如下:\n");
            for (auto e : blockQueen) {
                printf("进程:%d\n", e.pid);
            }
            printf("请输入要唤醒的进程编号:");
            int pid;
            scanf("%d", &pid);
            if (!blockToWakeup(2, pid)) {
                printf("请检查输入的进程编号是否有误\n");
            }

        }
        if (op == 5) {
            break;
        }
        printf("\n");
    }
}


void function1() {
    system("cls");
    printf("1     设置随机参数空闲内存分区\n");
    printf("2     设置指定参数空闲内存分区\n");
    printf("其他   退出\n");
    printf("请选择操作:");
    int op; scanf("%d", &op);
    if (op == 1) {
        int lastAddress = 0;
        for (auto e : freeTable) {
            lastAddress = max(lastAddress, e.headAddress + e.size);
        }
        int size = rand() % 500 + 100;
        int shift = rand() % 100 + 1;
        freeTable.push_back(FreeTable(++FCOUNT, lastAddress + shift, size));
        mapAddress[FCOUNT] = lastAddress + shift;
        mapSize[FCOUNT] = size;
        printf("成功设置了起始地址为%d, 大小为%d的空闲分区\n", freeTable.back().headAddress, freeTable.back().size);
    }
    else if (op == 2) {
        int lastAddress = 0;
        for (auto e : freeTable) {
            lastAddress = max(lastAddress, e.headAddress + e.size);
        }
        printf("请输入起始地址, 不小于%d:", lastAddress);
        int headAddress;
        scanf("%d", &headAddress);
        while (headAddress < lastAddress) {
            printf("请重新输入起始地址, 不小于%d:", lastAddress);
            scanf("%d", &headAddress);
        }
        printf("请输入内存大小:");
        int size;
        scanf("%d", &size);
        freeTable.push_back(FreeTable(++FCOUNT, headAddress, size));
        mapAddress[FCOUNT] = headAddress;
        mapSize[FCOUNT] = size;
        printf("成功设置了起始地址为%d, 大小为%d的空闲分区\n", freeTable.back().headAddress, freeTable.back().size);
    }
    printf("执行结束, 按任意键退出...");
    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            startMenu();
            return;
        }
    }
}

void function2() {
    system("cls");
    printf("1     创建随机参数进程\n");
    printf("2     创建指定参数进程\n");
    printf("其他   退出\n");
    printf("请选择操作:");
    int op; scanf("%d", &op);
    if (op == 1) {
        int size = rand() % 100 + 50;
        int tot = rand() % 30 + 10;
        if (!createProcess(size, tot)) {
            printf("随机创建失败, 内存大小不足\n");
        }
    }
    else if (op == 2) {
        printf("请输入申请的内存大小:");
        int size; scanf("%d", &size);
        printf("请输入进程总执行时间:");
        int tot; scanf("%d", &tot);
        if (!createProcess(size, tot)) {
            printf("创建失败, 内存大小不足\n");
        }
    }
    printf("执行结束, 按任意键退出...");
    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            startMenu();
            return;
        }
    }
}

void function3() {
    system("cls");
    printf("开始执行...\n");
    blockToWakeup(1);
    printf("执行结束, 按任意键退出...");
    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            startMenu();
            return;
        }
    }
}

void function4() {
    system("cls");
    printf("开始执行...\n");
    runProcess();
    printf("执行结束, 按任意键退出...");
    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            startMenu();
            return;
        }
    }
}

void function5() {
    system("cls");
    printf("开始执行...\n");
    showAll();
    printf("执行结束, 按任意键退出...");
    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            startMenu();
            return;
        }
    }
}

void function6() {
    system("cls");
    printf("开始执行...\n");
    showAll(0);
    printf("请输入要销毁的进程编号:");
    int id;
    scanf("%d", &id);
    for (auto it = runningQueen.begin(); it != runningQueen.end(); it++) {
        if (it->pid == id) {
            destroyProcess(*it);
            runningQueen.erase(it);
            break;
        }
    }
    for (auto it = readyQueen.begin(); it != readyQueen.end(); it++) {
        if (it->pid == id) {
            destroyProcess(*it);
            readyQueen.erase(it);
            break;
        }
    }
    for (auto it = blockQueen.begin(); it != blockQueen.end(); it++) {
        if (it->pid == id) {
            destroyProcess(*it);
            blockQueen.erase(it);
            break;
        }
    }  
    
    printf("执行结束, 按任意键退出...");
    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            startMenu();
            return;
        }
    }
}

void startMenu() {
    system("cls");
    printf("\n\n\n\n\n\n\n");
    printf("                                            进程控制和内存模拟程序\n");
    printf("                                   =======================================\n");
    printf("                                   ==  1     设置空闲内存分区           ==\n");
    printf("                                   ==  2     新建进程                   ==\n");
    printf("                                   ==  3     阻塞队列全部切换到运行状态 ==\n");
    printf("                                   ==  4     进程运行模拟               ==\n");
    printf("                                   ==  5     显示全部进程状态           ==\n");
    printf("                                   ==  6     销毁某个进程               ==\n");
    printf("                                   ==  其他  退出                       ==\n");
    printf("                                   =======================================\n");
    printf("                                                  请选择操作:");
    int op; scanf("%d", &op);
    if (op == 1) {
        function1();
    }
    else if (op == 2) {
        function2();
    }
    else if (op == 3) {
        function3();
    }
    else if (op == 4) {
        function4();
    }
    else if (op == 5) {
        function5();
    }
    else if (op == 6) {
        function6();
    }
    else exit(0);
}