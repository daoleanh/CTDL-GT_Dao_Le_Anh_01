#include <iostream>
using namespace std;

const int MAX_CH = 50;
const int MAX_SEC = 50;
const int MAX_SUB = 50;
const int MAX_SUBSUB = 50;
const int MAX_NAME = 60;

struct Subsub { //dinh nghia cau truc muc con cua muc con
    char name[MAX_NAME];
    int pages; 
};

struct Sub { //dinh nghia cau truc muc con 
    char name[MAX_NAME];
    int pages; 
    int nSubsub;
    Subsub subsub[MAX_SUBSUB];
};

struct Sec { //dinh nghia cau truc muc
    char name[MAX_NAME];
    int pages; 
    int nSub;
    Sub sub[MAX_SUB];
};

struct Chap { //dinh nghia cau truc chuong
    char name[MAX_NAME];
    int pages; 
    int nSec;
    Sec sec[MAX_SEC];
};

struct Book {
    int nChap;
    Chap chap[MAX_CH];
};

// ===== Update pages từ dưới lên =====
int updateSub(Sub& x) {
    if (x.nSubsub == 0) return x.pages; // lá
    int s = 0;
    for (int i = 0; i < x.nSubsub; i++) s += x.subsub[i].pages;
    x.pages = s;
    return s;
}

int updateSec(Sec& x) {
    if (x.nSub == 0) return x.pages;
    int s = 0;
    for (int i = 0; i < x.nSub; i++) s += updateSub(x.sub[i]);
    x.pages = s;
    return s;
}

int updateChap(Chap& x) {
    if (x.nSec == 0) return x.pages;
    int s = 0;
    for (int i = 0; i < x.nSec; i++) s += updateSec(x.sec[i]);
    x.pages = s;
    return s;
}

void updateBook(Book& b) {
    for (int i = 0; i < b.nChap; i++) updateChap(b.chap[i]);
}

int soChuong(const Book& b) { return b.nChap; }

int chapDaiNhat(const Book& b) {
    int best = -1;
    for (int i = 0; i < b.nChap; i++)
        if (best == -1 || b.chap[i].pages > b.chap[best].pages) best = i;
    return best; // index
}

bool xoaSection(Book& b, int i, int j) {
    if (i < 0 || i >= b.nChap) return false;
    Chap& ch = b.chap[i];
    if (j < 0 || j >= ch.nSec) return false;

    for (int k = j; k < ch.nSec - 1; k++) ch.sec[k] = ch.sec[k + 1];
    ch.nSec--;

    updateChap(ch);
    return true;
}


void inChapter(const Book& b, int i) {
    if (i < 0 || i >= b.nChap) return;
    const Chap& ch = b.chap[i];
    cout << "Chapter " << i + 1 << ": " << ch.name << " (" << ch.pages << " trang)\n";
    for (int j = 0; j < ch.nSec; j++) {
        const Sec& s = ch.sec[j];
        cout << "  " << i + 1 << "." << j + 1 << " " << s.name << " (" << s.pages << ")\n";
        for (int k = 0; k < s.nSub; k++) {
            const Sub& u = s.sub[k];
            cout << "    " << i + 1 << "." << j + 1 << "." << k + 1 << " " << u.name << " (" << u.pages << ")\n";
            for (int t = 0; t < u.nSubsub; t++) {
                const Subsub& v = u.subsub[t];
                cout << "      " << i + 1 << "." << j + 1 << "." << k + 1 << "." << t + 1 << " " << v.name << " (" << v.pages << ")\n";
            }
        }
    }
}

int tongTrangBook(const Book& b) {
    int s = 0;
    for (int i = 0; i < b.nChap; i++) s += b.chap[i].pages;
    return s;
}

void inBook(const Book& b) {
    cout << "=== BOOK: " << b.nChap << " chuong, tong " << tongTrangBook(b) << " trang ===\n";
    for (int i = 0; i < b.nChap; i++) {
        inChapter(b, i);
        cout << "\n";
    }
}

//Nhập an toàn với char[] + iostream //gpt
void ignoreLine() {
    cin.ignore(100000, '\n');
}

void readLine(char s[], int maxLen) {
    cin.getline(s, maxLen);
    if (!cin) { // nếu quá dài, clear và bỏ phần dư
        cin.clear();
        ignoreLine();
        s[maxLen - 1] = '\0';
    }
}

