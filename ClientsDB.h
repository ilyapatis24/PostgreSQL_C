#pragma once
#pragma execution_character_set("utf-8")
#include <iostream>
#include <pqxx/pqxx>
#include <string>
#include <Windows.h>

struct Client
{
	std::string name_;
	std::string surname_;
	std::string email_;
	std::vector<std::string> phones_;
};

class ClientsDB
{
private:
	pqxx::connection connection_;

public:
	ClientsDB(const std::string& connection);
	ClientsDB() = delete;
	void dropTables();
	void createTables();
	void addClient(const std::string& name, const std::string& surname, const std::string& email, const std::string& phone);
	void addPhone(const std::string& name, const std::string& phone);
	void updateClient(const std::string& email, const std::string& newName, const std::string& newSurname, const std::string& newEmail);
	void removePhone(const std::string& email, const std::string& phone);
	void removeClient(const std::string& email);

	std::vector<Client> findClients(const std::string& query);

	void show();
};
