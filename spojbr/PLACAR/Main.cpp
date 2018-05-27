#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
 
using namespace std;
  
struct aluno 
{
	char nome[21];
	int nota;
} alunos[100];
 
 
bool comp (aluno a, aluno b) 
{
 
	if (a.nota == b.nota) return (strcmp(a.nome, b.nome) > 0);
	else return (a.nota < b.nota);
 
}
  
 
int main () 
{
 
	int n, teste = 1;
 
	while (scanf("%d", &n) != EOF) 
	{
 
		for (int i = 0; i < n; i++)
			scanf("%s %d", alunos[i].nome, &alunos[i].nota);
 
		sort(alunos, alunos + n, comp);
 
		printf("Instancia %d\n%s\n\n", teste++, alunos[0].nome);
 
	}
 
	return 0;
 
}