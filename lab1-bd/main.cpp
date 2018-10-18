#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

enum _retorno{OK, ERROR, NO_IMPLEMENTADA};
typedef _retorno TipoRet;

struct nodoListaArg{
    int pos;
    string info;
    nodoListaArg * ant;
    nodoListaArg * sig;
};
typedef nodoListaArg * ListaAgr;

struct nodoListaCelda{
    int nroCelda;
    string info;
    nodoListaCelda * sig;
};
typedef nodoListaCelda * ListaCelda;

struct nodoListaCampo{
	string nombreCampo;
	string tipoCampo;
	int nroCampo;
	nodoListaCampo * sig;
};
typedef nodoListaCampo * ListaCampo;

struct  nodoListaTupla{
	int indice;
	ListaCelda celda;
};
typedef nodoListaTupla * ListaTupla;

struct nodoListaTabla{
    string nombre;
    int nroCampos = 0;
    ListaCampo campo;
    ListaTupla tupla;
    nodoListaTabla * sig;
};
typedef nodoListaTabla * ListaTabla;

/** FUNCIONES AUXILIARES */
void readInput( string comando ); //Interpreta el comando de entrada
void printHelp(); // Imprime la Ayuda con los comandos validos
bool addTabla( ListaTabla &T, string nombreTabla );
string getParametros(ListaAgr L);
void imprimirArg(ListaAgr L);
void clearArg(ListaAgr L);
void addArgFinal(ListaAgr L, string arg);
void cargarListaArg(ListaAgr L, string allArg);

int main(){
    ListaTabla T = new nodoListaTabla; //dummy
    T->sig = NULL;

    string comando;
    while(comando!="exit"){
        getline(cin, comando);
        if( comando.empty()!=true )
            readInput(comando);
        else
            cout << "No ha ingresado ningun comando" <<endl;
    }
    return 0;
}

void printHelp(){
    cout <<endl<< "AYUDA DE COMANDOS: "<<endl;
    cout << "Nota: todos los comandos son 'case sensitive' "<<endl;
    cout << "  help  _______________________________________________________________________* IMPRIME LA AYUDA EN PANTALLA *" <<endl<<endl;
    cout << "  createTable(nombreTabla) ____________________________________________________* CREA UNA NUEVA TABLA *"<<endl<<endl;
    cout << "\t\tEjemplo:\t\tcreateTable(Empleados)"<<endl<<endl;
    cout << "  dropTable(nombreTabla) ______________________________________________________* ELIMINA UNA TABLA EXISTENTE *" <<endl<<endl;
    cout << "\t\tEjemplo:\t\tdropTable(Productos)"<<endl<<endl;
    cout << "  addCol(nombreTabla, nombreCol) ______________________________________________* AGREGA UNA NUEVA COLUMNA A LA TABLA EXISTENTE *" <<endl<<endl;
    cout << "\t\tEjemplo:\t\taddCol(Empleados, Apellido)"<<endl<<endl;
    cout << "  dropCol(nombreTabla, nombreCol) _____________________________________________* ELIMINA UNA COLUMNA DE UNA TABLA *" <<endl<<endl;
    cout << "\t\tEjemplo:\t\tdropCol(Proyectos, idProyecto)"<<endl<<endl;
    cout << "  insertInto(nombreTabla, valoresTupla) _______________________________________* INSERTA UN NUEVO REGISTRO EN LA TABLA *" <<endl<<endl;
    cout << "\t\tEjemplo:\t\tinsertInto(Personas, 3333111: Telma: Perez)"<<endl<<endl;
    cout << "  deleteFrom(nombreTabla, condicionEliminar) __________________________________* ELIMINA UN REGISTRO DE UNA TABLA *" <<endl<<endl;
    cout << "\t\tEjemplo:\t\tdeleteFrom(Personas, Perez)"<<endl<<endl;
    cout << "  update(nombreTabla, condicionModificar, columnaModificar, valorModificar) ___* ACTUALIZA UN CAMPO DE UNA TABLA *" <<endl<<endl;
    cout << "\t\tEjemplo:\t\tupdate(Personas, Nombre=Pepe: CI: 1555000)"<<endl<<endl;
    cout << "  printDataTable(Clientes) _________________________________________________* IMPRIME TODOS LOS REGISTROS DE UNA TABLA *" <<endl<<endl;
    cout << "\t\tEjemplo:\t\tprintDataTable(Clientes)"<<endl<<endl;
}


