#include <tcframe/spec.hpp>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N, ansN;
    vector<double> X, Y;
    vector<double> ansX, ansY;

    void InputFormat() {
        LINE(N);
        LINES(X, Y) % SIZE(N);
    }

    void OutputFormat() {
        LINE(ansN);
        LINES(ansX, ansY);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void Constraints() {
        CONS(1 <= N && N <= 1000);
        CONS(eachElementBetween(X, -1e9, 1e9));
        CONS(eachElementBetween(Y, -1e9, 1e9));
    }

private:
    bool eachElementBetween(const vector<double>& v, double lo, double hi) {
        for (int x : v) {
            if (x < lo || x > hi) {
                return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "4",
            "12 32",
            "45 98",
            "65 12",
            "10 30"
        });
        Output({
            "3",
            "10 30",
            "45 98",
            "65 12"
        });
    }

    void BeforeTestCase() {
        X.clear();
        Y.clear();
    }

    void TestCases() {
        CASE(N = 5, randomPoints(-10, 10));
        CASE(N = 10, randomPoints(-50, 50));
        CASE(N = 20, randomPoints(-100, 100));
        CASE(N = 100, randomPoints(-1e9, 1e9));
        CASE(N = 500, randomPoints(-1e9, 1e9));
        CASE(N = 1000, randomPoints(-1e9, 1e9));
    }

private:
    void randomPoints(int minP, int maxP) {
        for (int i = 0; i < N; i++) {
            X.push_back(rnd.nextDouble(minP, maxP));
            Y.push_back(rnd.nextDouble(minP, maxP));
        }
    }
};