#include "board.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "ciaaIO.h"

#include "main.h"


static void initHardware(void);

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

static void initHardware(void)
{
	SystemCoreClockUpdate();

	Board_Init();

	Board_LED_Set(0, false);
	ciaaIOInit();

}

static void task(void * a)
{
	while (1) {
		Board_LED_Toggle(0);
		vTaskDelay(500 / portTICK_RATE_MS);
	}
}

/* ESTA TAREA PRENDE UN LED*/
void tarea1 (void * parametro )
{

	while (1) {
		Board_LED_Toggle(0);
		vTaskDelay(500);
	}

}
/*ESTA TAREA VA A ESPERAR QUE SE APACHURRE UN PULSADOR  Y ENCENDERA UN LED CUANDO ESTO OCURRA*/
void tarea2 (void *parametro ){

	while (1) {
		if (ciaaReadInput (1) == 0) {
			Board_LED_Toggle(3);
			/*ESPERAR QUE TEC 2 SE SUELTA*/
			while (ciaaReadInput(1) ==0)
			{
				/*ESPERO*/
			}
		}

	}
}


/*==================[external functions definition]==========================*/

int main(void)
{
	initHardware();

	xTaskCreate(tarea1,"tarea1",512,0,1,0);
	xTaskCreate(tarea2,"tarea2",512,0,1,0);

	vTaskStartScheduler();

	while (1) {
	}
}

/** @} doxygen end group definition */

/*==================[end of file]============================================*/
