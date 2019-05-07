

#include "GR.h"

namespace CyA{
    GR::GR() {

    }
    GR::~GR() {

    }
    void GR::cargar(char *nombrefichero) {
        std::ifstream archivo;
        archivo.open(nombrefichero);
        if(!archivo.fail()){
            std::cout<<"Apertura de archivo correcta";
            unsigned a;
            char b;
            archivo>>a;
            for (int i = 0; i <a; ++i) {
                archivo >>b;
                simbolosterminales_.push_back(b);
            }
            archivo>>a;
            for (int j = 0; j <a ; ++j) {
                archivo>>b;
                simbolosnoterminales_.push_back(b);
            }
            for (int k = 0; k <simbolosnoterminales_.size(); ++k) {
                archivo>>b;
                regla c;
                c.simbolo_=b;
                archivo>>b;
                archivo>>b;
                char cadena[50];
                archivo.getline(cadena,50,'\n');
                std::string micadena;
                for (int i = 0; cadena[i]!='\0' ; ++i) {
                    if(cadena[i]!=' ') {
                        if (cadena[i] != '|') {
                            micadena.push_back(cadena[i]);
                        } else {
                            c.regla_.push_back(micadena);
                            micadena.clear();
                        }
                    }
                }
                c.regla_.push_back(micadena);
                reglas_.push_back(c);
            }
            archivo.close();
        }else{
            std::cout<<"Error en la apertura del archivo apertura";
        }

    }
    void GR::cargardesdeDFA(CyA::DFA A) {
        for(std::set<char>::iterator i=A.getAlfabeto_().begin(); i!=A.getAlfabeto_().end();i++){
            simbolosterminales_.push_back(i.operator*());
        }
        unsigned cont=0;
        for(std::set<Estado>::iterator i=A.getDFA_().begin();i!=A.getDFA_().end();i++){
            regla aux;

                aux.simbolo_=calculartermino(A.getarranque_(),i->estado_);
                for (int j = 0; j <i->transiciones_; ++j) {
                    std::string aux2;
                    aux2.push_back(i->transicion_[j].first);
                    aux2.push_back(calculartermino(A.getarranque_(),i->transicion_[j].second));
                    aux.regla_.push_back(aux2);
                }

            simbolosnoterminales_.push_back(calculartermino(A.getarranque_(),i->estado_));

            if(i->aceptacion_){
                std::string aux2="~";
                aux.regla_.push_back(aux2);
            }
            reglas_.push_back(aux);
        }
        if(simbolosnoterminales_[0]!='S'){
            int cont=0;
            while(simbolosnoterminales_[cont]!='S'){
                cont++;
            }
            char temp= simbolosnoterminales_[cont];
            for (int i = 0; i <cont+1 ; ++i) {
                char temp2=simbolosnoterminales_[i];
                simbolosnoterminales_[i]=temp;
                temp=temp2;
            }
            regla temp3= reglas_[cont];
            for (int i = 0; i <cont+1 ; ++i) {
                regla temp4=reglas_[i];
                reglas_[i]=temp3;
                temp3=temp4;
            }
        }
    }
    char GR::calculartermino(unsigned arranque, unsigned actual){
        static int b= 0;
        if(arranque==actual){
            return 'S';
        }else{
            if(actual>arranque){
                actual--;
            }
            char a='A';
            for (int i = 0; i <actual+b; ++i) {
                a++;
            }
            if(a=='S'){
                a++;
                b++;
            }
            return a;
        }

    }
    void GR::exportar(char *nombrefichero) {
        std::streambuf *psbuf, *backup;
        std::ofstream filestr;
        filestr.open (nombrefichero);

        backup = std::cout.rdbuf();

        psbuf = filestr.rdbuf();
        std::cout.rdbuf(psbuf);
        write(std::cout);
        std::cout.rdbuf(backup);
        filestr.close();
    }
    std::ostream& GR::write(std::ostream &os) {
        os<<simbolosterminales_.size()<<"\n";
        for (int i = 0; i <simbolosterminales_.size(); ++i) {
            os<<simbolosterminales_[i]<<" ";
        }
         os<<"\n"<<simbolosnoterminales_.size()<<"\n";
        for (int j = 0; j <simbolosnoterminales_.size() ; ++j) {
            os<<simbolosnoterminales_[j]<<" ";
        }
        os<<"\n";
        for (int k = 0; k <reglas_.size(); ++k) {
            os<<reglas_[k].simbolo_<<" -> ";
            for (int i = 0; i <reglas_[k].regla_.size()-1 ; ++i) {
                os<<reglas_[k].regla_[i]<<" | ";
            }
            os<< reglas_[k].regla_[reglas_[k].regla_.size()-1]<<"\n";
        }
        return os;
    }

}
