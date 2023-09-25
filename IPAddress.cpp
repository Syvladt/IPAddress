// IPAddress.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>


std::string octetget_address_part(std::string inStr, int part) {
    std::string octet = "";
    int numOctet = 0;
    for (int i = 0; i < inStr.length(); i++) {
        if (inStr [i] == '.') {
            numOctet++;
            i++;
        }
        if (numOctet == part) {
            octet += inStr[i];
        }
    }
    if (numOctet > 3)
        octet = "";
    return octet;
}

bool validate_octet(std::string inStr) {
    int int_octet = 0;
    if (inStr.length() < 1)
        return false;
    if (inStr[0] == '0' && inStr.length() > 1)
        return false;
    for (int i = inStr.length() - 1; i >= 0 ; i--) {
        if (inStr[i] < '0' || inStr[i] > '9')
            return false;
        else
            int_octet += (inStr[i] - '0') * pow (10, (inStr.length() - 1 - i));
    }
    if (int_octet >= 0 && int_octet <= 255)
        return true;
    else
        return false;
}

int main()
{
    std::string ipAdd;
    std::cout << "\nValidator IP address!\n\n";
    std::cout << "Input ip address: ";
    std::getline(std::cin, ipAdd);

        if (validate_octet(octetget_address_part(ipAdd, 0)) &&
            validate_octet(octetget_address_part(ipAdd, 1)) &&
            validate_octet(octetget_address_part(ipAdd, 2)) &&
            validate_octet(octetget_address_part(ipAdd, 3)))
            std::cout << "Valid\n";
        else
            std::cout << "Invalid\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
