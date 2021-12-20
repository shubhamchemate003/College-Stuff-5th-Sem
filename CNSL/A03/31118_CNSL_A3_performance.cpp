#include <bits/stdc++.h>
using namespace std;

const int D = 20;

bitset<D> encode_msg(char msg, int par, int& n) {
    bitset<D> bin_msg(msg);
    int d = 0;
    for (int i = 0; i < D; i++)
        if (bin_msg[i])
            d = i + 1;

    int r = 0;
    while ((1ll << r) < (d + r + 1))
        r++;

    n = d + r;
    bitset<D> enc_msg;
    for (int i = 0, j = 0; i < n; i++)
        if (i & (i + 1)) // current pos is not power of two
            enc_msg[i] = bin_msg[j++];

    for (int i = 0; i < r; i++) {
        int cnt = 0, x = (1 << i);
        for (int j = x - 1; j < n; j += 2 * x)
            for (int k = j; k < j + x; k++)
                if (enc_msg[k] == 1)
                    cnt++;

        cnt %= 2;
        if (par == 1 and cnt == 0) // odd parity
            enc_msg[x - 1] = 1;
        else if (par == 2 and cnt == 1) // even parity
            enc_msg[x - 1] = 1;
    }

    cout << "Number of redundant bits used are: " << r << endl;
    cout << "Encoded:\n";
    for (int i = 0; i < n; i++)
        cout << left << setw(3) << enc_msg[i] << " ";
    cout << endl;

    for (int i = 1; i <= n; i++) {
        string cur = "dp"[(i & (i - 1)) == 0] + to_string(i);
        cout << left << setw(3) << cur << " ";
    }
    cout << endl;

    return enc_msg;
}

int is_corrupted(bitset<D> dec_msg, int par, int n) {
    int r = 0;
    while ((1ll << r) < (n + 1))
        r++;

    bitset<D> p;

    for (int i = 0; i < r; i++) {
        int cnt = 0, x = (1 << i);
        for (int j = x - 1; j < n; j += 2 * x)
            for (int k = j; k < j + x; k++)
                if (dec_msg[k] == 1)
                    cnt++;

        cnt %= 2;
        if (par == 1 and cnt == 0)
            p[i] = 1;
        else if (par == 2 and cnt == 1)
            p[i] = 1;
    }

    cout << "Calculated value of parity bits:\n";
    for (int i = 0; i < r; i++)
        cout << setw(3) << p[i] << ' ';
    cout << endl;
    for (int i = 0; i < r; i++) {
        string cur = "p" + to_string((1 << i));
        cout << setw(3) << cur << ' ';
    }
    cout << endl;

    bool error_present = 0;
    for (int i = 0; i < r; i++)
        error_present |= (p[i] == 1);

    int pos = 0;
    for (int i = 0; i < r; i++)
        pos += (p[i] * (1 << i));

    return (error_present ? pos : -1);
}

char decode_msg(bitset<D> dec_msg, int n) {
    bitset<D> bits;
    for (int i = 0, j = 0; i < D; i++)
        if (i & (i + 1))
            bits[j++] = dec_msg[i];

    return char(bits.to_ulong());
}

signed main() {

    cout << "\n**Welcome to Hamming Code Error Detector and Corrector created by Shubham.**\n";

    while (1) {

        cout << "\n\n----------------------------------------------------------------------------\n";

        cout << "Enter the message: ";
        string msg; cin >> msg;

        cout << "\nMessage Transfer is started...\n";

        string rec = "";
        for (char x : msg) {

            cout << "\n--------------->Tranferring: " << x << "\n\n";

            cout << "====This is senders end\n";
            cout << "Choose Parity:\n";
            cout << "\t1. for Odd Parity.\n";
            cout << "\t2. for Even Parity.\n: ";
            int par; cin >> par;
            cout << "Encoding Your Message with " << ((par == 1) ? "Odd Parity" : "Even Parity") << "...\n";

            int n = 0;
            bitset<D> enc_msg = encode_msg(x, par, n);
            cout << "Encoded Successfully.\n\n";


            cout << "Your Message is Being Transferred to Receiver. Plz Wait..\n";


            cout << "====This is Medium====\n";
            cout << "Is any bit corrupted (if yes enter pos else enter -1)\n: ";
            int corr_pos = 0; cin >> corr_pos;
            bitset<D> dec_msg = enc_msg;
            // if any bit is corrupted corrupt it!
            if (corr_pos != -1)
                dec_msg[corr_pos - 1] = !dec_msg[corr_pos - 1];
            cout << "\n";


            cout << "This is receiver End====\n";
            int is_corr = is_corrupted(dec_msg, par, n);
            if (is_corr != -1) {
                cout << "Corrupted bit found at pos: " << is_corr << "\n";
                cout << "Correcting the corrupted bit...\n";
                dec_msg[is_corr - 1] = !dec_msg[is_corr - 1];
            }
            else cout << "No Errors found. Succeessfully Accepted.\n";

            char y = decode_msg(dec_msg, n);
            cout << "Received Character: " << y << "\n\n";
            rec += y;

        }

        cout << "****Your Message is Succeessfully Transfered****\n";
        cout << "Received Message is: " << rec << endl;

        cout << "\nError Detection and Correction Process is completed.\n";
        cout << "\nDo you want to check again?\n: ";
        int again = 0; cin >> again;

        if (!again) break;

    }


    cout << "Thank You!\n";

    return 0;
}