#TDA Empleado
# Nombre
# Apellido
# DNI

class Empleado:
    def __init__(self, nombre = "", apellido = "", dni = 0):
        self.nombre = nombre
        self.apellido = apellido
        self.dni = dni
    def __str__(self):
        cadenaPrint = self.nombre + " " + self.apellido + " (" + str(self.dni) + ")"
        return cadenaPrint
    def ObtenerNombre(self):
        return self.nombre

empleado1 = Empleado("Juan","Flores",1992929)
print(empleado1)
print(Empleado.ObtenerNombre(empleado1))
print(empleado1.ObtenerNombre())

        