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

void pasar_arreglo(int arreglo[], int arreglo_desordenado[], int longitud);
void insertion_sort(int arr[], int n);   
void bubble_sort(int arr[], int n);     
void selection_sort(int arr[], int n);   
void merge_sort(int arr[], int n);       
void quick_sort(int arr[], int n);       
void heap_sort(int arr[], int n);        
void shell_sort(int arr[], int n);       
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);
void swap(int* a, int* b);
int Partition(int arr[], int inicio, int fin);
void QuickSortHelper(int arr[], int inicio, int fin);
void heapify(int arr[], int length, int i);


//matrices
double datos_insercion[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double datos_burbuja[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double datos_seleccion[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double datos_mezcla[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double datos_rapido[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double datos_monticulos[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double datos_shell[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];



int main() {
//semilla
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
            insertion_sort(arreglo, longitud);
            auto insercion_end = high_resolution_clock::now();
            duration<double> insercion_duration = insercion_end - insercion_start;
            double insercion_run_time = insercion_duration.count() * 1000;
            datos_insercion[i][cont_columnas] = insercion_run_time;
            insercion_tiempo += insercion_run_time;
            //  cout << fixed << setprecision(6) << run_time << " milisegundos." << endl;
            //  cout << fixed << setprecision(6) << run_time << " milisegundos." << endl;
            // outFile << fixed << setprecision(6) << run_time << " milisegundos." << endl;

            //BURBUJA
            pasar_arreglo(arreglo, arreglo_desordenado, longitud);
            auto burbuja_start = high_resolution_clock::now();
            bubble_sort(arreglo, longitud);
            auto burbuja_end = high_resolution_clock::now();
            duration<double> burbuja_duration = burbuja_end - burbuja_start;
            double burbuja_run_time = burbuja_duration.count() * 1000;
            datos_burbuja[i][cont_columnas] = burbuja_run_time;
            burbuja_tiempo += burbuja_run_time;

            //SELECCIÓN
            pasar_arreglo(arreglo, arreglo_desordenado, longitud);
            auto seleccion_start = high_resolution_clock::now();
            selection_sort(arreglo, longitud);
            auto seleccion_end = high_resolution_clock::now();
            duration<double> seleccion_duration = seleccion_end - seleccion_start;
            double seleccion_run_time = seleccion_duration.count() * 1000;
            datos_seleccion[i][cont_columnas] = seleccion_run_time;
            seleccion_tiempo += seleccion_run_time;

            //MEZCLA
            pasar_arreglo(arreglo, arreglo_desordenado, longitud);
            auto mezcla_start = high_resolution_clock::now();
            merge_sort(arreglo, longitud);
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
            heap_sort(arreglo, longitud);
            auto heap_end = high_resolution_clock::now();
            duration<double> heap_duration = heap_end - heap_start;
            double heap_run_time = heap_duration.count() * 1000;
            datos_monticulos[i][cont_columnas] = heap_run_time;
            heap_tiempo += heap_run_time;

            //SHELLSORT
            pasar_arreglo(arreglo, arreglo_desordenado, longitud);
            auto shell_start = high_resolution_clock::now();
            shell_sort(arreglo, longitud);
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



//////////////////FUNCIÓN PARA PASAR ARREGLO/////////////
void pasar_arreglo(int arreglo[], int arreglo_desordenado[], int longitud) {
    for (int i = 0; i < longitud; i++) {
         arreglo_desordenado[i] = arreglo[i];
    }
}
////////////////////////////////////////////////////////////


/////////////////ORDEN POR INSERCIÓN////////////////////////
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && temp < arr[j]) {
           arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}
////////////////////////////////////////////////////////////


////////////////////ORDEN BURBUJA///////////////////////////
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
////////////////////////////////////////////////////////////



////////////////////ORDEN POR SELECCIÓN////////////////////
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}
//////////////////////////////////////////////////////////



////////////////////ORDEN POR MEZCLA//////////////////////
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
void merge_sort(int arr[], int n) {
    mergeSort(arr, 0, n - 1);
}
//////////////////////////////////////////////////////////


////////////////////ORDENAMIENTO RÁPIDO//////////////////////
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(int arr[], int inicio, int fin) {
    int pivote = arr[fin]; 
    int i = inicio - 1;
    for (int j = inicio; j <= fin - 1; j++) {
        if (arr[j] <= pivote) {
            i++; 
            swap(&arr[i], &arr[j]); 
        }
    }
    swap(&arr[i + 1], &arr[fin]); 
    return i + 1; 
}
void QuickSortHelper(int arr[], int inicio, int fin) {
    if (inicio < fin) {
        int pivote_idx = Partition(arr, inicio, fin);
        QuickSortHelper(arr, inicio, pivote_idx - 1);
        QuickSortHelper(arr, pivote_idx + 1, fin);
    }
}

void quick_sort(int arr[], int n) {

    QuickSortHelper(arr, 0, n - 1);
}
//////////////////////////////////////////////////////////

////////////////////ORDEN POR MONTÍCULOS//////////////////
void heapify(int arr[], int length, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < length && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < length && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, length, largest);
    }
}

void heap_sort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

}
//////////////////////////////////////////////////////////


////////////////////ORDEN POR SHELL///////////////////////
void shell_sort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i]; 
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
//////////////////////////////////////////////////////////
