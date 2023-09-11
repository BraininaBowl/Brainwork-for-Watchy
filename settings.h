#ifndef SETTINGS_H
#define SETTINGS_H

//WEATHER SETTINGS ARE CURRENTLY NOT USED 

//Weather Settings
#define CITY_ID  "2755420" //Gouda https://openweathermap.org/current#cityid
#define OPENWEATHERMAP_APIKEY "f058fe1cad2afe8e2ddc5d063a64cecb" //use your own API key :)
#define OPENWEATHERMAP_URL "http://api.openweathermap.org/data/2.5/weather?id=" //open weather api
#define TEMP_UNIT "metric" //metric = Celsius , imperial = Fahrenheit
#define TEMP_LANG "en"
#define WEATHER_UPDATE_INTERVAL 30 //must be greater than 5, measured in minutes

//NTP Settings
#define NTP_SERVER "pool.ntp.org"
#define GMT_OFFSET_SEC 3600 * 2 //Gouda = UTC +2, will be overwritten by weather data
#define DST_OFFSET_SEC 3600 * -0 // set to -1 for winter time

watchySettings settings{
    .cityID = CITY_ID,
    .weatherAPIKey = OPENWEATHERMAP_APIKEY,
    .weatherURL = OPENWEATHERMAP_URL,
    .weatherUnit = TEMP_UNIT,
    .weatherLang = TEMP_LANG,
    .weatherUpdateInterval = WEATHER_UPDATE_INTERVAL,
    .ntpServer = NTP_SERVER,
//    .gmtOffset = GMT_OFFSET_SEC,
    .gmtOffset = GMT_OFFSET_SEC + DST_OFFSET_SEC,
};

#endif
