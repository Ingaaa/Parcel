#include<iostream>
#include<fstream>
#include "stdio.h"
#include "stdlib.h"
using namespace std;

fstream fin ("parcel.in.txt", ios::in);
fstream fout ("parcel.out.txt", ios::out);
struct node
{
    int num;
    node *next;
};

struct node_pos
{
    short int parcel_num;
    int time; //Vai vajag?
    int coord_c; //Vai vajag?
    node *first;
};

class saraksts
{
    public:
    node *first;
    node *last;
public:
     saraksts()
    {
        first=NULL;
        last=NULL;
    };
//    void add_element (int amou, int pos)
//    {
//        node * P=new node;
//        P->position=pos;
//        P->amount=amou;
//        P->next=NULL;
//        if (first == NULL) first = P;
//        else last->next = P;
//        last = P;
//    };
     void print()
    {
        node * N=new node;
        N=first;
        while (N!=NULL)
        {

            N=N->next;
        }
    }
//    void sort_izeja ()
//    {
//        if((first!=NULL) && (first->next!=NULL))
//        {
//            node *p=first;
//            node *pasreiz=first;
//            node *ieprieks=NULL;
//            node *temp=NULL;
//            bool a=false;
//            short int skaits=0;
//
//            while (p!=NULL)
//            {
//                skaits++;
//                p=p->next;
//            }
//            for (int i=0; i<skaits; i++)
//            {
//                while (pasreiz->next !=NULL)
//                {
//                    temp=pasreiz->next;
//                    if ((pasreiz->position) > (temp->position))
//                    {
//                        a=true;
//                        pasreiz->next=temp->next;
//                        temp->next=pasreiz;
//                        if (ieprieks !=NULL) ieprieks->next=temp;
//                        ieprieks=temp;
//                        if (first==pasreiz) first=temp;
//                        if(pasreiz->next==NULL) last=pasreiz;
//
//                    }
//                    else
//                    {
//                        ieprieks=pasreiz;
//                        pasreiz=pasreiz->next;
//                    }
//                }
//
//                if (a==false) break;
//                else
//                {
//                    ieprieks=NULL;
//                    pasreiz=first;
//                    a=false;
//                }
//            }
//        }
//    }
//    void sort_izeja_dilstosi ()
//    {
//        if((first!=NULL) && (first->next!=NULL))
//        {
//            node *p=first;
//            node *pasreiz=first;
//            node *ieprieks=NULL;
//            node *temp=NULL;
//            bool a=false;
//            int skaits=0;
//
//            while (p!=NULL)
//            {
//                skaits++;
//                p=p->next;
//            }
//            for (int i=0; i<skaits; i++)
//            {
//                while (pasreiz->next !=NULL)
//                {
//                    temp=pasreiz->next;
//                    if ((pasreiz->position) < (temp->position))
//                    {
//                        a=true;
//                        pasreiz->next=temp->next;
//                        temp->next=pasreiz;
//                        if (ieprieks !=NULL) ieprieks->next=temp;
//                        ieprieks=temp;
//                        if (first==pasreiz) first=temp;
//                        if(pasreiz->next==NULL) last=pasreiz;
//
//                    }
//                    else
//                    {
//                        ieprieks=pasreiz;
//                        pasreiz=pasreiz->next;
//                    }
//                }
//
//                if (a==false) break;
//                else
//                {
//                    ieprieks=NULL;
//                    pasreiz=first;
//                    a=false;
//                }
//            }
//        }
//    }
//
};


node_pos* arr[65000];
int main()
{
    char komanda=' ';
    int laiks=0, koord_sk=0, koord=0, zemes_nr=0, biggest_pos=0;
    node *Temp=new node;

  for (int i =0; i<65001; i++)
  {
      arr[i]=new node_pos;
      arr[i]->parcel_num=0;
      arr[i]->time=0;
      arr[i]->coord_c=0;
      arr[i]->first=NULL;
  }
  fin>>laiks>>komanda;

  while (fin)
  {
      cout<<"komanda "<<komanda<<endl;
    if (komanda=='A')
    {

        fin>>zemes_nr>>koord_sk;
        if (arr[zemes_nr]->parcel_num==0)
            {
                if (zemes_nr>biggest_pos)biggest_pos=zemes_nr;
                arr[zemes_nr]->parcel_num=zemes_nr;
                for (int i=0; i<koord_sk; i++)
                {
                    fin>>koord;
                    node *P=new node;
                    P->num=koord;
                    P->next=NULL;
                    if (arr[zemes_nr]->first==NULL) arr[zemes_nr]->first=P;
                    else
                    {
                        P->next=arr[zemes_nr]->first;
                        arr[zemes_nr]->first=P;
                    }
                }
                fout<<laiks<<" A "<<zemes_nr<<" OK"<<endl;
            }
            else
            {
                fout<<laiks<<" A "<<zemes_nr<<" ERROR"<<endl;
                for (int i=0; i<koord_sk; i++)
                {
                    fin>>koord;
                }
            }


    }
    if (komanda=='D')
    {
        fin>>zemes_nr;
        if (arr[zemes_nr]->parcel_num!=0)
        {
            arr[zemes_nr]->parcel_num=0;
            arr[zemes_nr]->time=0;
            arr[zemes_nr]->coord_c=0;

            //jāizdēš
//            if (arr[zemes_nr]->first!=NULL)
//            {
//                Temp=arr[zemes_nr]->first;
//                Curr=arr[zemes_nr]->first;
//                while (Temp!=NULL)
//                {
//
//                }
//            }


            fout<<laiks<<" D "<<zemes_nr<<" OK"<<endl;
        }
        else
        {
            fout<<laiks<<" D "<<zemes_nr<<" ERROR"<<endl;
        }
    }
    if (komanda=='P')
    {
        fin>>zemes_nr;

        if (arr[zemes_nr]->parcel_num!=0)
        {

            fout<<laiks<<" P "<<zemes_nr;
            Temp=arr[zemes_nr]->first;
            while(Temp!=NULL)
            {
                fout<<" "<<Temp->num;
                Temp=Temp->next;
            }
            fout<<endl;
        }
        else
        {

            fout<<laiks<<" P "<<zemes_nr<<" ERROR"<<endl;
        }

    }
    if (komanda=='K')
    {

    }
    else
    {

    }

   fin>>laiks>>komanda;
  }

}