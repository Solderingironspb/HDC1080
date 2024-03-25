/*
 * HDC1080.h
 *
 *  Created on: 25 мар. 2024 г.
 *      Author: Oleg Volkov
 *
 * Простенькая библиотека для работы с датчиком температуры и влажности HDC1080
 */

/*Пример работы:
 * 		extern struct AFilter_structure AFilter; //Обьявляем структуру данных фильтра
 *
 * 		int main(void){
 * 		HDC1080_init();
 * 		while(1){
 * 			//Получать данные о температуре и влажности с периодом 0,1 с
 *			Delay_ms(50); //50 перед запросом и 50 перед получением ответа
 *			HDC1080_Run();
 *			}
 *		}
*/

#ifndef INC_HDC1080_H_
#define INC_HDC1080_H_

#include "stm32f103xx_CMSIS.h"

#define HDC1080_ADDR		0x40
#define HDC1080_I2C_USE		I2C1

typedef struct{
	float Temperature;		//Температура
	float Humidity;			//Влажность
	uint16_t Settings;		//Настройки модуля
	uint8_t tx_buffer[3];	//Исходящий буфер
	uint8_t rx_buffer[4];	//Входящий буфер
	bool flag;				//Флаг для периодического опроса
}HDC1080_struct;

void HDC1080_init(void);
void HDC1080_Send_request(void);
void HDC1080_Get_data(void);
void HDC1080_Run(void);

#endif /* INC_HDC1080_H_ */
