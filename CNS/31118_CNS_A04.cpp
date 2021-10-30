#include <iostream>
#include <vector>
#include <bitset>
#include <iomanip>
#include <queue>
#define vb(x) vector<bitset<(x)>>
using namespace std;

const int D = 8;

void printIP(const vb(D)& ip, int which = 0) {
    if (which) {
        for (int i = 0; i < 4; i++)
            cout << ip[i] << ' ';
        cout << endl;
    }
    else {
        for (int i = 0; i < 4; i++) {
            cout << ip[i].to_ulong();
            if (i < 3) cout << '.';
        }
    }
}

char getIPClass(const vb(D)& ip) {
    bitset<D> pre = ip[0];

    if (pre[7] == 0)
        return 'A';
    if (pre[6] == 0)
        return 'B';
    if (pre[5] == 0)
        return 'C';
    if (pre[4] == 0)
        return 'D';
    return 'E';
}

vb(D) getDefaultMask(const char cls) {
    vb(D) def_mask(4, bitset<D> {});

    for (int i = 0; i <= cls - 'A'; i++)
        def_mask[i].set();

    return def_mask;
}

vb(D) getNetID(const vb(D)& ip) {
    char cls = getIPClass(ip);
    vb(D) def_mask = getDefaultMask(cls);

    vb(D) net_id;
    for (int i = 0; i < 4; i++)
        net_id.push_back(ip[i] & def_mask[i]);

    return net_id;
}

vb(D) getBroadCastID(const vb(D)& net_id) {
    char cls = getIPClass(net_id);

    vb(D) broad_id;
    for (int i = 0; i < 4; i++) {
        bitset<D> cur = net_id[i];
        if (i <= (cls - 'A'))
            broad_id.push_back(cur);
        else {
            cur.set();
            broad_id.push_back(cur);
        }
    }

    return broad_id;
}

vb(D) calculateSubnetMask(const vb(D)& ip, int subnets) {
    char cls = getIPClass(ip);

    int k = 1;
    while ((1 << k) < subnets)
        k++;

    vb(D) mask = ip;
    for (int i = cls - 'A' + 1; i < 4; i++) {
        mask[i].reset();
        for (int j = 0; j < k; j++)
            mask[i][8 - j - 1] = 1;
        k = max(k - 8, 0);
    }

    return mask;
}

void showSubnetRange(const vb(D)& net_id, int subnets) {
    int k = 1;
    while ((1 << k) < subnets)
        k++;

    int cnt = 1;
    priority_queue<int> pq; pq.push(256);
    while (cnt < subnets) {
        int cur = pq.top(); pq.pop();
        pq.push(cur / 2);
        pq.push(cur / 2);
        cnt++;
    }

    int cur = 0;

    cout << "Subnets:\n";
    while (!pq.empty()) {
        bitset<D> l(cur), r(cur + pq.top() - 1);
        vb(D) st = net_id, end = net_id;

        st[3] = l;
        end[3] = r;

        printIP(st);
        cout << " - ";
        printIP(end);
        cout << endl;

        cur += pq.top();
        pq.pop();
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("../input1.txt", "r", stdin);
    freopen("../output1.txt", "w", stdout);
#endif

    string given_ip = "192.46.7.3";
    // cin >> given_ip;

    vb(D) ip;
    for (int i = 0; i < given_ip.size();) {

        auto j = given_ip.find(".", i);
        if (j == string::npos)
            j = given_ip.size();

        int num = stoi(given_ip.substr(i, j - i));
        bitset<D> binary(num);
        ip.push_back(binary);

        i = j + 1;
    }

    cout << "IP: ";
    printIP(ip); cout << '\n';

    cout << "Class: ";
    char cls = getIPClass(ip);
    cout << cls << endl;

    cout << "Default Mask: ";
    printIP(getDefaultMask(cls)); cout << '\n';

    cout << "Network ID: ";
    vb(D) net_id = getNetID(ip);
    printIP(net_id); cout << '\n';

    cout << "getBroadCastID: ";
    printIP(getBroadCastID(ip)); cout << '\n';

    int subnets = 6;
    vb(D) sub_mask = calculateSubnetMask(ip, subnets);
    printIP(sub_mask, 0); cout << '\n';

    showSubnetRange(net_id, subnets);

    return 0;
}