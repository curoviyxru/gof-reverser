#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    if (argc < 3) return 0;
    fstream in(argv[1], ios::binary | ios::in);

    in.seekg(0, in.end);
    long N = in.tellg();
    in.seekg(0, in.beg);

    if (N < 0) {
        in.close();
        return 0;
    }

    fstream out(argv[2], ios::binary | ios::out);
    char* data = new char[N];

    in.read(data, N);

    long R =
        N < 100 ? 10 + (N % 10) :
        N < 200 ? 50 + (N % 20) :
        N < 300 ? 80 + (N % 20) :
        100 + (N % 50);

    for (int i = 0; i < R; ++i) {
        char c = data[i];
        data[i] = data[N - i - 1];
        data[N - i - 1] = c;
    }

    out.write(data, N);

    in.close();
    out.close();
    delete[] data;

    return 0;
}
