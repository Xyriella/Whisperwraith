#pragma once
#include <map>
#include <string>
#include <vector>
class Settings
{
public:
	Settings();
	void loadSettings();
	void saveSettings();

	bool getInt(const std::string key, int& value);
	bool getBool(const std::string key, bool& value);
	bool getFloat(const std::string key, float& value);
	bool getString(const std::string key, std::string& value);

	bool getIntArray(const std::string key, std::vector<int>& value);
	bool getBoolArray(const std::string key, std::vector<bool>& value);
	bool getFloatArray(const std::string key, std::vector<float>& value);
	bool getStringArray(const std::string key, std::vector<std::string>& value);

	bool getIntMapS(const std::string key, std::map<std::string, int>& value);
	bool getBoolMap(const std::string key, std::map<std::string, bool>& value);
	bool getFloatMap(const std::string key, std::map<std::string, float>& value);
	bool getStringMap(const std::string key, std::map<std::string, std::string>& value);

	bool setInt(const std::string key, int& value);
	bool setBool(const std::string key, bool& value);
	bool setFloat(const std::string key, float& value);
	bool setString(const std::string key, std::string& value);

	bool setIntArray(const std::string key, std::vector<int>& value);
	bool setBoolArrayS(const std::string key, std::vector<bool>& value);
	bool setFloatArray(const std::string key, std::vector<float>& value);
	bool setStringArray(const std::string key, std::vector<std::string>& value);

	bool setIntMap(const std::string key, std::map<std::string, int>& value);
	bool setBoolMap(const std::string key, std::map<std::string, bool>& value);
	bool setFloatMap(const std::string key, std::map<std::string, float>& value);
	bool setStringMap(const std::string key, std::map<std::string, std::string>& value);

private:

public:
private:

	//Line format
	//{structure}{type} "{name}" {data}

	std::map<std::string, int> intSettings;											//si
	std::map<std::string, float> floatSettings;										//sf
	std::map<std::string, bool> boolSettings;										//sb
	std::map<std::string, std::string> stringSettings;								//ss

	std::map<std::string, std::vector<int>> intArraySettings;						//ai
	std::map<std::string, std::vector<float>> floatArraySettings;					//af
	std::map<std::string, std::vector<bool>> boolArraySettings;						//ab
	std::map<std::string, std::vector<std::string>> stringArraySettings;			//as

	std::map<std::string, std::map<std::string, int>> intMapSettings;				//mi
	std::map<std::string, std::map<std::string, float>> floatMapSettings;			//mf
	std::map<std::string, std::map<std::string, bool>> boolMapSettings;				//mb
	std::map<std::string, std::map<std::string, std::string>> stringMapSettings;	//ms
};

