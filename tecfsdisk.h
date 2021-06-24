#ifndef TECFSDISK_H
#define TECFSDISK_H
#include <QDomProcessingInstruction>

/**
 * @brief The TECFSDisk class es la clase encargada de leer los archivos XML y obtener los parametros
 */
class TECFSDisk
{
public:
    /**
     * @brief TECFSDisk Constructor
     */
    TECFSDisk();
    /**
     * @brief puerto es la variable donde se almacena el puerto del disco creado
     */
    int puerto;
    /**
     * @brief ip es la variable donde se almacena la ip del disco creado
     */
    QString ip ;
    /**
     * @brief Path es la variable donde se almacena el path del disco creado
     */
    QString Path;
    /**
     * @brief ParseXML es la función encargada del abrir y leer el archivo XML
     * @param i variable que indica el número del disco que quiere crear para abrir el XML correspondiente
     */
    void ParseXML(int i);
    /**
     * @brief listNodeChild esta función es la encargada de acceder a la parte del nodo hijo del archivo, para obtener los parametros
     * @param inElem es el elemento que hace referencia al nodo padre del archivo
     * @param lv es para saber en el nivel que se encuentra del archivo
     */
    void listNodeChild(QDomElement inElem,int lv);
    /**
     * @brief GetPuerto función para obtener el puerto leido en el XML
     * @return el puerto de acceso del disco creado
     */
    int GetPuerto();
    /**
     * @brief GetIP función para obtener la ip leido en el XML
     * @return la ip de acceso del disco creado
     */
    QString GetIP();
    /**
     * @brief GetPath función para obtener la dirección de acceso del archivo leido en el XML
     * @return el Path de acceso del disco creado
     */
    QString GetPath();


};

#endif // TECFSDISK_H
