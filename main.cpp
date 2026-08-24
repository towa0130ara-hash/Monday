#include <iostream>
using namespace std;

// 関数の宣言
void changeArray(int arr[], int size, int number);

int main()
{
    // 配列を作成
    int arr[5] = { 10, 20, 30, 40, 50 };

    int number;

    // 倍率を入力
    cout << "何倍しますか？ ";
    cin >> number;

    // 変更前
    cout << "変更前" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }

    
    changeArray(arr, 5, number);

    
    cout << endl;
    cout << "変更後" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
