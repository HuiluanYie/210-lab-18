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
        // print() prints out the movie's title, reveiws and average rating
        // arguments: none(natually refers to the Movie object)
        // returns: none
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

    void adds_review_head(float r, string c)
    {
        // adds_review_head() adds a review (rating + comment) to the head of the list
        // arguments: the rating, the comment
        // returns: none
        Review * new_rev = new Review;
        new_rev->rating = r;
        new_rev->comment = c;

        if (!reviews) {
            reviews = new_rev;
        } else {
            new_rev -> next = reviews;
            reviews = new_rev;
        }
    }
};

//Function prototype

int main() {
    // declarations
    
    return 0;
}

//Function definition
