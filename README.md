# Projeto - Daniel Pastore - Objetos Inteligentes Conectados

**Sistema de Rastreamento em Tempo Real para Inventário Industrial**

Código-fonte: Projeto_Obj_Inteligentes_DanielPastore.ino

**Descrição do Funcionamento e Software Desenvolvido**

O código para execução de testes pode ser encontrado na área de arquivos, com o nome “Projeto_Obj_Inteligentes_DanielPastore.ino”. Para executar esse código (compilar e transferir para o hardware), é necessário executá-lo na IDE do Arduino (conectar o hardware ao computador através da interface USB e selecionar o device apropriado na lista suspensa.
Na seção abaixo é possível encontrar a configuração do hardware compatível com o código disponível aqui.
Em resumo, o código é responsável em tratar a informação lida das tags RFID, gerar a informação necessária para informar no display LCD, bem como transmitir as informações através da biblioteca MQTT para os feeds / dashboard disponível no Adafruit para visualização dessas informações.

**Descrição do Hardware e Detalhes dos Sensores e Atuadores**
- Placa Arduino Uno R3;
- Alternativamente é possível utilizar a placa WeMos D1 WiFi – ESP8266, o que pode ser vantajoso, uma vez que já vem com integração nativa com o WiFi; 
- Sensor RFID – Módulo MFRC522 13.56 Mhz;
- Display LCD 16x2 Linhas (com controlador HD44780);
- Módulo WiFi (para uso com o Arduino Uno R3) ESP8266 ESP-12E;
- Chaveiro Tag RFID Mifare 1k 13.56 Mhz;
- Cartão RFID Programável Mifare 13.56 Mhz;

**Bibliotecas Utilizadas**
Para o desenvolvimento do código-fonte foram utilizadas as seguintes bibliotecas:
- SPI.h: para gestão da comunicação entre o Arduino e os dispositivos periféricos;
- MFRC522.h: para a leitura / escrita de tags RFID;
- WiFi.h: para conexão do Arquino a redes WiFi;
- Adafruit_MQTT.h: para implementação do protocolo MQTT;
- Adafruit_MQTT_Client.h: para configuração do cliente MQTT e integração com o WiFi;
- AdafruitIO_Wifi.h: para uso da plataforma Adafruit IO para gestão dos dados.


