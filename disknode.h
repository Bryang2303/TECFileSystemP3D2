#ifndef DISKNODE_H
#define DISKNODE_H
#include "QList"


class DiskNode
{
public:
    /**
     * @brief puertos Lista donde se mantienen los puertos de acceso de los disco para mejor acceso del Controller Node
     */
    QList<int> puertos;
    /**
     * @brief IPs Lista donde se mantienen la ip de acceso de los disco para mejor acceso del Controller Node
     */
    QList<QString> IPs;
    /**
     * @brief PathD Lista donde se mantienen el path de acceso de cada disco para mejor acceso del Controller Node
     */
    QList<QString> PathD;
    /**
     * @brief sizeD Tamano del disco(Cantidad de bloques)
     */
    int sizeD;
    /**
     * @brief sizeB Tamano de los bloques del disco(Cantidad de archivos)
     */
    int sizeB;
    /**
     * @brief DiskNode Constructor
     */
    DiskNode();
    /**
     * @brief crearDisk funcion que se encarga de instalar el TECFSDisk para la creación de los discos y sus acceso
     */
    void crearDisk();
    /**
     * @brief get_tamanoDisk obtener el tamaño del disco
     * @return tamano determinado
     */
    int get_tamanoDisk();
    /**
     * @brief get_tamanoBloque obtener el tamaño de cada  bloque
     * @return tamano determinado
     */
    int get_tamanoBloque();
    /**
     * @brief getpuertofunción para obtener el puerto del disco requerido
     * @return el puerto de acceso del disco
     */
    int getpuerto(int i);
    /**
     * @brief getIP función para obtener la ip del disco requerido
     * @return la ip de acceso del disco
     */
    QString getIP(int p);
    /**
     * @brief getpath función para obtener la dirección de acceso del disco requerido
     * @return el Path de acceso del disco
     */
    QString getpath(int r);
};

#endif // DISKNODE_H
