#ifndef CLASSINVERTEDINDEX_H
#define CLASSINVERTEDINDEX_H

struct node
{
    unsigned int element;
    struct node *left;
    struct node *right;
    int height;
    struct node *subroot;
};

class ClassInvertedIndex
{
    public:
        unsigned int M_DEL(struct node* &);
        unsigned int    NUM_OF_NODES(struct node* &);
        int    BSHEIGHT(struct node*);
        int    GETBAL(struct node *);
        void INSERT(unsigned int  , struct node* &);
        struct node* DELETE(unsigned int  , struct node* );
        struct node* MLNODE(struct node* &);
        struct node* FIND_ELEMENT(struct node* &,unsigned int &);
        struct node* R_ROT (struct node* &);
        struct node* L_ROT (struct node* &);
        struct node* RL_ROT (struct node* &);
        struct node* LR_ROT (struct node* &);
};


#endif //
