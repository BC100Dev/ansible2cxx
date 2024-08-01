// Test Code Purposes only

#include <iostream>
#include <fstream>
#include <yaml-cpp/yaml.h>

int main(int argc, char** argv) {
    try {
        YAML::Node config = YAML::LoadFile("TestScript.yml");

        for (const auto& item : config) {
            std::cout << "Name: " << item["name"].as<std::string>() << std::endl;
            std::cout << "Hosts: " << item["hosts"].as<std::string>() << std::endl;
            std::cout << "User: " << item["user"].as<std::string>() << std::endl;

            if (item["tasks"]) {
                std::cout << "Tasks:" << std::endl;
                for (const auto& task : item["tasks"]) {
                    std::cout << "  Task Name: " << task["name"].as<std::string>() << std::endl;
                    std::cout << "  Copy:" << std::endl;
                    std::cout << "    Backup: " << task["copy"]["backup"].as<bool>() << std::endl;
                    std::cout << "    Source: " << task["copy"]["src"].as<std::string>() << std::endl;
                    std::cout << "    Destination: " << task["copy"]["dest"].as<std::string>() << std::endl;
                    std::cout << "    Owner: " << task["copy"]["owner"].as<std::string>() << std::endl;
                    std::cout << "    Group: " << task["copy"]["group"].as<std::string>() << std::endl;
                    std::cout << "    Mode: " << task["copy"]["mode"].as<int>() << std::endl;
                }
            }

            if (item["handlers"]) {
                std::cout << "Handlers:" << std::endl;
                for (const auto& handler : item["handlers"]) {
                    std::cout << "  Handler Name: " << handler["name"].as<std::string>() << std::endl;
                    std::cout << "  Service:" << std::endl;
                    std::cout << "    Name: " << handler["service"]["name"].as<std::string>() << std::endl;
                    std::cout << "    State: " << handler["service"]["state"].as<std::string>() << std::endl;
                }
            }
        }
    } catch (const YAML::Exception& e) {
        std::cerr << "Error parsing YAML file: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}