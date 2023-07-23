class FooBar {
private:
    int n;
    condition_variable cv;
    mutex m;
    bool turn;
public:
    FooBar(int n) {
        this->n = n;
        turn = 0;
    }

    // idea: is to lock inside the loop and have a turn var for each turn 
    // then when its foo or bar turn then print else wait

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);

            while(turn == 1){
                cv.wait(lock);
            }
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            turn = 1;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);

            while(turn == 0){
                cv.wait(lock);
            }
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            turn = 0;
            cv.notify_all();
        }

    }
};