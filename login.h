#include "dataStructure.h"
using namespace std;
//structur
string dataOneRow;

void insert(loginList* ls,string fname,string lname,string email ,string password){
	Node *e;
	e = new Node;
	e->l.email=email;
	e->l.fname=fname;
	e->l.lname=lname;
	e->l.password=password;
	if(ls->n==0){
		ls->head=e;
		ls->tail=e;
	}else{
		ls->tail->next=e;
		ls->tail=e;
	}
	ls->n=ls->n +1;
}
//input
void signUp(string *fname,string *lname,string *email,string *password,string *rpassword){

	cout<<"Please input you information :\n";
	cout<<"FIRST NAME :";cin>>*fname;
	cout<<"LAST NAME:";cin>>*lname;
	cout<<"EMAIL :";cin>>*email;
	cout<<"PASSWORD :";cin>>*password;
	again:
	cout<<"REENTER PASSWORD :";cin>>*rpassword;
	if(*rpassword!=*password){
		cout<<"WRONG PASSWORD !Please input again\n";
		goto again;
	}
}
int checkExistEmailInFile(string email){
    fstream emailf;
    emailf.open("email.txt",ios::in);
    while(emailf.eof()!=true){
        dataOneRow="";
        getline(emailf, dataOneRow);
        if(!dataOneRow.empty()&& email==dataOneRow){
            emailf.close();
            return 0; //email exsit
        }
    }
    emailf.close();
    return 1;
}
int checkExistpassword(string password){
    fstream passf;
    passf.open("password.txt",ios::in);
    while(passf.eof()!=true){
        dataOneRow="";
        getline(passf, dataOneRow);
        if(!dataOneRow.empty()&& password==dataOneRow){
            passf.close();
            return 0; //email exsit
        }
    }
    passf.close();
    return 1;
}
void Login(){
    string email,password;
    cout<<"Enter email: ";
		fflush(stdin); getline(cin, email);
    cout<<"Enter password:"; 
		fflush(stdin); getline (cin, password);
    if(checkExistEmailInFile(email)==0 && checkExistpassword(password)==0){
        cout<<"Welcome back name"<<endl;
    }else if(checkExistEmailInFile(email)==1 && checkExistpassword(password)==1){
        cout<<"Incorrect Password"<<endl;
    }
}
void displayLoginInfo(loginList* ls){
	Node *tm;
	tm=ls->head;
	while(tm!=NULL){
		cout<<tm->l.fname<<" "<<tm->l.lname<<endl;
		cout<<tm->l.email<<endl;
		cout<<tm->l.password;
		tm=tm->next;
	}
}

void writeNameEmail(loginList* ls){
	Node *tem;
	Node *te;
	string t;
	tem=new Node;
	te=new Node;
	tem=ls->head;
	te=tem->next;
	fstream file;
	file.open("name.txt",ios::app);
	while(tem->next!=NULL){
		te=tem->next;
		while(tem->next){
			if(tem->l.fname>te->l.fname){
				t=tem->l.fname;
				tem->l.fname=te->l.fname;
				te->l.fname=t;
			}
			tem=tem->next;
		}
	  te=te->next;
	}
		while(tem!=NULL){
			file<<setw(10)<<tem->l.fname<<setw(5)<<tem->l.lname<<endl;
			tem=tem->next;
		}
    file.close();
}
void writeEmail(loginList *ls){
	Node *te;
	te=ls->head;
	fstream emailf;
	emailf.open("email.txt",ios::app);
	while(te!=NULL){
		emailf<<te->l.email;
		te=te->next;
	}
	emailf<<endl;
    emailf.close();

}
void writePass(loginList *ls){
	Node *te;
	te=ls->head;
	fstream passf;
	passf.open("password.txt",ios::app);
	while(te!=NULL){
		passf<<te->l.password;;
		te=te->next;
	}
	passf<<endl;
	passf.close();
}