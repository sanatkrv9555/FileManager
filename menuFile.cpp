#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
void createFile(string &fname)
{
    ofstream fout;
    fout.open(fname);
    if(fout)
    {
        cout<<"File created successfully"<<endl;
    }
    else
    {
        cout<<"Error in creating file "<<endl;
    }
    fout.close();
}

void writeFile(string &fname)
{
    ofstream fout;
    fout.open(fname,ios::app);
    string data;
    cout<<"Use '$' to end on new line"<<endl;
    while(true)
    {
        getline(cin,data);
        if(data=="$")
        break;
        fout<<data<<endl;
    }
    fout.close();
}

void updateFile(string &fname)
{
    ofstream fout;
    fout.open(fname);
    string data;
    cout<<"Use '$' to end on new line"<<endl;
    while(true)
    {
        getline(cin,data);
        if(data=="$")
        break;
        fout<<data<<endl;
    }
    fout.close();
}
void readFile(string &fname)
{
    ifstream fin;
    fin.open(fname);
    string line;
    while(getline(fin,line))
    {
        cout<<line<<endl;
    }
    fin.close();
}

void deleteFile(string fname)
{
    const char *filename= fname.c_str();
    if( remove(filename)==0)
    {
        cout<<"File deleted successfully"<<endl;
    }
    else
    {
        cout<<"Error in deleting file "<<endl;
    }
}
int main()
{
    while(true)
    {
    cout<<"Menu Driven Program "<<endl;
    cout<<"=============File Manager================\n"<<endl;
    cout<<"Press 1 : Create a New File"<<endl;
    cout<<"Press 2 : Read Data from the File"<<endl;
    cout<<"Press 3 : Append Data inside the File"<<endl;
    cout<<"Press 4 : Update Data from the File"<<endl;
    cout<<"Press 5 : Delete the Particular File"<<endl;
    cout<<"Press 6 : Exit from the File Manager"<<endl;
    cout<<"\nEnter your choice"<<endl;
    int ch;
    cin>>ch;
    if(ch==6)
    {
        cout<<"Exit from the File Manager "<<endl;
        break;
    }
    cout<<"Enter file name"<<endl;
    string fname;
    cin>>fname;
    if(ch==1)
    {
         createFile(fname);  
    }
    else if(ch==2)
    {
        readFile(fname);
    }
    else if(ch==3)
    {
        writeFile(fname);
    }
    else if(ch==4)
    {
        updateFile(fname);
    }
    else if(ch==5)
    {
        deleteFile(fname);
    }
    else{
        cout<<"Invalid Input ! Try Again "<<endl;
    }
    }
    return 0;
}