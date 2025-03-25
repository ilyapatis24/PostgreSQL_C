#include "ClientsDB.h"

int main(int argc, char** argv)
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    try
    {
        std::string connection_string = "host=127.0.0.1 port=5432 dbname=clients user=postgres password=postgres";
        ClientsDB db(connection_string);
        db.dropTables();
        db.createTables();

        db.addClient("Ilya", "Poteshonkov", "ilyapatis24@mail.ru", "+79115464033");
        db.show();


        db.addClient("Alexei", "Petrov", "apetrov@mail.ru", "+79115464022");
        db.show();

        try
        {
            db.addPhone("Ilya", "89658756555");
            db.show();

            db.addPhone("Alexei", "89658756548");
            db.show();
        }
        catch (const std::exception& ex)
        {
            std::cout << "Exception happened: " << ex.what() << std::endl;
        }

        try
        {
            db.updateClient("ilyapatis24@mail.ru", "Ilya", "Patis", "ilya24@mail.ru");
            db.show();

            db.updateClient("apetrov@mail.ru", "Leha", "Panov", "apanov@mail.ru");
            db.show();
        }
        catch (const std::exception& ex)
        {
            std::cout << "Exception happened: " << ex.what() << std::endl;
        }

        db.removePhone("ilya24@mail.ru", "+79115464033");

        db.removeClient("ilya24@mail.ru");

        std::vector<Client> foundClients = db.findClients("Leha");
        for (const auto& [name, surname, email, phones] : foundClients)
        {
            std::cout << "Found client: " << name << " " << surname << " " << email << " " << std::endl;
        }
        db.show();
    }
    catch (const std::exception& ex)
    {
        std::cout << "Exception happened: " << ex.what() << std::endl;
    }

    return 0;
};