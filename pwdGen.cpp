#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class PasswordGenerator {
    private:
        int pwdLen;
        const string Upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const string Lower = "abcdefghijklmnopqrstuvwxyz";
        const string Num = "0123456789";
        const string Spl = "!@#$%&*?";

    public:
        void setLength(int len) {
            pwdLen = len;
        }

        string generatePassword() {
            srand(time(nullptr));

            int alphaSize = 26;
            int numSize = 10;
            int splSize = Spl.size();
            string passWord = "";

            for (int i = 0; i < pwdLen; i++) {
                string randSelect = "3120";
                int randomSelection = rand() % randSelect.size();
                char selected;

                switch (randomSelection) {
                    case 0:
                        selected = Upper[rand() % alphaSize];
                        break;
                    case 1:
                        selected = Lower[rand() % alphaSize];
                        break;
                    case 2:
                        selected = Num[rand() % numSize];
                        break;
                    case 3:
                        selected = Spl[rand() % splSize];
                        break;
                }

                passWord += selected;
            }
            return passWord;
        }
};

int main() {
    cout << "----------------PASSWORD GENERATOR----------------" << std::endl;

    PasswordGenerator generator;

    int pwdLen;
    cout << "Enter the password length : ";
    cin >> pwdLen;

    generator.setLength(pwdLen);

    while (true) {
        char Generate;
        cout << "Generate Password (y/n): ";
        cin >> Generate;

        switch (Generate) {
            case 'y':
                cout << "Your Password is : " << generator.generatePassword() << endl;
                break;

            case 'n':
                exit(0);

            default:
                cout << "Invalid input. Please enter 'y' or 'n'." << endl;
                break;
        }
    }

    return 0;
}
