

#include <iostream>

#include <sstream>

#include <vector>

#include <map>

 

using namespace std;

 

struct CallLog {

    string from_number;

    string to_number;

    string date;

    string from_time;

    string end_time;

};

 

int main() {

    vector<CallLog> call_logs;

    string line;

   

    // Đọc dữ liệu log từ đầu vào (stdin)

    while (getline(cin, line)) {

        stringstream ss(line);

        string keyword;

        ss >> keyword;

 

        if (keyword == "call") {

            CallLog log;

            ss >> log.from_number >> log.to_number >> log.date >> log.from_time >> log.end_time;

            call_logs.push_back(log);

        } else if (keyword == "?check_phone_number") {

            // Kiểm tra số điện thoại hợp lệ

            bool valid = true;

            for (const CallLog& log : call_logs) {

                if (log.from_number.size() != 10 || log.to_number.size() != 10) {

                    valid = false;

                    break;

                }

                for (char c : log.from_number) { 

                    if (!isdigit(c)) {

                        valid = false;

                        break;

                    }

                }

                for (char c : log.to_number) {

                    if (!isdigit(c)) {

                        valid = false;

                        break;

                    }

                }

            }

            cout << (valid ? "1" : "0") << endl;

        } else if (keyword == "?number_calls_from") {

            // Đếm số cuộc gọi từ số điện thoại cụ thể

            string phone_number;

            ss >> phone_number;

            int count = 0;

            for (const CallLog& log : call_logs) {

                if (log.from_number == phone_number) {

                    count++;

                }

            }

            cout << count << endl;

        } else if (keyword == "?number_total_calls") {

            // Tổng số cuộc gọi trong log

            cout << call_logs.size() << endl;

        } else if (keyword == "?count_time_calls_from") {

            // Tính tổng thời gian gọi từ số điện thoại cụ thể (theo giây)

            string phone_number;

            ss >> phone_number;

            int total_seconds = 0;

            for (const CallLog& log : call_logs) {

                if (log.from_number == phone_number) {

                    // Xử lý thời gian (định dạng hh:mm:ss)

                    int from_hour, from_minute, from_second;

                    sscanf(log.from_time.c_str(), "%d:%d:%d", &from_hour, &from_minute, &from_second);

                    int end_hour, end_minute, end_second;

                    sscanf(log.end_time.c_str(), "%d:%d:%d", &end_hour, &end_minute, &end_second);

                   

                    // Tính tổng thời gian gọi (theo giây)

                    total_seconds += (end_hour - from_hour) * 3600 + (end_minute - from_minute) * 60 + (end_second - from_second);

                }

            }

            cout << total_seconds << endl;

        } else {

            cout << "Truy vấn không hợp lệ" << endl;

        }

    }

 

    return 0;

}

 