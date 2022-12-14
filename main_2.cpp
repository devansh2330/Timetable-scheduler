#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<stdlib.h>

using namespace std;

class subject_sub 
    {
        public:
        string name;
        int teach_hrs=3;
        int sub_code;
    };

class tutor
{
    public:
    string name;
    subject_sub sub[3];
    int t_roll;
};

class batch
{
    public:
    string name;
    string sub[6];
    int b_roll;
    int teach_hrs=18;
};


    
class lesson
{
    public:
    tutor teacher_alloted;
    batch batch_alloted;
    subject_sub sub_alloted;
    lesson() {
        teacher_alloted.name = "----";
        batch_alloted.name = "----";
        sub_alloted.name = "-----";
    }

    void lesson_blank()
    {
        teacher_alloted.name = "----";
        batch_alloted.name = "----";
        sub_alloted.name = "-----";
    }
};

class session
{
    public:
    lesson a[3];
    
};

/*class TT
{
    public:
    int weekday;
    int class_slot[6][8];
    int room_no;
    string teacher_alloted;
    string stu_alloted;

    };*/

    
void print_tt(session session[8][6])
{  
    std::ifstream inf("input.txt");
    std::ofstream ouf("output.txt");

    for(int i=0;i<8;i++)
    {
        for(int z=0;z<101;z++)
        {
            ouf<<"_";
        }
        ouf<<endl;
        for(int k=0;k<3;k++)
        {
            for(int j=0;j<6;j++)
        {
            ouf<<session[i][j].a[k].batch_alloted.name<<"/"<<session[i][j].a[k].sub_alloted.name<<"/"<<session[i][j].a[k].teacher_alloted.name<<" | ";
        }
        ouf<<endl;
        }
        
    }
    for(int z=0;z<101;z++)
        {
            ouf<<"_";
        }
        ouf<<endl;
}

tutor pair_match(tutor teacher[],subject_sub subject)
{
    /*for(int i=0;i<8;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(teacher[i].sub[j].name==subject.name)
            {
                return teacher[i];
            }
        }
    }*/
    int x=subject.sub_code;
    int i=(x-1)/3;

    return teacher[i];

}

bool clash_check(session session)
{
    int x=0;

    
        if(session.a[0].batch_alloted.name == session.a[1].batch_alloted.name && session.a[1].batch_alloted.name!="----"||
         session.a[1].batch_alloted.name == session.a[2].batch_alloted.name && session.a[2].batch_alloted.name!="----"||
         session.a[0].batch_alloted.name == session.a[2].batch_alloted.name && session.a[2].batch_alloted.name!="----" )
         {
            x++;
         }

         if( session.a[0].teacher_alloted.name == session.a[1].teacher_alloted.name && session.a[1].teacher_alloted.name!="----" ||
         session.a[1].teacher_alloted.name == session.a[2].teacher_alloted.name && session.a[2].teacher_alloted.name!="----" ||
         session.a[0].teacher_alloted.name == session.a[2].teacher_alloted.name && session.a[2].teacher_alloted.name!="----"  )
         {
            x++;
         }

    if(x==0)
    {
        return true;
    }
    return false;

    
}

int clash_find(session session, int i,int j)
{
    lesson temp;
    if(session.a[0].batch_alloted.name==session.a[1].batch_alloted.name)
    {
        temp=session.a[1];
        

        return 1;
    }
    if(session.a[1].batch_alloted.name==session.a[2].batch_alloted.name)
    {
        temp=session.a[2];
      

        return 2;
    }
    if(session.a[0].batch_alloted.name==session.a[2].batch_alloted.name)
    {
        temp=session.a[2];
        
        return 2;
    }
   return -1;
}


int t_hrs_check(subject_sub subject[])
{
    int total_hr_left=0;
    for(int z=0;z<24;z++)
        {
            total_hr_left=total_hr_left + subject[z].teach_hrs;
        }

        return total_hr_left;
        
}
    

bool has_clash(session ses, tutor t, batch b) {
    for (int i=0; i<3; i++) {
        if (ses.a[i].batch_alloted.name == b.name || ses.a[i].teacher_alloted.name == t.name) {
            return true;
        }
    }
    return false;
}

// void batch_delete(batch section[],subject_sub subject)

