#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>
#include<iostream.h>
#include<math.h>
#include<fstream.h>
#include<string.h>
#include<graphics.h>
class patient
{
    private:
	      char name[30],phone[12],dob[12],bg[5],address[100],department[20],date[12];
	      int age,pid;
    public:
	      void addpatient(int i);
	      int returnid()
	      {
		   return pid;
	      }
	      void outputdata();
	      void dischargepatient();
	      void outdata();
    protected:
};
class patientid
{
    private:
	      int id;
    public:
	      int returnid()
	      {
		   return id;
	      }
	      void add(int i)
	      {
		   id=i;
	      }
};
class department
{
    private:
	      char name[30],type[40],date[12],timing[15];
	      int did,roomno;
    public:
	      void adddept(int i);
	      int returndid()
	      {
		   return did;
	      }
	      void outputdept(int y);
	      void deletedept();
	      void outdata();
    protected:
};
class deptid
{
    private:
	      int id;
    public:
	      int returnid()
	      {
		   return id;
	      }
	      void add(int i)
	      {
		   id=i;
	      }
};
class doctor
{
    private:
	      char name[30],department[40],timing[15],phone[12];
	      int docid,roomno;
    public:
	      void adddoct(int i);
	      int returndocid()
	      {
		   return docid;
	      }
	      void outputdoct(int y);
	      void deletedoct();
	      void outdata();
    protected:
};
class doctid
{
    private:
	      int id;
    public:
	      int returnid()
	      {
		   return id;
	      }
	      void add(int i)
	      {
		   id=i;
	      }
};
int iddoc()
{
     doctid id;
     int rec,i;
     fstream finout;
     finout.open("docid1.txt",ios::in);
     finout.seekg(0,ios::end);
     rec=finout.tellg()/sizeof(id);
     finout.seekg(0,ios::beg);
     if(rec==0)
     {
	 i=1;
     }
     else
     {
	 finout.read((char *)&id,sizeof(id));
	 i=id.returnid();
     }
     finout.close();
     return i;
}
int calcrecorddoctor()   // it calculate total records
{
    doctor d1;
    fstream finout;
    int rec;
    finout.open("doc1.txt",ios::in);
    finout.seekg(0,ios::end);
    rec=finout.tellg()/sizeof(d1);
    finout.close();
    return rec;
}
int idd()
{
     deptid id;
     int rec,i;
     fstream finout;
     finout.open("did1.txt",ios::in);
     finout.seekg(0,ios::end);
     rec=finout.tellg()/sizeof(id);
     finout.seekg(0,ios::beg);
     if(rec==0)
     {
	 i=1;
     }
     else
     {
	 finout.read((char *)&id,sizeof(id));
	 i=id.returnid();
     }
     finout.close();
     return i;
}
int calcrecorddept()   // it calculate total records
{
    department d1;
    fstream finout;
    int rec;
    finout.open("dept1.txt",ios::in);
    finout.seekg(0,ios::end);
    rec=finout.tellg()/sizeof(d1);
    finout.close();
    return rec;
}
int idp()
{
     patientid id;
     int rec,i;
     fstream finout;
     finout.open("id1.txt",ios::in);
     finout.seekg(0,ios::end);
     rec=finout.tellg()/sizeof(id);
     finout.seekg(0,ios::beg);
     if(rec==0)
     {
	 i=1;
     }
     else
     {
	 finout.read((char *)&id,sizeof(id));
	 i=id.returnid();
     }
     finout.close();
     return i;
}
int calcrecordpatient()   // it calculate total records
{
    patient p1;
    fstream finout;
    int rec;
    finout.open("p1.txt",ios::in);
    finout.seekg(0,ios::end);
    rec=finout.tellg()/sizeof(p1);
    finout.close();
    return rec;
}
void page()    // drawing of page boundry
{
    for(int i=1;i<=79;i++)
    {
	 gotoxy(i,1);
	 cprintf("%c",205);
    }
    for(int k=1;k<=79;k++)
    {
	 gotoxy(k,25);
	 cprintf("%c",205);
    }
    gotoxy(1,1);
    cprintf("%c",201);
    gotoxy(79,1);
    cprintf("%c",187);
     for(int j=2;j<=25;j++)
    {
	 gotoxy(1,j);
	 cprintf("%c",186);
    }
    for(int l=2;l<=25;l++)
    {
	 gotoxy(79,l);
	 cprintf("%c",186);
    }
    gotoxy(1,25);
    cprintf("%c",200);
    gotoxy(79,25);
    cprintf("%c",188);
    gotoxy(33,2);
    cprintf(" ABC Hospital ");
    gotoxy(25,3);
    cprintf(" Najafgarh ,New Delhi- 110043");
}
void patient::outdata()
{

     gotoxy(12,11);
     cprintf("  Name of Patient                  -         %s",name);
     gotoxy(12,12);
     cprintf("  Phone No.                        -         %s",phone);
     gotoxy(12,13);
     cprintf("  Address                          -         %s",address);
     gotoxy(12,14);
     cprintf("  Age                              -         %d",age);
     gotoxy(12,15);
     cprintf("  Date of Birth(dd/mm/yyyy)        -         %s",dob);
     gotoxy(12,16);
     cprintf("  Blood Group                      -         %s",bg);
     gotoxy(12,17);
     cprintf("  Date (dd/mm/yyyy)                -         %s",date);
     gotoxy(12,18);
     cprintf("  Department                       -         %s",department);
}
void patient::dischargepatient()
{
    int id,rec,flag=0;
    char ch;
    fstream finout,finout1;
    patient p1;
     clrscr();
     page();
     for(int j=1;j<=79;j++)
     {
	 gotoxy(j,5);
	 cprintf("%c",196);
     }
     gotoxy(1,5);
     cprintf("%c",199);
     gotoxy(79,5);
     cprintf("%c",182);
     gotoxy(29,6);
     cprintf(" Patient Discharge ");
     for(int k=1;k<=79;k++)
     {
	 gotoxy(k,7);
	 cprintf("%c",196);
     }
     gotoxy(1,7);
     cprintf("%c",199);
     gotoxy(79,7);
     cprintf("%c",182);
     for(k=8;k<=24;k++)
     {
	 gotoxy(10,k);
	 cprintf("%c",179);
     }
     gotoxy(10,7);
     cprintf("%c",194);
     gotoxy(10,25);
     cprintf("%c",207);
     for(k=8;k<=24;k++)
     {
	 gotoxy(70,k);
	 cprintf("%c",179);
     }
     gotoxy(70,7);
     cprintf("%c",194);
     gotoxy(70,25);
     cprintf("%c",207);
     gotoxy(12,10);
     cprintf("  Patient Id                       -         ");
     cin>>id;
     rec=calcrecordpatient();
     finout.open("p1.txt",ios::in);
     finout1.open("temp.txt",ios::out);
     for(int i=1;i<=rec;i++)
     {
	 finout.read((char *)&p1,sizeof(p1));
	 if(id==p1.returnid())
	 {
	      p1.outdata();
	      flag=1;
	      break;
	 }
     }
     if(flag==0)
     {
	 gotoxy(25,22);
	 cprintf("Patient not Found!!");
	 getch();
	 return;
     }
     finout.close();
     finout.open("p1.txt",ios::in);
     gotoxy(25,20);
     cprintf("Do tou want to Delete Record(y/n)");
     cin>>ch;
     if(ch=='y')
     {
       for(int i=1;i<=rec;i++)
       {
	   finout.read((char *)&p1,sizeof(p1));
	   if(p1.returnid()!=id)
	   {
	      finout1.write((char *)&p1,sizeof(p1));
	   }
       }
       gotoxy(25,22);
       cprintf("Patient Dsicharged");
       finout.close();
       finout1.close();
       remove("p1.txt");
       rename("temp.txt","p1.txt");
       return;
     }
     finout.close();
     finout1.close();
     getch();
}
void patient::addpatient(int i)
{
     clrscr();
     page();
     for(int j=1;j<=79;j++)
     {
	 gotoxy(j,5);
	 cprintf("%c",196);
     }
     gotoxy(1,5);
     cprintf("%c",199);
     gotoxy(79,5);
     cprintf("%c",182);
     gotoxy(30,6);
     cprintf(" Patient Details ");
     for(int k=1;k<=79;k++)
     {
	 gotoxy(k,7);
	 cprintf("%c",196);
     }
     gotoxy(1,7);
     cprintf("%c",199);
     gotoxy(79,7);
     cprintf("%c",182);
     for(k=8;k<=24;k++)
     {
	 gotoxy(10,k);
	 cprintf("%c",179);
     }
     gotoxy(10,7);
     cprintf("%c",194);
     gotoxy(10,25);
     cprintf("%c",207);
     for(k=8;k<=24;k++)
     {
	 gotoxy(70,k);
	 cprintf("%c",179);
     }
     gotoxy(70,7);
     cprintf("%c",194);
     gotoxy(70,25);
     cprintf("%c",207);
     pid=i;
     gotoxy(12,12);
     cprintf("  Enter name of Patient            -         ");
     cin>>name;
     gotoxy(12,13);
     cprintf("  Enter Phone No.                  -         ");
     cin>>phone;
     gotoxy(12,14);
     cprintf("  Enter Address                    -         ");
     cin>>address;
     gotoxy(12,15);
     cprintf("  Enter Age                        -         ");
     cin>>age;
     gotoxy(12,16);
     cprintf("  Enter D.O.B(dd/mm/yyyy)          -         ");
     cin>>dob;
     gotoxy(12,17);
     cprintf("  Enter Blood Group                -         ");
     cin>>bg;
     gotoxy(12,18);
     cprintf("  Patient Id                       -         %d",pid);
     gotoxy(12,19);
     cprintf("  Enter Date (dd/mm/yyyy)          -         ");
     cin>>date;
     gotoxy(12,20);
     cprintf("  Department                       -         ");
     cin>>department;
}
void patient::outputdata()
{
     clrscr();
     page();
     for(int j=1;j<=79;j++)
     {
	 gotoxy(j,5);
	 cprintf("%c",196);
     }
     gotoxy(1,5);
     cprintf("%c",199);
     gotoxy(79,5);
     cprintf("%c",182);
     gotoxy(30,6);
     cprintf(" Patient Details ");
     for(int k=1;k<=79;k++)
     {
	 gotoxy(k,7);
	 cprintf("%c",196);
     }
     gotoxy(1,7);
     cprintf("%c",199);
     gotoxy(79,7);
     cprintf("%c",182);
     for(k=8;k<=24;k++)
     {
	 gotoxy(10,k);
	 cprintf("%c",179);
     }
     gotoxy(10,7);
     cprintf("%c",194);
     gotoxy(10,25);
     cprintf("%c",207);
     for(k=8;k<=24;k++)
     {
	 gotoxy(70,k);
	 cprintf("%c",179);
     }
     gotoxy(70,7);
     cprintf("%c",194);
     gotoxy(70,25);
     cprintf("%c",207);
     gotoxy(12,12);
     cprintf("  Patient Id                       -         %d",pid);
     gotoxy(12,13);
     cprintf("  Name of Patient                  -         %s",name);
     gotoxy(12,14);
     cprintf("  Phone No.                        -         %s",phone);
     gotoxy(12,15);
     cprintf("  Address                          -         %s",address);
     gotoxy(12,16);
     cprintf("  Age                              -         %d",age);
     gotoxy(12,17);
     cprintf("  Date of Birth(dd/mm/yyyy)        -         %s",dob);
     gotoxy(12,18);
     cprintf("  Blood Group                      -         %s",bg);
     gotoxy(12,19);
     cprintf("  Date (dd/mm/yyyy)                -         %s",date);
     gotoxy(12,20);
     cprintf("  Department                       -         %s",department);
}
void patientm()
{
    char ch1;
    int rec,id;
    patient p1;
    fstream finout;
    do
    {
	 clrscr();
	 page();
	 for(int j=1;j<=79;j++)
	 {
	      gotoxy(j,5);
	      cprintf("%c",196);
	 }
	 gotoxy(1,5);
	 cprintf("%c",199);
	 gotoxy(79,5);
	 cprintf("%c",182);
	 gotoxy(32,6);
	 cprintf("PATIENT MENU ");
	 for(int k=1;k<=79;k++)
	 {
	      gotoxy(k,7);
	      cprintf("%c",196);
	 }
	 gotoxy(1,7);
	 cprintf("%c",199);
	 gotoxy(79,7);
	 cprintf("%c",182);
	 for(k=8;k<=24;k++)
	 {
	      gotoxy(20,k);
	      cprintf("%c",179);
	 }
	 gotoxy(20,7);
	 cprintf("%c",194);
	 gotoxy(20,25);
	 cprintf("%c",207);
	 for(k=8;k<=24;k++)
	 {
	      gotoxy(60,k);
	      cprintf("%c",179);
	 }
	 gotoxy(60,7);
	 cprintf("%c",194);
	 gotoxy(60,25);
	 cprintf("%c",207);
	 gotoxy(29,10);
	 cprintf("1. Add Patient ");
	 gotoxy(29,12);
	 cprintf("2. Patient List ");
	 gotoxy(29,14);
	 cprintf("3. Discharge Patient");
	 gotoxy(29,16);
	 cprintf("4. Main Menu");
	 gotoxy(29,22);
	 cprintf("Enter your choice : ");
	 ch1=getche();
	 switch(ch1)
	 {
	      case '1':
			clrscr();
			id=idp();
			finout.open("p1.txt",ios::app);
			p1.addpatient(id);
			finout.write((char *)&p1,sizeof(p1));
			finout.close();
			id=id+1;
			patientid r1;
			finout.open("id1.txt",ios::out);
			r1.add(id);
			finout.write((char *)&r1,sizeof(r1));
			finout.close();
			break;
	      case '2':
			finout.open("p1.txt",ios::in);
			rec=calcrecordpatient();
			for(int i=1;i<=rec;i++)
			{
			     finout.read((char *)&p1,sizeof(p1));
			     p1.outputdata();
			     getch();
			     clrscr();
			}
			finout.close();
			break;
	      case '3':
			p1.dischargepatient();
			break;
	      case '4':
			break;
	 }
    }while(ch1!='4');
}
void page2()
{
    clrscr();
     page();
     for(int j=1;j<=79;j++)
     {
	 gotoxy(j,5);
	 cprintf("%c",196);
     }
     gotoxy(1,5);
     cprintf("%c",199);
     gotoxy(79,5);
     cprintf("%c",182);
     gotoxy(30,6);
     cprintf(" DEPARTMENT DETAILS ");
     for(int k=1;k<=79;k++)
     {
	 gotoxy(k,7);
	 cprintf("%c",196);
     }
     gotoxy(1,7);
     cprintf("%c",199);
     gotoxy(79,7);
     cprintf("%c",182);
     gotoxy(3,8);
     cprintf("  ID");
     for(k=8;k<=24;k++)
     {
	 gotoxy(10,k);
	 cprintf("%c",179);
     }
     gotoxy(10,7);
     cprintf("%c",194);
     gotoxy(10,25);
     cprintf("%c",207);
     gotoxy(15,8);
     cprintf("   NAME");
     for(k=8;k<=24;k++)
     {
	 gotoxy(30,k);
	 cprintf("%c",179);
     }
     gotoxy(30,7);
     cprintf("%c",194);
     gotoxy(30,25);
     cprintf("%c",207);
     gotoxy(35,8);
     cprintf("   TYPE");
     for(k=8;k<=24;k++)
     {
	 gotoxy(50,k);
	 cprintf("%c",179);
     }
     gotoxy(50,7);
     cprintf("%c",194);
     gotoxy(50,25);
     cprintf("%c",207);
     gotoxy(54,8);
     cprintf(" TIMING");
     for(k=8;k<=24;k++)
     {
	 gotoxy(65,k);
	 cprintf("%c",179);
     }
     gotoxy(65,7);
     cprintf("%c",194);
     gotoxy(65,25);
     cprintf("%c",207);
     gotoxy(69,8);
     cprintf("ROOM NO.");
     for(k=1;k<=79;k++)
     {
	 gotoxy(k,9);
	 cprintf("%c",196);
     }
     gotoxy(1,9);
     cprintf("%c",199);
     gotoxy(79,9);
     cprintf("%c",182);
     gotoxy(10,9);
     cprintf("%c",197);
     gotoxy(30,9);
     cprintf("%c",197);
     gotoxy(50,9);
     cprintf("%c",197);
     gotoxy(65,9);
     cprintf("%c",197);
}
void department::outputdept(int y)
{
	 gotoxy(4,y);
	 cprintf("%d",did);
	 gotoxy(15,y);
	 cprintf("%s",name);
	 gotoxy(35,y);
	 cprintf("%s",type);
	 gotoxy(55,y);
	 cprintf("%s",timing);
	 gotoxy(70,y);
	 cprintf("%d",roomno);
}
void outd()
{
     clrscr();
     int rec=calcrecorddept();
     page2();
     fstream finout;
     department d1;
     int y=10;
     finout.open("dept1.txt",ios::in);
     for(int i=1;i<=rec;i++)
     {
	 finout.read((char *)&d1,sizeof(d1));
	 d1.outputdept(y);
	 y++;
	 if(y==25)
	 {
	      getch();
	      clrscr();
	      page2();
	      y=10;
	 }
     }
     finout.close();
     getch();
}
void department::adddept(int i)
{
     clrscr();
     page();
     for(int j=1;j<=79;j++)
     {
	 gotoxy(j,5);
	 cprintf("%c",196);
     }
     gotoxy(1,5);
     cprintf("%c",199);
     gotoxy(79,5);
     cprintf("%c",182);
     gotoxy(30,6);
     cprintf(" ADD DEPARTMENT ");
     for(int k=1;k<=79;k++)
     {
	 gotoxy(k,7);
	 cprintf("%c",196);
     }
     gotoxy(1,7);
     cprintf("%c",199);
     gotoxy(79,7);
     cprintf("%c",182);
     for(k=8;k<=24;k++)
     {
	 gotoxy(10,k);
	 cprintf("%c",179);
     }
     gotoxy(10,7);
     cprintf("%c",194);
     gotoxy(10,25);
     cprintf("%c",207);
     for(k=8;k<=24;k++)
     {
	 gotoxy(70,k);
	 cprintf("%c",179);
     }
     gotoxy(70,7);
     cprintf("%c",194);
     gotoxy(70,25);
     cprintf("%c",207);
     did=i;
     gotoxy(12,10);
     cprintf("  Enter name of Department        -          ");
     cin>>name;
     gotoxy(12,12);
     cprintf("  Enter type of Department        -          ");
     cin>>type;
     gotoxy(12,14);
     cprintf("  Enter Date(dd/mm/yyyy)          -          ");
     cin>>date;
     gotoxy(12,16);
     cprintf("  Enter Timings                   -          ");
     cin>>timing;
     gotoxy(12,18);
     cprintf("  Enter Room No.                  -          ");
     cin>>roomno;
     gotoxy(12,20);
     cprintf("  Department Id                   -          %d",did);
     getch();
}
void department::outdata()
{
     gotoxy(12,13);
     cprintf("  Name of Department              -          %s",name);
     gotoxy(12,14);
     cprintf("  Type of Department              -          %s",type);
     gotoxy(12,15);
     cprintf("  Date(dd/mm/yyyy)                -          %s",date);
     gotoxy(12,16);
     cprintf("  Timings                         -          %s",timing);
     gotoxy(12,17);
     cprintf("  Enter Room No.                  -          %d",roomno);
}
void department::deletedept()
{
    char ch;
    int id,rec,flag=0;
    fstream finout,finout1;
    department d1;
     clrscr();
     page();
     for(int j=1;j<=79;j++)
     {
	 gotoxy(j,5);
	 cprintf("%c",196);
     }
     gotoxy(1,5);
     cprintf("%c",199);
     gotoxy(79,5);
     cprintf("%c",182);
     gotoxy(29,6);
     cprintf(" Delete Department ");
     for(int k=1;k<=79;k++)
     {
	 gotoxy(k,7);
	 cprintf("%c",196);
     }
     gotoxy(1,7);
     cprintf("%c",199);
     gotoxy(79,7);
     cprintf("%c",182);
     for(k=8;k<=24;k++)
     {
	 gotoxy(10,k);
	 cprintf("%c",179);
     }
     gotoxy(10,7);
     cprintf("%c",194);
     gotoxy(10,25);
     cprintf("%c",207);
     for(k=8;k<=24;k++)
     {
	 gotoxy(70,k);
	 cprintf("%c",179);
     }
     gotoxy(70,7);
     cprintf("%c",194);
     gotoxy(70,25);
     cprintf("%c",207);
     gotoxy(12,12);
     cprintf("  Enter Department ID             -          ");
     cin>>id;
     rec=calcrecorddept();
     finout.open("dept1.txt",ios::in);
     finout1.open("temp.txt",ios::out);
     for(int i=1;i<=rec;i++)
     {
	 finout.read((char *)&d1,sizeof(d1));
	 if(d1.returndid()==id)
	 {
	      d1.outdata();
	      flag=1;
	      break;
	 }
     }
     if(flag==0)
     {
	 gotoxy(25,22);
	 cprintf("Department not Found!!");
	 getch();
	 return;
     }
     finout.close();
     finout.open("dept1.txt",ios::in);
     gotoxy(25,20);
     cprintf("Do you want to Delete Department(y/n) - ");
     cin>>ch;
     if(ch=='y')
     {
       for(int i=1;i<=rec;i++)
       {
	   finout.read((char *)&d1,sizeof(d1));
	   if(d1.returndid()!=id)
	   {
	      finout1.write((char *)&d1,sizeof(d1));
	   }
       }
       gotoxy(25,22);
       cprintf("Department Deleted");
       finout.close();
       finout1.close();
       remove("dept1.txt");
       rename("temp.txt","dept1.txt");
       getch();
       return;
     }
     finout.close();
     finout1.close();
     getch();
}
void deptm()
{
    char ch1;
    int rec,id;
    department d1;
    fstream finout;
    do
    {
	 clrscr();
	 page();
	 for(int j=1;j<=79;j++)
	 {
	      gotoxy(j,5);
	      cprintf("%c",196);
	 }
	 gotoxy(1,5);
	 cprintf("%c",199);
	 gotoxy(79,5);
	 cprintf("%c",182);
	 gotoxy(32,6);
	 cprintf("DEPARTMENT MENU ");
	 for(int k=1;k<=79;k++)
	 {
	      gotoxy(k,7);
	      cprintf("%c",196);
	 }
	 gotoxy(1,7);
	 cprintf("%c",199);
	 gotoxy(79,7);
	 cprintf("%c",182);
	 for(k=8;k<=24;k++)
	 {
	      gotoxy(20,k);
	      cprintf("%c",179);
	 }
	 gotoxy(20,7);
	 cprintf("%c",194);
	 gotoxy(20,25);
	 cprintf("%c",207);
	 for(k=8;k<=24;k++)
	 {
	      gotoxy(60,k);
	      cprintf("%c",179);
	 }
	 gotoxy(60,7);
	 cprintf("%c",194);
	 gotoxy(60,25);
	 cprintf("%c",207);
	 gotoxy(29,10);
	 cprintf("1. Add Department");
	 gotoxy(29,12);
	 cprintf("2. Department List ");
	 gotoxy(29,14);
	 cprintf("3. Delete Department");
	 gotoxy(29,16);
	 cprintf("4. Main Menu");
	 gotoxy(29,22);
	 cprintf("Enter your choice : ");
	 ch1=getche();
	 switch(ch1)
	 {
	      case '1':
			clrscr();
			id=idd();
			finout.open("dept1.txt",ios::app);
			d1.adddept(id);
			finout.write((char *)&d1,sizeof(d1));
			finout.close();
			id=id+1;
			patientid r1;
			finout.open("did1.txt",ios::out);
			r1.add(id);
			finout.write((char *)&r1,sizeof(r1));
			finout.close();
			break;
	      case '2':
			outd();
			break;
	      case '3':
			d1.deletedept();
			break;
	      case '4':
			break;
	 }
    }while(ch1!='4');
}
void doctor::adddoct(int i)
{
     clrscr();
     page();
     for(int j=1;j<=79;j++)
     {
	 gotoxy(j,5);
	 cprintf("%c",196);
     }
     gotoxy(1,5);
     cprintf("%c",199);
     gotoxy(79,5);
     cprintf("%c",182);
     gotoxy(33,6);
     cprintf(" ADD DOCTOR ");
     for(int k=1;k<=79;k++)
     {
	 gotoxy(k,7);
	 cprintf("%c",196);
     }
     gotoxy(1,7);
     cprintf("%c",199);
     gotoxy(79,7);
     cprintf("%c",182);
     for(k=8;k<=24;k++)
     {
	 gotoxy(10,k);
	 cprintf("%c",179);
     }
     gotoxy(10,7);
     cprintf("%c",194);
     gotoxy(10,25);
     cprintf("%c",207);
     for(k=8;k<=24;k++)
     {
	 gotoxy(70,k);
	 cprintf("%c",179);
     }
     gotoxy(70,7);
     cprintf("%c",194);
     gotoxy(70,25);
     cprintf("%c",207);
     docid=i;
     gotoxy(12,12);
     cprintf("  Enter Name of Doctor            -          ");
     cin>>name;
     gotoxy(12,13);
     cprintf("  Enter Department                -          ");
     cin>>department;
     gotoxy(12,14);
     cprintf("  Enter Phone No.                 -          ");
     cin>>phone;
     gotoxy(12,15);
     cprintf("  Enter Timings                   -          ");
     cin>>timing;
     gotoxy(12,16);
     cprintf("  Enter Room No.                  -          ");
     cin>>roomno;
     gotoxy(12,17);
     cprintf("  Department Id                   -          %d",docid);
     getch();
}
void page3()
{
    clrscr();
     page();
     for(int j=1;j<=79;j++)
     {
	 gotoxy(j,5);
	 cprintf("%c",196);
     }
     gotoxy(1,5);
     cprintf("%c",199);
     gotoxy(79,5);
     cprintf("%c",182);
     gotoxy(33,6);
     cprintf(" DOCTOR DETAILS ");
     for(int k=1;k<=79;k++)
     {
	 gotoxy(k,7);
	 cprintf("%c",196);
     }
     gotoxy(1,7);
     cprintf("%c",199);
     gotoxy(79,7);
     cprintf("%c",182);
     gotoxy(3,8);
     cprintf("  ID");
     for(k=8;k<=24;k++)
     {
	 gotoxy(10,k);
	 cprintf("%c",179);
     }
     gotoxy(10,7);
     cprintf("%c",194);
     gotoxy(10,25);
     cprintf("%c",207);
     gotoxy(15,8);
     cprintf("   NAME");
     for(k=8;k<=24;k++)
     {
	 gotoxy(30,k);
	 cprintf("%c",179);
     }
     gotoxy(30,7);
     cprintf("%c",194);
     gotoxy(30,25);
     cprintf("%c",207);
     gotoxy(35,8);
     cprintf("DEPARTMENT");
     for(k=8;k<=24;k++)
     {
	 gotoxy(50,k);
	 cprintf("%c",179);
     }
     gotoxy(50,7);
     cprintf("%c",194);
     gotoxy(50,25);
     cprintf("%c",207);
     gotoxy(54,8);
     cprintf(" TIMING");
     for(k=8;k<=24;k++)
     {
	 gotoxy(65,k);
	 cprintf("%c",179);
     }
     gotoxy(65,7);
     cprintf("%c",194);
     gotoxy(65,25);
     cprintf("%c",207);
     gotoxy(69,8);
     cprintf("ROOM NO.");
     for(k=1;k<=79;k++)
     {
	 gotoxy(k,9);
	 cprintf("%c",196);
     }
     gotoxy(1,9);
     cprintf("%c",199);
     gotoxy(79,9);
     cprintf("%c",182);
     gotoxy(10,9);
     cprintf("%c",197);
     gotoxy(30,9);
     cprintf("%c",197);
     gotoxy(50,9);
     cprintf("%c",197);
     gotoxy(65,9);
     cprintf("%c",197);
}
void doctor::outputdoct(int y)
{
	 gotoxy(4,y);
	 cprintf("%d",docid);
	 gotoxy(15,y);
	 cprintf("%s",name);
	 gotoxy(35,y);
	 cprintf("%s",department);
	 gotoxy(55,y);
	 cprintf("%s",timing);
	 gotoxy(70,y);
	 cprintf("%d",roomno);

}
void outdoc()
{
     clrscr();
     int rec=calcrecorddoctor();
     page3();
     fstream finout;
     doctor d1;
     int y=10;
     finout.open("doc1.txt",ios::in);
     for(int i=1;i<=rec;i++)
     {
	 finout.read((char *)&d1,sizeof(d1));
	 d1.outputdoct(y);
	 y++;
	 if(y==25)
	 {
	      getch();
	      clrscr();
	      page2();
	      y=10;
	 }
     }
     finout.close();
     getch();
}
void doctor::outdata()
{
     gotoxy(12,13);
     cprintf("  Name of Doctor                  -          %s",name);
     gotoxy(12,14);
     cprintf("  Department                      -          %s",department);
     gotoxy(12,15);
     cprintf("  Phone No.                       -          %s",phone);
     gotoxy(12,16);
     cprintf("  Timings                         -          %s",timing);
     gotoxy(12,17);
     cprintf("  Room No.                        -          %d",roomno);
}
void doctor::deletedoct()
{
    char ch;
    int id,rec,flag=0;
    fstream finout,finout1;
    doctor p1;
     clrscr();
     page();
     for(int j=1;j<=79;j++)
     {
	 gotoxy(j,5);
	 cprintf("%c",196);
     }
     gotoxy(1,5);
     cprintf("%c",199);
     gotoxy(79,5);
     cprintf("%c",182);
     gotoxy(29,6);
     cprintf("DELETE DOCTOR");
     for(int k=1;k<=79;k++)
     {
	 gotoxy(k,7);
	 cprintf("%c",196);
     }
     gotoxy(1,7);
     cprintf("%c",199);
     gotoxy(79,7);
     cprintf("%c",182);
     for(k=8;k<=24;k++)
     {
	 gotoxy(10,k);
	 cprintf("%c",179);
     }
     gotoxy(10,7);
     cprintf("%c",194);
     gotoxy(10,25);
     cprintf("%c",207);
     for(k=8;k<=24;k++)
     {
	 gotoxy(70,k);
	 cprintf("%c",179);
     }
     gotoxy(70,7);
     cprintf("%c",194);
     gotoxy(70,25);
     cprintf("%c",207);
     gotoxy(12,12);
     cprintf("  Enter Doctor Id                 -         ");
     cin>>id;
     rec=calcrecorddoctor();
     finout.open("doc1.txt",ios::in);
     finout1.open("temp.txt",ios::out);
     for(int i=1;i<=rec;i++)
     {
	 finout.read((char *)&p1,sizeof(p1));
	 if(p1.returndocid()==id)
	 {
	      p1.outdata();
	      flag=1;
	      break;
	 }
     }
     if(flag==0)
     {
	 gotoxy(25,22);
	 cprintf("Record Not Found !!!");
     }
     finout.close();
     finout.open("doc1.txt",ios::in);
     gotoxy(25,20);
     cprintf("Do you want to Delete Doctor(y/n) - ");
     cin>>ch;
     if(ch=='y')
     {
       for(int i=1;i<=rec;i++)
       {
	   finout.read((char *)&p1,sizeof(p1));
	   if(p1.returndocid()!=id)
	   {
	      finout1.write((char *)&p1,sizeof(p1));
	   }
       }
       gotoxy(25,22);
       cprintf("Doctor's Record Deleted");
       finout.close();
       finout1.close();
       remove("doc1.txt");
       rename("temp.txt","doc1.txt");
       getch();
       return;
     }
     finout.close();
     finout1.close();
     getch();
}
void docm()
{
    char ch1;
    int rec,id;
    doctor d1;
    fstream finout;
    do
    {
	 clrscr();
	 page();
	 for(int j=1;j<=79;j++)
	 {
	      gotoxy(j,5);
	      cprintf("%c",196);
	 }
	 gotoxy(1,5);
	 cprintf("%c",199);
	 gotoxy(79,5);
	 cprintf("%c",182);
	 gotoxy(34,6);
	 cprintf("DOCTOR MENU ");
	 for(int k=1;k<=79;k++)
	 {
	      gotoxy(k,7);
	      cprintf("%c",196);
	 }
	 gotoxy(1,7);
	 cprintf("%c",199);
	 gotoxy(79,7);
	 cprintf("%c",182);
	 for(k=8;k<=24;k++)
	 {
	      gotoxy(20,k);
	      cprintf("%c",179);
	 }
	 gotoxy(20,7);
	 cprintf("%c",194);
	 gotoxy(20,25);
	 cprintf("%c",207);
	 for(k=8;k<=24;k++)
	 {
	      gotoxy(60,k);
	      cprintf("%c",179);
	 }
	 gotoxy(60,7);
	 cprintf("%c",194);
	 gotoxy(60,25);
	 cprintf("%c",207);
	 gotoxy(29,10);
	 cprintf("1. Add Doctor ");
	 gotoxy(29,12);
	 cprintf("2. Doctor's List ");
	 gotoxy(29,14);
	 cprintf("3. Delete Doctor's Record");
	 gotoxy(29,16);
	 cprintf("4. Main Menu");
	 gotoxy(29,22);
	 cprintf("Enter your choice : ");
	 ch1=getche();
	 switch(ch1)
	 {
	      case '1':

			clrscr();
			id=iddoc();
			finout.open("doc1.txt",ios::app);
			d1.adddoct(id);
			finout.write((char *)&d1,sizeof(d1));
			finout.close();
			id=id+1;
			patientid r1;
			finout.open("docid1.txt",ios::out);
			r1.add(id);
			finout.write((char *)&r1,sizeof(r1));
			finout.close();
			break;
	      case '2':
			outdoc();
			break;
	      case '3':
			d1.deletedoct();
			break;
	      case '4':
			break;
	 }
    }while(ch1!='4');
}
void p()
{
int x, y;

int i, j, kk;
kk=0;
for(j=100; j<350; j++)
{
if (j%20==0)
{
setcolor(kk);
kk=kk+3;
delay(200);
}
ellipse(320, 30, 0, 360, j+100,j+0);
}
for(j=100; j<350; j++)
{
if(j%20==0)
{
setcolor(BLACK);
delay(50);
}
ellipse(320,30,0,360,j+100,j+0);
}
cleardevice();
}
void n()
{
int i;
setcolor(15);
arc(120,220,55,120,100);
delay(100);
line(70,133,70,170);
line(173,135,170,170);
delay(150);
line(70,165,80,165);
arc(120,180,180,0,50);
delay(100);
line(160,170,170,168);
delay(100);
arc(95,155,60,160,20);
circle(100,165,20);
delay(100);
setfillstyle(1,0);
floodfill(100,165,15);
circle(106,165,9);
setfillstyle(1,15);
delay(100);
floodfill(106,165,15);
setcolor(BLACK);
circle(108,165,5);
setfillstyle(1,3);
floodfill(108,165,BLACK);
delay(150);
setcolor(15);
arc(145,150,-5,130,18);
delay(100);
circle(140,165,20);
circle(134,165,9);
delay(100);
setfillstyle(1,15);
floodfill(134,165,15);
setcolor(BLACK);
circle(133,165,5);
setfillstyle(1,3);
floodfill(133,165,BLACK);
delay(150);
setcolor(15);
arc(122,185,200,120,5);
delay(100);
arc(75,140,120,-130,22);
arc(118,150,10,152,60);
delay(100);
ellipse(120,202,180,0,15,20);
delay(100);
line(105,201,140,201);
arc(70,173,90,278,20);
arc(60,175,350,80,5);
delay(100);
arc(163,175,278,67,25);
arc(179,175,100,-120,5);
delay(150);
arc(120,220,190,-10,20);
delay(100);
arc(145,240,30,-260,15);
arc(100,240,90,150,15);
delay(100);
arc(120,260,10,75,20);
line(140,255,159,233);
delay(100);
arc(120,255,120,-180,20);
line(100,255,85,233);
delay(150);
setcolor(14);
arc(95,273,100,150,40);
delay(100);
arc(145,270,10,75,40);
line(60,253,40,320);
delay(100);
arc(60,300,350,20,100);
delay(100);
line(185,263,198,275);
line(195,277,220,265);
delay(100);
arc(189,285,190,-130,30);
arc(182,293,190,278,20);
delay(150);
line(185,313,232,285);
arc(150,299,150,198,70);
delay(100);
arc(240,265,160,-50,20);
delay(100);
setcolor(15);
ellipse(225,265,20,180,5,25);
delay(100);
line(229,255,255,245);
line(234,262,259,250);
delay(150);
arc(229,262,320,0,30);
line(240,272,260,260);
arc(229,250,300,0,30);
delay(150);
arc(245,245,300,0,10);
line(81,300,75,320);
line(10,320,200,318);
delay(100);
}
void tf()
 {
    int maxx=getmaxx();
    int maxy=getmaxy();
    int i;
    for(i=0;i<maxy/3+30;i++)
    {
 settextstyle(7,0,7); /*font    direction    size*/
 setcolor(1);
 outtextxy(maxx/3+70,i,"Welcome");
 delay(10);
 setcolor(0);
 outtextxy(maxx/3+70,i,"Welcome");
    }
    setcolor(1);
    outtextxy(maxx/3+70,i,"Welcome");
}
void corners()
{
   int maxx,maxy,i;
   maxx=getmaxx();
   maxy=getmaxy();
   for(i=0;i<6;i++)
   {
 setfillstyle(1,i+1);
 pieslice(1,maxy,15*i,15*(i+1),100);
 setcolor(8);
 delay(100);
   }

   for(i=0;i<6;i++)
   {
 setfillstyle(1,i+1);
 pieslice(1,1,15*(18+i),15*(i+19),100);
 setcolor(8);
 delay(100);
   }

   for(i=0;i<6;i++)
   {
 setfillstyle(1,i+1);
 pieslice(maxx,1,15*(12+i),15*(i+13),100);
 setcolor(8);
 delay(100);
   }

   for(i=0;i<6;i++)
   {
 setfillstyle(1,i+1);
 pieslice(maxx,maxy,15*(6+i),15*(i+7),100);
 setcolor(8);
 delay(100);
   }
}
void o()
{
    cleardevice();
    float i=0.1;
    int j=0,x,y,i1=1;
    x=getmaxx()/2;
    y=getmaxy()/2;
    while(!kbhit())
    {
	 setcolor(i1);
	 i1++;
	 arc(x,y,1+j,2+j,i+=0.04);
	 delay(1);
	 if(i1==15)
	      i=1;
	 j++;
    }
}
void b()
{
    int x,y,i,j;
    x=getmaxx();
    setcolor(5);
    for(i=1,j=1;i<=x;i++,j++)
    {
	 rectangle(0,0,i,j);
	 delay(6);
    }
}
void tf2()
{
    int i,maxx,maxy;
    maxx=getmaxx();
    maxy=getmaxy();
    for(i=0;i<maxx/3-30;i++)
    {
 settextstyle(7,0,7); /*font    direction    size*/
 setcolor(1);
 outtextxy(i,maxx/3+10,"Management");
 delay(10);
 setcolor(0);
 outtextxy(i,maxx/3+10,"Management");
    }
    setcolor(1);
    outtextxy(i,maxx/3+10,"Management");

    for(i=0;i<maxy/3;i++)
    {
 settextstyle(7,0,7); /*font    direction    size*/
 setcolor(1);
 outtextxy(maxx/3-100,i,"Hospital");
 delay(10);
 setcolor(0);
 outtextxy(maxx/3-100,i,"Hospital");
    }
    setcolor(1);
    outtextxy(maxx/3-100,i,"Hospital");
 }
