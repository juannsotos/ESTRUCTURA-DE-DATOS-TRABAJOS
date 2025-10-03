import java.util.Scanner; // Creas la clase
public class BuscarNumero {
    public static void main(String[] args) {
        int[] misNumeros = {7, 25, 2, 30, 10, 8, 15, 43};
        Scanner lector = new Scanner(System.in); // Creas el objeto tipo scaner (se usa para recibir datos del usuario)
        System.out.print("Ahora, ingresa tu numero a buscar: ");
        int edad = lector.nextInt();
        
        boolean encontrado = false;
        for (int elemento : misNumeros) {
            if (elemento == edad) {
                encontrado = true;
                break; // Se rompe el ciclo, porque ya se encontro el número 15
            }
        }

        if (encontrado) {
            System.out.println("Se encontró el valor.");
        } else {
            System.out.println("No se encontró el valor.");
        }

        lector.close(); // Es una buena practica cerrar el scaner ya cuando no lo usas
    }
    
}
