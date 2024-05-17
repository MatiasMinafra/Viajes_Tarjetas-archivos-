#include <iostream>
#include <string.h>
using namespace std;

void cargarCadena(char *pal, int tam)
{
    int i;
    fflush(stdin); /// limpia el buffer de entrada para que la carga se haga sin caracteres que hayan quedado sin usar
    for (i = 0; i < tam; i++)
    {
        pal[i] = cin.get();
        if (pal[i] == '\n')
            break;
    }
    pal[i] = '\0';
    fflush(stdin); /// vuelve a limpiar el buffer para eliminar los caracteres sobrantes
}

class Fecha
{
private:
    int dia, mes, anio;

public:
    Fecha(int d = 0, int m = 0, int a = 0)
    {
        dia = d;
        mes = m;
        anio = a;
    }
    void Mostrar();
    void Cargar();
    int getanio()
    {
        return anio;
    }
    void setDia(int d)
    {
        dia = d;
    }
    void setMes(int m)
    {
        mes = m;
    }
    void setAnio(int a)
    {
        anio = a;
    }
};

void Fecha::Mostrar()
{
    cout << dia << "/" << mes << "/" << anio << endl;
}

void Fecha::Cargar()
{
    cout << "DIA: ";
    cin >> dia;
    cout << "MES: ";
    cin >> mes;
    cout << "A" << char(165) << "O: ";
    cin >> anio;
}

class Tarjeta
{

    int _numeroTarjeta;
    Fecha fecha;
    int _dni;
    float _saldo;
    bool _estado;

public:
    Tarjeta()
    {
        _numeroTarjeta = 0;
        _dni = 0;
        _saldo = 0;
        _estado = true;
    }
    void cargar()
    {
        cout << " ingrese el numero de la tarjeta " << endl;
        cin >> _numeroTarjeta;
        fecha.Cargar();
        cout << " ingrese el dni " << endl;
        cin >> _dni;
        cout << "ingrese el saldo " << endl;
        cin >> _saldo;
        _estado = true;
    }
    void mostrar()
    {
        cout << _numeroTarjeta << endl;
        cout << _dni << endl;
        cout << _saldo << endl;
        fecha.Mostrar();
    }
    int getnumerotarjeta()
    {
        return _numeroTarjeta;
    }
    void setnumerotarjeta(int numeroTarjeta)
    {
        _numeroTarjeta = numeroTarjeta;
    }
    int getdni()
    {
        return _dni;
    }
    void setdni(int dni)
    {
        _dni = dni;
    }
    float getsaldo()
    {
        return _saldo;
    }
    void setsaldo(int saldo)
    {
        _saldo = saldo;
    }
    int getestado()
    {
        return _estado;
    }
};

class ArchivoTarjeta
{
private:
    char nombre[30];

public:
    ArchivoTarjeta(const char *n = "tarjeta.dat")
    {
        strcpy(nombre, n);
    }
    bool grabarRegistro(Tarjeta &obj);
    Tarjeta leerRegistro(int pos);
    int buscarRegistro(int num);
    int contarRegistros();
    bool modificarRegistro(Tarjeta obj, int pos);
    void listarRegistros();
};
bool ArchivoTarjeta::grabarRegistro(Tarjeta &obj)
{
    FILE *p;
    p = fopen(nombre, "ab");
    if (p == NULL)
    {
        cout << "error " << endl;
        exit(1);
    }
    bool escribio = fwrite(&obj, sizeof(Tarjeta), 1, p);

    fclose(p);
    return escribio;
}
Tarjeta ArchivoTarjeta::leerRegistro(int pos)
{
    FILE *p;
    Tarjeta obj;
    p = fopen(nombre, "rb");
    if (p == NULL)
    {
        cout << " error " << endl;
        exit(1);
    }
    fseek(p, sizeof(Tarjeta) * pos, 0);
    fread(&obj, sizeof(Tarjeta), 1, p);
    fclose(p);
    return obj;
}