void tf3()
{
    int i,maxx,maxy;
    maxx=getmaxx();
    maxy=getmaxy();
    for(i=0;i<maxx/3-30;i++)
    {
 settextstyle(7,0,6); /*font    direction    size*/
 setcolor(1);
 outtextxy(i,maxx/3-50,"Using This");
 delay(10);
 setcolor(0);
 outtextxy(i,maxx/3-50,"Using This");
    }
    setcolor(1);
    outtextxy(i,maxx/3-50,"Using This");

    for(i=0;i<maxy/3-60;i++)
    {
 settextstyle(7,0,6); /*font    direction    size*/
 setcolor(1);
 outtextxy(maxx/3-100,i,"Thanks For");
 delay(10);
 setcolor(0);
 outtextxy(maxx/3-100,i,"Thanks For");
    }
    setcolor(1);
    outtextxy(maxx/3-100,i,"Thanks For");

    for(i=maxx;i>maxx/3+30;i--)
    {
 settextstyle(7,0,6); /*font    direction    size*/
 setcolor(1);
 outtextxy(i,maxx/3+20,"Software");
 delay(10);
 setcolor(0);
 outtextxy(i,maxx/3+20,"Software");
     }
     setcolor(1);
     outtextxy(i,maxx/3+20,"Software");

}
void main()
{
    /*
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode,"");
    setbkcolor(5);
    p();
    tf();
    n();
    corners();
    b();
    o();
    cleardevice();
    tf2();
    corners();
    b();
    closegraph(); */
    char ch2;
    fstream finout;
    textbackground(6);
    textcolor(14);
    //finout.open("id1.txt",ios::out);
    //finout.close();
    do
    {
	 clrscr();
	 page();
	 for(int j=1;j<=79;j++)
	 {
	      gotoxy(j,5);
	      cprintf("%c",196);
	 }
	 gotoxy(1,5);
	 cprintf("%c",199);
	 gotoxy(79,5);
	 cprintf("%c",182);
	 gotoxy(35,6);
	 int k;
	 cprintf("MAIN MENU ");
	 for(k=1;k<=79;k++)
	 {
	      gotoxy(k,7);
	      cprintf("%c",196);
	 }
	 for(k=8;k<=24;k++)
	 {
	      gotoxy(20,k);
	      cprintf("%c",179);
	 }
	 gotoxy(20,7);
	 cprintf("%c",194);
	 gotoxy(20,25);
	 cprintf("%c",207);
	 for(k=8;k<=24;k++)
	 {
	      gotoxy(60,k);
	      cprintf("%c",179);
	 }
	 gotoxy(60,7);
	 cprintf("%c",194);
	 gotoxy(60,25);
	 cprintf("%c",207);

	 gotoxy(1,7);
	 cprintf("%c",199);
	 gotoxy(79,7);
	 cprintf("%c",182);
	 gotoxy(29,10);
	 cprintf("  1. Patient Menu");
	 gotoxy(29,12);
	 cprintf("  2. Department Menu ");
	 gotoxy(29,14);
	 cprintf("  3. Doctor Menu");
	 gotoxy(29,16);
	 cprintf("  4. Exit");
	 gotoxy(29,21);
	 cprintf("  Enter your choice : ");
	 ch2=getche();
	 switch(ch2)
	 {
	      case '1':
			patientm();
			break;
	      case '2':
			deptm();
			break;
	      case '3':
			docm();
			break;
	      case '4':
		       /*
			int gdriver = DETECT, gmode, errorcode;
			initgraph(&gdriver, &gmode,"");
			setbkcolor(5);
			tf3();
			corners();
			b();
			closegraph();  */
			break;
	 }
    }while(ch2!='4');
}