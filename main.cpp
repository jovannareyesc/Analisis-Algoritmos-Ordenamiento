#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>

#define NUM_PRUEBAS 1000
#define MIN_TAMANO 10
#define MAX_TAMANO 1000
#define INCREMENTO 10
#define NUM_ALGORITMOS 7

using namespace std::chrono;
using namespace std;

void orden_por_insercion(int arreglo[], int longitud);
void orden_por_burbuja(int arreglo[], int longitud);
void orden_por_seleccion(int s[], int n);
void merge(int *array, int l, int m, int r);
void orden_por_mezcla(int *array, int l, int r);
void swap(int* a, int* b);
int partition (int arr[], int  low, int high);
void orden_rapido(int arr[], int low, int high);
void heapify(int arr[], int n, int i);
void orden_por_monticulos(int arr[], int n);
void orden_shell(int s[], int n);
void pasar_arreglo(int arreglo[], int arreglo_desordenado[], int longitud);

void swap(int* a, int* b);
int Partition(int arr[], int inicio, int fin);
void quicksort_h(int arr[], int inicio, int fin);
void quick_sort(int arr[], int n);

//matrices
double datos_insercion[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double datos_burbuja[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double datos_seleccion[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double datos_mezcla[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double datos_rapido[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double datos_monticulos[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double datos_shell[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];



int main() {

    srand(time(NULL));
    const int longitud_arr = MAX_TAMANO;
    int longitud = MIN_TAMANO;
    int repeticiones = NUM_PRUEBAS;
    int arreglo[longitud_arr];
    int arreglo_desordenado[longitud_arr];
    int cont_columnas = 1;
    double insercion_tiempo = 0;
    double burbuja_tiempo = 0;
    double seleccion_tiempo = 0;
    double mezcla_tiempo = 0;
    double ordenrapido_tiempo = 0;
    double heap_tiempo = 0;
    double shell_tiempo = 0;

    for (int k = 1; k <= 100 ; k++) {
        for (int i = 0 ; i < repeticiones ; i++ ){
            for (int j = 0 ; j < longitud ; j++){
                arreglo[j] = 1 + rand() % 1000;
            }

            //cout << cont_columnas << endl;

            //INSERCION
            pasar_arreglo(arreglo, arreglo_desordenado, longitud);
            auto insercion_start = high_resolution_clock::now();
            orden_por_insercion(arreglo, longitud);
            auto insercion_end = high_resolution_clock::now();
            duration<double> insercion_duration = insercion_end - insercion_start;
            double insercion_run_time = insercion_duration.count() * 1000;
            datos_insercion[i][cont_columnas] = insercion_run_time;
            insercion_tiempo += insercion_run_time;
            //  cout << fixed << setprecision(6) << run_time << " milisegundos." << endl;
            // outFile << fixed << setprecision(6) << run_time << " milisegundos." << endl;

            //BURBUJA
            pasar_arreglo(arreglo, arreglo_desordenado, longitud);
            auto burbuja_start = high_resolution_clock::now();
            orden_por_insercion(arreglo, longitud);
            auto burbuja_end = high_resolution_clock::now();
            duration<double> burbuja_duration = burbuja_end - burbuja_start;
            double burbuja_run_time = burbuja_duration.count() * 1000;
            datos_burbuja[i][cont_columnas] = burbuja_run_time;
            burbuja_tiempo += burbuja_run_time;

            //SELECCIÓN
            pasar_arreglo(arreglo, arreglo_desordenado, longitud);
            auto seleccion_start = high_resolution_clock::now();
            orden_por_seleccion(arreglo, longitud);
            auto seleccion_end = high_resolution_clock::now();
            duration<double> seleccion_duration = seleccion_end - seleccion_start;
            double seleccion_run_time = seleccion_duration.count() * 1000;
            datos_seleccion[i][cont_columnas] = seleccion_run_time;
            seleccion_tiempo += seleccion_run_time;

            //MEZCLA
            pasar_arreglo(arreglo, arreglo_desordenado, longitud);
            auto mezcla_start = high_resolution_clock::now();
            orden_por_seleccion(arreglo, longitud);
            auto mezcla_end = high_resolution_clock::now();
            duration<double> mezcla_duration = mezcla_end - mezcla_start;
            double mezcla_run_time = mezcla_duration.count() * 1000;
            datos_mezcla[i][cont_columnas] = mezcla_run_time;
            mezcla_tiempo += mezcla_run_time;

            //QUICKSORT
            pasar_arreglo(arreglo, arreglo_desordenado, longitud);
            auto ordenrapido_start = high_resolution_clock::now();
            quick_sort(arreglo_desordenado, longitud);
            auto ordenrapido_end = high_resolution_clock::now();
            duration<double> ordenrapido_duration = ordenrapido_end - ordenrapido_start;
            double ordenrapido_run_time = ordenrapido_duration.count() * 1000;
            datos_rapido[i][cont_columnas] = ordenrapido_run_time;
            ordenrapido_tiempo += ordenrapido_run_time;


            //HEAPSORT
            pasar_arreglo(arreglo, arreglo_desordenado, longitud);
            auto heap_start = high_resolution_clock::now();
            orden_por_monticulos(arreglo, longitud);
            auto heap_end = high_resolution_clock::now();
            duration<double> heap_duration = heap_end - heap_start;
            double heap_run_time = heap_duration.count() * 1000;
            datos_monticulos[i][cont_columnas] = heap_run_time;
            heap_tiempo += heap_run_time;

            //SHELLSORT
            pasar_arreglo(arreglo, arreglo_desordenado, longitud);
            auto shell_start = high_resolution_clock::now();
            orden_shell(arreglo, longitud);
            auto shell_end = high_resolution_clock::now();
            duration<double> shell_duration = shell_end - shell_start;
            double shell_run_time = shell_duration.count() * 1000;
            datos_shell[i][cont_columnas] = shell_run_time;
            shell_tiempo += shell_run_time;
        }

        cout << "La iteraci\242n de algoritmo de longitud n\243mero " << longitud << " ha sido ejecutada. " << endl;
        cout << endl;

        //columna de promedios
        datos_insercion[1000][cont_columnas] = insercion_tiempo/1000;
        datos_burbuja[1000][cont_columnas] = burbuja_tiempo/1000;
        datos_seleccion[1000][cont_columnas] = seleccion_tiempo/1000;
        datos_mezcla[1000][cont_columnas] = mezcla_tiempo/1000;
        datos_rapido[1000][cont_columnas] = ordenrapido_tiempo/1000;
        datos_monticulos[1000][cont_columnas] = heap_tiempo/1000;
        datos_shell[1000][cont_columnas] = shell_tiempo/1000;

        cont_columnas++;
        longitud += 10;

        //reiniciar tiempo

        insercion_tiempo = 0;
        burbuja_tiempo = 0;
        seleccion_tiempo = 0;
        mezcla_tiempo = 0;
        ordenrapido_tiempo = 0;
        heap_tiempo = 0;
        shell_tiempo = 0;
    }

    /////////////////////////////////////////////////////////////////


    //INSERCION pasa los tiempos a txt///////////////////////////////
    ofstream outFile_insercion("1_insercion_ordenamiento.csv");
    if (!outFile_insercion.is_open()) {\
        cerr << "ERROR: No se pudo escribir el archivo." << endl;
        return 1;
    }
    longitud = 0;
    outFile_insercion << ",";
    for (int i = 10 ; i <= 1000 ; i+= 10) {
        outFile_insercion << "Tama\361o " << i << ",";
    }
    outFile_insercion << endl;
    for (int i = 1 ; i <= repeticiones ; i++) {
        outFile_insercion << i << ",";
        for (int j = 0 ; j < 100 ; j++) {
            outFile_insercion << fixed << setprecision(6) << datos_insercion[i-1][j+1] << ",";
        }
        outFile_insercion << endl;
    }
    outFile_insercion << "Promedio:,";
    for (int i = 0; i < 100 ; i++) {
        outFile_insercion << datos_insercion[1000][i+1] << ",";
    }
    outFile_insercion.close();
    //////////////////////////////////////////////////////////


    /////BURBUJA pasa los tiempos a txt///////////////////////
    ofstream outFile_burbuja("2_burbuja_ordenamiento.csv");
    if (!outFile_burbuja.is_open()) {\
        cerr << "ERROR: No se pudo escribir el archivo." << endl;
        return 1;
    }
    longitud = 0;
    outFile_burbuja << ",";
    for (int i = 10; i <= 1000; i += 10) {
        outFile_burbuja << "Tama\361o " << i << ",";
    }
    outFile_burbuja << endl;
    for (int i = 1; i <= repeticiones; i++) {
        outFile_burbuja << i << ",";
        for (int j = 0; j < 100; j++) {
            outFile_burbuja << fixed << setprecision(6) << datos_burbuja[i-1][j+1] << ",";
        }
        outFile_burbuja << endl;
    }
    outFile_burbuja << "Promedio:,";
    for (int i = 0; i < 100; i++) {
        outFile_burbuja << datos_burbuja[1000][i+1] << ",";
    }
    outFile_burbuja.close();
////////////////////////////////////////////////////////////

    ////////SELECCIÓN pasa los tiempos a txt///////////////
    ofstream outFile_seleccion("3_seleccion_ordenamiento.csv");
    if (!outFile_seleccion.is_open()) {\
        cerr << "ERROR: No se pudo escribir el archivo." << endl;
        return 1;
    }
    longitud = 0;
    outFile_seleccion << ",";
    for (int i = 10; i <= 1000; i += 10) {
        outFile_seleccion << "Tama\361o " << i << ",";
    }
    outFile_seleccion << endl;
    for (int i = 1; i <= repeticiones; i++) {
        outFile_seleccion << i << ",";
        for (int j = 0; j < 100; j++) {
            outFile_seleccion << fixed << setprecision(6) << datos_seleccion[i-1][j+1] << ",";
        }
        outFile_seleccion << endl;
    }
    outFile_seleccion << "Promedio:,";
    for (int i = 0; i < 100; i++) {
        outFile_seleccion << datos_seleccion[1000][i+1] << ",";
    }
    outFile_seleccion.close();
    ////////////////////////////////////////////////////////////


    ////////MERGESORT pasa los tiempos a txt///////////////////
    ofstream outFile_mezcla("4_mergesort_ordenamiento.csv");
    if (!outFile_mezcla.is_open()) {\
        cerr << "ERROR: No se pudo escribir el archivo." << endl;
        return 1;
    }
    longitud = 0;
    outFile_mezcla << ",";
    for (int i = 10; i <= 1000; i += 10) {
        outFile_mezcla << "Tama\361o " << i << ",";
    }
    outFile_mezcla << endl;
    for (int i = 1; i <= repeticiones; i++) {
        outFile_mezcla << i << ",";
        for (int j = 0; j < 100; j++) {
            outFile_mezcla << fixed << setprecision(6) << datos_mezcla[i-1][j+1] << ",";
        }
        outFile_mezcla << endl;
    }
    outFile_mezcla << "Promedio:,";
    for (int i = 0; i < 100; i++) {
        outFile_mezcla << datos_mezcla[1000][i+1] << ",";
    }
    outFile_mezcla.close();
    ////////////////////////////////////////////////////////////


    ////////QUICKSORT pasa los tiempos a txt///////////////////
    ofstream outFile_quicksort("5_quicksort_ordenamiento.csv");
    if (!outFile_quicksort.is_open()) {
        cerr << "ERROR: No se pudo escribir el archivo." << endl;
        return 1;
    }
    longitud = 0;
    outFile_quicksort << ",";
    for (int i = 10; i <= 1000; i += 10) {
        outFile_quicksort << "Tama\361o " << i << ",";
    }
    outFile_quicksort << endl;
    for (int i = 1; i <= repeticiones; i++) {
        outFile_quicksort << i << ",";
        for (int j = 0; j < 100; j++) {
            outFile_quicksort << fixed << setprecision(6) << datos_rapido[i-1][j+1] << ",";
        }
        outFile_quicksort << endl;
    }
    outFile_quicksort << "Promedio:,";
    for (int i = 0; i < 100; i++) {
        outFile_quicksort << datos_rapido[1000][i+1] << ",";
    }
    outFile_quicksort.close();
    ////////////////////////////////////////////////////////////


    ////////HEAPSORT pasa los tiempos a txt////////////////////
    ofstream outFile_heapsort("6_heapsort_ordenamiento.csv");
    if (!outFile_heapsort.is_open()) {\
        cerr << "ERROR: No se pudo escribir el archivo." << endl;
        return 1;
    }
    longitud = 0;
    outFile_heapsort << ",";
    for (int i = 10; i <= 1000; i += 10) {
        outFile_heapsort << "Tama\361o " << i << ",";
    }
    outFile_heapsort << endl;
    for (int i = 1; i <= repeticiones; i++) {
        outFile_heapsort << i << ",";
        for (int j = 0; j < 100; j++) {
            outFile_heapsort << fixed << setprecision(6) << datos_monticulos[i-1][j+1] << ",";
        }
        outFile_heapsort << endl;
    }
    outFile_heapsort << "Promedio:,";
    for (int i = 0; i < 100; i++) {
        outFile_heapsort << datos_monticulos[1000][i+1] << ",";
    }
    outFile_heapsort.close();
    ////////////////////////////////////////////////////////////



    ////////SHELLSORT pasa los tiempos a txt///////////////////
    ofstream outFile_shellsort("7_shellsort_ordenamiento.csv");
    if (!outFile_shellsort.is_open()) {\
        cerr << "ERROR: No se pudo escribir el archivo." << endl;
        return 1;
    }
    longitud = 0;
    outFile_shellsort << ",";
    for (int i = 10; i <= 1000; i += 10) {
        outFile_shellsort << "Tama\361o " << i << ",";
    }
    outFile_shellsort << endl;
    for (int i = 1; i <= repeticiones; i++) {
        outFile_shellsort << i << ",";
        for (int j = 0; j < 100; j++) {
            outFile_shellsort << fixed << setprecision(6) << datos_shell[i-1][j+1] << ",";
        }
        outFile_shellsort << endl;
    }
    outFile_shellsort << "Promedio:,";
    for (int i = 0; i < 100; i++) {
        outFile_shellsort << datos_shell[1000][i+1] << ",";
    }
    outFile_shellsort.close();
    ////////////////////////////////////////////////////////////
    return 0;
}





////////////////ORDEN POR INSERCIÓN///////////////////////////
void orden_por_insercion(int arreglo[], int longitud) {
    for (int i = 1; i < longitud; i++) {
        int aux = arreglo[i];
        int j = i - 1;
        while (j >= 0 && aux < arreglo[j]) {
            arreglo[j + 1] = arreglo[j];
            j = j - 1;
        }
        arreglo[j + 1] = aux;
    }
}
///////////////////////////////////////////////////////////////




///////////ORDEN POR BURBUJA OPTIMIZADO//////////////////////
void orden_por_burbuja(int arreglo[], int longitud) {
    int temp;
    bool aux = true;
    while (aux) {
        aux = false;
        for (int j = 0 ; j < longitud-1 ; j++) {
            if (arreglo[j] > arreglo[j+1]) {
                temp = arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = temp;
                aux = true;

            }
        }
    }

    cout << endl;
}
////////////////////////////////////////////////////////////




///////////////ORDEN POR SELECCIÓN/////////////////////////
void orden_por_seleccion(int arreglo[], int longitud) {

    int i_min, temp;
    for (int i = 0; i < longitud - 1; ++i)
    {
        i_min = i;
        for (int j = i + 1; j < longitud; ++j)
        {
            if (arreglo[j] < arreglo[i_min])
            {
                i_min = j;
            }
        }
        if (i_min != i)
        {
            temp = arreglo[i];
            arreglo[i] = arreglo[i_min];
            arreglo[i_min] = temp;
        }
    }
}
///////////////////////////////////////////////////////////




//////////////////ORDEN POR MEZCLA////////////////////////
void merge(int *arreglo, int l, int m, int r) {
    int i, j, k, nl, nr;
    nl = m-l+1; nr = r-m;
    int larr[nl], rarr[nr];

    for(i = 0; i<nl; i++)
        larr[i] = arreglo[l+i];

    for(j = 0; j<nr; j++)
        rarr[j] = arreglo[m+1+j];

    i = 0; j = 0; k = l;

    while(i < nl && j<nr) {
        if(larr[i] <= rarr[j]) {
            arreglo[k] = larr[i];
            i++;
        } else {
            arreglo[k] = rarr[j];
            j++;
        }
        k++;
    }
    while(i<nl) {
        arreglo[k] = larr[i];
        i++; k++;
    }
    while(j<nr) {
        arreglo[k] = rarr[j];
        j++; k++;
    }
}
void ordenamiento_por_mezcla(int *arreglo, int l, int r) {
    int m;
    if(l < r) {
        int m = l+(r-l)/2;

        ordenamiento_por_mezcla(arreglo, l, m);
        ordenamiento_por_mezcla(arreglo, m+1, r);
        merge(arreglo, l, m, r);
    }
}

///////////////////////////////////////////////////////////



//////////////ORDEN POR ORDENAMIENTO RÁPIDO//////////////
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(int arreglo[], int start, int end) {
    int pivot = arreglo[end];
    int i = start - 1;
    for (int j = start; j <= end - 1; j++) {
        if (arreglo[j] <= pivot) {
            i++;
            swap(&arreglo[i], &arreglo[j]);
        }
    }
    swap(&arreglo[i + 1], &arreglo[end]);
    return i + 1;
}
void quicksort_h(int arreglo[], int start, int end) {
    if (start < end) {
        int p_index = Partition(arreglo, start, end);
        quicksort_h(arreglo, start, p_index - 1);
        quicksort_h(arreglo, p_index + 1, end);
    }
}
void quick_sort(int arreglo[], int longitud) {
    quicksort_h(arreglo, 0, longitud - 1);
}
////////////////////////////////////////////////////////////



////////////////ORDEN POR MONTÍCULO////////////////////////
void heapify(int arreglo[], int longitud, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < longitud && arreglo[left] > arreglo[largest])
        largest = left;

    if (right < longitud && arreglo[right] > arreglo[largest])
        largest = right;

    if (largest != i) {
        swap(arreglo[i], arreglo[largest]);
        heapify(arreglo, longitud, largest);
    }
}

void orden_por_monticulos(int arreglo[], int longitud) {
    for (int i = longitud / 2 - 1; i >= 0; i--)
        heapify(arreglo, longitud, i);

    for (int i = longitud- 1; i >= 0; i--) {
        swap(arreglo[0], arreglo[i]);
        heapify(arreglo, i, 0);
    }
}
/////////////////////////////////////////////////////////



/////////////////ORDEN POR MEZCLA////////////////////////
void orden_shell(int arreglo[], int longitud)
{
    int gap[4] = { longitud/2, longitud/4, longitud/8, 1};
    int temp, k;

    for (int i = 0; i < 4; ++i)
    {
        for (int j = gap[i]; j < longitud; ++j)
        {
            temp = arreglo[j];
            k = j;
            while (k >= gap[i] && arreglo[k - gap[i]] > temp)
            {
                arreglo[k] = arreglo[k - gap[i]];
                k = k - gap[i];
            }
            arreglo[k] = temp;
        }
    }
}
//////////////////////////////////////////////////////////




//////////////////FUNCIÓN PARA PASAR ARREGLO/////////////
void pasar_arreglo(int arreglo[], int arreglo_desordenado[], int longitud) {
    for (int i = 0; i < longitud; i++) {
         arreglo_desordenado[i] = arreglo[i];
    }

}
