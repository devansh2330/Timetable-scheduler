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
        int is_common=-1;
        string com_batch;

        void blank_subject()
        {
            teach_hrs=0;
        }
    };

class tutor
{
    public:
    string name;
    subject_sub sub[4];
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
    batch batch_alloted[2];
    subject_sub sub_alloted;
    lesson() 
    {
        teacher_alloted.name = "";
        batch_alloted[0].name = "";
        sub_alloted.name = "";
        batch_alloted[2].name="";
    }

    void lesson_blank()
    {
        teacher_alloted.name = "----";
        batch_alloted[0].name = "----";
        sub_alloted.name = "-----";
        batch_alloted[1].name="";
    }
};

class session
{
    public:
    lesson a[4];
    
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
    std::ifstream inf("input_2.txt");
    std::ofstream ouf("time_table_students.txt");

    string weekday_names[7]={"HALL NO.","      MONDAY    ","     TUESDAY     ","    WEDNESDAY    ","     THURSDAY    ","      FRIDAY     ","     SATURDAY    "};

    for(int z=0;z<122;z++)
        {
            ouf<<"_";
        }
        ouf<<endl;
        for(int i=0;i<7;i++)
        {
            ouf<<""<<weekday_names[i]<<"| ";
        }
        ouf<<endl;
        for(int z=0;z<122;z++)
        {
            ouf<<"=";
        }
        ouf<<endl;


    for(int i=0;i<8;i++)
    {
        
        for(int k=0;k<4;k++)
        {
            ouf<<"   H"<<(k+1)<<"   |";
            for(int j=0;j<6;j++)
        {
            if(session[i][j].a[k].batch_alloted[1].name=="")
            {
                ouf<<"   "<<session[i][j].a[k].batch_alloted[0].name<<"/"<<session[i][j].a[k].sub_alloted.name/*<<"/"<<session[i][j].a[k].teacher_alloted.name*/<<"    | ";
            }
            else
            {
                ouf<<session[i][j].a[k].batch_alloted[0].name<<"&&"<<session[i][j].a[k].batch_alloted[1].name<<"/"<<session[i][j].a[k].sub_alloted.name/*<<"/"<<session[i][j].a[k].teacher_alloted.name*/<<" | ";
            }
        }
        ouf<<endl;
        }
        for(int z=0;z<122;z++)
        {
            ouf<<"_";
        }
        ouf<<endl;
        
    }
    for(int z=0;z<122;z++)
        {
            ouf<<"_";
        }
        ouf<<endl;
}

void print_tt_teachers(session session[8][6])
{  
    std::ifstream inf("input_2.txt");
    std::ofstream ouf("time_table_teachers.txt");

    string weekday_names[7]={"HALL NO.","      MONDAY    ","     TUESDAY     ","    WEDNESDAY    ","     THURSDAY    ","      FRIDAY     ","     SATURDAY    "};

    for(int z=0;z<122;z++)
        {
            ouf<<"_";
        }
        ouf<<endl;
        for(int i=0;i<7;i++)
        {
            ouf<<""<<weekday_names[i]<<"| ";
        }
        ouf<<endl;
        for(int z=0;z<122;z++)
        {
            ouf<<"=";
        }
        ouf<<endl;


    for(int i=0;i<8;i++)
    {
        
        for(int k=0;k<4;k++)
        {
            ouf<<"   H"<<(k+1)<<"   |";
            for(int j=0;j<6;j++)
        {
              ouf<<"   "<<session[i][j].a[k].teacher_alloted.name<<"/"<<session[i][j].a[k].sub_alloted.name/*<<"/"<<session[i][j].a[k].teacher_alloted.name*/<<"    | ";
        }
        ouf<<endl;
        }
        for(int z=0;z<122;z++)
        {
            ouf<<"_";
        }
        ouf<<endl;
        
    }
    for(int z=0;z<122;z++)
        {
            ouf<<"_";
        }
        ouf<<endl;
}

void loading_time(int y,string p)
{
    int x=0;
    for(int i=0;i<y;i++)
    {   
        
        for(int j=0;j<500000000;j++)
        {
            if(j==99999999)
            {
                  x++;
                  x++;
                  x--;
                  cout<<p;
            }
        }
    }
}

