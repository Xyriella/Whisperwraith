#pragma once
#include <map>
#include <string>
#include <vector>
class Settings
{
public:
	Settings();
	void saveSettings();

	//Getters
	bool getInt(const std::string& key, int& value);
	bool getBool(const std::string& key, bool& value);
	bool getFloat(const std::string& key, float& value);
	bool getString(const std::string& key, std::string& value);

	//Setters
	bool setInt(const std::string& key, const int& value);
	bool setBool(const std::string& key, const bool& value);
	bool setFloat(const std::string& key, const float& value);
	bool setString(const std::string& key, const std::string& value);

private:
	void loadSettings();

	std::pair<std::string, int> processIntLine(const std::string& line);
	std::pair<std::string, bool> processBoolLine(const std::string& line);
	std::pair<std::string, float> processFloatLine(const std::string& line);
	std::pair<std::string, std::string> processStringLine(const std::string& line);

	std::string serializeIntLine(const std::pair < std::string, int>& pair);
	std::string serializeBoolLine(const std::pair < std::string, bool>& pair);
	std::string serializeFloatLine(const std::pair < std::string, float>& pair);
	std::string serializeStringLine(const std::pair < std::string, std::string>& pair);
public:
private:

	const std::string filename = "options.txt";

	//Line format
	//{structure}{type} "{name}" {data}

	//data is one value
	std::map<std::string, int> intSettings;											//si
	std::map<std::string, bool> boolSettings;										//sb
	std::map<std::string, float> floatSettings;										//sf
	std::map<std::string, std::string> stringSettings;								//ss

	/*
	//Stored as comma seperated, strings with quotation marks
	std::map<std::string, std::vector<int>> intArraySettings;						//ai
	std::map<std::string, std::vector<bool>> boolArraySettings;						//ab
	std::map<std::string, std::vector<float>> floatArraySettings;					//af
	std::map<std::string, std::vector<std::string>> stringArraySettings;			//as

	//Comma seperated pairs structured as {"key", value}
	std::map<std::string, std::map<std::string, int>> intMapSettings;				//mi
	std::map<std::string, std::map<std::string, bool>> boolMapSettings;				//mb
	std::map<std::string, std::map<std::string, float>> floatMapSettings;			//mf
	std::map<std::string, std::map<std::string, std::string>> stringMapSettings;	//ms
	*/
};

