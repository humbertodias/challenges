#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 10000

typedef enum {False,True} Boolean;

typedef struct {
  int num_vert,num_centers;
  int degree[MAXN];
  int cdegree[MAXN];
  int center[MAXN];
  int adj[MAXN][MAXN];
  int father[MAXN];
  int num_children[MAXN];
  int height[MAXN];
  int levels[MAXN][MAXN];
  int num_levels[MAXN];
  int tree_height;
  char label[MAXN][MAXN*2+1];
} Tree;

Tree t1,t2;

void read_tree(Tree *t, int num_vert) {
  int i,v,w;

  t->num_centers=t->num_vert=num_vert;
  for (i=0; i<t->num_vert; i++) t->degree[i]=0;
  for (i=1; i<t->num_vert; i++) {
    scanf("%d %d",&v,&w);
    v--;w--;
    t->adj[v][t->degree[v]++]=w;
    t->adj[w][t->degree[w]++]=v;
  }
  for (i=0; i<t->num_vert; i++) t->cdegree[i]=t->degree[i];
}

void find_center(Tree *t) {
  int i,j,v,w,nq;
  int queue[MAXN];
  Boolean iscenter[MAXN];

  for (v=0;v<t->num_vert;v++) iscenter[v]=True;
  while (t->num_centers>2) {
    nq=0;
    for (v=0;v<t->num_vert;v++) {
      if (iscenter[v] && t->cdegree[v]==1) {
  queue[nq++]=v;
  iscenter[v]=False;
  t->num_centers--;
      }
    }
    for (i=0;i<nq;i++) {
      v=queue[i];
      t->cdegree[v]--;
      for (j=0; j<t->degree[v]; j++) {
  w=t->adj[v][j];
  if (iscenter[w])
    t->cdegree[w]--;
      }
    }
  }
  t->num_centers=0;
  for (v=0;v<t->num_vert;v++) 
    if (iscenter[v])
      t->center[t->num_centers++]=v;
}

void enroot(Tree *t, int root) {
  int i,h,v,w,inq,outq,maxh;
  int queue[MAXN];

  for (i=0;i<t->num_vert;i++) {
    t->num_levels[i]=0;
    t->father[i]=-1;
  }
  inq=outq=0;
  t->father[root]=-1;
  t->height[root]=maxh=0;
  t->levels[0][0]=root;
  t->num_levels[0]=1;
  queue[inq++]=root;
  while (inq!=outq) {
    v=queue[outq++];
    t->num_children[v]=0;
    for (i=0;i<t->degree[v];i++) {
      w=t->adj[v][i];   
      if (w==t->father[v]) continue;
      t->father[w]=v;
      t->num_children[v]++;
      h=t->height[v]+1;
      if (h>maxh)
  maxh=h;
      t->height[w]=h;
      t->levels[h][t->num_levels[h]++]=w;
      queue[inq++]=w;
    }
  }
  t->tree_height=maxh+1;
}

int compare(const void *s1, const void *s2) {
  return strcmp(s1,s2);
}

char labels[MAXN][2*MAXN+1];
int nlabels;

void build_label(Tree *t, int v) {
  int j,w;

  if (t->num_children[v]==0) strcpy(&t->label[v][0],"10");
  else {
    // build list of labels from children
    nlabels=0;
    for (j=0;j<t->degree[v];j++) {
      w=t->adj[v][j];
      if (w==t->father[v]) continue;
      strcpy(&labels[nlabels++][0],&t->label[w][0]);
    }
    // sort list of labels
    qsort(labels, nlabels, sizeof(char)*(2*MAXN+1),compare);
    // build this node label
    strcpy(&t->label[v][0],"1");
    for (j=0;j<nlabels;j++)
      strcat(&t->label[v][0],&labels[j][0]);
    strcat(&t->label[v][0],"0");
  }
}

Boolean is_iso (Tree *t1,int root1,Tree *t2,int root2) {
  int i,h;

  if (t1->tree_height!=t2->tree_height) return False;
  for (h=t1->tree_height-1;h>=0;h--) {
    if (t1->num_levels[h]!=t2->num_levels[h]) return False;
    for (i=0;i<t1->num_levels[h];i++) 
      build_label(t1,t1->levels[h][i]);
    for (i=0;i<t2->num_levels[h];i++) 
      build_label(t2,t2->levels[h][i]);
  }
  if (strcmp(&t1->label[root1][0],&t2->label[root2][0])==0)
    return True;
  return False;
}


int main(void) {
  char result;
  int n;

  while (scanf("%d",&n)==1) {
    result='N';
    read_tree(&t1,n);
    read_tree(&t2,n);
    if (t1.num_vert!=t2.num_vert) {
      printf("N\n");
      continue;
    }
    find_center(&t1);
    find_center(&t2);
    enroot(&t1,t1.center[0]);
    enroot(&t2,t2.center[0]);
    if (is_iso(&t1,t1.center[0],&t2,t2.center[0]))
      result='S';
    else if (t1.num_centers==2) {
      enroot(&t1,t1.center[1]);
      if (is_iso(&t1,t1.center[1],&t2,t2.center[0])) 
  result='S';
    }
    else if (t2.num_centers==2) {
      enroot(&t2,t2.center[1]);
      if (is_iso(&t1,t1.center[0],&t2,t2.center[1]))
  result='S';
    }
    printf("%c\n",result);
  }
  return 0;
}