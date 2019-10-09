#include <iostream>
#include<cstdio>
#include<sstream>
#include<cctype>
#include <stdlib.h>
#include <conio.h>
#include "ClassInvertedIndex.h"
#include <math.h>

using namespace std;



void ClassInvertedIndex::INSERT(unsigned int x,struct node* &p){
        if (p == NULL)
            {
                p = new node;
                p->element = x;
                p->left=NULL;
                p->right = NULL;
                p->height=0;
                p->subroot=NULL;
                if (p==NULL)
                {
                    cout<<"MEMORY FULL\n"<<endl;
                }
            }
            else
            {
                if (x<p->element)
                {
                    INSERT(x,p->left);
                    if ((BSHEIGHT(p->left) - BSHEIGHT(p->right))==2)
                    {
                        if (x < p->left->element)
                        {
                            p=R_ROT(p);
                        }
                        else
                        {
                            p=LR_ROT(p);
                        }
                    }
                }
                else if (x>p->element)
                {
                    INSERT(x,p->right);
                    if ((BSHEIGHT(p->right) - BSHEIGHT(p->left))==2)
                    {
                        if (x > p->right->element)
                        {
                            p=L_ROT(p);
                        }
                        else
                        {
                           p=RL_ROT(p);
                        }
                    }
                }

}
p->height = 1 + max(BSHEIGHT(p->left),
                           BSHEIGHT(p->right));
}


struct node* ClassInvertedIndex::DELETE(unsigned int key,struct node* root){
{
    if (root == NULL)
        return root;

    if ( key < root->element)
        root->left = DELETE(key,root->left);

    else if( key > root->element)
        root->right = DELETE(key,root->right);
    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct node *temp = root->left ? root->left :
                                             root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
             *root = *temp;
             free(temp);
        }
        else
        {
            struct node* temp = MLNODE(root->right);
            root->element = temp->element;
            root->subroot= temp->subroot;
            root->right = DELETE(temp->element,root->right);
        }
    }
    if (root == NULL)
      return root;
    root->height = 1 + max(BSHEIGHT(root->left),
                           BSHEIGHT(root->right));
    int balance = GETBAL(root);
    if (balance > 1 && GETBAL(root->left) >= 0)
        return R_ROT(root);
    if (balance > 1 && GETBAL(root->left) < 0)
    {
        return LR_ROT(root);
    }

    if (balance < -1 && GETBAL(root->right) <= 0)
        return L_ROT(root);

    if (balance < -1 && GETBAL(root->right) > 0)
    {
        return RL_ROT(root);
    }
    return root;
}
}

unsigned int ClassInvertedIndex::M_DEL(struct node* &p)
{
	unsigned int c;
	if (p->left == NULL)
	{
		c=p->element;
		node *d=p;
		p=p->right;
		free(d);
		return c;
	}
	else
	{
        c=M_DEL(p->left);
		return c;
	}
}

int ClassInvertedIndex::BSHEIGHT(struct node* p)
{
	if (p == NULL)
		return -1;
    return p->height;
}

int ClassInvertedIndex::GETBAL(struct node *p)
{
    if (p == NULL)
        return 0;
    return BSHEIGHT(p->left) - BSHEIGHT(p->right);
}

unsigned int ClassInvertedIndex::NUM_OF_NODES(struct node* &p)
{
    if (p==NULL)
     return 0;
    return NUM_OF_NODES(p->right)+NUM_OF_NODES(p->left) +1;
}

struct node* ClassInvertedIndex::MLNODE(struct node* &p)
{
	if (p->left == NULL)
	{
		struct node *d=p;
		p=p->right;
		return d;
	}
	else
	{
	    struct node *d=p;
		d=MLNODE(p->left);
		return d;
	}
}

struct node* ClassInvertedIndex::L_ROT(struct node* &parent){
    struct node* temp;
    temp=parent->right;
    parent->right=temp->left;
    temp->left=parent;
    parent->height=max(BSHEIGHT(parent->left),BSHEIGHT(parent->right))+1;
    temp->height=max(BSHEIGHT(temp->left),BSHEIGHT(temp->right))+1;
    return temp;
}

struct node* ClassInvertedIndex::R_ROT(struct node* &parent){
    struct node *temp;
    temp=parent->left;
    parent->left=temp->right;
    temp->right=parent;
    parent->height=max(BSHEIGHT(parent->left),BSHEIGHT(parent->right))+1;
    temp->height=max(BSHEIGHT(temp->left),BSHEIGHT(temp->right))+1;
    return temp;
}


struct node* ClassInvertedIndex::RL_ROT(struct node* &parent){
    parent->right=R_ROT(parent->right);
    return L_ROT(parent);
}


struct node* ClassInvertedIndex::LR_ROT(struct node* &parent){
    parent->left=L_ROT(parent->left);
    return R_ROT(parent);
}


struct node* ClassInvertedIndex::FIND_ELEMENT(struct node* &p,unsigned int &key)
{
  if(p == NULL)
    return p;
  else if (p->element < key)
    FIND_ELEMENT(p->right,key);
  else if (p->element > key)
    FIND_ELEMENT(p->left,key);
  else
    return p;
}














