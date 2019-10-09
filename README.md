# WORKSHOP7: PROTOCOLOS DE COMUNICACIÓN I2C & SPI
Realizado por: Daniel Cristancho
Universida Sergio Arboleda, Bogotá-Colombia
Ingeniería electrónica

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

<a href="SPI"><img src="../master/Imagenes/SPI.png"  width="50%" align="justify"></a>

**I2C**
* velocidad de transmisión muy altas, simplicidad y funcionamiento
* Puede transmitir y recibir información permitiendo que dos dispositivos se puedan comunicar entre si
* Sistema de comunicación de muy corta distancia
* La comunicaciín es en serie y sincrónica
* Flujo de datos equivalente es de 3.4 Mbps
* Utiliza menos pines comparado con SPI
* Hardware más complejo comparado con SPI
* La comunicación es más lenta comprada con SPI
* Es multimaestro y multiesclavo
* Utiliza dos hilos bidireccionales: SDA (Serial Data Line) y SCL (Serial Clock Line)
* Usa de 7 a 10 bits de direcciones 
* Permite velocidades de 100Kbits/s en standard mode, 10Kbits/s en low-speed mode, 400Kbits/s en Fast mode, 1Mbit/s en Fast mode plus y 3.4 Mbits/s en High speed mode

**DIAGRAMA DE CONEXIÓN SPI**

<a href="I2C"><img src="../master/Imagenes/I2C.png"  width="50%" align="justify"></a>

### CRITERIOS DE DISEÑO

1. Establecer comunicación Maestro-Esclavo utilizando SPI e I2C
2. Permitir la recepción y el envio de datos entre maestro-esclavo según la comunicación empleada
3. La señal detectada por el sistema debera generarla un pulsador
4. Generar una alerta visual cuando el dato fue entregado exitosamente 
5. Realizar el Script en raspbian por comunicación SSH (Aplica para rapsberry)

### DIAGRAMA DE BLOQUES DE LA SOLUCIÓN


### COMUNICACIÓN I2C
**Procedimiento**

1. Iniciar la raspberry y acceder a la consola de comando
2. Configurar la raspberry
  * sudo raspi-config
  * selesccionar interfacing options
  * seleccionar i2c 
  * seleccionar si
  * seleccionar aceptar
  * seleccionar finish
  
3. Verificar la comunicación I2C usando sudo i2cdetect -y 1
4. Instalar python sudo apt-get install python-smbus
5. Instalar librerias usando sudo apt-get install rpi.gpio 
6. Crear el script de Python usando sudo nano NOMBREDELSCRIPT.py (Tener presente en que directorio se guardo)
7. Compilar el script usando python NOMBREDELSCRIPT.py

**SCRIPT DE PYTHON** 

    import smbus
    import time
    import Rpi.GPIO as GPIO         #IMPORTAR LIBRERIAS
    
    us = smbus.SMBus(1)            #i2c
    address = 0x04                  #Direccion de conexion
    
    GPIO.setmode(GPIO.BCM)          #Iniciando GPIO
    GPIO.setup(18, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)     #GPIO18 como entrada (pin 12)
    
    def WBytes():
        bus.write_byte(address,1)
        return -1
        
    while true:                     #Encendido y apagado del led
        if GPIO.input(18) == 1:
                WBytes()
                print ("Envio : ")
        time.sleep(1)

**CONFIGURAR EL ARDUINO COMO ESCLAVO**
**SCRIPT DE ARDUINO** 

    #include <Wire.h>
    char x='0';
    void setup() {

      //Estableciendo direccion con Raspberry Pi 3
      Wire.begin(0x10);                   
      Wire.onReceive(receiveEvent); 

      //Estableciendo configuracion de Arduino
      pinMode(LED_BUILTIN, OUTPUT);
      pinMode(7 ,OUTPUT);
      digitalWrite(LED_BUILTIN, LOW); 
      Serial.begin(9600); 
    }
    void loop() { //Ciclo de encendido y apagado del LED
      delay(100);

      if(x==1){
         Serial.println("Encendiendo");
         digitalWrite(LED_BUILTIN, HIGH);
         digitalWrite(7, HIGH);
     }else{
         Serial.println("Apagando");
         digitalWrite(LED_BUILTIN, LOW);
         digitalWrite(7, LOW);
         }
     }
     
    void receiveEvent(int howMany) {
    while (Wire.available()) { 
      x = Wire.read();
      }
    }

**DIAGRAMA DE CONEXIÓN I2C** 
<a href="I2C"><img src="../master/Esquemáticos/I2C_esquematico.PNG"  width="50%" align="justify"></a>