int main()
{
    std::ifstream inf("input.txt");
    std::ofstream ouf("output.txt");
    
   /* string arr[6][8][4][3];
    int teacher_count,sub_count,class_count;

    cout<<"enter the number of teachers"<<endl;
    cin>>teacher_count;
    cout<<"enter the number of subjects"<<endl;
    cin>>sub_count;
    cout<<"enter the number of classes"<<endl;
    cin>>class_count;



    cout<<"enter the teacher details"<<endl;
    cout<<endl;*/
  /*  vector<tutor> teacher;
    
    for(int i=0;i<teacher_count;i++)
    {   vector<tutor> tinput;
        cout<<"Teacher"<<i+1<<endl;
        cout<<"name:";
        cin>>tinput.name;
        cout<<"subject:";
        cin>>tinput.sub;

    tutor teacher[6];
    subject_sub subject[6];
    
    for(int i=0;i<teacher_count;i++)
    {
        cout<<"-----TEACHER "<<i+1<<"-----"<<endl;
        cout<<"name: ";
        cin>>teacher[i].name;
        cout<<"subject: ";
        cin>>teacher[i].sub;
        cout<<endl;
    }

    stud_class s_class[4];
    
    for(int i=0;i<class_count;i++)
    {
        cout<<"CLASS "<<i+1;

        cout<<"name: ";
        cin>>s_class[i].name;
        if(i>=1)
        {
            continue;;
        }
        for(int j=0;j<sub_count;j++)
        {
            cout<<"subject "<<j+1<<": ";
        cin>>s_class[i].sub[j];
        cout<<endl;
        }
    }

   
   for(int i=0;i<6;i++)
   {
    subject[i].name=s_class[0].sub[i];
   }*/ 
// required hours

int teacher_count,student_count,rand_count,false_indicator=0;


inf>>teacher_count;
tutor teacher[8];
subject_sub subject[24];
batch section[4];
session session[8][6];

for(int i=0;i<teacher_count;i++)
{
    inf>>teacher[i].name;
    for(int j=0;j<3;j++)
    {
        inf>>teacher[i].sub[j].name;
        teacher[i].sub[j].sub_code=(i*3)+j+1;
        subject[(i*3)+j]=teacher[i].sub[j];
    }
}
inf>>student_count;
for(int i=0;i<student_count;i++)
{
    inf>>section[i].name;
    section[i].b_roll=i+1;
    for(int j=0;j<6;j++)
    {
        inf>>section[i].sub[j];
    }
}

//input complete
int total_hr_left=0;

for(int i=0;i<8;i++)
{
    for(int j=0;j<6;j++)
    {
        
        
        for(int k=0;k<3;k++)
        {   
            total_hr_left=t_hrs_check(subject);
            if(total_hr_left==0)
            {
                for(int n=k;n<3;n++)
                {
                    session[i][j].a[n].lesson_blank();
                }
                break;
            }
            int l,m;

            l=rand()%4;
            m=(l*6)+rand()%6;
            tutor t = pair_match(teacher,subject[m]);
            int xx=0;
            while (has_clash(session[i][j], t, section[l]) || subject[m].teach_hrs<1 || section[l].teach_hrs<1)
            {
                xx++;
                l=rand()%4;
                m=(l*6)+rand()%6;
                t = pair_match(teacher, subject[m]);
                if(xx>1000)
                {
                    break;
                }
            }
            if(xx>1000)
            {
                session[i][j].a[k].batch_alloted.name="";
                session[i][j].a[k].sub_alloted.name="";
                session[i][j].a[k].teacher_alloted.name="";
            }
            // while (section[l].teach_hrs<1) {
            //     l = (l+1)%4;
            // }
            // while (subject[m].teach_hrs<1) {
            //     m=(l*6)+rand()%6;
            // }
            // if (has_clash(session[i][j], t, b)) {}

            session[i][j].a[k].batch_alloted=section[l];
            session[i][j].a[k].sub_alloted=subject[m];
            session[i][j].a[k].teacher_alloted=t;

            subject[m].teach_hrs--;
            section[l].teach_hrs--;
        }

        if(clash_check(session[i][j])==false)
        {
            false_indicator++;
            int clash_pos=clash_find(session[i][j],i,j);
            
            for(int m=0;m<24;m++)
            {
               if(subject[m].name == session[i][j].a[clash_pos].sub_alloted.name)
               {
                subject[m].teach_hrs++;
                session[i][j].a[clash_pos].lesson_blank();
               }
            }



    /*            if(i==7)
                {   for(int q=0;q<3;q++)
                {
                    if(session[i][j+1].a[q].batch_alloted.name!="")
                 {
                     continue;
                 }
                  session[i][j+1].a[q]=clash_find(session[i][j],i,j);
                  break;
             }
            
             }
             else
                {
                  for(int q=0;q<3;q++)
                 {
                     if(session[i+1][j].a[q].batch_alloted.name!="")
                    {
                         continue;
                    }
                      session[i+1][j].a[q]=clash_find(session[i][j],i,j);
                      break;
                 }

*/

                }       
        }
     print_tt(session);
    cout<<"clashes:"<<false_indicator<<endl;

}
   

}





//print_tt(arr);




    


    
