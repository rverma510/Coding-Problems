#include <bits/stdc++.h>
using namespace std;
enum class WeatherDataType {
    Temperature, Wind
};
struct TempData {
    int stationId;
    time_t time;
    double current;
    double max;
    double min;
};
struct WindData {
    int stationId;
    time_t time;
    int speed;
    short duration;
};
struct Input {
    WeatherDataType type;
    union {
        TempData temp;
        WindData wind;
    };
};
void processTemp(TempData t) {
    cout << "Processing Temperature Data\n";
}
void processWind(WindData w) {
    cout << "Processing Wind Data\n";
}
void initialize(queue<Input> &inputs) {
    Input first;
    first.type = WeatherDataType::Temperature;
    first.temp = {101, 1418855664, 91.8, 108.5, 67.2};
    inputs.push(first);

    Input second;
    second.type = WeatherDataType::Wind;
    second.wind = { 204, 1418859354, 14, 27 };
    inputs.push(second);
}
int main(int argc, char *argv[]) {
    queue<Input> inputs;
    initialize(inputs);
    while (!inputs.empty()) {
        Input const i = inputs.front();
        switch(i.type) {
            case WeatherDataType::Temperature :
                processTemp(i.temp);
                break;
            case WeatherDataType::Wind :
                processWind(i.wind);
                break;
        }
        inputs.pop();
    }
    return 0;
}