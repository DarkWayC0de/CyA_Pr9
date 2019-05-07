/**
* @file regla.h
* @version 1.0
* @date 16/12/2018
* @author Diego Cruz Rodriguez
* @title Clase regla
* @brief Clase para almacenar reglas de una gramatica
*/

#ifndef PR9_REGLA_H
#define PR9_REGLA_H

#include <vector>
#include <string>

/**
 * @brief Uso de namespace CyA
 */
namespace CyA {
  /**
   * @brief Clase para almacernar una regla de una gramatica
   */
  class regla {

  public:
    /**
     * @brief Variable para guardar el simbolo_ de la regla
     */
    char simbolo_;
    /**
     * @brief Variable para guardar las diferentes alternativas de produciones
     */
    std::vector<std::string> regla_;
    /**
    * @brief Constructor por defecto de regla
    */
    regla();
    /**
     * @brief Destructor por defecto de regla
     */
    ~regla();
  };
}

#endif //PR9_REGLA_H
