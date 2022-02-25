/*
 * MSSV: 19110482
 * Ho va ten: Huynh Thi Bao Tran
 * Assignment: Thuc hanh 3
 * Create at: 03/01/2022
 * IDE: Microsoft Visual Studio Code
 */

#include <iostream>
#include <vector>


#define LIMIT 25
#define MAX 999999

using namespace std;

// khai bao cac bien can su dung
int graph[LIMIT][LIMIT];
int length[LIMIT];
int parent[LIMIT];
bool done[LIMIT];

int n, start, goal;

// khai bao cac ham can su dung
void read_data(); // ham lay du lieu tu file "thong_tin_dinh.txt"
void my_dijkstra(); // ham thuc hien thuat toan dijkstra
void result(); // ham xuat ket qua
void find_path(int start, int goal);


int main() {
  read_data();
  my_dijkstra();
  result();

  getchar();
  system("pause");
  return 0;
} 


void read_data() {
  // doc file "thong_tin_dinh.txt"
  FILE *fileInput;
  fileInput = freopen("thong_tin_dinh.txt", "r", stdin);

  char check; // bien kiem tra do thi vo huong hay co huong

  cin >> check;
  cin >> n;

  // khoi tao gia tri ban dau cho graph
  int i = 1;
  while (i <= n) {
    int j = 1;
    while (j <= n) {
      graph[i][j] = MAX;
      j++;
    }
    i++;
  }

  // nhan gia tri cho graph va start, goal
  bool tamp = true;
  while (tamp) {
    int a, b, c;
    cin >> a >> b;
    if (cin.fail()) {
      start = a;
      goal = b;
      c = 0;
      tamp = false;
    }
    else {
      cin >> c;
    }

    // kiem tra do thi la vo huong hay co huong
    if (check == '0') {
      graph[a][b] = graph[b][a] = c;
    }
    else {
      graph[a][b] = c;
    }
  }

  /*
  // xuat do thi ra man hinh
  cout << "check " << check << endl;
  cout << "n " << n << endl;
  i = 1;
  while (i <= n) {
    int j = 1;
    while (j <= n) {
      cout << graph[i][j] << " ";
      j++;
    }
    cout << endl;
    i++;
  }
  cout << "start " << start << endl;
  cout << "goal " << goal << endl;
  */
  
  fclose(stdin);
}


void my_dijkstra() {
  // khoi tao gia tri ban dau cho length
  int i = 1;
  while (i <= n) {
    length[i] = MAX;
    i++;
  }

  length[start] = 0;

  int go = start;
  while (true) {
    go = goal;
    int i = 1;
    while (i <= n) {
      if ((done[i] == false) && (length[go] > length[i])) {
        go = i;
      }
      i++;
    }

    done[go] = true;
    
    if ((length[go] == MAX) || (go == goal)) {
      break;
    }
    
    int vet = 1;
    while (vet <= n) {
      if ((graph[go][vet] > 0) && (!done[vet])) {
        if (graph[go][vet] + length[go] < length[vet]) {
          length[vet] = graph[go][vet] + length[go];
          parent[vet] = go;
        }
      }
      vet++;
    }
  }
}


void find_path(int start, int goal) {
  // khoi tao gia tri ban dau cho vector path
  vector<int> path;
  int u = goal;

  while (u != start) {
    path.push_back(u);
    u = parent[u];
  }
  
  path.push_back(start);

  // xuat cac dinh thuoc duong di ngan nhat
  cout << "Duong di ngan nhat cua do thi la: ";
  int i = path.size()-1;
  while (i > 0) {
    cout << path[i] << " -> ";
    i--;
  }
  cout << path[0];
}


void result() {
  // xuat file ket qua
  FILE *fileOutput;
  fileOutput = freopen("ket_qua_bai_3_19110482.txt", "w", stdout);

  if (length[goal] == MAX) {
    cout << "Khong co duong di ngan nhat";
  }
  else {
    cout << "Tong chi phi di chuyen = " << length[goal] << endl;
    find_path(start, goal);
  }
  
  fclose(stdout);
}