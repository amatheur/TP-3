template <typename T>
string_map<T>::string_map(): _raiz(NULL), _size(0){

}

template <typename T>
string_map<T>::Nodo::Nodo() {
    definicion = NULL;
    siguientes = new Nodo*[256];
    for(int i = 0; i < 256; i++){
        siguientes[i] = NULL;
    }
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    _destroy(_raiz);
    _raiz = NULL;
    _copiar(_raiz, d._raiz);
    _size = d._size;
}

template <typename T>
string_map<T>::~string_map(){
    _destroy(_raiz);
    _size = 0;
}

template <typename T>
T& string_map<T>::operator[](const string& clave) {
    if (empty()) {
        _raiz = new Nodo;
    }
    Nodo* actual = _raiz;
    for (int i = 0; i < clave.size(); i++) {
        if (actual->siguientes[int(clave[i])] == NULL) {
            actual->siguientes[int(clave[i])] = new Nodo;
        }
        actual = actual->siguientes[int(clave[i])];
    }
    if (actual->definicion == NULL) {
        actual->definicion = new T;
        _size ++;
    }
    return *(actual->definicion);
}


template <typename T>
int string_map<T>::count(const string& clave) const{
    Nodo *actual = _raiz;
    if (empty()) {
        return 0;
    }
    if(clave.size() == 0){
        if(actual->definicion == NULL){
            return 0;
        } else{
            return 1;
        }
    }
    for (int i = 0; i < clave.size(); i++) {
        if (actual->siguientes[int(clave[i])] == NULL) {
            return 0;
        } else {
            actual = actual->siguientes[int(clave[i])];
        }
    }
    if (actual->definicion == NULL) {
        return 0;
    }else{
        return 1;
    }
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo *actual = _raiz;
    for (int i = 0; i < clave.size(); i++) {
        actual = actual->siguientes[int(clave[i])];
    }
    return *(actual->definicion);
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo *actual = _raiz;
    for (int i = 0; i < clave.size(); i++) {
        actual = actual->siguientes[int(clave[i])];
    }
    return *(actual->definicion);
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    vector<Nodo*> pila;
    Nodo *actual = _raiz;
    for (int i = 0; i < clave.size(); i++) {
        pila.push_back(actual);
        actual = actual->siguientes[int(clave[i])];
    }
    delete actual->definicion;
    actual->definicion = NULL;
    for (int j = clave.size() - 1; j == 0; ++j) {
        if(actual->noTieneHijos() and actual->definicion == NULL and pila.size()!= 0){
            if(actual == _raiz){
                _raiz = NULL;
            }

            delete(actual);
            actual = pila.back();
            pila.pop_back();
            actual->siguientes[int(clave[j])] = NULL;
        }
    }
    _size --;
}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    return _raiz == NULL;
}

template <typename T>
bool string_map<T>::Nodo::noTieneHijos() {
    for (int i = 0; i < 256; ++i) {
        if(siguientes[i] != NULL){
            return false;
        }
    }
    return true;
}

template <typename T>
void string_map<T>::_destroy(Nodo* &raiz) {

    if(raiz != NULL) {
        for (int i = 0; i < 256; ++i) {
            if (raiz->siguientes[i] != NULL) {
                _destroy(raiz->siguientes[i]);
            }
        }
        delete(raiz);
        raiz = NULL;
    }
}

template <typename T>
void string_map<T>::_copiar(Nodo*& padre, Nodo* aCopiar) {
    if(aCopiar != NULL){
        padre = new Nodo;
        if(aCopiar->definicion != NULL){
            padre->definicion = new T(*(aCopiar->definicion));
        }
        for (int i = 0; i < 256; i++) {
            if(aCopiar->siguientes[i] != NULL){
                padre->siguientes[i] = aCopiar->siguientes[i];
                _copiar(padre->siguientes[i], aCopiar->siguientes[i]);
            }
        }
    }

}

template <typename T>
string_map<T>::Nodo::~Nodo() {
    delete(definicion);
    delete[](siguientes);
}