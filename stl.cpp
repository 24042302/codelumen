//https://atcoder.jp/contests/abc247/tasks/abc247_d
/** 
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    int choice,x,c;
    queue<int>num;

    while(q--){
        cin>>choice;
        if(choice==1){
            cin>>x>>c;
            while(c--){
                num.push(x);
            }
        }
        else{
            long long sum=0;
            cin>>c;
            while(c--){
                sum+=num.front();
                num.pop();
            }
            cout<<sum<<endl;
        }
    }return 0;
}
    **/

/** 
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    int choice,x,c;
    queue<pair<long long,long long>>cylinder;

    while(q--){
        cin>>choice;
        if(choice==1){
            cin>>x>>c;
            cylinder.push({x,c});
        }else{
            cin>>c;
            long long sum=0;
            while(c>0){
                pair<long long,long long>&front_block = cylinder.front();
                long long value=front_block.first;
                long long count=front_block.second;

                if(count<=c){
                    c-=count;
                    sum+=value*count;
                    cylinder.pop();

                }else{
                    sum+=c*value;
                    front_block.second-=c;
                    c=0;
                }


            }
            cout<<sum<<endl;

    }

}return 0;}
**/


/** 
#include<bits/stdc++.h>
using namespace std;

int main() {
	map<int, int> m{{1, 2}, {2, 2}, {1, 2}, {8, 2}, {6, 2}};//有序
	map<int, int>::iterator it1 = m.lower_bound(2);
	cout << it1->first << "\n";//it1->first=2
	map<int, int>::iterator it2 = m.upper_bound(2);
	cout << it2->first << "\n";//it2->first=6
	return 0;
}

**/


/** 
#include<bits/stdc++.h>
using namespace std;

signed main(){
    bitset<4> foo (string("1001"));
bitset<4> bar (string("0011"));

cout << (foo ^= bar) << endl;// 1010 (foo对bar按位异或后赋值给foo)

cout << (foo &= bar) << endl;// 0001 (按位与后赋值给foo)

cout << (foo |= bar) << endl;// 1011 (按位或后赋值给foo)

cout << (foo <<= 2) << endl;// 0100 (左移2位，低位补0，有自身赋值)

cout << (foo >>= 1) << endl;// 0100 (右移1位，高位补0，有自身赋值)

cout << (~bar) << endl;// 1100 (按位取反)

cout << (bar << 1) << endl;// 0110 (左移，不赋值)

cout << (bar >> 1) << endl;// 0001 (右移，不赋值)

cout << (foo == bar) << endl;// false (1001==0011为false)

cout << (foo != bar) << endl;// true  (1001!=0011为true)

cout << (foo & bar) << endl;// 0001 (按位与，不赋值)

cout << (foo | bar) << endl;// 1011 (按位或，不赋值)

cout << (foo ^ bar) << endl;// 1010 (按位异或，不赋值)

}
**/

/** 
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,opt,mod,min,max;
    cin>>n>>opt>>mod>>min>>max;
    vector<int>num(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
}
**/



/** 
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
     unsigned long long n,x;
    string arr;
   
    while(T--){
        stack<unsigned long long>s;
        long long n;
        cin>>n;
        while(n--){
        cin>>arr;
        if(arr=="push"){
            cin>>x;
            s.push(x);
        }else if(arr=="query"){
            if(!s.empty()){
                cout<<s.top()<<endl;;
            }else{
                cout<<"Anguei!"<<endl;;
            }
        }else if(arr=="size"){
            cout<<s.size()<<endl;
        }else if(arr=="pop"){
            if(!s.empty()){
                s.pop();
            }else{
                cout<<"Empty"<<endl;}
        }
    }
    }return 0;
}

**/

//https://www.luogu.com.cn/problem/P1901
/**#include<bits/stdc++.h>
using namespace std;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int>H(n+1);
    vector<int>V(n+1);
    for(int i=1;i<=n;i++){
        cin>>H[i]>>V[i];
    }

    vector<long long>received_energy(n+1,0);
    stack<int>s;
    

    //从左到右
    for(int i=1;i<=n;i++){
        while(!s.empty()&&H[s.top()]<=H[i]){
            s.pop();
        }
        if(!s.empty()){
            received_energy[s.top()]+=V[i];
        }

        s.push(i);
    }

    //清空栈，第二次遍历
 while(!s.empty()){
       s.pop();
   }
    for(int i=n;i>=1;i--){
        while(!s.empty()&&H[s.top()]<=H[i]){
            s.pop();
        }
        if(!s.empty()){
            received_energy[s.top()]+=V[i];
        }
        s.push(i);
    }

    long long max_energy=0;
    for(int i=1;i<=n;i++){
        if(received_energy[i]>max_energy){
            max_energy=received_energy[i];
        }
    }
    cout<<max_energy<<endl;
    return 0;
}**/


