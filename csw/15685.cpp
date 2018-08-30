
 aarning(disable:4996) warning(disable:4996)
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool map[102][102];
int n;
int end_x = 0;//끝점의 정보 저장
int end_y = 0;
int result = 0;
int dx[4] = { 0, -1, 0, 1 };//하좌우상
int dy[4] = { 1, 0, -1, 0 };

vector<int> input;
void find(vector<int> &input) {

	int size = (int)input.size();

	for (int i = size - 1; i >= 0; i--) {
		int dir = (input[i] + 1) % 4;

		end_x = end_x + dx[dir];
		end_y = end_y + dy[dir];

		map[end_x][end_y] = true;
		input.push_back(dir);
	}
}

int main() {

	
	cin >> n;
	for (int i = 0; i<n; i++) {
		
		int y, x, d, g;
		cin >> y >> x >> d >> g;//x와 y좌표를 바꿔입력받는다.
		
		input.clear();//벡터초기화

		end_x = x;//끝점갱신
		end_y = y;
		map[end_x][end_y] = true;//현재 받은끝점 지도에 갱신 

		
		end_x = x + dx[d];//0세대 만들기
		end_y = y + dy[d];
		map[end_x][end_y] = true;//만든0세대 지도에 표시

		input.push_back(d); //0세대의 방향정보 벡터로 넣어줌

		for (int i = 0; i<g; i++) {//반복문을 통해 세대만큼 드래곤커브 만들어줌
			find(input);
		}

	}
	//결과값 찾기
	for (int i = 0; i <= 100; i++) 
	{
		for (int j = 0; j <= 100; j++) 
		{
			if (map[i][j] == true && map[i][j + 1] == true && map[i + 1][j] == true && map[i + 1][j + 1] == true)
			{
				result++;
			}
		}
	}
	cout << result << endl;
	return 0;
}
