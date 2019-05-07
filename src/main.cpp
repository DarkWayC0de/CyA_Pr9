#include <iostream>
#include "DFA.h"
#include "GR.h"

int main(int _argc,char *_argv[]){
   if(_argc==3){
        CyA::DFA A;
        A.cargar(_argv[1]);
        CyA::GR B;
        B.cargardesdeDFA(A);
        B.exportar(_argv[2]);
    }else{

        return 1;
    }
    return 0;
}
