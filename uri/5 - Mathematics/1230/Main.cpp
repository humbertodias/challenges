#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define LIMIT 1123456

int N, X, Y;
int f[LIMIT];
int answer[LIMIT];
int left[LIMIT], right[LIMIT];
int lowest[LIMIT], highest[LIMIT];
vector<pair<int, int> > intervals;
int min_area_interval[LIMIT], max_area_interval[LIMIT];
int vals[LIMIT][2];
bool print_values = true;

bool read() {
    if (scanf("%d %d %d", &N, &X, &Y) == EOF) {
        return false;
    }
    for (int i = 0; i < X; i++) {
        scanf("%d %d", &vals[i][0], &vals[i][1]);
    }
    return true;
}

void fail() {
    printf("N\n");
}

void success() {
    printf("S");
    if (print_values) {
        for (int i = 1; i < N; i++) {
            if (f[i] == -1) {
                printf(" %d", answer[i]);
            }
        }
    }
    printf("\n");
}

void process() {
    memset(f, -1, sizeof f);
    memset(highest, -1, sizeof highest);
    memset(lowest, 0x3f, sizeof lowest);
    memset(answer, 0, sizeof answer);
    intervals.clear();
    for (int i = 0; i <= N; i++) {
        left[i] = i;
        right[i] = i;
    }
    for (int i = 0; i < X; i++) {
        f[vals[i][0]] = vals[i][1];
        highest[vals[i][0]] = lowest[vals[i][0]] = answer[vals[i][0]] = vals[i][1];
    }
    if (f[0] == -1 or f[N] == -1) {
        fail();
        return;
    }
    for (int i = 1; i < N; i++) {
        if (f[i] == -1) {
            left[i] = left[i - 1];
        }
    }
    for (int i = N - 1; i > 0; i--) {
        if (f[i] == -1) {
            right[i] = right[i + 1];
        }
    }
    int aux = f[0];
    for (int i = 1; i < N; i++) {
        if (f[i] == -1) {
            lowest[i] = min(lowest[i], aux);
            highest[i] = max(highest[i], aux);
        } else {
            aux = f[i];
        }
    }
    aux = f[N];
    for (int i = N - 1; i > 0; i--) {
        if (f[i] == -1) {
            lowest[i] = min(lowest[i], aux);
            highest[i] = max(highest[i], aux);
        } else {
            aux = f[i];
        }
    }

    //checking lower and upper bounds to see if there's a solution
    //low_accumulated[i] = high_accumulated[i] = 0, since it's a single point
    long long lower = 0, upper = 0;
    for (int i = 0; i < N; i++) {
        lower += (lowest[i] + lowest[i + 1]);
        upper += (highest[i] + highest[i + 1]);
        answer[i] = highest[i];
    }
    if (lower > 2 * Y or upper < 2 * Y) {
        fail();
        return;
    }
    //from now on we are sure we have a solution, we only need to find one which is =P
    for (int i = 1; i < N; i++) {
        if (f[i] == -1) {
            int idx = intervals.size();
            intervals.push_back(make_pair(left[i], right[i]));
            min_area_interval[idx] = 0;
            max_area_interval[idx] = 0;
            for (int j = left[i]; j < right[i]; j++) {
                min_area_interval[idx] += lowest[j] + lowest[j + 1];
                max_area_interval[idx] += highest[j] + highest[j + 1];
            }
            i = right[i];
        }
    }
    long long actual_value = upper;

    for (int i = 0; i < intervals.size(); i++) {
        if (actual_value - max_area_interval[i] + min_area_interval[i] > 2 * Y) {
            actual_value -= max_area_interval[i] - min_area_interval[i];
            for (int j = intervals[i].first + 1; j < intervals[i].second; j++) {
                answer[j] = lowest[j];
            }
        } else {
            for (int j = intervals[i].first + 1; j < intervals[i].second; j++) {
                if (actual_value - 2 * (highest[j] - lowest[j]) > 2 * Y) {
                    actual_value -= 2 * (highest[j] - lowest[j]);
                    answer[j] = lowest[j];
                } else {
                    answer[j] -= (actual_value - 2 * Y) / 2;
                    break;
                }
            }
            int area = 0;
            for (int j = 0; j < N; j++) {
                area += (answer[j] + answer[j + 1]);
            }
            if (area != 2 * Y) {
                fail();
                return;
            }
            if (f[intervals[i].first] > f[intervals[i].second]) {
                int remaining = 0;
                for (int j = intervals[i].first + 1; j < intervals[i].second; j++) {
                    remaining += answer[j];
                }
                int tmp = 0;
                for (int j = intervals[i].first + 1; j < intervals[i].second; j++) {
                    answer[j] = remaining / (intervals[i].second - intervals[i].first - 1);
                    tmp += answer[j];
                }
                remaining -= tmp;
                int j = intervals[i].first + 1;
                while (remaining) {
                    answer[j]++;
                    j++;
                    remaining--;
                }
            }
            break;
        }
    }
    success();
}

int main() {
    while (read()) {
        process();
    }
    return 0;
}