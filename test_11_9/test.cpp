//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//    int T;
//    cin >> T;
//    while (T--)
//    {
//        int N, K;
//        cin >> N >> K;
//        vector<int> put;
//        put.resize(2 * N);
//        for (int i = 0; i < 2 * N; i++)
//        {
//            cin >> put[i];
//        }
//        while (K--)
//        {
//            int left = N - 1, right = 2 * N - 1;
//            int i = 2 * N - 1;
//            while (i >= 0)
//            {
//                vector<int> tmp;
//                tmp.resize(2 * N);
//                tmp[i--] = put[right--];
//                tmp[i--] = put[left--];
//                swap(tmp, put);
//            }
//        }
//
//        for (int i = 0; i < 2 * N; i++)
//        {
//            cout << put[i];
//            if (i != 2 * N - 1)
//                cout << ' ';
//        }
//        cout << endl;
//    }
//    return 0;
//}
#include <iostream>
#include <set>

using namespace std;
int main()
{
    set<char> st;
    char n;
    while (scanf_s("%c", &n) != EOF)
    {
        st.insert(n);
    }

    auto it = st.begin();
    cout << *it;
    return 0;
}