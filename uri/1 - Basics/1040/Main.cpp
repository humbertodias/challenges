#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    float a,b,c,d,e,media;

    cin >> a >> b >> c >> d;

    media = (a*2 + b*3 + c*4 + d*1)/(10.0);
    cout << "Media: " << fixed << setprecision(1) << media << "\n";

    if(media >= 7.0)
        cout << "Aluno aprovado.\n";
    if(media < 5.0)
        cout << "Aluno reprovado.\n";
    if(media >= 5.0 && media < 7.0){
        cout << "Aluno em exame.\n";
        cin >> e;
        cout << "Nota do exame: " << fixed << setprecision(1) << e << "\n";

        if((media + e)/2.0 >= 5.0)
            cout << "Aluno aprovado.\n";
        else
            cout << "Aluno reprovado.\n";

        cout << "Media final: " << fixed << setprecision(1) << (media + e)/2.0 << "\n";
    }
    return 0;
}