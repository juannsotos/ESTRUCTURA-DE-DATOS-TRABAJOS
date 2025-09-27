// 26/09/2025 Jp
class Program
{
    static int Filas = 9;
    static int Columnas = 9;
    static char[,] Tablero_1 = new char[Filas, Columnas];
    static char[,] Tablero_2 = new char[Filas, Columnas];


    public static void MostrarTablero1(char[,] matriz, int filas, int columnas)
    {
        char[] letras = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };
        Console.Write("  ");
        for (int j = 0; j < columnas; j++)
        {
            Console.Write(j + 1 + " ");
        }
        Console.WriteLine();
        
        for (int i = 0; i < filas; i++)
        {
            Console.Write(letras[i] + " ");
            for (int j = 0; j < columnas; j++)
            {
                Console.Write(matriz[i, j] + " ");
            }
            Console.WriteLine();
        }
       
    }

    public static void MostrarTablero2(char[,] matriz, int filas, int columnas)
    {
        char[] letras = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };
        Console.Write(" ");
        for (int j = 0; j < columnas; j++)
        {
            Console.Write(j + 1 + " ");
        }
        Console.WriteLine();

        for (int i = 0; i < filas; i++)
        {
            Console.Write(letras[i] + " ");
            for (int j = 0; j < columnas; j++)
            {
                Console.Write(matriz[i, j] + " ");
            }
            Console.WriteLine();
        }

    }
    public static void AgregarBarcos(int jugador)
    {
        if (jugador == 1)
        {
            for (int vuelta = 0; vuelta < 4; vuelta++)
            {
                Console.WriteLine("... Turno Jugador 1 ...");
                MostrarTablero1(Tablero_1, Filas, Columnas);
                Console.WriteLine(" 1) ## 2) ### 3) #### 4) ##### ");
                Console.Write(" ¿Que barco deseas agregar ?: ");
                int Barco = int.Parse(Console.ReadLine()) + 1;

                while (Barco < 2 || Barco > 5)
                {
                    MostrarTablero1(Tablero_1, Filas, Columnas);
                    Console.WriteLine(" 1) ## 2) ### 3) #### 4) ##### ");
                    Console.WriteLine("Barco Invalido, Ingrese numero correccto: ");
                    Barco = int.Parse(Console.ReadLine()) + 1;
                }

                Console.Write("Ingrese columna; ");
                int Columna = (int.Parse(Console.ReadLine()) - 1);
                while (Columna < 1 || Columna > 9)
                {
                    Console.WriteLine("Ingresa columna correcta (1 - 9): ");
                    Columna = (int.Parse(Console.ReadLine()) - 1);
                }

                Console.Write("Ingrese letra: ");
                char letra = Char.ToUpper(Console.ReadKey().KeyChar);
                int Fila = letra - 'A';
                Console.WriteLine();
                Console.Write("¿En que direccion? H) Horizontal | V) Vertical: ");
                char direccion = Char.ToUpper(Console.ReadKey().KeyChar);
                Console.WriteLine();
                if ((Barco >= 2) && (Barco <= 5))
                {
                    if (direccion == 'H')
                    {
                        if (Columna + Barco <= Columnas)
                        {
                            for (int i = 0; i < Barco; i++)
                            {
                                if (Tablero_1[Fila, Columna+i] == '#')
                                {
                                    Console.WriteLine();
                                    Console.WriteLine("Ya se encuentra un barco en dicha posicion !");

                                    break;
                                }
                                else
                                {
                                    Tablero_1[Fila, Columna+i] = '#';
                                }

                            }

                        }
                        else
                        {
                            Console.WriteLine(" !! SU BARCO EXCEDE EL TABLERO !! ");
                        }
                        
                    }
                    else if (direccion == 'V')
                    {
                        if (Fila + Barco <= Filas)
                        {
                            for (int i = 0; i < Barco; i++)
                            {
                                if (Tablero_1[Fila + i,Columna] == '#')
                                {
                                    Console.WriteLine("Ya se encuentra un barco en dicha posicion !");
                                    break;
                                }
                                else
                                {
                                    Tablero_1[Fila + i, Columna] = '#';
                                }

                            }
                        }
                        else
                        {
                            Console.WriteLine(" !! CORDENADAS INVALIDAS !!");
                        }
                    }
                    else
                    {
                        Console.WriteLine("Error, barco invalido");
                    }
                }

                MostrarTablero1(Tablero_1, Filas, Columnas);
                Console.ReadKey();
                Console.Clear();
            }
           
        }
        
        if (jugador == 2)
        {
            MostrarTablero2(Tablero_2, Filas, Columnas);
            Console.WriteLine(" ... Turno Jugador 2 ... ");
            Console.WriteLine(" ¿Que barco deseas agregar ?");
            Console.WriteLine(" 1) ## 2) ### 3) #### 4) ##### ");
            int Barco = int.Parse(Console.ReadLine());

        }
    }   
    static void Main()
    {
       
        //Llenar el tableros
        for (int i = 0; i < Filas; i++)
        {
            for (int j = 0; j < Columnas; j++)
            {
                Tablero_1[i, j] = '~';
                Tablero_2[i, j] = '~';

            }
        }
        //Colocar barcos
        int Jugador = 1;
        AgregarBarcos(Jugador);
        int jugador = 2;
        AgregarBarcos(jugador);

        //for (int i = 0; i < 26; i++)
        {
            Console.WriteLine(" -- Tablero Jugador 1 -- ");
            MostrarTablero1(Tablero_1, Filas, Columnas);
            Console.WriteLine(" -- Tablero Jugador 2 -- ");
            MostrarTablero2(Tablero_2, Filas, Columnas);
        }
        

    }
}
