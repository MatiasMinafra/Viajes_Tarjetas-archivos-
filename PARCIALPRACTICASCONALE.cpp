
#incluide<iostream>
using namespace std;
class Material {
private:
    int codigo;
    std::string nombre;
    std::string marca;
    std::string tipo;
    double precio_unitario;
    bool activo;

public:
    // Constructor
    Material(int codigo, const std::string& nombre, const std::string& marca, const std::string& tipo, double precio_unitario, bool activo)
        : codigo(codigo), nombre(nombre), marca(marca), tipo(tipo), precio_unitario(precio_unitario), activo(activo) {}

    // Métodos get
    int getCodigo() const {
        return codigo;
    }

    std::string getNombre() const {
        return nombre;
    }

    std::string getMarca() const {
        return marca;
    }

    std::string getTipo() const {
        return tipo;
    }

    double getPrecioUnitario() const {
        return precio_unitario;
    }

    bool getActivo() const {
        return activo;
    }

    // Métodos set
    void setCodigo(int codigo) {
        this->codigo = codigo;
    }

    void setNombre(const std::string& nombre) {
        this->nombre = nombre;
    }

    void setMarca(const std::string& marca) {
        this->marca = marca;
    }

    void setTipo(const std::string& tipo) {
        this->tipo = tipo;
    }

    void setPrecioUnitario(double precio_unitario) {
        this->precio_unitario = precio_unitario;
    }

    void setActivo(bool activo) {
        this->activo = activo;
    }

    // Método para mostrar los datos
    void mostrar() const {
        std::cout << "Código: " << codigo << std::endl;
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Marca: " << marca << std::endl;
        std::cout << "Tipo: " << tipo << std::endl;
        std::cout << "Precio unitario: " << precio_unitario << std::endl;
        std::cout << "Activo: " << (activo ? "Sí" : "No") << std::endl;
    }

    // Método para cargar los datos desde la entrada estándar
    void cargar() {
        std::cout << "Ingrese el código: ";
        std::cin >> codigo;

        std::cout << "Ingrese el nombre: ";
        std::cin >> nombre;

        std::cout << "Ingrese la marca: ";
        std::cin >> marca;

        std::cout << "Ingrese el tipo: ";
        std::cin >> tipo;

        std::cout << "Ingrese el precio unitario: ";
        std::cin >> precio_unitario;

        std::cout << "Ingrese si está activo (1: Sí, 0: No): ";
        std::cin >> activo;
    }
};
class Compra {
private:
    int numero_compra;
    int numero_proveedor;
    int codigo_material;
    int codigo_obra;
    int cantidad;
    double importe;
    int dia;
    int mes;
    int ano;
    bool activo;

public:
    // Constructor
    Compra(int numero_compra, int numero_proveedor, int codigo_material, int codigo_obra, int cantidad, double importe, int dia, int mes, int ano, bool activo)
        : numero_compra(numero_compra), numero_proveedor(numero_proveedor), codigo_material(codigo_material), codigo_obra(codigo_obra), cantidad(cantidad),
          importe(importe), dia(dia), mes(mes), ano(ano), activo(activo) {}

    // Métodos get
    int getNumeroCompra() const {
        return numero_compra;
    }

    int getNumeroProveedor() const {
        return numero_proveedor;
    }

    int getCodigoMaterial() const {
        return codigo_material;
    }

    int getCodigoObra() const {
        return codigo_obra;
    }

    int getCantidad() const {
        return cantidad;
    }

    double getImporte() const {
        return importe;
    }

    int getDia() const {
        return dia;
    }

    int getMes() const {
        return mes;
    }

    int getAno() const {
        return ano;
    }

    bool getActivo() const {
        return activo;
    }

    // Métodos set
    void setNumeroCompra(int numero_compra) {
        this->numero_compra = numero_compra;
    }

    void setNumeroProveedor(int numero_proveedor) {
        this->numero_proveedor = numero_proveedor;
    }

    void setCodigoMaterial(int codigo_material) {
        this->codigo_material = codigo_material;
    }

    void setCodigoObra(int codigo_obra) {
        this->codigo_obra = codigo_obra;
    }

    void setCantidad(int cantidad) {
        this->cantidad = cantidad;
    }

    void setImporte(double importe) {
        this->importe = importe;
    }

    void setDia(int dia) {
        this->dia = dia;
    }

    void setMes(int mes) {
        this->mes = mes;
    }

    void setAno(int ano) {
        this->ano = ano;
    }

    void setActivo(bool activo) {
        this->activo = activo;
    }

    // Método para mostrar los datos
    void mostrar() const {
        std::cout << "Número de compra: " << numero_compra << std::endl;
        std::cout << "Número de proveedor: " << numero_proveedor << std::endl;
        std::cout << "Código de material: " << codigo_material << std::endl;
        std::cout << "Código de obra: " << codigo_obra << std::endl;
        std::cout << "Cantidad: " << cantidad << std::endl;
        std::cout << "Importe: " << importe << std::endl;
        std::cout << "Fecha: " << dia << "/" << mes << "/" << ano << std::endl;
        std::cout << "Activo: " << (activo ? "Sí" : "No") << std::endl;
    }

    // Método para cargar los datos desde la entrada estándar
    void cargar() {
        std::cout << "Ingrese el número de compra: ";
        std::cin >> numero_compra;

        std::cout << "Ingrese el número de proveedor: ";
        std::cin >> numero_proveedor;

        std::cout << "Ingrese el código de material: ";
        std::cin >> codigo_material;

        std::cout << "Ingrese el código de obra: ";
        std::cin >> codigo_obra;

        std::cout << "Ingrese la cantidad: ";
        std::cin >> cantidad;

        std::cout << "Ingrese el importe: ";
        std::cin >> importe;

        std::cout << "Ingrese la fecha (dia mes año): ";
        std::cin >> dia >> mes >> ano;

        std::cout << "Ingrese si está activo (1: Sí, 0: No): ";
        std::cin >> activo;
    }
};
int main (){



return 0;