int terminal_ui_start(int* working_day)
{
    int x=0;
    char go_ahead;
    int stat_nod;
    stat_nod=0;
    int weekday;
    

    cout<<"loading";

    loading_time(3,".");
    cout<<endl;

    for(int i=0;i<40;i++)
    {
        cout<<"-";
    }

    cout<<"WELCOME TO TIMETABLE SCHEDULER";

    for(int i=0;i<40;i++)
    {
        cout<<"-";
    }
    cout<<endl;
    loading_time(1,"");
    cout<<"Input the data in \"input.txt\""<<endl;
    cout<<"Press any key to proceed: ";
    cin>>go_ahead;
    loading_time(1,"");
    cout<<"Input the number of working days(5/6): ";
    cin>>weekday;
    *working_day=weekday;

    cout<<"Press Y to see developer statistics(Y/N): ";
    cin>>go_ahead;
    if(go_ahead=='Y')
    {
        stat_nod++;
    }
    loading_time(1,"");
    cout<<"Initializing";
    loading_time(3,".");
    cout<<endl;
    cout<<"Processing Data";
    loading_time(3,".");
    cout<<endl;

    return stat_nod;

    }

void terminal_ui_end()
{
    cout<<"Timetable Processed"<<endl;
    loading_time(1,".");
    cout<<endl;
    loading_time(1,".");
    cout<<endl;
    loading_time(1,".");
    cout<<endl;
    cout<<"Timetable Executed"<<endl;
    loading_time(1,"");
    cout<<"Open \"time_table_teachers.txt\" to see teachers time table"<<endl;
    cout<<"Open \"time_table_students.txt\" to see students time table"<<endl;

    for(int i=0;i<47;i++)
    {
        cout<<"-";
    }

    cout<<"PROGRAM FINISHED";

    for(int i=0;i<47;i++)
    {
        cout<<"-";
    }
    cout<<endl;
    char final_say;
    cin>>final_say;

}

int pair_match(batch section[],subject_sub subject)
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
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(section[i].sub[j]==subject.name)
            {
                return i;
            }
        }
    }

    return 0;

}

bool clash_check(session session)
{
    int x=0;//change done
 
    for(int i=0;i<3;i++)
    {
        for(int j=(i+1);j<4;j++)
        {
            for(int k=0;k<2;k++)
            {
                for(int l=0;l<2;l++)
                {
                    if(session.a[i].batch_alloted[k].name == session.a[j].batch_alloted[l].name && session.a[i].batch_alloted[k].name!="" && session.a[i].batch_alloted[k].name!="----")
                    {
                       x++;
                    }
                }
            }
        }
    }

    for(int i=0;i<3;i++)
    {
        for(int j=(i+1);j<4;j++)
        {
            if(session.a[i].teacher_alloted.name == session.a[j].teacher_alloted.name && session.a[j].teacher_alloted.name!="----")
            {
                x++;
            }
        }
    }

    if(x==0)
    {
        return true;
    }
    return false;

    
}

int clash_find(session session, int i,int j)
{
  //change done

   for(int i=0;i<3;i++)
    {
        for(int j=(i+1);j<4;j++)
        {
            for(int k=0;k<2;k++)
            {
                for(int l=0;l<2;l++)
                {
                    if(session.a[i].batch_alloted[k].name == session.a[j].batch_alloted[l].name && session.a[i].batch_alloted[k].name!="")
                    {
                       return j;
                    }
                }
            }
        }

    for(int i=0;i<3;i++)
    {
        for(int j=(i+1);j<4;j++)
        {
            if(session.a[i].teacher_alloted.name == session.a[j].teacher_alloted.name)
            {
               return j;
            }
        }
    }
    }


   return -1;
}


int t_hrs_check(subject_sub subject[])
{
    int total_hr_left=0;
    for(int z=0;z<40;z++)
        {
            total_hr_left=total_hr_left + subject[z].teach_hrs;
        }

        return total_hr_left;
        
}
    

bool has_clash(session ses, tutor t, subject_sub s,batch b) 
{
  
   for (int i=0; i<4; i++) {
        if (ses.a[i].sub_alloted.name == s.name || ses.a[i].teacher_alloted.name == t.name || ses.a[i].batch_alloted[0].name == b.name || ses.a[i].batch_alloted[1].name == b.name)
         {
            return true;
        }
    }
    return false;


   
}

// void batch_delete(batch section[],subject_sub subject)