int readIntClamp(int lo, int hi) {  //tranh loi nhap sai (tham khao gpt)
    int x;
    cin >> x;
    if (!cin) {
        cin.clear();
        ignoreLine();
		return lo; // neu nhap sai tra ve gia tri mac dinh lo
    }
	if (x < lo) x = lo; // nhap x be hon lo thi tra ve lo
	if (x > hi) x = hi; // nhap x lon hon hi thi tra ve hi
	return x; // neu hop le tra ve gia tri nhap
}

void nhapSubsub(Subsub& x) {
    cout << "        Ten subsub: ";
    ignoreLine();
    readLine(x.name, MAX_NAME);
    cout << "        So trang (la): ";
    x.pages = readIntClamp(0, 1000000);
}

void nhapSub(Sub& x) {
    cout << "      Ten sub: ";
    ignoreLine();
    readLine(x.name, MAX_NAME);

    cout << "      So subsub (0.." << MAX_SUBSUB << "): ";
    x.nSubsub = readIntClamp(0, MAX_SUBSUB);

    if (x.nSubsub == 0) {
        cout << "      So trang (la): ";
        x.pages = readIntClamp(0, 1000000);
    }
    else {
        x.pages = 0;
        for (int i = 0; i < x.nSubsub; i++) {
            cout << "      [Subsub " << i + 1 << "]\n";
            nhapSubsub(x.subsub[i]);
        }
    }
}

void nhapSec(Sec& x) {
    cout << "    Ten section: ";
    ignoreLine();
    readLine(x.name, MAX_NAME);

    cout << "    So sub (0.." << MAX_SUB << "): ";
    x.nSub = readIntClamp(0, MAX_SUB);

    if (x.nSub == 0) {
        cout << "    So trang (la): ";
        x.pages = readIntClamp(0, 1000000);
    }
    else {
        x.pages = 0;
        for (int i = 0; i < x.nSub; i++) {
            cout << "    [Sub " << i + 1 << "]\n";
            nhapSub(x.sub[i]);
        }
    }
}

void nhapChap(Chap& x) {
    cout << "  Ten chapter: ";
    ignoreLine();
    readLine(x.name, MAX_NAME);

    cout << "  So section (0.." << MAX_SEC << "): ";
    x.nSec = readIntClamp(0, MAX_SEC);

    if (x.nSec == 0) {
        cout << "  So trang (la): ";
        x.pages = readIntClamp(0, 1000000);
    }
    else {
        x.pages = 0;
        for (int i = 0; i < x.nSec; i++) {
            cout << "  [Section " << i + 1 << "]\n";
            nhapSec(x.sec[i]);
        }
    }
}

void nhapBook(Book& b) {
    cout << "So chuong (1.." << MAX_CH << "): ";
    b.nChap = readIntClamp(1, MAX_CH);
    for (int i = 0; i < b.nChap; i++) {
        cout << "\n[Chapter " << i + 1 << "]\n";
        nhapChap(b.chap[i]);
    }
	updateBook(b); // update so chuong moi nhap xong
}

// main
int main() {
    static Book b;

    cout << "=== Nhap BOOK (chap -> sec -> sub -> subsub) ===\n";
    nhapBook(b);

    int c;
    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. In toan bo book\n";
        cout << "2. So chuong\n";
        cout << "3. Chapter dai nhat\n";
        cout << "4. Xoa 1 section (theo i, j)\n";
        cout << "5. In 1 chapter\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";

        if (!(cin >> c)) {
            cin.clear();
            ignoreLine();
            continue;
        }

        if (c == 0) break;

        if (c == 1) {
            updateBook(b);
            inBook(b);
        }
        else if (c == 2) {
            cout << "So chuong = " << soChuong(b) << "\n";
        }
        else if (c == 3) {
            updateBook(b);
            int idx = chapDaiNhat(b);
            if (idx >= 0) {
                cout << "Chapter dai nhat: #" << idx + 1 << " - " << b.chap[idx].name
                    << " (" << b.chap[idx].pages << " trang)\n";
            }
        }
        else if (c == 4) {
            cout << "Nhap i (chapter): ";
            int i; cin >> i;
            cout << "Nhap j (section): ";
            int j; cin >> j;
            bool ok = xoaSection(b, i - 1, j - 1);
            cout << (ok ? "Da xoa.\n" : "Khong hop le.\n");
        }
        else if (c == 5) {
            cout << "Nhap chapter: ";
            int i; cin >> i;
            updateBook(b);
            inChapter(b, i - 1);
        }
        else {
            cout << "Lua chon khong hop le.\n";
        }
    }
    return 0;
}

