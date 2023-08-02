#include <iostream>
#include <vector>
using namespace std;

class User {
    public:
        int num;
        vector<int> links;
        int writeBuffer;
        int readBuffer;
        
        User(int num) {
            this->num = num;
            writeBuffer = 0;
            readBuffer = 0;
        }
        void AddLink(int x) {
            links.push_back(x);
        }
        
        void IncrementBuffer(int x) {
            writeBuffer += x;
        }
        
        void SyncBuffers() {
            readBuffer = writeBuffer;
        }
        
        void ResetBuffers() {
            readBuffer = 0;
            writeBuffer = 0;
        }
        

};

int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    
    // Create Users
    vector<User> users;
    for (int i=0; i < n; i++) {
        User u(i);
        users.push_back(u);
    }
    
    // Create User links
    for (int i=0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        users.at(x).AddLink(y);
        users.at(y).AddLink(x);
    }
    
    //----------------------------------------------------------
    
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    // Initial Tweets    
    for (int k=0; k < users.at(s).links.size(); k++) {
        int index = users.at(s).links.at(k);
        users.at(index).IncrementBuffer(1);
//        cout << "pew | ";
    }
    // Sync & Count Buffers
    int tweets = 0;
    for (int i=0; i < users.size(); i++) {
        users.at(i).SyncBuffers();
        tweets += users.at(i).readBuffer;
    }
//    cout << tweets << endl;

    if (t == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    if (t == 1) {
        cout << tweets << endl;
        return 0;
    }

    //----------------------------------------------------------
    
    // Main Loop
    for (int i=1; i < t; i++) {
        
        // Reset writeBuffers
        for (int j=0; j < users.size(); j++)
            users.at(j).writeBuffer = 0;
        
        // Every Edge
        for (int j=0; j < users.size(); j++) {
            if (users.at(j).readBuffer > 0) {
                
                // Pew Pew
                for (int k=0; k < users.at(j).links.size(); k++) {
                    //cout << "pew ";
                    int index = users.at(j).links.at(k);
                    users.at(index).IncrementBuffer(users.at(j).readBuffer);
                }
                //cout << "| ";
                
                // Reset Read Buffer
                users.at(j).readBuffer = 0;
                
            }
        }
        
        // Sync & Count Buffers
        int tweets = 0;
        for (int z=0; z < users.size(); z++) {
            users.at(z).SyncBuffers();
            tweets += users.at(z).readBuffer;
        }
        
        //cout << i << " " << tweets << " " << endl;
        
        if (t == i+1) {
            cout << tweets << endl;
        }
        
        
    }
    
    

    return 0;
}
