# WORKSHOP7: PROTOCOLOS DE COMUNICACIÓN I2C & SPI

## INTRODUCCIÓN
La intención de este laboratorio es comprender los protocolos de comunicación SPI e I2C y cómo desarrolarlos utilizando scripts  de raspbian, para ello, usaremos una Rasberry Pi3 B+ y un Arduino uno para hacer la comunicación entre ellos empleando cada uno de los protocolos anteriormente mencionados. 
Básicamente los sistemas deberán realizar las ordenes dispuestas en el dispositivo maestro (Raspberry) y ejecutar las intrucciones en el dispositivo esclavo(Arduino).

## MATERIALES
* 1 Computador con IDE de arduino y algún tipo de comunicación SSH para rapsberry
* 1 Raspberry Pi B+
* 1 Arduino (Cualquier versión o modelo)
* 1 Diodo LED con su respectiva resistencia (330 ohmios)
* 1 protoboard y cables de conexión
* 1 pulsador

## OBJETIVOS
* Afianzar los conceptos básicos asociados a Internet de las Cosas (IoT).
* Familiarizarse con los protocolos típicos de comunicaciones entre dispositivos IoT vía cables.
* Desarrollar dos aplicaciones sencillas para transferir comandos entre dos Raspberry Pi para encender y apagar un actuador LED utilizando I2C y SPI.
* Presentar las aplicaciones funcionando correctamente.
* Identificar las principales diferencias entre los protocolos de comunicación: I2C y SPI.

# DESARROLLO Y PROCEDIMIENTO
### CUADRO COMPARATIVO ENTRE SPI e I2C
**VENTAJAS**

**SPI**
* Comunicación Full dúplex
* Mayor velocidad de transmisión que otro bus serial.
* Protocolo flexible en que se puede tener un control absoluto sobre los bits transmitidos.
* Implementación en hardware simple
* No está limitado a la transferencia de bloques de 8 bits
* Elección del tamaño de la trama de bits, de su significado y propósito
* Transferencia de datos síncrona de 3 hilos
* Mayor rapidez comparado con I2C
* Doble búfer para transmisión de datos
* El maestro posee el control de todas las comunicaciones
* Puede tener más de un esclavo
* Menor gasto de energía comparado con I2C
* Utiliza físicamente más puntos de conexión (pines) que I2C
* Flujo de datos equivalente de 10 a 20 Mbps

**DIAGRAMA DE CONEXIÓN SPI**

<a href="SPI"><img src="../master/Imagenes/SPI.png"  width="50%" ></a>

<div style="width:50%">![Chilling](../master/Imagenes/SPI.png)</div>