int ArchivoTarjeta::buscarRegistro(int numerotarjeta)
{
    FILE *p;
    Tarjeta obj;
    p = fopen(nombre, "rb");
    if (p == NULL)
    {
        cout << " erorr " << endl;
        exit(1);
    }
    int pos = 0;
    while (fread(&obj, sizeof(Tarjeta), 1, p) == 1)
    {
        if (obj.getnumerotarjeta() == numerotarjeta)
        {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}
int ArchivoTarjeta::contarRegistros()
{
    FILE *p;
    p = fopen(nombre, "rb");
    if (p == NULL)
    {
        cout << " erorr " << endl;
        exit(1);
    }
    fseek(p, 0, SEEK_END);
    int cantidadRegistros = ftell(p) / sizeof(Tarjeta);
    fclose(p);
    return cantidadRegistros;
}
bool ArchivoTarjeta::modificarRegistro(Tarjeta obj, int pos)
{
    FILE *p;
    p = fopen(nombre, "rb+");
    if (p == NULL)
    {
        cout << " erorr " << endl;
        exit(1);
    }
    fseek(p, sizeof(Tarjeta) * pos, 0);
    bool escribio = fwrite(&obj, sizeof(Tarjeta), 1, p);
    fclose(p);
    return escribio;
}

void ArchivoTarjeta::listarRegistros()
{
    FILE *p;
    Tarjeta obj;
    p = fopen(nombre, "rb");
    if (p == NULL)
    {
        cout << " erorr " << endl;
        exit(1);
    }
    while (fread(&obj, sizeof(Tarjeta), 1, p) == 1)
    {
        obj.mostrar();
    }
    fclose(p);
}

class Viaje
{
private:
    int _numerodeviaje;
    int _numerotarjeta;
    int _transporte; // son 3 tipos de transportes
    Fecha _fecha;
    float _importeDelViaje;
    bool _estado;

public:
    Viaje()
    {
        int _numerodeviaje = 0;
        int _numerotarjeta = 0;
        int _transporte = 0;
        float _importeDelViaje = 0;
        bool _estado;
    }
    int get_numerodeviaje()
    {
        return _numerodeviaje;
    }
    void set_numerodeviaje(int numerodeviaje)
    {
        _numerodeviaje = numerodeviaje;
    }
    int get_numerotarjeta()
    {
        return _numerotarjeta;
    }
    void set_numerotarjeta(int numerotarjeta)
    {
        _numerotarjeta = numerotarjeta;
    }
    int get_transporte()
    {
        return _transporte;
    }
    void set_transporte(int transporte)
    {
        _transporte = transporte;
    }
    Fecha get_fecha()
    {
        return _fecha;

    }
    void set_fecha(int dia,int mes,int anio)
    {
        _fecha.setAnio(anio);
        _fecha.setMes(mes);
        _fecha.setDia(dia);
    }
    int get_importedelviaje()
    {
        return _importeDelViaje;
    }
    void set_importedelviaje(float importedelviaje)
    {
        _importeDelViaje = importedelviaje;
    }
    int get_estado()
    {
        return _estado;
    }
    void set_estado(int estado)
    {
        _estado = estado;
    }

    void cargar()
    {
        cout << "Ingrese numero de viaje " << endl;
        cin >> _numerotarjeta;
        cout << "ingrese numero de tarjeta " << endl;
        cin >> _numerotarjeta;
        cout << " Ingrese transporte " << endl;
        cin >> _transporte;
        _fecha.Cargar();
        cout << "Ingrese importe del viaje " << endl;
        cin >> _importeDelViaje;
        _estado = true;
    }

    void mostrar()
    {
        cout << _numerodeviaje << endl;
        cout << _numerotarjeta << endl;
        cout << _transporte << endl;
        _fecha.Mostrar();
        cout << _importeDelViaje << endl;
    }
};

class ArchivoViaje
{
private:
    char nombre[30];

public:
    ArchivoViaje(const char *n = "viaje.dat")
    {
        strcpy(nombre, n);
    }
    bool grabarRegistro(Viaje &obj);
    Viaje leerRegistro(int pos);
    int buscarRegistro(int num);
    int contarRegistros();
    bool modificarRegistro(Viaje obj, int pos);
    bool listarRegistros();
    void bajalogicaViaje();
};

bool ArchivoViaje::grabarRegistro(Viaje &obj)
{
    FILE *p;
    p = fopen("viajesAnioActual.dat", "ab");
    if (p == NULL)
    {
        cout << "error " << endl;
        exit(1);
    }
    bool escribio = fwrite(&obj, sizeof(Viaje), 1, p);

    fclose(p);
    return escribio;
}
Viaje ArchivoViaje::leerRegistro(int pos)
{
    FILE *p;
    Viaje obj;
    p = fopen(nombre, "rb");
    if (p == NULL)
    {
        cout << " error " << endl;
        return obj;
    }
    fseek(p, pos*sizeof(Viaje), 0);
    fread(&obj, sizeof(Viaje), 1, p);
    fclose(p);
    return obj;
}

int ArchivoViaje::buscarRegistro(int numeroDeViaje)
{
    FILE *p;
    Viaje obj;
    p = fopen(nombre, "rb");
    if (p == NULL)
    {
        cout << " erorr " << endl;
        exit(1);
    }
    int pos = 0;
    while (fread(&obj, sizeof(Viaje), 1, p) == 1)
    {
        if (obj.get_numerodeviaje() == numeroDeViaje)
        {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}
bool ArchivoViaje::listarRegistros()
{
    FILE *p;
    Viaje obj;
    p=fopen(nombre, "rb");
    if(p==NULL) return false;
    while(fread(&obj, sizeof obj, 1, p)==1)
    {
        obj.mostrar();
        cout<<endl;
    }
    fclose(p);
    return true;
}
int ArchivoViaje::contarRegistros()
{
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2);///funcion que permite ubicarse dentro del archivo, en este caso lo ubique al final EOF
    int tam=ftell(p);///me devuelve la cantidad de bytes que hay desde el principio del archivo a la posici�n actual del indicador de pFILE.
    fclose(p);
    return tam/sizeof(Viaje);

}
bool bajaLogicaViaje()
{
    Viaje reg;
    ArchivoViaje archiViaje("viaje.dat");
    cout<<"INGRESE EL NUMERO DE viaje  A BORRAR ";
    int num;
    cin>>num;
    int pos=archiViaje.buscarRegistro(num);
    if(pos<0)
    {
        cout<<"NO SE ENCUENTRA EL REGISTRO"<<endl;
        return false;
    }
    reg=archiViaje.leerRegistro(pos);
        reg.mostrar();
    cout<<"ESTA SEGURO DE ELIMINAR EL REGISTRO ? (S/N) ";
    char respuesta;
    cin>>respuesta;
    if(respuesta=='S' || respuesta =='s')
    {
        reg.set_estado(false);
        if(archiViaje.modificarRegistro(reg,pos))
        {
            cout<<"REGISTRO ELIMINADO";
        }
        else
        {
            cout<<"NO SE PUDO ELIMINAR EL REGISTRO";
        }
        cout<<endl;
    }

}








//  a) Informar para un número de tarjeta que se ingresa por teclado la cantidad de viajes
// realizados en cada uno de los medios de transporte el año pasado.
//  b) El viaje con menor importe. Mostrar todo el registro.
//  c) El mes de mayor recaudación por viajes en subte entre todos los años,
// sin tener en cuenta el año actual.
// d) Generar un archivo con los registros de los viajes del año actual.

//e) Informar para un número de tarjeta que se ingresa por teclado la cantidad de viajes
// realizados en cada uno de los años transcurridos.

//f) El viaje con mayor importe. Mostrar todo el registro.

//g) El mes de menor recaudación por viajes en tren entre todos los años, sin tener en cuenta
//el año actual.


void punto1()
{
    ArchivoViaje archV("viaje.dat");
    Viaje objetoViaje;
    int cantidad=archV.contarRegistros();
    int numTarjetaNuevo;
    int tipos_viajes[3]= {};
    cout << "Ingrese el numero de la tarjeta " << endl;
    cin >> numTarjetaNuevo;
    for (size_t i = 0; i < cantidad; i++)
    {
        objetoViaje=archV.leerRegistro(i);
        if (numTarjetaNuevo==objetoViaje.get_numerotarjeta())
        {
            tipos_viajes[objetoViaje.get_transporte()-1]++;
        }
    }
    cout << "la cantidad de viajes para el colectivo es: " << tipos_viajes[0] << endl;
    cout << "la cantidad de viajes para subte es: " << tipos_viajes[1] << endl;
    cout << "la cantidad de viajes para el tren es: " << tipos_viajes[2] << endl;
}
void punto2()
{
    ArchivoViaje archV("viaje.dat");
    Viaje objetoViaje,barato;
    int cantidad = archV.contarRegistros();
    int menorviaje=1;
    for (size_t i = 0; i < cantidad; i++)
    {
        objetoViaje=archV.leerRegistro(i);
        if (i==0)
        {
            menorviaje=objetoViaje.get_importedelviaje();
            barato=objetoViaje;
        }
        else if(objetoViaje.get_importedelviaje()<menorviaje)
        {
            menorviaje=objetoViaje.get_importedelviaje();
            barato=objetoViaje;
        }

    }
    cout << " este es el menor viaje  " << menorviaje << endl;
    barato.mostrar();
}
void punto3()
{
    ArchivoViaje archV("viaje.dat");
    Viaje objetoViaje;
    Fecha fecha;
    float v_Meses[12]= {};
    int cantidad=archV.contarRegistros();
    int mesmaximo=0;
    int indiceMaximo;
    for (size_t i = 0; i < cantidad; i++)
    {
        objetoViaje=archV.leerRegistro(i);
        if (fecha.getanio()==2023 && objetoViaje.get_transporte()==3)
        {
            v_Meses[objetoViaje.get_transporte()-1]+=objetoViaje.get_importedelviaje();
        }
        for (size_t i = 0; i < 12; i++)
        {
            if (v_Meses[i]>mesmaximo)
            {
                mesmaximo=v_Meses[i];
                indiceMaximo=i+1;
            }

        }

    }
    cout << "el mes de mayor recaudacion para el subte fue " << indiceMaximo << endl;
}
void punto4()
{
    ArchivoViaje archV("viaje.dat");
    Viaje objetoViaje;
    Fecha fecha;
    int cantidad=archV.contarRegistros();
    for (size_t i = 0; i < cantidad; i++)
    {
        objetoViaje=archV.leerRegistro(i);
        if (fecha.getanio()==2023)
        {
            archV.grabarRegistro(objetoViaje)==false;
            cout << "No se pudo grabar el registro " << endl;
            return;
        }
    }
}
//e) Informar para un número de tarjeta que se ingresa por teclado la cantidad de viajes
// realizados en cada uno de los años transcurridos.

void punto5()
{
    ArchivoViaje archV("viaje.dat");
    Viaje objetoViaje;
    Fecha fecha;
    int anioMinimo=0;
    int anioMaximo=0;


    int cantidad=archV.contarRegistros();
    int numTarjetaNuevo;
    cout << "Ingrese el numero de la tarjeta " << endl;
    cin >> numTarjetaNuevo;
    for (size_t i = 0; i < cantidad; i++)
    {
        objetoViaje=archV.leerRegistro(i);
        if(i==0)
        {
            anioMinimo==objetoViaje.get_fecha().getanio();
            anioMaximo==objetoViaje.get_fecha().getanio();

        }
        else if (objetoViaje.get_fecha().getanio()>anioMaximo)
        {
            anioMaximo=objetoViaje.get_fecha().getanio();
        }
        else if(objetoViaje.get_fecha().getanio()<anioMinimo)
        {
            anioMinimo=objetoViaje.get_fecha().getanio();

        }
    }
      for(int anio=anioMinimo; anio<=anioMaximo; anio++){
        int cantidadViajes=0;
        for(size_t j = 0; j < cantidad; j++)
        {
            objetoViaje=archV.leerRegistro(j);
            if(objetoViaje.get_fecha().getanio()==anio&&objetoViaje.get_numerotarjeta()==numTarjetaNuevo){
                    cantidadViajes++;
            }

    }
     cout << " para la tarjeta " << numTarjetaNuevo << " el anio " << anio << "fue de " << cantidadViajes << endl;
    }


}
//k) Generar un archivo para registrar por cada número de tarjeta la cantidad de viajes realizados
//  en colectivos el año pasado. Cada registro debe tener el número de tarjeta, el DNI del dueño y la cantidad de viajes.
class PuntoK{
int _dni;
int _num_tarjeta;
int _cantidad_viajes;
public:
 void set_dni(int dni){
     _dni=dni;
 }
 void set_num_tarjeta(int numerotarjeta){
 _num_tarjeta=numerotarjeta;
 }
 void set_cantidad_viajes(int cantidadviajes){
    _cantidad_viajes=cantidadviajes;
 }

 bool grabardisco(){
     bool escribio=false;
     FILE *p;
     p=fopen("puntoK.dat","ab");
     if(p=NULL){
        cout << "No se pudo abrir " << endl;
        return false;
     }
    escribio=fwrite(this,sizeof(PuntoK),1,p);
    return escribio;
 }

};
void puntoK(){
 ArchivoTarjeta archT("tarjeta.dat");
 Tarjeta objetoTarjeta;
 ArchivoViaje archV("viaje.dat");
 Viaje objetoViaje;
 PuntoK objetok;
 int cantidad=archT.contarRegistros();
 int cantidadViajes=archV.contarRegistros();
 int numero_tarjeta;
 for(int i=0; i<cantidad; i++){
     objetoTarjeta=archT.leerRegistro(i);
     int contadorViaje=0;
  for(int j=0; j<cantidadViajes; j++){
       objetoViaje= archV.leerRegistro(j);
    if(objetoViaje.get_transporte()==1&&objetoViaje.get_fecha().getanio()==2023&&objetoViaje.get_numerotarjeta()==objetoTarjeta.getnumerotarjeta()){
        contadorViaje++;
    }


  }
    objetok.set_cantidad_viajes(contadorViaje);
    objetok.set_dni(objetoTarjeta.getdni());
    objetok.set_num_tarjeta(objetoTarjeta.getnumerotarjeta());
    objetok.grabardisco();

 }

}






int main()
{
    ArchivoViaje("viaje.dat");
    ArchivoViaje archivoRegistrosDeViajes;
    ArchivoTarjeta("tarjeta.dat");
    ArchivoTarjeta archivoRegistrosDeTarjetas;
    Tarjeta t1;
    Viaje v1;
    bool salir = false;
    while (salir==false)
    {
        int opciones;
        cout << " MENU " << endl;
        cout << "____________________" << endl;
        cout << "OPCIONES " << endl;
        cout << "____________________" << endl;
        cout << "1-Cargar Tarjetas " << endl;
        cout << "2- Listar tarjetas " << endl;
        cout << "3- Cargar viajes " << endl;
        cout << "4- Listar viajes " << endl;
        cout << "5- cantidad de viajes realizados por cada transporte " << endl;
        cout << "6- el viaje con menor importe es " << endl;
        cout << "7- cantidad de viajes en el anio actual " << endl;
        cout << "8- cantidad de viajes realizados por anio " << endl;


        cout << "-9 baja logica del registro " << endl;
        cout << "10- salir " << endl;

        cin >> opciones;
        switch (opciones)
        {
        case 0:
            salir=true;
            break;

        case 1:
            t1.cargar();
            archivoRegistrosDeTarjetas.grabarRegistro(t1);
            break;

        case 2:
            archivoRegistrosDeTarjetas.listarRegistros();

            break;
        case 3:
            v1.cargar();
            archivoRegistrosDeViajes.grabarRegistro(v1);
            break;

        case 4:
            archivoRegistrosDeViajes.listarRegistros();
            break;

        case 5:
            punto1();

            break;
        case 6:
            punto2();
            break;
        case 7:
            punto4();
            break;
        case 8:
            punto5();
            break;
        case 9:
            archivoRegistrosDeViajes.bajalogicaViaje();
            break;
        case 10:
            break;

        default:



            break;
        }



    }

    return 0;
}
