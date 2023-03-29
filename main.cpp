#include <iostream>
#include <fstream>

using namespace std;

// Localization

// How many locale strings?
#define LOC_COUNT 27

// English
string LOC_EN[LOC_COUNT] = {"Slate", "Welcome to Slate", "Please enter the height of your canvas in cells: ", "Please enter the width of your canvas in cells: ", "Please wait...", "Fill canvas with this character: ", "Basic canvas, ", " (width x height format)", "[Q]uit Slate", "What do you want to do?", "[Z] Fill the entire canvas", "Finished.", "Type something and press Enter to continue...", "Use this character as the cursor: ", "Draw with this character: ", "[M]ove the cursor", "Use W/A/S/D + Enter to move, E to use the eraser, F for area-fill or Q to quit.", "Change the [c]ursor", "Change the [d]rawing character", "Eraser: ", "Area-fill in progress. Move your cursor somewhere else, and press F to fill the area between the two cursor positions. The fill must be downwards!", "[N]ew file", "[S]ave file", "Save file - Slate", "Enter a relative or absolute path to save this file: ", "Something went wrong while saving the file!", "The file was saved successfully!"};

// Romanian
string LOC_RO[LOC_COUNT] = {"Slate", "Bun venit la Slate", "Introdu înălțimea imaginii în celule: ", "Introdu lățimea imaginii în celule: ", "Așteptați...", "Umple imaginea cu acest caracter: ", "Imagine simplă, ", " (format lățime x înălțime)", "[Q] Închide Slate", "Ce doriți să faceți?", "[Z] Umple toată imaginea", "Terminat.", "Scrie ceva și apasă Enter pentru a continua...", "Utilizează acest caracter pe post de cursor: ", "Desenează cu acest caracter: ", "[M]ișcă cursorul", "Folosește W/A/S/D + Enter pentru a te mișca, E pentru a folosi guma de șters, F pentru umplere locală sau Q pentru a ieși.", "Schimbă [c]ursorul", "Schimbă caracterul de [d]esen", "Gumă de șters: ", "Umplere locală în curs. Mută cursorul altundeva, și apasă F pentru a umple zona dintre cele două poziții. Umplerea trebuie să fie în jos!", "Fișier [n]ou", "[S]alvare fișier", "Salvare fișier - Slate", "Introduceți o cale relativă sau absolută pentru a salva acest fișier: ", "Ceva nu a mers în salvarea acestui fișier!", "Fișierul a fost salvat!"};

// Base locale object
string LOC[LOC_COUNT];

