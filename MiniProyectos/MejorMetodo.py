import sys
import time
import random
import math
import bisect
import matplotlib.pyplot as plt  # Importamos plt al inicio
import numpy as np               # Importamos numpy al inicio

# Le damos mas chanza al Quick Sort
try:
    sys.setrecursionlimit(200000)
except (ValueError, OverflowError):
    print("Ni modo, no se pudo poner mas limite. El Quick Sort puede ke falle.")

# --- 1. Los Metodos de Ordenamiento ---
# (Esta seccion esta IDENTICA, va de la linea 17 a la 317 de tu codigo)
# ... (insertion_sort, bubble_sort, selection_sort, ...)
# ... (merge_sort, quick_sort, heap_sort, shell_sort, ...)
# ... (radix_sort, bucket_sort) ...

def insertion_sort(arr):
    """El famoson Insercion Sort. Va agarrando uno por uno y lo acomoda donde va."""
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

def bubble_sort(arr):
    """El Burbuja. El lentote este ke va subiendo el mas grande como burbuja."""
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break
    return arr

def selection_sort(arr):
    """El de Seleccion. Este compa busca el mas plebe de tochos y lo pone al puro frente."""
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr

def binary_insertion_sort(arr):
    """El Insercion Binaria. Usa buskeda binaria pa encontrar el lugar mas rapido."""
    for i in range(1, len(arr)):
        val = arr[i]
        j = bisect.bisect_left(arr, val, 0, i)
        for k in range(i, j, -1):
            arr[k] = arr[k-1]
        arr[j] = val
    return arr

def merge_sort(arr):
    """El Merge Sort. Divide y venceras, pues."""
    if len(arr) > 1:
        mid = len(arr) // 2
        L = arr[:mid]
        R = arr[mid:]
        merge_sort(L)
        merge_sort(R)
        i = j = k = 0
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1
        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1
    return arr

def _partition(arr, low, high):
    """Ayudante del Quick Sort (particion)."""
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def _quick_sort_recursive(arr, low, high):
    """La recursion del Quick Sort."""
    if low < high:
        pi = _partition(arr, low, high)
        _quick_sort_recursive(arr, low, pi - 1)
        _quick_sort_recursive(arr, pi + 1, high)

def quick_sort(arr):
    """El Quick Sort. El machin, el rapido."""
    _quick_sort_recursive(arr, 0, len(arr) - 1)
    return arr

def _heapify(arr, n, i):
    """Ayudante del Heap Sort (pa hacer el monticulo)."""
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2
    if l < n and arr[l] > arr[largest]:
        largest = l
    if r < n and arr[r] > arr[largest]:
        largest = r
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        _heapify(arr, n, largest)

def heap_sort(arr):
    """El Heap Sort. Usa un 'heap' (monticulo) pa ordenar."""
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        _heapify(arr, n, i)
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        _heapify(arr, i, 0)
    return arr

def shell_sort(arr):
    """El Shell Sort. Como Insercion pero mejorado, con saltos (gaps)."""
    n = len(arr)
    gap = 1
    while gap < n // 3:
        gap = 3 * gap + 1
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 3
    return arr

