#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class BinToOct {
protected:
    string binary;
    int octal = 0;

public:
    BinToOct(string binary = "unknown") : binary(binary) {}

    void set_binary(string s) { binary = s; }
    string get_binary() const { return binary; }
    int get_oct() const { return octal; }

    bool is_valid_bin(const string& bin) const {
        for (char c : bin) {
            if (c != '0' && c != '1') {
                return false;
            }
        }
        return true;
    }

    void convertBinaryToOctal() {
        // Padding binary to make its length a multiple of 3
        while (binary.length() % 3 != 0) {
            binary = '0' + binary;
        }

        octal = 0;
        int length = binary.length();
        for (int i = 0; i < length; i += 3) {
            int digit = (binary[i] - '0') * 4 +
                (binary[i + 1] - '0') * 2 +
                (binary[i + 2] - '0') * 1;
            octal = octal * 10 + digit;
        }

        cout << "=> The result of conversion is: " << octal << endl;
    }
};

class HexaToOct : public BinToOct {
private:
    string hexa;
    string bin = "";

public:
    HexaToOct(string hexa = "unknown") : hexa(hexa) {}

    void set_hexa(string str) { hexa = str; }
    string get_bin() const { return bin; }
    string get_hexa() const { return hexa; }

    bool is_valid_hexa(const string& hexa) const {
        for (char c : hexa) {
            if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))) {
                return false;
            }
        }
        return true;
    }

    string convertHexalToBinary() {
        for (char c : hexa) {
            int n;
            if (c >= '0' && c <= '9') {
                n = c - '0';
            }
            else {
                n = c - 'A' + 10;
            }

            string temp;
            for (int i = 0; i < 4; ++i) {
                temp = char((n % 2) + '0') + temp;
                n /= 2;
            }
            bin += temp;
        }

        return bin;
    }
};

class OctToBin {
private:
    string octal;
    string bin = "";

public:
    OctToBin(string octal = "unknown") : octal(octal) {}

    void set_Oct(string s) { octal = s; }
    string get_Oct() const { return octal; }
    string get_Bin() const { return bin; }

    bool is_valid_Oct(const string& octal) const {
        for (char c : octal) {
            if (c < '0' || c > '7') {
                cout << "=> alert, you entered a digit or more that are not in the range [0-7]" << endl;
                return false;
            }
        }
        return true;
    }

    string convertOctalToBinary() {
        for (char c : octal) {
            switch (c) {
            case '0': bin += "000"; break;
            case '1': bin += "001"; break;
            case '2': bin += "010"; break;
            case '3': bin += "011"; break;
            case '4': bin += "100"; break;
            case '5': bin += "101"; break;
            case '6': bin += "110"; break;
            case '7': bin += "111"; break;
            }
        }
        return bin;
    }
};

class DecToOct {
private:
    int decimal;
    int octal = 0;

public:
    DecToOct(int decimal = 0) : decimal(decimal) {}

    void set_dec() {
        cout << " => Enter number in decimal system: " << endl << "\t => ";
        cin >> decimal;
    }

    int get_dec() const { return decimal; }
    int get_Octal() const { return octal; }

    void convertDecimalToOctal() {
        int temp = decimal;
        int multi = 1;
        while (temp > 0) {
            int remainder = temp % 8;
            octal += remainder * multi;
            temp /= 8;
            multi *= 10;
        }

        cout << "\n=> The result of conversion is: " << octal << endl;
    }
};

// function
void print_start()
{
    cout << "\n\t*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n";
    cout << "\t*~*~*~*~*~*~*~*~*~* NUMBER SYSTEMS *~*~*~*~*~*~*~*~*~*\n";
    cout << "\t*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n\n";

}

void main_function()
{
    int choice;

    while (true) {
       
        cout << "'''''''''''' AVAILABLE CONVERSIONS ''''''''''''" << endl;
        cout << "=> ( 1 ) Convert from Decimal to Octal" << endl;
        cout << "=> ( 2 ) Convert from Octal to Binary" << endl;
        cout << "=> ( 3 ) Convert from Binary to Octal" << endl;
        cout << "=> ( 4 ) Convert from Hexadecimal to Octal" << endl;
        cout << "\t Enter your choice: " << endl << "\t => ";
        cin >> choice;

        switch (choice) {
        case 1: {
            DecToOct decimal;
            decimal.set_dec();
            decimal.convertDecimalToOctal();
            break;
        }
        case 2: {
            OctToBin octal;
            string octalStr;
            cout << " => Enter number in Octal system: " << endl << "\t => ";
            cin >> octalStr;
            if (octal.is_valid_Oct(octalStr)) {
                octal.set_Oct(octalStr);
                cout << "=> The result after conversion : ";
               cout<< octal.convertOctalToBinary();
            }
            break;
        }
        case 3: {
            BinToOct binary;
            string binStr;
            cout << " => Enter number in Binary system: " << endl << "\t => ";
            cin >> binStr;
            if (binary.is_valid_bin(binStr)) {
                binary.set_binary(binStr);
                binary.convertBinaryToOctal();
            }
            break;
        }
        case 4: {
            HexaToOct hex;
            string hexStr;
            cout << " => Enter number in Hexadecimal system: " << endl << "\t => ";
            cin >> hexStr;
            if (hex.is_valid_hexa(hexStr)) {
                hex.set_hexa(hexStr);

                hex.convertHexalToBinary();
                string binaryStr = hex.get_bin();
                hex.set_binary(binaryStr);
                hex.convertBinaryToOctal();
            }
            break;
        }
        default:
            cout << " => Invalid choice. Exiting." << endl;
            return;
        }

        int retry_choice;
        cout << " \n*******************" << endl;
        cout << " => Enter:" << endl;
        
        cout << " => ( 1) to go to main menu" << endl;
        cout << " => ( 2) to exit." << endl;
        cout << "\t => ";
        cin >> retry_choice;

        if (retry_choice == 1) {
            continue; // Return to the main menu
        }
        else if (retry_choice == 2) {
            cout << " => See you soon!" << endl;
            return; // Exit the program
        }
       
    }
}

int main() {
    print_start();
    main_function();
    return 0;
}
