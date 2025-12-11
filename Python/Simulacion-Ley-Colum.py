import pygame
import math

# --- CONFIGURACIÓN ---
ANCHO, ALTO = 800, 600
BLANCO = (255, 255, 255)
NEGRO = (0, 0, 0)
ROJO = (255, 50, 50)   # Positivas
AZUL = (50, 50, 255)   # Negativas

# Constante de Coulomb (ajustada para que se vea bien en pantalla, no es la real 9e9)
# En simulación visual a veces usamos escalas relativas.
# Si el profe pide valor real, usen k = 9e9 y ajusten las cargas a microCoulombs.
K_COULOMB = 10000 

class Particula:
    def __init__(self, x, y, carga):
        self.x = x
        self.y = y
        self.carga = carga # +1 o -1 para simplificar, o valores en Coulombs
        self.color = ROJO if carga > 0 else AZUL
        self.radio = 15

    def dibujar(self, ventana):
        pygame.draw.circle(ventana, self.color, (int(self.x), int(self.y)), self.radio)
        signo = "+" if self.carga > 0 else "-"
        font = pygame.font.SysFont("Arial", 20)
        texto = font.render(signo, True, BLANCO)
        ventana.blit(texto, (self.x - 5, self.y - 12))

        coord_texto = font.render(f"({int(self.x)}, {int(self.y)})", True, (200, 200, 200))
        ventana.blit(coord_texto, (self.x + 15, self.y + 15))

def calcular_fuerza(p1, p2):
    # 1. Distancia (Pitagoras)
    dx = p1.x - p2.x
    dy = p1.y - p2.y
    distancia = math.sqrt(dx**2 + dy**2)
    
    if distancia < 20: # Evitar división por cero si están muy cerca
        distancia = 20

    # 2. Ley de Coulomb (Magnitud)
    fuerza = K_COULOMB * abs(p1.carga * p2.carga) / (distancia**2)

    # 3. Dirección (Ángulo)
    angulo = math.atan2(dy, dx)

    # 4. Repulsión o Atracción
    if p1.carga * p2.carga > 0: # Cargas iguales se repelen
        fx = fuerza * math.cos(angulo)
        fy = fuerza * math.sin(angulo)
    else: # Cargas opuestas se atraen (fuerza va hacia la otra carga)
        fx = -fuerza * math.cos(angulo)
        fy = -fuerza * math.sin(angulo)
        
    return fx, fy, fuerza

# --- MAIN LOOP ---
def main():
    pygame.init()
    ventana = pygame.display.set_mode((ANCHO, ALTO))
    pygame.display.set_caption("Simulador Ley de Coulomb - Equipo Software")
    reloj = pygame.time.Clock()

    particulas = []
    particulas = [] 
    # --- CÓDIGO DE PRUEBA (AGREGAR ESTO) ---
    #particulas.append(Particula(200, 300, 10))  # Partícula 1 en X=200
    #particulas.append(Particula(400, 300, -10)) # Partícula 2 en X=400 (Distancia = 200)
    # ---------------------------------------
    font = pygame.font.SysFont("Arial", 18)

    corriendo = True
    while corriendo:
        ventana.fill(NEGRO)
        
        # Eventos
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                corriendo = False
            
            if event.type == pygame.MOUSEBUTTONDOWN:
                x, y = pygame.mouse.get_pos()
                if event.button == 1: # Clic Izquierdo (+)
                    particulas.append(Particula(x, y, 10)) # Carga +10
                elif event.button == 3: # Clic Derecho (-)
                    particulas.append(Particula(x, y, -10)) # Carga -10

        # Lógica Física
        # Vamos a calcular la fuerza TOTAL sobre la ÚLTIMA partícula agregada
        # generada por todas las anteriores.
        
        texto_info = ["Instrucciones: Clic Izq (+), Clic Der (-)"]
        
        if len(particulas) > 0:
            # Dibujar todas las partículas
            for p in particulas:
                p.dibujar(ventana)

            if len(particulas) >= 2:
                target = particulas[-1] # La última que pusimos
                fx_total = 0
                fy_total = 0
                
                # Sumatoria de fuerzas (Principio de Superposición)
                for i in range(len(particulas) - 1):
                    otra = particulas[i]
                    fx, fy, mag = calcular_fuerza(target, otra)
                    fx_total += fx
                    fy_total += fy
                    
                    # Dibujar línea de interacción (opcional)
                    pygame.draw.line(ventana, (50, 50, 50), (target.x, target.y), (otra.x, otra.y), 1)

                # Dibujar Vector Resultante
                # Escalamos el vector para que se vea en pantalla
                escala_visual = 5 
                end_x = target.x + fx_total * escala_visual
                end_y = target.y + fy_total * escala_visual
                
                pygame.draw.line(ventana, (0, 255, 0), (target.x, target.y), (end_x, end_y), 3)
                
                # Datos para el reporte
                mag_total = math.sqrt(fx_total**2 + fy_total**2)
                texto_info.append(f"Fuerza Resultante en última carga: {mag_total:.2f} N")
                texto_info.append(f"Componente X: {fx_total:.2f} N")
                texto_info.append(f"Componente Y: {fy_total:.2f} N")

        # Mostrar texto en pantalla
        for i, linea in enumerate(texto_info):
            img = font.render(linea, True, BLANCO)
            ventana.blit(img, (10, 10 + i * 20))

        pygame.display.flip()
        reloj.tick(60)

    pygame.quit()

if __name__ == "__main__":
    main()