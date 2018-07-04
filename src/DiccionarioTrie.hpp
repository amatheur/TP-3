template <typename T>
DiccionarioTrie<T>::DiccionarioTrie(): _raiz(NULL){

}

template <typename T>
DiccionarioTrie<T>::Nodo::Nodo() {
    significado = NULL;
    siguientes = new Nodo*[256];
    for(int i = 0; i < 256; i++){
        siguientes[i] = NULL;
    }
}

template <typename T>
DiccionarioTrie<T>::~DiccionarioTrie(){
    _destroy(_raiz);
}

template <typename T>
DiccionarioTrie::ItDiccTrie DiccionarioTrie<T>::Definir(const string& clave) {
    if (_raiz == NULL) {
        _raiz = new Nodo;
    }
    Nodo* actual = _raiz;
    Pila<Nodo*> padres;

    for (int i = 0; i < clave.size(); i++) {
        if (actual->siguientes[int(clave[i])] == NULL) {
            actual->siguientes[int(clave[i])] = new Nodo;
        }
        padres.push(actual);
        actual = actual->siguientes[int(clave[i])];
    }

    actual->significado = new T;

    return ItDiccTrie::ItDiccTrie(actual, padres, clave);
}


template <typename T>
bool DiccionarioTrie<T>::Definido(const string &clave) const{
    Nodo *actual = _raiz;
    if (actual == NULL) {
        return false;
    }
    if(clave.size() == 0){
        if(actual->significado == NULL){
            return false;
        } else{
            return true;
        }
    }
    for (int i = 0; i < clave.size(); i++) {
        if (actual->siguientes[int(clave[i])] == NULL) {
            return false;
        } else {
            actual = actual->siguientes[int(clave[i])];
        }
    }
    if (actual->significado == NULL) {
        return false;
    }else{
        return true;
    }
}



template <typename T>
T& DiccionarioTrie<T>::Significado(const string &clave) {
    Nodo *actual = _raiz;
    for (int i = 0; i < clave.size(); i++) {
        actual = actual->siguientes[int(clave[i])];
    }
    return *(actual->significado);
}


template <typename T>
void DiccionarioTrie::_destroy(Nodo* &raiz) {

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
DiccionarioTrie<T>::Nodo::~Nodo() {
    delete(significado);
    delete[](siguientes);
}

template <typename T>
DiccionarioTrie<T>::ItDiccTrie::ItDiccTrie() {
    _actual = NULL;
    Pila<DiccionarioTrie<T>::Nodo*> padres;
    _padres = padres;
}

template <typename T>
DiccionarioTrie<T>::ItDiccTrie::ItDiccTrie(Nodo *actual, Pila<Nodo *> padres, string clave) {
    _actual = actual;
    _padres = padres;
    _clave = clave;
}

template <typename T>
DiccionarioTrie<T>::ItDiccTrie DiccionarioTrie<T>::BuscarIterador(string clave) {
    Nodo* actual = _raiz;
    Pila<Nodo*> padres;

    for (int i = 0; i < clave.size(); i++) {
        padres.push(actual);
        actual = actual->siguientes[int(clave[i])];
    }

    return ItDiccTrie::ItDiccTrie(actual, padres, clave);
}

template <typename T>
bool DiccionarioTrie<T>::ItDiccTrie::HaySiguiente(Nodo *actual, int desde) const{
    for (int i = desde + 1; i < 256; ++i) {
        if(actual->siguientes[i] != NULL){
            return true;
        }
    }
    return false;
}

template <typename T>
int DiccionarioTrie<T>::ItDiccTrie::Siguiente(Nodo *actual, int desde) {
    for (int i = desde + 1; i < 256; ++i) {
        if(actual->siguientes[i] != NULL){
            return i;
        }
    }
}

template <typename T>
DiccionarioTrie<T>::ItDiccTrie DiccionarioTrie<T>::CrearIt() {
    Nodo* actual = _raiz;
    Pila<Nodo*> padres;
    string clave;
    ItDiccTrie s = ItDiccTrie();
    int sig;
    while(actual->significado == NULL && s.ItDiccTrie::HaySiguiente(actual, -1)){
        padres.push(actual);
        sig = s.ItDiccTrie::Siguiente(actual, -1);
        actual = actual->siguientes[sig];
        clave += (char)sig;
    }
    return ItDiccTrie::ItDiccTrie(actual, padres, clave);
}

template <typename T>
tuple<string, T> DiccionarioTrie<T>::ItDiccTrie::Actual() {
    return (_clave, *(_actual->significado));
}

template <typename T>
void DiccionarioTrie<T>::ItDiccTrie::Avanzar() {
    AvanzarAux();
    while (_actual->significado != NULL){
        AvanzarAux();
    }
}

template <typename T>
void DiccionarioTrie<T>::ItDiccTrie::AvanzarAux() {
    int sig;
    if(HaySiguiente(_actual, -1)){
        sig = Siguiente(_actual, -1);
        _padres.push(_actual);
        _actual = _actual->siguientes[sig];
        _clave += (char)sig;
    } else {
        char ultChar = _clave.back();
        if(HaySiguiente(_padres.top(), int(ultChar))){
            sig = Siguiente(_padres.top(), int(ultChar));
            _actual = _padres.top()->siguientes[sig];
            _clave.pop_back();
            _clave += (char) sig;
        } else {
            _actual = _padres.top();
            _padres.pop();
            _clave.pop_back();
        }
    }
}

