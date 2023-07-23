class ZeroEvenOdd {
private:
    int n;
    mutex m;
    condition_variable cv;
    int i;
    int turn;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        i=1;
        turn = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(turn != 0 and i<=n){
                cv.wait(lock);
            }
            if(i>n) break;

            printNumber(0);

            turn = (i%2 == 0) ? 2 : 1;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(turn != 2 and i<=n){
                cv.wait(lock);
            }
            if(i>n) break;

            printNumber(i);
            i++;

            turn = 0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(turn != 1 and i<=n){
                cv.wait(lock);
            }
            if(i>n) break;

            printNumber(i);
            i++;

            turn = 0;
            cv.notify_all();
        }
    }
};