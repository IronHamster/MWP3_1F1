#include <iostream>

bool Zwrotna(int** R, int n) {
    for (int i = 0; i < n; i++)
        if (R[i][i] == 0)
            return false;
    return true;
}

bool Przeciwzwrotna(int** R, int n) {
    for (int i = 0; i < n; i++)
        if (R[i][i] != 0)
            return false;
    return true;
}

bool Symetryczna(int** R, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++)
            if (R[i][j] != R[j][i])
                return false;
    }
    return true;
}

bool Antysymetryczna(int** R, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++)
            if (R[i][j] && R[j][i])
                return false;
    }
    return true;
}

bool Spojna(int** R, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++)
            if (!(R[i][j] || R[j][i]))
                return false;
    }
    return true;
}

bool Przechodnia(int** R, int n) {
    int B = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B = 0;
            for (int k = 0; (!B) && (k < n); k++) {
                B = R[i][k] && R[k][j];
                if (R[i][j] < B)
                    return false;
            }
        }
    }
    return true;
}

int main() {
    int x = 0, y = 0;
    int maks1 = 0, maks2 = 0;

    int** R = new int*[100];
    for (int i = 0; i < 100; i++)
        R[i] = new int[100]();

    while (std::cin >> x >> y) {
        R[x - 1][y - 1] = 1;
        if (x > maks1)
            maks1 = x;
        if (y > maks2)
            maks2 = y;
    }

    size_t rozmiar = maks1 > maks2 ? maks1 : maks2;

    bool jestZwrotna = Zwrotna(R, rozmiar);
    bool jestPrzeciwzwrotna = Przeciwzwrotna(R, rozmiar);
    bool jestSymetryczna = Symetryczna(R, rozmiar);
    bool jestAntysymetryczna = Antysymetryczna(R, rozmiar);
    bool jestPrzechodnia = Przechodnia(R, rozmiar);
    bool jestSpojna = Spojna(R, rozmiar);

    if (jestZwrotna) std::cout << "Z ";
    if (jestPrzeciwzwrotna) std::cout << "PZ ";
    if (jestSymetryczna) std::cout << "S ";
    if (jestAntysymetryczna) std::cout << "AS ";
    if (jestPrzechodnia) std::cout << "P ";
    if (jestSpojna) std::cout << "SP ";
    if (!(jestZwrotna || jestPrzeciwzwrotna || jestSymetryczna || jestAntysymetryczna || jestPrzechodnia || jestSpojna)) {
        std::cout << "X";
        return 0;
    } else std::cout << "\n";

    bool RR = jestZwrotna && jestSymetryczna && jestPrzechodnia;
    bool RPL = jestZwrotna && jestAntysymetryczna && jestPrzechodnia && jestSpojna;
    bool RPCz = jestZwrotna && jestAntysymetryczna && jestPrzechodnia;

    if (RR) std::cout << "RR ";
    if (RPL) std::cout << "RPL ";
    else if (RPCz) std::cout << "RPCz";
    if (!(RR || RPL || RPCz)) {
        std::cout << "X";
    }

    for (int i = 0; i < rozmiar; i++)
        delete[] R[i];
    delete[] R;

    return 0;
}
