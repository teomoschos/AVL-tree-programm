#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "ClassInvertedIndex.h"

using namespace std;


int main()
{
    struct node *root=NULL;
    struct node *root2=NULL;
    ClassInvertedIndex avl;
    string line;
    FILE *fp;
    ifstream command("commands.txt");
    if(!command)
    cout<<"ERROR - COMMANDS FILE NON EXISTENT \n";
    else
    {
            while (getline(command,line))
            {
                   if(line[0]=='R')
                   {
                        if((fp=fopen("input.txt","r"))==NULL)
                        cout<<"ERROR - INPUT FILE NON EXISTENT \n";
                        else
                        {
                            unsigned int i,j;
                                while ((fscanf(fp,"%d    %d", &i, &j))==2)
                                   {
                                    avl.INSERT(i,root);
                                    root2=avl.FIND_ELEMENT(root,i);
                                     if (root2)
                                    avl.INSERT(j,root2->subroot);
                                   }
                            fclose(fp);
                        }
                   }
                   else if(line[0]=='I')
                   {
                      unsigned int temp,temp2,num,z=0;
                      istringstream stream(line);
                      while(true)
                        {
                            if(stream >> num)
                                {
                                if (!z)
                                {
                                    temp=num;
                                    z++;
                                }
                                else
                                {
                                   temp2=num;
                                }
                                }
                                else if (stream.eof())
                                    {
                                     break;
                                    }
                                else
                                    {
                                     stream.clear();
                                     stream.ignore();
                                    }
                        }
                        avl.INSERT(temp,root);
                        root2=avl.FIND_ELEMENT(root,temp);
                        if (root2)
                            avl.INSERT(temp2,root2->subroot);
                      }
                   else if(line[0]=='D')
                    {
                      unsigned int temp,temp2,num,z=0;
                      istringstream stream(line);
                      while(true)
                        {
                            if(stream >> num)
                                {
                                    if (!z)
                                    {
                                        temp=num;
                                        z++;
                                    }
                                    else
                                    {
                                        temp2=num;
                                    }
                                 }
                            else if (stream.eof())
                                    {
                                     break;
                                    }
                                else
                                    {
                                     stream.clear();
                                     stream.ignore();
                                    }
                        }
                        root2=avl.FIND_ELEMENT(root,temp);
                        if (root2)
                        {
                            root2->subroot=avl.DELETE(temp2,root2->subroot);
                            if (!root2->subroot)
                            {
                                root=avl.DELETE(temp,root);
                            }
                        }
                      }
                      else if (line[0]=='W')
                      {
                        ofstream output("output.txt");
                        unsigned int non;
                        while (root)
                            {
                             struct node* p=avl.MLNODE(root);
                             non=avl.NUM_OF_NODES(p->subroot);
                             output<<"id : "<<p->element<<" , neighours : "<<non<<" , links : ";
                             output<<avl.M_DEL(p->subroot);
                             while (p->subroot)
                             {
                              output<<","<<avl.M_DEL(p->subroot);
                             }
                             output<<endl;
                             free(p);
                            }
                      }
                      else
                      {
                          break;
                      }
            }
           command.close();
    }
}