/**
#include<bits/stdc++.h>
using namespace std;

int getpriority(const string &op){
    if(op=="not")return 3;
    if(op=="and")return 2;
    if(op=="or")return 1;
    return 0;
}


void apply_op(stack<bool>&values,stack<string>&ops){
    string op=ops.top();
    ops.pop();

    if(op=="not"){
        bool val=values.top();
        values.pop();
        values.push(!val);
    }
    else{
        bool right_val=values.top();
        values.pop();
        bool left_val=values.top();
        values.pop();

        if(op=="and"){
            values.push(left_val&&right_val);
        }else if(op=="or"){
            values.push(left_val||right_val);
        }
    }
}

void solve(){
    string line;
    if(!getline(cin,line)){
        return;
    }
    stringstream ss(line);
    string token;

    stack<bool>values;
    stack<string>ops;

    try{
        bool first_token=true;
        while(ss>>token){
            first_token=false;
            if(token=="true"){
                values.push(true);
            }else if(token=="false"){
                values.push(false);
            }else if(getpriority(token)>0){
                while(!ops.empty()&&getpriority(ops.top())>=getpriority(token)){
                    apply_op(values,ops);
                }
                ops.push(token);
            }
        }
        while(!ops.empty()){
        apply_op(values,ops);
    }if(values.size()==1){
        cout<<(values.top()?"true":"false")<<endl;
    }

    }
    

    
    catch(const exception&e){
        cout<<"error"<<endl;
    }
}

int main(){
    solve();
    return 0;
}
**/


/** 
#include<bits/stdc++.h>
using namespace std;

int getpriority(const string &op) {
    if (op == "not") return 3;
    if (op == "and") return 2;
    if (op == "or") return 1;
    return 0;
}

void apply_op(stack<bool>& values, stack<string>& ops) {
    if (ops.empty()) {
        throw runtime_error("Empty operator stack");
    }
    string op = ops.top();
    ops.pop();

    if (op == "not") {
        if (values.empty()) {
            throw runtime_error("Not enough operands for not");
        }
        bool val = values.top();
        values.pop();
        values.push(!val);
    } else { // and or
        if (values.size() < 2) {
            throw runtime_error("Not enough operands for and/or");
        }
        bool right_val = values.top();
        values.pop();
        bool left_val = values.top();
        values.pop();

        if (op == "and") {
            values.push(left_val && right_val);
        } else if (op == "or") {
            values.push(left_val || right_val);
        }
    }
}

void solve() {
    string line;
    if (!getline(cin, line)) {
        cout << "error" << endl;
        return;
    }
    // 处理空输入
    if (line.empty()) {
        cout << "error" << endl;
        return;
    }
    stringstream ss(line);
    string token;

    stack<bool> values;
    stack<string> ops;

    try {
        enum class PrevType {
            NONE,       // 初始状态
            OPERAND,    // 前一个是true/false
            OP_NOT,     // 前一个是not
            OP_AND_OR   // 前一个是and/or
        };
        PrevType prev_type = PrevType::NONE;

        while (ss >> token) {
            if (token == "true" || token == "false") {
                // 当前是操作数
                if (prev_type == PrevType::OPERAND) {
                    throw runtime_error("Consecutive operands");
                }
                values.push(token == "true");
                prev_type = PrevType::OPERAND;
            } else if (token == "not") {
                // 当前是not（单目运算符，右结合）
                if (prev_type == PrevType::OPERAND) {
                    throw runtime_error("Not after operand");
                }
                // 仅处理优先级更高的运算符（同优先级not不先应用，因为右结合）
                while (!ops.empty() && getpriority(ops.top()) > getpriority(token)) {
                    apply_op(values, ops);
                }
                ops.push(token);
                prev_type = PrevType::OP_NOT;
            } else if (token == "and" || token == "or") {
                // 当前是and/or（双目运算符，左结合）
                if (prev_type != PrevType::OPERAND) {
                    throw runtime_error("Invalid and/or position");
                }
                // 左结合：同优先级时先应用左边的运算符
                while (!ops.empty() && getpriority(ops.top()) >= getpriority(token)) {
                    apply_op(values, ops);
                }
                ops.push(token);
                prev_type = PrevType::OP_AND_OR;
            } else {
                // 未知token
                throw runtime_error("Unknown token");
            }
        }

        // 检查表达式是否以运算符结束
        if (prev_type == PrevType::OP_NOT || prev_type == PrevType::OP_AND_OR) {
            throw runtime_error("Expression ends with operator");
        }

        // 处理剩余的运算符
        while (!ops.empty()) {
            apply_op(values, ops);
        }

        // 确保结果唯一
        if (values.size() != 1) {
            throw runtime_error("Invalid result count");
        }

        cout << (values.top() ? "true" : "false") << endl;
    } catch (const exception& e) {
        cout << "error" << endl;
    }
}

int main() {
    solve();
    return 0;
}
**/


//https://www.luogu.com.cn/problem/P8082
/**#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;

    string number;
    cin>>number;

    string result="";

    for(char digit:number){
        while(!result.empty()&&k>0&&digit>result.back()){
            result.pop_back();
            k--;
        }
        result.push_back(digit);
    }
    while(k>0){
        result.pop_back();
        k--;
    }
    cout<<result<<endl;
    return 0;
    
}

**/

/** 
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int>H(n+1,0);
    stack<int>s;
    for(int i=1;i<=n;i++){
        cin>>H[i]
    }
}
**/



#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int choice,x;
    stack<int>s;
    stack<int>ms;
    int max_num=0;
    vector<int>f;
    while(n--){
        cin>>x;
        if(x==0){
            cin>>x;
            s.push(x);
            if(ms.empty()||x>=ms.top()){
                ms.push(x);
            }
            
        }else if(x==1){
           if(!s.empty()){
            if(ms.top()==s.top()){
                ms.pop();

            }s.pop();   
                }
        }else if(x==2){
            if(!ms.empty()){
                cout<<ms.top()<<endl;
            }else{
                cout<<0<<endl;
            }
        }
    }
    return 0;
}



