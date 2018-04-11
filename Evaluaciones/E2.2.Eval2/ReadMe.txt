La empresa Jueg A.S. es una empresa dedicada a la producción, almacenamiento y distribución de videojuegos.
Los tipos de videojuegos creados son:
	-Estrategia (Lucha y Arcade)
	-Aventura (Plataforma y Gráfica)
	-Aprendizaje (Idiomas, Música)

Para cada videojuego agrega al menos 3 atributos diferentes.

La creación de videojuegos involucra las siguientes operaciones
(cada uno de los siguientes es un método necesario para la creación de un videojuego –instancia-):
	-Concepción
	-Diseño
	-Planificación
	-Producción
	-Pruebas de aceptación

	Nota: en cada método sólo agrega un mensaje que indique que estás en el proceso correspondiente.

Se pide que selecciones varios patrones de diseño (al menos 3) que permitan encapsular la creación de videojuegos.
Dado que se producen muchas copias de un mismo videojuego, se pide utilizar el patrón Prototype.

Además de la definición de los productos se pide que elabores un almacén (una clase que encapsule los procesos de un almacén de videojuegos). Las operaciones disponibles para el almacén son
(puedes utilizar vectores, listas o lo que más te convenga):
	-Crea el inventario:
		-Selecciona una estructura de datos para guardar el almacén
	-Agregar videojuegos al inventario
	-Eliminar videojuegos del inventario (elimina por número de serie o por nombre).
	-Incluye una función que permite deshacer las últimas tres operaciones de eliminación (re-hacer) (utiliza un patrón de diseño)
	-Ordenar los videojuegos que se tienen disponibles
		-Por precio de menor a mayor y viceversa
	-Buscar videojuegos
		-La búsqueda se puede realizar por número de serie (único) o por nombre
	-Obtener el número total de elementos en el inventario
	-Imprimir todos los elementos del inventario
	-Crea un método que permita realizar operaciones sobre los precios de los productos del inventario.
	Las operaciones que se pueden realizar son incrementar o reducir el precio en un cierto porcentaje.
	Crea un método que reciba como parámetros el inventario y la función a realizar (operación: incremento, etc.) (utiliza el patrón de diseño Visitor)
	-Agrega un pequeño menú en que se permita acceder a todas las funciones anteriores
La empresa es muy innovadora y continuamente está creando videojuegos nuevos. El público entusiasta de los videojuegos desea estar siempre enterado de los nuevos lanzamientos por lo que se te pide que desarrolles un sistema de notificaciones. Cada que se crea una instancia de un videojuego nuevo automáticamente se notifica a los usuarios inscritos al sistema de notificaciones y dichos usuarios contestan (imprimen) felices que se han enterado. (utiliza el patrón Observer)
	Entregables
		incluye todos los diagramas realizados (clases)
		Código desarrollado
			Coloca todo tu código en la carpeta de GitHub que le corresponde (ver syllabus)


Patrones:
	-Prototype
	-Command
	-Visitor (incrementar/reducir_precio operacion(inventario, incrementar);)
	-Observer