/****************     LEE EL INGRESO DE LOS COMANDOS     ************************/
void readInput(string comando){
    string actual;
    int nroComas =0;
    int nroArg=0;

    for (int i=0; i<comando.length(); ++i){ // Borra todos los espacios en blanco y cuenta los parametros que trae
        actual = comando[i];
        if( actual==" " ){
            comando.erase(i, 1);
            i--;
        }
        if( actual=="," ){
            nroComas++;
        }
    }

    size_t posApertura = comando.find("(");      // posicion del parentesis de apertura
    string sentencia = comando.substr(0,posApertura); //setencia ingresada con espacios
    size_t posCierre = comando.find(")");        // posicion de parentesis de cierre
    string allArg = comando.substr(posApertura+1 ,(posCierre - posApertura -1)); // obtiene el contenido de los argumentos

    if( allArg.empty() || allArg == " " )
        nroArg = 0;
    else
        nroArg = nroComas+1;

    cout << "El comando ingresado es: " << sentencia <<endl;
    cout << "Y los argumentos son: " << allArg << endl;
    cout << "El largo del comando es: " << comando.length()<<endl;
    cout << "Numero de argumentos: " << nroArg <<endl;

    //Se cargan los argumentos en una lista
    ListaAgr listaArg = new nodoListaArg;
    listaArg->pos = 0;
    listaArg->ant = NULL;
    listaArg->sig = NULL;
    cargarListaArg(listaArg, allArg);
    imprimirArg(listaArg);


    if( sentencia=="createTable" && nroArg==1 ){ //createTable( nombreTabla)

    }

    if( sentencia=="dropTable" && nroArg==1 ){ // dropTable( nombreTabla )

    }

    if( sentencia == "addCol" && nroArg==2 ) {//addCol( nombreTabla, nombreCol )

    }

    if( sentencia == "dropCol" && nroArg==2 ){ //   dropCol( nombreTabla, nombreCol)

    }

    if( sentencia == "insertInto" && nroArg>1 )// insertInto( nombreTabla,valoresTupla")

    if( sentencia == "deleteFrom" && nroArg==1 ) //deleteFrom( nombreTabla, condicionEliminar )

    if( sentencia == "update" && nroArg>3  ) // update( nombreTabla, condicionModificar, columnaModificar, valorModificar)

    if( sentencia == "printDataTable" )// printDataTable( nombreTabla );

    if( sentencia == "help" && nroArg==0  )//  printHelp()
        printHelp();
    if(sentencia!="createTable" && sentencia!="dropTable" && sentencia!="addCol" && sentencia!="dropCol" && sentencia!="insertInto" && sentencia!="deleteFrom" && sentencia!="update" && sentencia!="printDataTable" && sentencia!="help" )
        cout << "\t¡EL comando '" << comando <<"' no es valido!" << '\n';
}

string getParametro(ListaAgr L){
    string dato;
    return dato;
}

void addArgFinal(ListaAgr L, string arg){
    ListaAgr nuevo = new nodoListaArg;
    ListaAgr aux = L;
    nuevo->info = arg;
    nuevo->sig = NULL;
    while( aux->sig!=NULL )
        aux = aux->sig;
    aux->sig = nuevo;
    nuevo->ant = aux;
    nuevo->pos = aux->pos+1;
}

void clearArg(ListaAgr L){
    ListaAgr aux = L;
    aux = aux->sig;
}

void imprimirArg(ListaAgr L){
    if( L != NULL ){
        cout<< "|"<<L->pos<< " = "<<L->info<<"|"<<endl;
        imprimirArg( L->sig );
    }
}

void cargarListaArg(ListaAgr L, string allArg){
    int largo = allArg.length();
    char parametros[largo];
    int inicio=0;
    string dato;
    strcpy(parametros,allArg.c_str());

    for(int i=0; i<= largo; i++){
        if( parametros[i]!=','){
            dato += parametros[i];
        }else{
            addArgFinal(L, dato);
            dato="";
        }
    }
    addArgFinal(L, dato);
}


bool addTabla( ListaTabla &T, string nombreTabla){

}
