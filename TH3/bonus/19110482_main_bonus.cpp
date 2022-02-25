/*
 * MSSV: 19110482
 * Ho va ten: Huynh Thi Bao Tran
 * Assignment: bonus 3
 * Create at: 03/01/2022
 * IDE: Microsoft Visual Studio Code
 */

#include <iostream>
#include <fstream>
#include <vector>

#define LIMIT 25
#define MAX 99999

using namespace std;

// khai bao cac bien can su dung
int n, start, goal;
int graph[LIMIT][LIMIT];
int length[LIMIT];
int parent[LIMIT];
bool done[LIMIT];
char namepath[LIMIT][MAX];


// khai bao cac ham can su dung
void read_name_path(); // ham lay du lieu tu file "ten_dinh.txt"
void read_data(); // ham lay du lieu tu file "thong_tin_dinh.txt"
void my_dijkstra(); // ham thuc hien thuat toan dijkstra
void result(); // ham xuat ket qua
void find_path(int start, int goal);


int main() {
  read_data();
  read_name_path();
  my_dijkstra();
  result();

  getchar();
  system("pause");
  return 0;
}

void read_name_path() {
  // doc file "ten_dinh.txt"
  ifstream fileName("ten_dinh.txt");

  int i = 1;
  int numpath;
  while (!fileName.eof()) {
    fileName >> numpath;
    fileName.getline(namepath[numpath], MAX);
    i++;
  }

  /*
  // xuat cac dinh ra man hinh
  int j = 1;
  while (j < i) {
    cout << "dinh thu " << j << namepath[j] << endl;
    j++;
  }
  */

  fileName.close();
}


void read_data() {
  // doc file "thong_tin_dinh.txt"
  FILE *fileInput;
  fileInput = freopen("thong_tin_dinh.txt", "r", stdin);
  int check; // bien kiem tra do thi vo huong hay co huong

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
    if (check == 0) {
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
  int a = 1;
  while (a <= n) {
    int b = 1;
    while (b <= n) {
      cout << graph[a][b] << " ";
      b++;
    }
    cout << endl;
    a++;
  }
  cout << "start " << start << endl;
  cout << "goal " << goal << endl;
  */

  fclose(fileInput);
}


void my_dijkstra() {
  // khoi tao gia tri ban dau cho length
  int i = 1;
  while (i <= n) {
    length[i] = MAX;
    i++;
  }
  length[start] = 0;

  int g = start;
  while (true) {
    g= goal;
    int i = 1;
    while (i <= n) {
      if(done[i] == false && length[g] > length[i]) {
        g = i;
      }
      i++;
    }

    done[g] = true;
    
    if(length[g] == MAX || g==goal) {
      break;
    }
  
    int v = 1;
    while (v <= n) {
      if(graph[g][v] > 0 && !done[v]) {
        if(graph[g][v] + length[g] < length[v]) {
          length[v] = graph[g][v] + length[g];
          parent[v] = g;
        }
      }
      v++;
    }
  }
}


void result() {
  // xuat ket qua ra man hinh
  if(length[goal] == MAX) {
    cout << "Khong co duong di ngan nhat";
  }
  else {
    cout << "Tong chi phi di chuyen = " << length[goal] << endl;
    find_path(start, goal);
  }
  
  // xuat file ket qua
  FILE *fileOutput;
  fileOutput = freopen("ket_qua_bonus_19110482.txt", "w", stdout);

  if(length[goal] == MAX) {
    cout << "Khong co duong di ngan nhat";
  }
  else {
    cout << "Tong chi phi di chuyen = " << length[goal] << endl;
    find_path(start, goal);
  }
  
  fclose(stdout);
}


void find_path(int start, int goal) {
  // khoi tao vector path
  vector<int> path;
  int u = goal;

  while (u != start) {
    path.push_back(u);
    u = parent[u];
  }
  path.push_back(start);

  // xuat cac dinh thuoc duong di ngan nhat
  cout << "Duong di ngan nhat cua do thi la:";
  int i = path.size()-1;
  while (i > 0) {
    cout << namepath[path[i]] << " ->";
    i--;
  }
  cout << namepath[path[0]];
}