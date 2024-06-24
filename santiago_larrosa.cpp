#include <stdio.h>
#include <windows.h>
//lo hice en dev C++

//Matriz que contiene los datos ligados al operador como las ventas que genero tanto cantidad como valor total y si alguna venta supero las 4 unidades
int OpMatriz [7][3];
//Vcetor que contiene ganacias por tipo
int TipGanVec [4];
//Los precios por tipo de vainda
int Precios [4] = {100, 300, 200, 50};
//Compruebo la cantidad de ventas que superaron la cantidad de 4 unidades
int VentasMas4 = 0;
//Ganacias por operador
float OperadorGan [7];

//Funcion que asigna los valores de la matriz operador
void Operador (int Op, int TipVianda, int Cant, int Mas4) {
	//Ganacias en total para el negocio
	OpMatriz [Op-1][0] += Precios[TipVianda-1] * Cant;
	//Cantidad de unidades vendidas
	OpMatriz [Op-1][1] += Cant;
	//Cantidad de operaciones que superaron las 4 unidades sirve para asignar el extra
	OpMatriz [Op-1][2] += Mas4;
}
//Asigna el valor de ganancia por tipo de vianda
void Vianda (int TipVianda, int Cant){
	//Hago la operacion correspondiente
	TipGanVec[TipVianda-1] += Cant* Precios[TipVianda-1] ;
}
//Funcion para tomar los datos
int TomarPedido (int Op){
	//Tipo de vianda
	char TipVianda;
	//Cantidad
	int Cant;
	//Convierte valor char a int para que lo pueda manejar
	int TipoNum;
	int Mas4 = 0;
	
	//Pregunto por el tipo de vianda y le doy el valor al usuario
	printf ("Ingrese el tipo de vianda \n V = vegetales| C = carne | P = pescado | F = frutas \n");
	printf ("Precio por tipo de vianda\n                    VEGETALES = %d \n                    CARNE = %d \n                    PESCADO = %d \n                    FRUTAS %d\n",Precios[0],Precios[1],Precios[2],Precios[3]);
	scanf (" %c", &TipVianda);
	//Convierto los valores de letras a numeros para los calculos
	switch (TipVianda){
		case 'V':
			TipoNum=1;
			break;
		case 'C':
			TipoNum=2;
			break;
		case 'P':
			TipoNum=3;
			break;
		case 'F':
			TipoNum=4;
			break;
		default :
			//En caso de que ingrese un valor erroneo
			printf ("Esa opcion NO EXISTE\n");
			return 0;
			break;
	}
	//Enetendi que solo se puede un tipo de vianda por pedido
	printf ("Hola! \n Cada tipo de vianda es un pedido por ende debe especificar la CANTIDAD \n");
	scanf ("%d", &Cant);
	//Si lo supera le suma uno a la cantidad de pedidos que superaron 4
	if (Cant > 4){
		VentasMas4 ++;
		Mas4 = 1;
	}
	//Llamo a las funciones correspondientes con sus valores tambien
	Operador (Op, TipoNum, Cant, Mas4);
	Vianda (TipoNum, Cant);

}
//Funcion para obtener las ganancias de los operadores
void OperadorGanFun () {
	float por = 1;
	for (int i = 0; i < 7; i++) {
		//Compruebo si es que hicieron alguna venta que superara las 4 unidades
		if (OpMatriz[i][2] > 0){
			por = 0.13;
		
		}
		else if (OpMatriz[i][2] == 0) {
			por = 0.10;
		}
		// Hago la cuenta
		OperadorGan[i] = OpMatriz[i][0]*por; 
		
	}
}

int main (){
	int Op = 1;
	//Esta variable sirve para ver si es que puse un valor mayor a 7
	int ok = 0;
	//Mientras que sea mayor a cero
	while(Op > 0) {
		ok = 0;
		//Mientras que sera menor o igual a 7
	while (!ok){
	printf ("Elija el operador que desea que lo atienda \n| 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n");
	scanf ("%d", &Op);
	if (Op <= 7){
		ok = 1;
	}
	}
	if (Op<1){
		break;
	}
	//Llamo a la funcion para tomar un pedido
	TomarPedido(Op);
	}
	//Llamo a la consola para asignar colores
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//Asigno color verde de fondo y blanco para las letras
	SetConsoleTextAttribute(hconsole, BACKGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	//Llamo a la funcion de ganancia por operador
	OperadorGanFun();
	//Entrego los datos finales
	printf ("Estos son los datos del dia                                                       \n");
	printf ("La cantidad de Ventas que superaron las 4 viandas: %d                             \n", VentasMas4);
    printf ("Las ganancias por tipo de vianda:                                                 \n");
    printf ("Verduras: %d                                                                      \n", TipGanVec[0]);
    printf ("Carne: %d                                                                         \n", TipGanVec[1]);
    printf ("Pescado: %d                                                                       \n", TipGanVec[2]);
    printf ("Frutas: %d                                                                        \n", TipGanVec[3]);
    for (int i = 0; i < 7; i++){
    	printf ("El operador %d Vendio %d viandas Sus ganacias totales fueron de %f\n",i+1,OpMatriz[i][1], OperadorGan[i]);
	}
	//Vuelvo al valro original
		SetConsoleTextAttribute(hconsole,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

