#include <iostream>
#include "../lista/lista.cpp"
#include "../../helpers/arrays.cpp"
using namespace std;

class Arista {
    public:
        int costo;
        bool existe;

        Arista(int costo): costo(costo), existe(true){};
        Arista(): costo(0), existe(false){};
};

class Grafo {
    private:
        bool esDirigido;
        int tope;
        int cantVertices;
        int** vertices;
        Arista* ** matAdy;
        Lista<int> * listaHuecos;

        int posVertice(int vert){
            for (int i = 0; i < tope; i++) {
                if(this->vertices[i] != NULL && *this->vertices[i] == vert) {
                    return i;
                }
            }
            return -1;
        }

        void DFSRec(int pos, bool * vis){
            cout << *this->vertices[pos] << endl;
            vis[pos] = true;
            for(int j=0; j<tope; j++){
                if(!vis[j] && this->matAdy[pos][j]->existe){
                    DFSRec(j, vis);
                }
            }
        }

    public:
        Grafo(int tope, bool esDirigido){
            this->tope = tope;
            this->esDirigido = esDirigido;
            this->cantVertices = 0;
            this->vertices = new int*[tope];
            for(int i=0; i<tope; vertices[i++] = NULL);

            this->matAdy = new Arista**[tope];
            for(int i=0; i<tope; i++){
                this->matAdy[i] = new Arista*[tope];
                if(esDirigido){
                    for(int j=0; j<tope; j++){
                        this->matAdy[i][j] = new Arista();
                    }
                }else{
                    for(int j=i+1; j<tope; j++){
                        this->matAdy[i][j] = this->matAdy[j][i] = new Arista();
                    }
                }
            }
            for(int k=0; k<tope; k++){
                this->matAdy[k][k] = new Arista();
            }

            this->listaHuecos = new Lista<int>();
            for(int k=0; k<tope; k++){
                this->listaHuecos->insertarFin(k);
            }
        }

        void insertarVertice(int vert){
            int hueco = this->listaHuecos->obtenerPpio();
            this->listaHuecos->borrarPpio();

            this->vertices[hueco] = new int(vert);
            this->cantVertices++;
        }

        void insertarArista(int origen, int destino, int costo){
            int posOrigen = posVertice(origen);
            int posDestino = posVertice(destino);
            
            Arista * arista = this->matAdy[posOrigen][posDestino];
            arista->costo=costo;
            arista->existe=true;
        }

        void ordenTopologico(){

            Lista<int>* bolsaCeros = new Lista<int>();        
            // Calculo vector de grados de incidencia de los vértices
            int* gradosIncidencia = new int[tope];
            for(int k=0; k<tope; k++){
                gradosIncidencia[k] = 0;
            }
            for(int j=0; j<tope; j++){
                if(vertices[j] == NULL){
                    continue;
                }
                for(int i=0; i<tope; i++){
                    if(this->matAdy[i][j]->existe){
                        gradosIncidencia[j]++;
                    }
                }
                if(gradosIncidencia[j]==0){
                    bolsaCeros->insertarFin(j);
                }
            }
            for(int k=0; k<cantVertices; k++){
                if(bolsaCeros->esVacia()){
                    cout << "CICLOOOOOO!" << endl;
                    return;
                }
                int vert = bolsaCeros->obtenerPpio();
                bolsaCeros->borrarPpio();
                cout << *this->vertices[vert] << endl;
                for(int j=0; j<tope; j++){
                    if(this->matAdy[vert][j]->existe){
                        gradosIncidencia[j]--;
                        if(gradosIncidencia[j]==0){
                            bolsaCeros->insertarFin(j);
                        }
                    }
                }
            }
        }

        // Depth-First Search
        void DFS(int origen){
            int posOrigen = posVertice(origen);
            bool * vis = new bool[tope];
            for(int i=0; i<tope; vis[i++] = false);
            DFSRec(posOrigen, vis);
        }

        // Breadth-First Search
        void BFS(int origen){
            int posOrigen = posVertice(origen);
            bool * vis = new bool[tope];
            for(int i=0; i<tope; vis[i++] = false);
            Lista<int> * cola = new Lista<int>();
            cola->insertarFin(posOrigen);
            while(!cola->esVacia()){
                int pos = cola->obtenerPpio();
                cola->borrarPpio();
                cout <<*this->vertices[pos] << endl;
                vis[pos] = true;
                for(int j=0; j<tope; j++){
                    if(!vis[j] && this->matAdy[pos][j]->existe){
                        cola->insertarFin(j);
                    }
                }
            }
        }

};

void pruebaOrdenTopologico() {
    Grafo * g = new Grafo(10, true);
    g->insertarVertice(1);
    g->insertarVertice(2);
    g->insertarVertice(3);
    g->insertarVertice(4);
    g->insertarVertice(5);
    g->insertarVertice(6);
    g->insertarVertice(7);

    g->insertarArista(1,2,1);
    g->insertarArista(1,3,1);
    g->insertarArista(1,4,1);
    g->insertarArista(2,4,1);
    g->insertarArista(2,5,1);
    g->insertarArista(3,6,1);
    g->insertarArista(4,3,1);
    g->insertarArista(4,6,1);
    g->insertarArista(4,7,1);
    g->insertarArista(5,4,1);
    g->insertarArista(5,7,1);
    g->insertarArista(7,6,1);

    g->ordenTopologico();
}

void pruebaBFS(){
Grafo * g = new Grafo(17, true);
    g->insertarVertice(1);
    g->insertarVertice(2);
    g->insertarVertice(3);
    g->insertarVertice(4);
    g->insertarVertice(5);
    g->insertarVertice(6);
    g->insertarVertice(7);
    g->insertarVertice(8);
    g->insertarVertice(9);
    g->insertarVertice(10);
    g->insertarVertice(11);
    g->insertarVertice(12);
    g->insertarVertice(13);
    g->insertarVertice(14);
    g->insertarVertice(15);
    g->insertarVertice(16);
    g->insertarVertice(17);

    g->insertarArista(1,2,1);
    g->insertarArista(1,3,1);
    g->insertarArista(1,4,1);
    g->insertarArista(1,5,1);
    g->insertarArista(2,6,1);
    g->insertarArista(2,7,1);
    g->insertarArista(2,8,1);
    g->insertarArista(3,9,1);
    g->insertarArista(3,10,1);
    g->insertarArista(3,11,1);
    g->insertarArista(4,12,1);
    g->insertarArista(4,13,1);
    g->insertarArista(4,14,1);
    g->insertarArista(5,15,1);
    g->insertarArista(5,16,1);
    g->insertarArista(5,17,1);

    g->BFS(1);
}

int main() {
    pruebaBFS();
    return 0;
}