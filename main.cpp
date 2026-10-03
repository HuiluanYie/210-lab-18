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

    //Function prototype
    // copy constructor
    Movie(const Movie&);

    // destructor
    ~Movie();

    // copy assignment operator

    // other methods
    
    void print();
    void adds_review_head(float r, string c);

};

int main() {
    // declarations
    vector <Movie> movies;
    
    return 0;
}

//Function definition
// copy constructor
Movie::Movie(const Movie& other)
{
    // copy over the title
    title = other.title;
    Review* source = other.reviews;
    Review * r_ptr = reviews;
    // go to the tail of the reviews linked list 
    while (r_ptr != nullptr && r_ptr -> next != nullptr) {
        r_ptr = r_ptr -> next;
    }
    //copy over the reviews
    while (source)
    {
        Review * new_rev = new Review;
        new_rev->rating = source->rating;
        new_rev->comment = source->comment;

        // add the new reweiw to the tail
        if (!r_ptr) {
            reviews = new_rev;
        } 
        else {
            r_ptr -> next = new_rev;
            r_ptr = new_rev;
        }
        source = source->next;
    }
}

// destructor
Movie::~Movie(){
    Review * current = reviews;
    while (current) {
        reviews = current -> next;
        delete current;
        current = reviews;
    }
    reviews = nullptr;
}

// copy assignment operator

// other methods


// other methods
void Movie::print() {
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

void Movie::adds_review_head(float r, string c)
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