int main()
{
    std::ifstream inf("input_2.txt");
    std::ofstream ouf("output.txt");

    //int ui_return_values[2];
    int weekday_count=6;
    int clashes_nod=terminal_ui_start(&weekday_count);

    

    
    
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
tutor teacher[10];
subject_sub subject[40];
batch section[7];
session session[8][6];

for(int i=0;i<teacher_count;i++)
{
    inf>>teacher[i].name;
    for(int j=0;j<4;j++)
    {
        inf>>teacher[i].sub[j].name;
        teacher[i].sub[j].sub_code=(i*4)+j+1;
        subject[(i*4)+j]=teacher[i].sub[j];
    }
}

for(int i=0;i<40;i++)
{
    if(subject[i].name=="-----")
    {
        subject[i].teach_hrs=0;
    }
}

/*for(int i=0;i<7;i++)
{
    for(int j=0;j<6;j++)
    {
        for(int k=0;k<7;k++)
        {
            for(int l=0;l<6;l++)
            {cout<<"start"<<i<<j<<k<<l<<endl;
                if(i<=k && j<=l)
                {
                    continue;
                }
                if(section[i].sub[j]==section[k].sub[l] && section[i].sub[j]!="-----")
                {
                    for(int m=0;m<40;m++)
                    {
                        if(section[i].sub[j]==subject[m].name)
                        {
                            subject[m].is_common++;
                            subject[m].com_batch=section[k].name;
                            break;
                        }
                    }
                }
            }
        }
    }
}
*/
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

for(int i=0;i<40;i++)
{
    for(int j=0;j<7;j++)
    {
        for(int k=0;k<6;k++)
        {
            if(subject[i].name==section[j].sub[k] && subject[i].name!="-----")
            {
                subject[i].is_common++;
            
            }
            if(subject[i].is_common==1)
            {
                subject[i].com_batch=section[j].name;
                section[j].sub[k]="-----";
               // cout<<subject[i].name<<" "<<section[j].name<<" "<<i<<" "<<j<<" "<<k<<endl;
                break;
            }
        }

        if(subject[i].is_common==1)
        {
            break;
        }
    }
}

//cout<<"input complete"<<endl;


//input complete

if(weekday_count==5)
    {
        for(int i=0;i<8;i++)
        {
           for(int j=0;j<4;j++)
           {
             session[i][5].a[j].batch_alloted[0].name="----";
             session[i][5].a[j].sub_alloted.name="-----";
             session[i][5].a[j].teacher_alloted.name="----";
           }
        }
    }

int total_hr_left=0;

for(int i=0;i<8;i++)
{
    for(int j=0;j<weekday_count;j++)
    {
        
        
        for(int k=0;k<4;k++)
        {   

            total_hr_left=t_hrs_check(subject);
            if(total_hr_left==0)
            {
                for(int n=k;n<4;n++)
                {
                    session[i][j].a[n].lesson_blank();
                }
                break;
            }
            int l,m;
            int b;

            l=rand()%10;//teacher
            m=(l*4)+rand()%4;//subject
            b=pair_match(section,subject[m]);//section

            
          
            int xx=0;
            while ( subject[m].teach_hrs<1 || has_clash(session[i][j],teacher[l],subject[m],section[b])==true)
            {
                xx++;

                l=rand()%10;
                m=(l*4)+rand()%4;
                b=pair_match(section,subject[m]);

                
                

                if(xx>1000)
                {
                    break;
                }
            }
            if(xx>1000)
            {
                session[i][j].a[k].batch_alloted[0].name="----";
                session[i][j].a[k].sub_alloted.name="-----";
                session[i][j].a[k].teacher_alloted.name="----";
            } else {
                
                session[i][j].a[k].batch_alloted[0]=section[b];
                session[i][j].a[k].sub_alloted=subject[m];
                session[i][j].a[k].teacher_alloted=teacher[l];

                if(subject[m].is_common==1)
                {
                    session[i][j].a[k].batch_alloted[1].name=subject[m].com_batch;

                    
                }

                subject[m].teach_hrs--;
                section[l].teach_hrs--;
            }
            
            // while (section[l].teach_hrs<1) {
            //     l = (l+1)%4;
            // }
            // while (subject[m].teach_hrs<1) {
            //     m=(l*6)+rand()%6;
            // }
            // if (has_clash(session[i][j], t, b)) {}

            
        }

        if(clash_check(session[i][j])==false)
        {
            false_indicator++;
            int clash_pos=clash_find(session[i][j],i,j);
            
            for(int m=0;m<40;m++)
            {
               if(subject[m].name == session[i][j].a[clash_pos].sub_alloted.name && subject[m].name !="-----")
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
     print_tt_teachers(session);
     print_tt(session);
    
    if(clashes_nod==1)
    {
        cout<<"clashes:"<<false_indicator<<endl;
    }

}

terminal_ui_end();
   

}





//print_tt(arr);
