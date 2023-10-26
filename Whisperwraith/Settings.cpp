#include "Settings.h"
#include <fstream>
#include <iostream>
#include <regex>

Settings::Settings()
{
	loadSettings();
}

void Settings::saveSettings()
{
	std::ofstream settingsFile(filename);
	for (const auto& pair : intSettings) {
		settingsFile << serializeIntLine(pair) << std::endl;
	}
	for (const auto& pair : boolSettings) {
		settingsFile << serializeBoolLine(pair) << std::endl;
	}
	for (const auto& pair : floatSettings) {
		settingsFile << serializeFloatLine(pair) << std::endl;
	}
	for (const auto& pair : stringSettings) {
		settingsFile << serializeStringLine(pair) << std::endl;
	}
	settingsFile.close();
}

bool Settings::getInt(const std::string& key, int& value)
{
	auto setting = intSettings.find(key);
	if (setting != intSettings.end()) {
		value = setting->second;
	}
	return setting != intSettings.end();
}

bool Settings::getBool(const std::string& key, bool& value)
{
	auto setting = boolSettings.find(key);
	if (setting != boolSettings.end()) {
		value = setting->second;
	}
	return setting != boolSettings.end();
}

bool Settings::getFloat(const std::string& key, float& value)
{
	auto setting = floatSettings.find(key);
	if (setting != floatSettings.end()) {
		value = setting->second;
	}
	return setting != floatSettings.end();
}

bool Settings::getString(const std::string& key, std::string& value)
{
	auto setting = stringSettings.find(key);
	if (setting != stringSettings.end()) {
		value = setting->second;
	}
	return setting != stringSettings.end();
}

bool Settings::setInt(const std::string& key, const int& value)
{
	bool alreadyExisted = intSettings.find(key) != intSettings.end();
	intSettings[key] = value;
	return alreadyExisted;
}

bool Settings::setBool(const std::string& key, const bool& value)
{
	bool alreadyExisted = boolSettings.find(key) != boolSettings.end();
	boolSettings[key] = value;
	return alreadyExisted;
}

bool Settings::setFloat(const std::string& key, const float& value)
{
	bool alreadyExisted = floatSettings.find(key) != floatSettings.end();
	floatSettings[key] = value;
	return alreadyExisted;
}

bool Settings::setString(const std::string& key, const std::string& value)
{
	bool alreadyExisted = stringSettings.find(key) != stringSettings.end();
	stringSettings[key] = value;
	return alreadyExisted;
}

void Settings::loadSettings()
{
	std::ifstream settingsFile(filename);
	std::string line;
	while (std::getline(settingsFile, line)) {
		std::string lineType = line.substr(0, 2);
		if (lineType == "si") {
			try {
				intSettings.emplace(processIntLine(line));
			}
			catch (std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
		}else if (lineType == "sb") {
			try {
				boolSettings.emplace(processBoolLine(line));
			}
			catch (std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
		}
		else if (lineType == "sg") {
			try {
				floatSettings.emplace(processFloatLine(line));
			}
			catch (std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
		}
		else if (lineType == "ss") {
			stringSettings.emplace(processStringLine(line));
		}
	}
	settingsFile.close();
}

std::pair < std::string, int> Settings::processIntLine(const std::string& line)
{
	std::string key = line.substr(4, line.find('"', 4) - 4);
	std::string valueString = line.substr(line.find('"', 4) + 1);
	return { key, std::stoi(valueString) };
}

std::pair < std::string, bool> Settings::processBoolLine(const std::string& line)
{
	std::string key = line.substr(4, line.find('"', 4) - 4);
	std::string valueString = line.substr(line.find('"', 4) + 1);
	if (valueString != "true" && valueString != "false") {
		throw std::invalid_argument("Value " + valueString + " could not be parsed as a bool");
	}
	return { key, valueString == "true" ? true : false };
}

std::pair < std::string, float> Settings::processFloatLine(const std::string& line)
{
	std::string key = line.substr(4, line.find('"', 4) - 4);
	std::string valueString = line.substr(line.find('"', 4) + 1);
	return { key, std::stof(valueString) };
}

std::pair < std::string, std::string> Settings::processStringLine(const std::string& line)
{
	std::string key = line.substr(4, line.find('"', 4) - 4);
	std::string value = line.substr(line.find('"', 4) + 2);
	return { key, value };
}

std::string Settings::serializeIntLine(const std::pair<std::string, int>& pair)
{
	return "si \"" + pair.first + "\" " + std::to_string(pair.second);
}

std::string Settings::serializeBoolLine(const std::pair<std::string, bool>& pair)
{
	return "sb \"" + pair.first + "\" " + (pair.second ? "true" : "false");
}

std::string Settings::serializeFloatLine(const std::pair<std::string, float>& pair)
{
	return "sf \"" + pair.first + "\" " + std::to_string(pair.second);
}

std::string Settings::serializeStringLine(const std::pair<std::string, std::string>& pair)
{
	const std::regex newLineFilter("\n|\\n");

	std::string filteredString = std::regex_replace(pair.second, newLineFilter, "");

	return "ss \"" + pair.first + "\" " + filteredString;
}
