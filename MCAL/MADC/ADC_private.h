/*
 * ADC_private.h
 *
 *  Created on: Sep 23, 2026
 *      Author: mohamed
 */

#ifndef MCAL_MADC_ADC_PRIVATE_H_
#define MCAL_MADC_ADC_PRIVATE_H_

#define ADMUX     (*((volatile u8*)(0x27)))
#define ADCSRA    (*((volatile u8*)(0x26)))
#define ADCH      (*((volatile u8*)(0x25)))
#define ADCL      (*((volatile u8*)(0x24)))
#define ADC_DATA  (*((volatile u16*)(0x24)))

#define ADC_VREF_AREF             0
#define ADC_VREF_AVCC             1
#define ADC_VREF_INTERNAL_2_56    3

#define ADC_PRESCALER_DIV_2       1
#define ADC_PRESCALER_DIV_4       2
#define ADC_PRESCALER_DIV_8       3
#define ADC_PRESCALER_DIV_16      4
#define ADC_PRESCALER_DIV_32      5
#define ADC_PRESCALER_DIV_64      6
#define ADC_PRESCALER_DIV_128     7


#endif /* MCAL_MADC_ADC_PRIVATE_H_ */
