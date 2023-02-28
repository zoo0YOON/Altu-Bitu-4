#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    
    string line;
    stack<char> st;

    while (true){ // 한줄 한줄 판단해야 하므로, .이 나오면 다음 문장으로 넘어가야 하므로 while 사용해줌
		getline(cin, line); 
		if (line[0] == '.') {
            break;
        } // 줄 나눔 역할

		for (int i = 0; i < line.length() - 1; i++){
			if (line[i] == '(' || line[i] == '[') {
                st.push(line[i]);
            }

			if (line[i] == ']'){
				if (!st.empty() && st.top() == '[') {
                    st.pop();
                }
				else { 
                    cout << "yes\n";
                }
			}

			if (line[i] == ')')
            {
				if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
				else { 
                    cout << "no\n";
                    break;
                }
			}

			if (st.empty() && i == line.length() - 2) {
                cout << "yes\n";
            } 
			else if (!st.empty() && i == line.length() - 2) {
                cout << "no\n";
                break;
            }
		}

	}
}