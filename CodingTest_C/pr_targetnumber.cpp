#include <string>
#include <vector>



using namespace std;
int cntGlobal;

//&: 복사를 피하고 원본을 직접 가리키는 장치(참조 = 이 값의 또다른 이름)
//const : 수정불가 약속
//변수가 가리키는 대상을 바꾸어야할 떄 : 포인터(*)
void dfs(const vector<int>& numbers, int idx, int sum, int target) {
    if (idx == (int)numbers.size()) {
        if (sum == target) cntGlobal++;
        return;
    }

    dfs(numbers, idx + 1, sum + numbers[idx], target);

    dfs(numbers, idx + 1, sum - numbers[idx], target);
}

int solution(vector<int> numbers, int target) {
    cntGlobal = 0;
    dfs(numbers, 0, 0, target);
    return cntGlobal;
}