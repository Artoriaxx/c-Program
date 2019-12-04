#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
const int N=1001000;
char s[N];
int rec_whole[N];
int rec_part[N];
int replace[N];
int is_letter(char c){
	if(('0'<=c&&c<='9') || ('a'<=c&&c<='z') || ('A'<=c&&c<='Z') )return 1;
	return 0;
}
int equal(char a,char b,int dif_up_or_low){
	if(dif_up_or_low){
		return (a==b);
	}
	else{
		if('A'<=a&&a<='Z')a+=('a'-'A');
		if('A'<=b&&b<='Z')b+=('a'-'A');
		return (a==b);
	}
}
int get_numof_words(int n){
	int num_word=0;
	for(int i=1;i<n;i++){
		if(is_letter(s[i])&&!is_letter(s[i-1]) ){
			num_word++;
		}
	}
	return num_word;
}
int get_max(int a,int b){
	if(a>b)return a;
	return b;
}
int get_numof_pun(int n){
	int cnt=0;
	for(int i=0;i<n;i++){
		int pun_cur=0;
		while(!is_letter(s[i])){
			if(s[i]!=' '&&s[i]!='\n'){
				pun_cur=get_max(pun_cur,1);//an interval can only have at most 1 punctuation.
			}
			i++;
		}
		cnt+=pun_cur;
		//if( is_letter(s[i]) )i--;
	}
	return cnt;
}
int get_numof_spaces(int n){
	int cnt=0;
	for(int i=1;i<n;i++){
		if(s[i]==' ')cnt++;
	}
	return cnt;
}
int get_part_match(int n,char *key_word,int keylen,int dif_up_or_low){
	int cnt=0;
	for(int i=1;i<=n-keylen;i++){
		int can_match=1;
		for(int j=i;j<=i+keylen-1;j++){
			if( !equal(s[j],key_word[j-i],dif_up_or_low) ){
				can_match=0;
				break;
			}
		}
		if(can_match==1){
			cnt++;
			rec_part[cnt]=i;
		}
	}
	return cnt;
}
int get_whole_match(int n,char *key_word,int keylen,int dif_up_or_low){
	int cnt=0;
	for(int i=1;i<=n-keylen;i++){
		int can_match=1;
		if(is_letter(s[i])&&!is_letter(s[i-1])){
			for(int j=i;j<=i+keylen-1;j++){
				if( !equal(s[j],key_word[j-i],dif_up_or_low) ){
					can_match=0;
					break;
				}
			}
			if(can_match==1&&!is_letter(s[i+keylen]) ){
				cnt++;
				rec_whole[cnt]=i;
			}
		}
	}
	return cnt;
}
void get_after_replace_whole(int &n,int numrep,char *obj,int lenobj,int lenold){
	if(lenobj>lenold){
		int cha=lenobj-lenold;
		for(int i=1;i<=numrep;i++){
			int beg=rec_whole[replace[i]]+(i-1)*cha;
			int end=beg+lenobj-1;
			n=n+cha;
			for(int j=n-1;j>=beg+lenobj;j--){
				s[j]=s[j-cha];
			}
			for(int j=beg;j<=end;j++){
				s[j]=obj[j-beg];
			}
		}
	}
	else{
		int cha=lenold-lenobj;
		for(int i=1;i<=numrep;i++){
			int beg=rec_whole[replace[i]]-(i-1)*cha;
			int end=beg+lenobj-1;
			n=n-cha;
			for(int j=end+1;j<n;j++){
				s[j]=s[j+cha];
			}
			for(int j=beg;j<=end;j++){
				s[j]=obj[j-beg];
			}
		}
	}
}
void get_after_replace_part(int &n,int numrep,char *obj,int lenobj,int lenold){
	if(lenobj>lenold){
		int cha=lenobj-lenold;
		for(int i=1;i<=numrep;i++){
			int beg=rec_part[replace[i]]+(i-1)*cha;
			int end=beg+lenobj-1;
			n=n+cha;
			for(int j=n-1;j>=beg+lenobj;j--){
				s[j]=s[j-cha];
			}
			for(int j=beg;j<=end;j++){
				s[j]=obj[j-beg];
			}
		}
	}
	else{
		int cha=lenold-lenobj;
		for(int i=1;i<=numrep;i++){
			int beg=rec_part[replace[i]]-(i-1)*cha;
			int end=beg+lenobj-1;
			n=n-cha;
			for(int j=end+1;j<n;j++){
				s[j]=s[j+cha];
			}
			for(int j=beg;j<=end;j++){
				s[j]=obj[j-beg];
			}
		}
	}
}
void save_as(){
	char name[110];
	printf("type the path and name(for example,d:/love_you.txt,with no ' ') of file you want to save as:\n");
	scanf("%s",name);
	int nnn=strlen(s);
	FILE *pfile;
	pfile=fopen(name,"w");
	if(pfile == NULL)//判断指针是否为空
   	{
   	    printf("can not open the file");
   	    fclose(pfile);
   	    return;
   	}
   	fwrite(s+1,1,nnn,pfile);
   	fclose(pfile);
}
void open_file(){
	char name[110];
	printf("type the name(for example,d:/love_you.txt,with no ' ') of file you want to open:\n");
	FILE *pfile;
	scanf("%s",name);
	pfile=fopen(name,"r");
	if(pfile==NULL){
		perror("Error opening file");
		return;
	}
	else {
		fgets(s,10010001,pfile);
		printf("%s\n",s);
	}
	fclose(pfile);
}
void print_hint(){
	printf("Want do you want to do next with the text?\n");
	printf("type:\n");
	printf("1 ------------ Count number of words(including numbers)\n");
	printf("2 ------------ Count number of punctuations\n");
	printf("3 ------------ Count number of spaces\n");
	printf("4 ------------ Count number of key words(and find their positions)\n");
	printf("5 ------------ save as\n");
	printf("6 ------------ exit this stupid system...\n");
}
int main(){
	int n=0;
	printf("welcom to the system!\n");
	printf("you can type:\n");
	printf("1 ------------ type your new text\n");
	printf("2 ------------ open a existed text\n");
	int typebegin;
	scanf("%d",&typebegin);
	getchar();
	int need_save=0;
	if(typebegin==1){
		while(1){
			char c=getchar();
			if(c=='\n')break;
			s[n++]=c;
		}
		need_save=1;
	}

	else{
		open_file();
		n=strlen(s);
	}

	for(int i=n;i>=1;i--){
		s[i]=s[i-1];
	}
	s[0]=' ';
	n++;
	int operr;
	
	while(1){
		printf("Do you want to see the operating menu?\n");
		int see=0;
		printf("1 ------------ I knew it,just begin!\n");
		printf("2 ------------ OK I will see it...\n");
		scanf("%d",&see);
		if(see==2)
			print_hint();
		scanf("%d",&operr);
		if(operr==1){
			int ans=get_numof_words(n);
			printf("%d\n",ans);
		}
		else if(operr==2){
			int ans=get_numof_pun(n);
			printf("%d\n",ans);
		}
		else if(operr==3){
			int ans=get_numof_spaces(n);
			printf("%d\n",ans);
		}
		else if(operr==4){
			printf("int this section you may find first and than replace if you want\n");
			printf("type your key_word:\n");
			char key_word[110];
			scanf("%s",key_word);
			printf("You want to:\n");
			printf("1 ------------ match whole word\n");
			printf("2 ------------ match word with this substring\n");
			int opp;
			scanf("%d",&opp);
			if(opp==1){
				printf("1 ------------ do not ignore upper or lower case\n");
				printf("0 ------------ do ignore upper or lower case\n");
				int dif;
				scanf("%d",&dif);
				int ans=get_whole_match(n,key_word,strlen(key_word),dif);
				printf("%d results found\n",ans);
				for(int i=1;i<=ans;i++){
					printf("the %dth result is from %d to %d\n",i,rec_whole[i],rec_whole[i]+strlen(key_word)-1);//begin of the result in rec_whole
				}
				printf("type how many results do you want to replace:\n");
				int numrep;
				scanf("%d",&numrep);
				if(numrep==0)continue;
				need_save=1;
				if(numrep==ans){
					for(int i=1;i<=ans;i++)replace[i]=i;
				}
				else{	
					printf("which one(s) of the results do you want to repalce by a same word?\n");
					for(int i=1;i<=numrep;i++){
						scanf("%d",replace+i);
					}
				}
			
				printf("you want to replace by?\n");
				char obj[110];
				scanf("%s",obj);
				int lenobj=strlen(obj);
				get_after_replace_whole(n,numrep,obj,lenobj,strlen(key_word));
				for(int i=1;i<n;i++){
					printf("%c",s[i]);
				}
				printf("\n");
				printf("done...\n\n\n");
			}
			else if(opp==2){
				
				printf("0 ------------ do ignore upper or lower case\n");
				printf("1 ------------ do not ignore upper or lower case\n");
				int dif;
				scanf("%d",&dif);
				int ans=get_part_match(n,key_word,strlen(key_word),dif);
				printf("%d results found\n",ans);
				for(int i=1;i<=ans;i++){
					printf("the %dth result is from %d to %d\n",i,rec_part[i],rec_part[i]+strlen(key_word)-1);
				}
				printf("done\n");
				printf("type how many results do you want to replace:\n");
				int numrep;
				scanf("%d",&numrep);
				if(numrep==0)continue;
				need_save=1;
				if(numrep==ans){
					for(int i=1;i<=ans;i++)replace[i]=i;
				}
				else{
					printf("which one(s) of the results do you want to repalce by a same word?\n");
					for(int i=1;i<=numrep;i++){
						scanf("%d",replace+i);
					}
				}
				printf("you want to replace by?\n");
				char obj[110];
				scanf("%s",obj);
				int lenobj=strlen(obj);
				get_after_replace_part(n,numrep,obj,lenobj,strlen(key_word));
				for(int i=1;i<n;i++){
					printf("%c",s[i]);
				}
				printf("\n");
				printf("done...\n\n\n");
			}
			
		}
		else if(operr==5){
			need_save=0;
			save_as();
			printf("done...\n\n");
		}
		else if(operr==6){
			if(need_save==1){
				printf("You didn't save your changes!Are you sure you want to exit?\n");
				printf("1 ------------ Don't exit\n");
				printf("2 ------------ Exit right now\n");
				int ex;
				scanf("%d",&ex);
				if(ex==1)continue;
				else break;
			}
			break;
		}
	}
	return 0;
}