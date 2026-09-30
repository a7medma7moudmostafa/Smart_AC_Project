#ifndef MCAL_MADC_ADC_INTERFACE_H_
#define MCAL_MADC_ADC_INTERFACE_H_

#define ADC_CH0   0
#define ADC_CH1   1
#define ADC_CH2   2
#define ADC_CH3   3
#define ADC_CH4   4
#define ADC_CH5   5
#define ADC_CH6   6
#define ADC_CH7   7

void MADC_voidInit(void);
u16  MADC_u16ReadChannel(u8 A_u8ChannelNum);

#endif /* MCAL_MADC_ADC_INTERFACE_H_ */
