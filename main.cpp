// COMSC-210 | Lab 18 | Huiluan Yie

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Review {
    float rating;
    string comment;
    Review * next = nullptr;
};

class Movie {
private:
    string title;
    Review * reviews;

public:
    // setter
    void set_title(string t) {
        title = t;
    }
    void set_reviews(Review * r) {
        reviews = r;
    }

    // getter
    string get_title() {
        return title;
    }
    Review * get_reviews(Review * r) {
        return reviews;
    }

    // other methods
    void print() {
        cout << "\nMovie Title: " << title << endl;

        int count = 0;
        Review * r_ptr = reviews;
        float rating_sum = 0;
        while (r_ptr)
        {
            count++;
            cout << "\t> Review #" << count << ": " << r_ptr->rating << ": " << r_ptr->comment;
            rating_sum += r_ptr->rating;
            r_ptr = r_ptr->next;
        }
        cout << "\t> Average: " << rating_sum / count << endl << endl;
    }

    void adds_review_head()
};

//Function prototype

int main() {
    // declarations
    
    return 0;
}

//Function definition
