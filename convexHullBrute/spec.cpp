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
        TimeLimit(100);
        MemoryLimit(64);
    }

    void Constraints() {
        CONS(1 <= N && N <= 2500);
        CONS(eachElementBetween(X, -1000, 1000));
        CONS(eachElementBetween(Y, -1000, 1000));
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
        CASE(N = 5, randomPoints(-1000, 1000));
        CASE(N = 10, randomPoints(-1000, 1000));
        CASE(N = 20, randomPoints(-1000, 1000));
        CASE(N = 100, randomPoints(-1000, 1000));
        CASE(N = 500, randomPoints(-1000, 1000));
        CASE(N = 2500, randomPoints(-1000, 1000));
    }

private:
    void randomPoints(int minP, int maxP) {
        for (int i = 0; i < N; i++) {
            X.push_back(rnd.nextDouble(minP, maxP));
            Y.push_back(rnd.nextDouble(minP, maxP));
        }
    }
};