#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cmath>


using namespace std;


int main(){

    srand(time(0));

   int resultado = ((rand() % 100) + 1);



    if (resultado > 70){

        cout << resultado << " Vitoria" << endl;

    }else{

    if (resultado > 50 ){

        cout << resultado << " passou perto" << endl;

    }else{
    if(resultado > 25 ){

        cout << resultado << " talvez na proxima" << endl;

    }else{
    if(resultado < 26){

        cout << resultado << " Derrota!" << endl;

    }
    }

    }



    }









return 0;
}
