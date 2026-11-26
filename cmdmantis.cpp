#include <bitset>
#include <chrono>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <limits>
#include <random>
#include <string>
#include <thread>

using namespace std;
using namespace this_thread;
using namespace chrono;
using namespace filesystem;

void cicl() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

random_device rd;

mt19937 gen(rd());

int main() {
    string commands[] = {
        "help: show all commands;",
        "hex: do int in number;",
        "rd: output random word;",
        "mk: make .dat with text do you want;",
        "exit: exit from mantix;",
        "rm: open .dat file and read;",
        "hex*: enter hex in dec;",
        "cls: clear terminal;",
        "gtch: call glitch's;",
        "dl: delete dat;",
        "asc: do from char to int;",
        "bits*16: do from int to bits in 16 size;",
        "bits*8: do from int to bits in 8 size;",
        "calc: do calc action;",
        "ps: chage password;"
        //"bash: do bash command"//
    };
    // uniform_int_distribution<int> dstr(1, 5);//
    cout << "CMDMant1S L0ading..\n";
    sleep_for(seconds(2));
    try {
        path pass = "./ps/password.dat";
        if (exists(pass)) {
            for (int i = 0; i < 3; i++) {
                ifstream ps("./ps/password.dat");
                string password;
                cout << "login: ";
                string psdw;
                getline(ps, psdw);
                cin >> password;
                cicl();
                if (password == psdw) {
                    cout << "Logined :)\n";
                    ps.close();
                    break;
                } else {
                    cout << "login incorrect\n";
                    ps.close();
                    if (i == 2) return 0;
                }
            }
        } else {
            path dir = "./ps";
            create_directory(dir);
            cout << "create password: ";
            string pswd;
            cin >> pswd;
            cicl();
            ofstream pswr("./ps/password.dat");
            pswr << pswd;
            pswr.close();
        }
    } catch (...) {
        cout << "what's wrong :(\n";
    }
    while (true) {
        string cmd;
        cout << "[cmd]^< ";
        getline(cin, cmd);
        if (cmd == "help") {
            for (string a : commands) {
                cout << a << endl;
            }

        }

        else if (cmd.empty()) {
            continue;
        }

        else if (cmd == "hex") {
            long long int he;
            cout << "enter int: ";
            cin >> he;
            cicl();
            cout << hex << he << dec << endl;
        }

        else if (cmd == "rd") {
            string random_words[] = {"you good",  "thank for using CMDMantiS", "Linux", "Tux",
                                     "CMDMantiS", "Have a good mood",          "5d0"};
            uniform_int_distribution<int> dstr(0, 6);
            short int word = dstr(gen);
            cout << random_words[word] << endl;
        }

        else if (cmd == "mk") {
            cout << "dat name: ";
            string name;
            cin >> name;
            cicl();
            ofstream dat(name + ".dat");
            cout << "write: ";
            string text;
            getline(cin, text);
            dat << text;
            dat.close();
        }

        else if (cmd == "exit") {
            cout << "goodbye. Thank you for using CMDMantiS :)\n";
            return 0;
        }

        else if (cmd == "rm") {
            string open_name;
            cout << ".dat file name: ";
            cin >> open_name;
            cicl();
            ifstream buf(open_name + ".dat");
            if (buf.is_open()) {
                cout << buf.rdbuf() << endl;
                buf.close();
            }

            else {
                cout << "sorry can's find file :(\n";
            }

        }

        else if (cmd == "hex*") {
            string hex_value;
            cout << "enter hex: ";
            cin >> hex_value;
            cicl();
            try {
                long long int dec_number = stoll(hex_value, nullptr, 16);
                cout << "dec: " << dec_number << endl;
            }

            catch (...) {
                cout << "cant do :( sorry user. Im too stupid. Also Im not enogh smart "
                        "for it :(\n";
            }

        }

        else if (cmd == "cls") {
            cout << "You: goodbye terminal\n";
            sleep_for(seconds(1));
            cout << "Terminal: goodbye user :(\n";
            sleep_for(seconds(2));
            system("clear");
        }

        else if (cmd == "gtch") {
            string glitch_words[] = {
                "Go away i'm busy!", "Okay what do you want?", "Ohhhhh", "Hello I'm glitch :)",
                "What????",          "Hahahah, Ok sorry :)"};
            uniform_int_distribution<int> words(0, 5);
            short int gltch_wrd = words(gen);
            cout << glitch_words[gltch_wrd] << endl;
        }

        else if (cmd == "dl") {
            string dat_to_del;
            cout << "what dat file to delete: ";
            getline(cin, dat_to_del);
            path dat = dat_to_del + ".dat";
            try {
                if (remove(dat)) {
                    cout << "dat: " << "'" << dat_to_del << "'" << " was deleted\n";
                } else {
                    cout << "file dat didn't deleted\n";
                }
            } catch (...) {
                cout << "what's wrong file don't deleted\n";
            }
        }

        else if (cmd == "asc") {
            char asc_value;
            cout << "enter letter: ";
            cin >> asc_value;
            cicl();
            cout << int(asc_value) << endl;
        }

        else if (cmd == "bits*16") {
            int bit_value;
            cout << "enter int: ";
            cin >> bit_value;
            cicl();
            bitset<16> bit_out(bit_value);
            cout << bit_out << endl;
        }

        else if (cmd == "bits*8") {
            int bit_value;
            cout << "enter int: ";
            cin >> bit_value;
            cicl();
            bitset<8> bit_out(bit_value);
            cout << bit_out << endl;
        }

        else if (cmd == "calc") {
            cout << "enter calc: ";
            double first;
            double second;
            char op;
            double ans;
            if (cin >> first >> op >> second) {
                cicl();
                switch (op) {
                    case '+':
                        cout << first + second << endl;
                        break;
                    case '-':
                        cout << first - second << endl;
                        break;
                    case '/':
                        cout << first / second << endl;
                        break;
                    case '*':
                        cout << first * second << endl;
                        break;
                    default:
                        cout << "can't count :(\n";
                        break;
                }
            }

            else {
                cout << "sorry, i don't understand :(\n";
                cicl();
            }

        } else if (cmd == "ps") {
            cout << "enter password: ";
            string old_pass;
            cin >> old_pass;
            cicl();
            ifstream check("./ps/password.dat");
            string pass_check;
            getline(check, pass_check);
            check.close();
            if (pass_check == old_pass) {
                cout << "enter new ps: ";
                string new_pass;
                cin >> new_pass;
                cicl();
                path new_ps = "./ps/password.dat";
                remove(new_ps);
                ofstream create_pass("./ps/password.dat");
                create_pass << new_pass;
                create_pass.close();
            } else {
                cout << "password incorrect\n";
            }
        }

        else {
            cout << "CMDMantiS:" << "'" << cmd << "'"
                 << " command not found :(\nYou can enter <help>\n";
        }
    }
}
