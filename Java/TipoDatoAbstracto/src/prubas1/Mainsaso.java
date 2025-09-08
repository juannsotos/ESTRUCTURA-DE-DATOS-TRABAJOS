package prubas1;

public class Mainsaso {

    public static void main(String[] args) {
        Person persona1 = new Person();

        persona1.setName("Juan");
        persona1.setDocument("123456789");
        
        Person persona2 = new Person();
        persona2.setName("Carlos");
        persona2.setDocument("987654321");

        if (persona1.equals(persona2)){
            System.out.println("Los nombres son iguales");
        }else{
            System.out.println("Nombres diferentes");
        }

        



    }
    
}
