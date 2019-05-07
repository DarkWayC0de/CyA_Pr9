/**
 * @file GR.h
 * @version 1.0
 * @date 16/12/2018
 * @author Diego Cruz Rodriguez
 * @title Clase Gramatica
 * @brief Clase para trabajar con Gramaticas
 */

#ifndef PR9_GR_H
#define PR9_GR_H

#include <DFA.h>
#include <fstream>
#include "regla.h"
/**
 * @brief Uso del namespace CyA
 */
namespace CyA {
  /**
   * @brief Clase para el uso de Gramaticas
   */
  class GR {
  private:
    std::vector<char> simbolosterminales_;
    std::vector<char> simbolosnoterminales_;
    std::vector<regla> reglas_;
    char calculartermino(unsigned arranque, unsigned actual);

  public:
    /**
     * @brief Constructor por defecto de GR
     */
    GR ();
    /**
     * @brief Destructor por defecto de GR
     */
    ~GR();
    /**
     * @brief Funcion para cargar una gramatica desde fichero
     * @param nombrefichero Nombre del fichera de la gramatica
     */
    void cargar(char nombrefichero[]);
    /**
     * @brief Funcion para cargar una gramatica desde un dfa
     * @param dfa_ Dfa para cargar la gramatica
     */
    void cargardesdeDFA(DFA dfa_);
    /**
     * @brief Funcion para exportar la gramatica a un fichero
     * @param nombrefichero Nombre del fichero a exportar
     */
    void exportar(char nombrefichero[]);
    /**
     * @brief Imprime una gramaticanateriormente cargada
     * @param os parametro de imprecion
     * @return  devuelve el parametro de imprecion
     */

      std::ostream& write(std::ostream &os);
  };
}


#endif //PR9_GR_H
