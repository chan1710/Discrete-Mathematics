/*
 * MSSV: 19110482
 * Ho va ten: Huynh Thi Bao Tran
 * Assignment: thuc hanh 2
 * Create at: 11/12/2021
 * IDE: Microsoft Visual Studio Code
 */

#include <iostream>
using namespace std;

#define MAX 1000

int graph[MAX][MAX], n;

int get_rows();
void read_file();
void check_connect();
void breadth_first_search(int graph[][MAX], int n, int i, int *count, int check[], int QUEUE[MAX]);
void print_result(int *check, int count);

int main() {
    check_connect();
    return 0;
}

int get_rows() {
    FILE *fi;
    fi = fopen("input_dothi.txt", "r");
    int rows = 1;
    while (!feof(fi)) {
        if (fgetc(fi) == '\n') {
            rows++;
        }
    }
    return rows;
}

void read_file() {
    freopen("input_dothi.txt", "r", stdin);
    n = get_rows();

    int i = 0;
    while (i < n) {
        int j = 0;
        while (j < n) {
            cin >> graph[i][j];
            j++;
        }
        i++;
    }
}

void check_connect() {
    int QUEUE[MAX], check[MAX], count = 0;
    read_file();

    int i = 0;
    while (i < n) {
        check[i] = 0;
        i++;
    }

    i = 0;
    while (i < n) {
        if (check[i] == 0) {
            count++;
            breadth_first_search(graph, n, i, &count, check, QUEUE);
        }
        i++;
    }
    print_result(check, count);
}

void breadth_first_search(int graph[][MAX], int n, int i, int *count, int check[], int QUEUE[MAX]) {
    int head = 1, tail = 1, temp;
    QUEUE[tail] = i;
    check[i] = *count;
    while (head <= tail) {
        temp = QUEUE[head];
        head++;

        int j = 1;
        while (j <= n) {
            if ((graph[temp][j] == 1) && (check[j] == 0))
            {
                tail++;
                QUEUE[tail] = j;
                check[j] = *count;
            }
            j++;
        }
    }
}

void print_result(int *check, int count) {
    cout << "\t So luong thanh phan lien thong: " << count;

    int i = 1;
    while (i <= count) {
        cout << endl
             << "\t Thanh phan " << i << ":";
        int j = 0;
        while (j < n) {
            if (check[j] == i)
            {
                cout << " " << j + 1;
            }
            j++;
        }
        i++;
    }
}