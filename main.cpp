#include <iostream>
#include "sll.h"
#include "Queue.h"
#include "Stack.h"
#include <string>
#include <fstream>

using namespace std;


void saveFile(Queue* q, string filename){
cout << "------------------";
    fstream file;
    file.open(filename.c_str(),ios::trunc);
    while (sizeQueue(q)>0) {
            string l = dequeue(q);
    cout << l << endl;
        file << l << endl;
    }
    file.close();
}

void readFile(Queue* q, string filename){

    fstream file;
    file.open(filename.c_str(),ios::in);
    if (file.is_open()) {
        string line;
        while (!file.eof()) {
            getline(file,line);
            enqueue(q, line);
        }
    }
    else {
        cout << filename << " dosyasi acilamadi...";
    }

    file.close();
}

int main()
{
    Stack history, future;
    Queue fileContent;

    string cmd, fnc, par, currentFile="", preFile="-";
    unsigned int spacePosition;
    do{

        if (currentFile!="") {
            cout << currentFile << " file content:" << endl;
            cout << "********************************************************************\n";
            if (currentFile != preFile) {
                freeQueue(&fileContent);
                readFile(&fileContent, currentFile);
            }


            printNL(&fileContent);

            cout << "********************************************************************\n";
        }

        cout << "Cmd:";
        getline(cin, cmd);
        preFile =  currentFile;
        spacePosition = cmd.find(" ");

        if (spacePosition != string::npos) {
            fnc = cmd.substr(0,spacePosition);
            par = cmd.substr(spacePosition+1,cmd.length()-spacePosition);
        }
        else {
            fnc=cmd;
            par="";
        }


        if (fnc.compare("open")==0) { //open arda.txt

             if (currentFile != "") {
                push(&history, currentFile);
                currentFile=par;
             }
              else {
                currentFile=par;
             }
        }

        else if(fnc.compare("back")==0){

            if(!isEmpty(&history)){
                push(&future, currentFile);
                currentFile=pop(&history);
            }
        }
        else if(fnc.compare("fwd")==0){

            if(!isEmpty(&future)){
                push(&history, currentFile);
                currentFile=pop(&future);
            }
        }

        else if(fnc.compare("add")==0){

                if(currentFile!=""){

                    cout << par;
                    enqueue(&fileContent, par);
                }

        }
        else if(fnc.compare("save")==0){

                if(currentFile!=""){

                    saveFile(&fileContent, currentFile);
                    freeQueue(&fileContent);
                    readFile(&fileContent, currentFile);
                }

        }
        else
        {
            cout << "Unknown command!" << endl;
        }

    }while(fnc.compare("quit") != 0 && fnc.compare("q") != 0);

    freeQueue(&fileContent);
    freeStack(&history);
    freeStack(&future);

    return 0;
}

//ARAYA EKLE (KONUMA EKLE VE SORTED EKLE)

