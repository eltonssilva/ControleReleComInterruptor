void connectToMqtt(){
  Serial.println("Conectando para o MQTT");
  mqttClient.connect();
}

void onMqttConnect(bool sessionPresent){
  Serial.println("Conectado no MQTT...");
  mqttClient.subscribe(MQTT_SUB_VALUE_LUZ_R, 2);
  mqttClient.subscribe(MQTT_SUB_VALUE_LUZ_G, 2);
  mqttClient.subscribe(MQTT_SUB_VALUE_LUZ_Y, 2);
}

void onMqttDisconnect(AsyncMqttClientDisconnectReason reason){
  Serial.println("Disconectado no MQTT...");

  if(WiFi.isConnected()){
    mqttReconnectTimer.once(2, connectToMqtt);
  }
  
}


void onMqttMessage(char* topic, char* payload, AsyncMqttClientMessageProperties properties, size_t len, size_t index, size_t total){
  Serial.print(topic);
  Serial.print(" ---- ");
  Serial.println(payload[0]);

  if( strcmp(topic, MQTT_SUB_VALUE_LUZ_R) == 0 ){
    Serial.println("Vermelho");

          if(payload[0] == '1'){
            // Ligo a lampada
            digitalWrite(Rele_R, HIGH);
            mqttClient.publish(MQTT_PUB_STATE_LUZ_R, 1, true, "1");
            
          }else if(payload[0] == '0'){
            // Desligo a lampada
            digitalWrite(Rele_R, LOW);
            mqttClient.publish(MQTT_PUB_STATE_LUZ_R, 1, true, "0");
          }

 
    
  }else if(strcmp(topic, MQTT_SUB_VALUE_LUZ_G) == 0){
    Serial.println("Verde");


          if(payload[0] == '1'){
            // Ligo a lampada
            digitalWrite(Rele_G, HIGH);
            mqttClient.publish(MQTT_PUB_STATE_LUZ_G, 1, true, "1");
            
          }else if(payload[0] == '0'){
            // Desligo a lampada
            digitalWrite(Rele_G, LOW);
            mqttClient.publish(MQTT_PUB_STATE_LUZ_G, 1, true, "0");
          }



    
  }else if(strcmp(topic, MQTT_SUB_VALUE_LUZ_Y) == 0){
    Serial.println("Amarelo");

          if(payload[0] == '1'){
            // Ligo a lampada
            digitalWrite(Rele_Y, HIGH);
            mqttClient.publish(MQTT_PUB_STATE_LUZ_Y, 1, true, "1");
            
          }else if(payload[0] == '0'){
            // Desligo a lampada
            digitalWrite(Rele_Y, LOW);
            mqttClient.publish(MQTT_PUB_STATE_LUZ_Y, 1, true, "0");
          }


    
    
  }


}

void mqttInit(){
  mqttClient.setServer(MQTT_HOST, MQTT_PORT);
  mqttClient.setCredentials(USER_MQTT, PASSWORD_MQTT);
  mqttClient.setClientId(ID_MQTT);
  mqttClient.onConnect(onMqttConnect);
  mqttClient.onDisconnect(onMqttDisconnect);
  mqttClient.onMessage(onMqttMessage);
}