int main() {
    int locale;
    cout << "\ec";
    cout << "1. English" << endl << "2. Română" << endl << endl << "> "; cin >> locale;
    switch (locale) {
        case 1: {
            for (int i = 0; i < LOC_COUNT; i++) LOC[i] = LOC_EN[i];
            break;
        }
        case 2: {
            for (int i = 0; i < LOC_COUNT; i++) LOC[i] = LOC_RO[i];
            break;
        }
        default: {
            for (int i = 0; i < LOC_COUNT; i++) LOC[i] = LOC_EN[i];
            break;
        }
    }

    // Initialize canvas
    int canvas_height, canvas_width; char fillChar, cursor, pencil;
    cout << "\ec";
    cout << LOC[1] << endl << endl;
    cout << LOC[2]; cin >> canvas_height;
    cout << LOC[3]; cin >> canvas_width;
    char canvas[canvas_height][canvas_width];
    cout << LOC[5]; cin >> fillChar;
    cout << LOC[13]; cin >> cursor;
    cout << LOC[14]; cin >> pencil;
    cout << "\ec";
    cout << LOC[4];
    for (int i = 0; i < canvas_height; i++)
        for (int j = 0; j < canvas_width; j++)
            canvas[i][j] = fillChar;
    cout << "\ec";

    // Start app
    int cursorH = 0, cursorW = 0;
    char op = ' ';
    while (op != 'q' && op != 'Q')
    {
        // Display the canvas
        cout << "\ec";
        for (int i = 0; i < canvas_height; i++)
        {
            for (int j = 0; j < canvas_width; j++)
            {
                cout << canvas[i][j] << " ";
            }
            cout << endl;
        }
        cout << LOC[6] << canvas_width << "x" << canvas_height << LOC[7] << endl << endl;
        cout << LOC[9] << endl << LOC[15] << endl << LOC[17] << endl << LOC[18] << endl << LOC[10] << endl << LOC[21] << endl << LOC[22] << endl << LOC[8] << endl << endl << "> ";
        cin >> op;
        if (op == 'z' || op == 'Z')
        {
            cout << endl << LOC[5]; cin >> fillChar;
            cout << endl << LOC[4] << endl;
            for (int i = 0; i < canvas_height; i++)
                for (int j = 0; j < canvas_width; j++)
                    canvas[i][j] = fillChar;
        } else if (op == 'm' || op == 'M') {
            // Enter Movement mode
            char moveDir = ' '; string isErasing = "false"; string areaFill = "false"; int ffw = 0, ffh = 0;
            while (moveDir != 'q' && moveDir != 'Q')
            {
                canvas[cursorH][cursorW] = cursor; char curPencil;
                if (isErasing == "true") { curPencil = fillChar; } else { curPencil = pencil; };
                cout << "\ec";
                for (int i = 0; i < canvas_height; i++)
                {
                    for (int j = 0; j < canvas_width; j++)
                    {
                        cout << canvas[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << LOC[6] << canvas_width << "x" << canvas_height << LOC[7] << endl << LOC[19] << isErasing << endl << endl;
                if (areaFill == "true") { cout << LOC[20]; } else { cout << LOC[16]; };
                cout << endl << endl << "> "; cin >> moveDir;
                if (moveDir == 'w' || moveDir == 'W')
                {
                    if (cursorH > 0) {
                        canvas[cursorH][cursorW] = curPencil;
                        cursorH--;
                    }
                } else if (moveDir == 'a' || moveDir == 'A')
                {
                    if (cursorW > 0) {
                        canvas[cursorH][cursorW] = curPencil;
                        cursorW--;
                    }
                } else if (moveDir == 's' || moveDir == 'S')
                {
                    if (cursorH < (canvas_height - 1)) {
                        canvas[cursorH][cursorW] = curPencil;
                        cursorH++;
                    }
                } else if (moveDir == 'd' || moveDir == 'D')
                {
                    if (cursorW < (canvas_width - 1)) {
                        canvas[cursorH][cursorW] = curPencil;
                        cursorW++;
                    }
                } else if (moveDir == 'e' || moveDir == 'E')
                {
                    if (isErasing == "true") { isErasing = "false"; } else { isErasing = "true"; };
                } else if (moveDir == 'f' || moveDir == 'F')
                {
                    if (areaFill == "true") {
                        for (int i = 0; i < canvas_height; i++)
                            if (i >= ffh && i <= cursorH)
                                for (int j = 0; j < canvas_width; j++)
                                    if (j >= ffw && j <= cursorW)
                                        canvas[i][j] = curPencil;
                        areaFill = "false";
                    } else {
                        ffw = cursorW;
                        ffh = cursorH;
                        areaFill = "true";
                    };
                }
            }
        } else if (op == 'c' || op == 'C') {
            cout << endl << LOC[13]; cin >> cursor;
            canvas[cursorH][cursorW] = cursor;
        } else if (op == 'd' || op == 'D') {
            cout << endl << LOC[14]; cin >> pencil;
        } else if (op == 'n' || op == 'N') {
            main();
            return 0;
        } else if (op == 's' || op == 'S') {
            string path;
            cout << "\ec" << LOC[23] << endl << "------------------------------" << endl << endl << LOC[24]; getline(cin >> ws, path);
            try {
                ofstream save(path);
                for (int i = 0; i < canvas_height; i++)
                {
                    for (int j = 0; j < canvas_width; j++)
                    {
                        save << canvas[i][j] << " ";
                    }
                    save << endl;
                }
                save.close();
                cout << endl << LOC[26] << " " << LOC[12];
                string temp;
                cin.clear();
                cin >> temp;
            } catch (...) {
                cout << endl << LOC[25] << " " << LOC[12];
                string temp;
                cin.clear();
                cin >> temp;
            }
        }
    }
    return 0;
}