def _counting_sort_for_radix(arr, exp):
    """Ayudante del Radix. Cuenta cuantos hay de cada digito."""
    n = len(arr)
    output = [0] * n
    count = [0] * 10 
    for i in range(n):
        index = (arr[i] // exp) % 10
        count[index] += 1
    for i in range(1, 10):
        count[i] += count[i - 1]
    i = n - 1
    while i >= 0:
        index = (arr[i] // exp) % 10
        output[count[index] - 1] = arr[i]
        count[index] -= 1
        i -= 1
    for i in range(n):
        arr[i] = output[i]

def radix_sort(arr):
    """El Radix Sort. Ordena por digitos (unidades, decenas...)."""
    if not arr:
        return arr
    max_val = max(arr)
    exp = 1
    while max_val // exp > 0:
        _counting_sort_for_radix(arr, exp)
        exp *= 10
    return arr

def bucket_sort(arr):
    """El Bucket Sort (por cubetas)."""
    if not arr:
        return arr
    max_val = max(arr)
    min_val = min(arr)
    if max_val == min_val:
        return arr
    n = len(arr)
    bucket_count = n
    buckets = [[] for _ in range(bucket_count)]
    bucket_range = (max_val - min_val) / bucket_count + 1
    for val in arr:
        index = int((val - min_val) / bucket_range)
        buckets[index].append(val)
    idx = 0
    for bucket in buckets:
        insertion_sort(bucket) # Usamos Insercion pa ordenar la cubeta
        for val in bucket:
            arr[idx] = val
            idx += 1
    return arr

# --- 2. El ke Hace los Arreglos ---
# (Esta seccion esta IDENTICA)

def generate_array(size, preorden):
    """
    Esta madre es la ke hace los arreglos pal desmadre.
    preorden: 1=Ordenado, 2=Aleatorio, 3=Inverso
    """
    base_arr = [random.randint(0, 100000) for _ in range(size)]
    
    if preorden == 1: # Ordenado
        base_arr.sort()
        return base_arr
    
    elif preorden == 2: # Aleatorio
        return base_arr
        
    elif preorden == 3: # Inverso
        base_arr.sort(reverse=True)
        return base_arr
    
    else:
        return base_arr

# --- 3. El Verificador (El Chismoso) ---
# (Esta seccion esta IDENTICA)

def is_sorted(arr):
    """Nomas pa checar ke el jale se hizo bien."""
    return all(arr[i] <= arr[i + 1] for i in range(len(arr) - 1))

# --- 4. Aki Empieza el Show (Logica Principal) ---
# (Esta seccion esta IDENTICA)

def run_benchmarks():
    """
    Funcion principal ke ejecuta el menu y las pruebas.
    ¡Ahora corre los 3 preordenes por cada tamaño!
    """
    
    results = [] # Aki vamos a guardar los tiempos
    
    size_map = {1: 100, 2: 1000, 3: 10000, 4: 100000}
    preorden_map = {1: "Ordenado", 2: "Aleatorio", 3: "Inverso"}
    
    algorithms = {
        "Bubble Sort": bubble_sort,
        "Selection Sort": selection_sort,
        "Insertion Sort": insertion_sort,
        "Binary Insertion Sort": binary_insertion_sort,
        "Shell Sort": shell_sort,
        "Merge Sort": merge_sort,
        "Heap Sort": heap_sort,
        "Quick Sort": quick_sort,
        "Radix Sort": radix_sort,
        "Bucket Sort": bucket_sort,
    }
    
    scenarios_run = set() 

    while True:
        print("\n" + "="*50)
        print("Escoge el tamaño del arreglo para la prueba:")
        for k, v in size_map.items():
            print(f"  {k}. {v:7,} numeros")
        print("  5. Ver Gráficas y Salir")
        print("  6. Salir (sin graficar)")
        
        try:
            choice_size = int(input("Opcion de tamaño: "))
            
            if choice_size == 5:
                return results, True  # Regresa (resultados, SI graficar)
            if choice_size == 6:
                return results, False # Regresa (resultados, NO graficar)
                
            if choice_size not in size_map:
                print("Esa no se puede, compa. Intenta otra vez.")
                continue
            
            size = size_map[choice_size]
            
            print(f"\n--- Preparando pruebas para TAMAÑO: {size:,} números ---")
            
            for choice_preorden in preorden_map.keys(): # 1, 2, 3
                
                preorden_str = preorden_map[choice_preorden]
                scenario_key = (size, preorden_str)
                
                if scenario_key in scenarios_run:
                    print(f"\nOJO: El escenario ({size}, {preorden_str}) ya lo corrimos.")
                    if input("¿Lo kieres correr otra vez de todos modos? (s/n): ").lower() != 's':
                        continue
                    results = [r for r in results if r[0] != size or r[1] != preorden_str]

                scenarios_run.add(scenario_key)

                print(f"\n--- Corriendo Escenario: {size:,} numeros, {preorden_str} ---")
                
                try:
                    original_array = generate_array(size, choice_preorden)
                    print(f"Arreglo base ({preorden_str}) hecho.")
                except MemoryError:
                    print(f"¡ERROR DE MEMORIA! No se pudo hacer el arreglo de {size:,} esta muy grande.")
                    scenarios_run.remove(scenario_key)
                    continue 

                for name, func in algorithms.items():
                    
                    arr_copy = list(original_array) # COPIA del arreglo
                    
                    print(f"  calando {name}...")
                    
                    try:
                        start_time = time.perf_counter()
                        func(arr_copy)
                        end_time = time.perf_counter()
                        
                        time_taken = end_time - start_time
                        
                        if is_sorted(arr_copy):
                            print(f"    ...jalo en {time_taken:.6f} segundos.")
                            results.append((size, preorden_str, name, time_taken))
                        else:
                            print(f"    *** ¡ERROR! ¡{name} la rego, no ordeno bien ***")
                            results.append((size, preorden_str, name, float('inf'))) 
                    
                    except (RecursionError, MemoryError, Exception) as e:
                        print(f"    *** ¡ERROR! {name} trono: {e} ***")
                        results.append((size, preorden_str, name, float('inf')))

                print(f"--- Escenario ({size}, {preorden_str}) terminado ---")

            print(f"\n--- Pruebas para TAMAÑO {size:,} completadas ---")

        except ValueError:
            print("Entrada no valida. Pon un numero, compa.")
        except KeyboardInterrupt:
            print("\nPrueba parada a la brava. Saliendo...")
            return results, False 
            
    return results, False

# --- 5. El ke Imprime kien Gano (Texto) ---
# (Esta seccion esta IDENTICA)

def show_results(results):
    """Muestra los resumenes de resultados en TEXTO."""
    if not results:
        print("\nNo se corrio ninguna prueba.")
        return

    print("\n\n" + "="*50)
    print("       INFORME FINAL DE RESULTADOS (TEXTO)")
    print("="*50)

    # --- Reporte 1: Por Escenario ---
    print("\n### Resultados por Escenario (Del mas rapido al mas lento) ###")
    scenarios = {}
    for (size, preorden, name, t) in results:
        key = (size, preorden)
        if key not in scenarios:
            scenarios[key] = []
        scenarios[key].append((name, t))
        
    sorted_scenarios = sorted(scenarios.items(), key=lambda item: (item[0][0], item[0][1]))

    for (size, preorden), res_list in sorted_scenarios:
        print(f"\n--- Escenario: {size:7,} numeros, {preorden} ---")
        res_list.sort(key=lambda x: x[1])
        
        for i, (name, t) in enumerate(res_list):
            if t == float('inf'):
                time_str = "TRONO"
            else:
                time_str = f"{t:.6f} s"
            
            label = ""
            if i == 0:
                label = " (aveztruz)"
            elif i == len(res_list) - 1:
                label = " (tortuga)"
                
            print(f"  {i+1:2}. {name:<22} {time_str:<15} {label}")

    # --- Reporte 2: Resumen por Metodo ---
    print("\n\n" + "="*50)
    print("\n### Resumen por Metodo (Tiempo Total Acumulado) ###")
    
    method_times = {}
    for (size, preorden, name, t) in results:
        method_times[name] = method_times.get(name, 0) + t
        
    sorted_methods = sorted(method_times.items(), key=lambda x: x[1])
    
    for i, (name, total_time) in enumerate(sorted_methods):
        if total_time == float('inf'):
            time_str = "TRONO EN ALGUNA PRUEBA"
        else:
            time_str = f"{total_time:.6f} s"
        print(f"  {i+1:2}. {name:<22} {time_str}")

# --- 6. ¡NUEVO! El ke Hace las Graficas (CORREGIDO AL MODELO "GRANJA") ---

def plot_results(results):
    """Muestra los resultados en gráficas de barras agrupadas (como la de la granja de Frank)."""
    if not results:
        print("\nNo hay nada que graficar.")
        return

    try:
        import matplotlib.pyplot as plt
        import numpy as np
    except ImportError:
        print("\n" + "="*60)
        print("  ¡ERROR! Para graficar, necesitas la librería 'matplotlib'.")
        print("  Abre tu terminal y corre: pip install matplotlib")
        print("="*60)
        return

    print("\nGenerando gráficas de barras agrupadas...")

    # Algoritmos y tipos de preorden únicos
    algorithms = sorted(list(set([r[2] for r in results])))
    preorden_types = ["Ordenado", "Aleatorio", "Inverso"]

    # Promediar tiempos por algoritmo y preorden (si hay varias pruebas del mismo tipo)
    avg_times = {alg: {p: [] for p in preorden_types} for alg in algorithms}
    for (size, preorden, name, t) in results:
        if t != float('inf'):
            avg_times[name][preorden].append(t)

    # Calculamos promedios
    for alg in algorithms:
        for p in preorden_types:
            if avg_times[alg][p]:
                avg_times[alg][p] = sum(avg_times[alg][p]) / len(avg_times[alg][p])
            else:
                avg_times[alg][p] = 0

    # Convertimos a listas para graficar
    ordenado_vals = [avg_times[alg]["Ordenado"] for alg in algorithms]
    aleatorio_vals = [avg_times[alg]["Aleatorio"] for alg in algorithms]
    inverso_vals = [avg_times[alg]["Inverso"] for alg in algorithms]

    # Posiciones de las barras
    x = np.arange(len(algorithms))
    width = 0.25  # ancho de cada barra

    # Crear figura
    plt.figure(figsize=(12, 6))
    plt.title("Comparación de Tiempos por Algoritmo y Tipo de Arreglo", fontsize=14, fontweight='bold')
    plt.xlabel("Método de Ordenamiento", fontsize=12)
    plt.ylabel("Tiempo (segundos)", fontsize=12)

    # Dibujar las barras (Ordenado, Aleatorio, Inverso)
    plt.bar(x - width, ordenado_vals, width, label="Ordenado", color="#6AC36A")  # verde
    plt.bar(x, aleatorio_vals, width, label="Aleatorio", color="#FFD966")         # amarillo
    plt.bar(x + width, inverso_vals, width, label="Inverso", color="#FFA64D")     # naranja

    # Configurar eje X
    plt.xticks(x, algorithms, rotation=30, ha="right")

    # Ajustar escala logarítmica si hay diferencias grandes
    max_time = max(max(ordenado_vals), max(aleatorio_vals), max(inverso_vals))
    if max_time > 100 or max_time < 0.001:
        plt.yscale("log")
        plt.ylabel("Tiempo (segundos, escala log)", fontsize=12)

    # Mostrar leyenda y cuadrícula
    plt.legend(title="Tipo de Arreglo")
    plt.grid(axis="y", linestyle="--", alpha=0.7)

    # Mostrar los valores arriba de cada barra (opcional)
    for bars in [ordenado_vals, aleatorio_vals, inverso_vals]:
        for i, v in enumerate(bars):
            if v > 0:
                plt.text(i, v * 1.05, f"{v:.2e}" if v < 0.01 or v > 100 else f"{v:.3f}", 
                         ha="center", fontsize=8, rotation=90)

    plt.tight_layout()
    plt.show()


# --- 7. Aki Arranca Todo ---
# (Esta seccion esta IDENTICA)

if __name__ == "__main__":
    # 1. Corremos las pruebas
    results_data, should_plot = run_benchmarks()
    
    # 2. Mostramos el resumen en texto (siempre es util)
    show_results(results_data)
    
    # 3. Graficamos solo si el usuario eligio la opcion 5
    if should_plot:
        plot_results(results_data)

    print("\n¡Benchmark completado! Adios.")