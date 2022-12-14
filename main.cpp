#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

class tutor
{
    public:
    string name;
    string sub;
};

class stud_class
{
    public:
    string name;
    string sub[6];
};



class TT
{
    public:
    int weekday;
    int class_slot[6][8];
    int room_no;
    string teacher_alloted;
    string stu_alloted;

    };

    class subject_sub 
    {
        public:
        string name;
        int teach_hrs=4;
    };

void print_tt(string arr[6][8][4][3])
{
    for(int i=0;i<6;i++)
    {
        for(int k=0;k<4;k++)
        {
            for(int j=0;j<8;j++)
            {
                cout<<arr[i][j][k][1]<<"/"<<arr[i][j][k][2]<<" | ";
            }
            cout<<endl;
        }
        for(int x=0;x<100;x++)
        {
            cout<<"_";
        }
    }
}

int main()
{
    string arr[6][8][4][3];
    int teacher_count,sub_count,class_count;

    cout<<"enter the number of teachers"<<endl;
    cin>>teacher_count;
    cout<<"enter the number of subjects"<<endl;
    cin>>sub_count;
    cout<<"enter the number of classes"<<endl;
    cin>>class_count;



    cout<<"enter the teacher details"<<endl;
    cout<<endl;
  /*  vector<tutor> teacher;
    
    for(int i=0;i<teacher_count;i++)
    {   vector<tutor> tinput;
        cout<<"Teacher"<<i+1<<endl;
        cout<<"name:";
        cin>>tinput.name;
        cout<<"subject:";
        cin>>tinput.sub;
*/ 
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
   }
// required hours


for(int i=0;i<6;i++)
{
    for(int j=0;j<8;j++)
    {
        
        for(int k=0;k<4;k++)
        {   int z=0;
            while(subject[k+z].teach_hrs==0)
            {
                z++;
            }
            arr[i][j][k][0]=teacher[k+z].name;
            arr[i][j][k][1]=s_class[k].name;
            arr[i][j][k][2]=teacher[k+z].sub;
            subject[k+z].teach_hrs--;

        }
    }
}
print_tt(arr);







    


    
}