// COMSC-210 | Lab 18 | Huiluan Yie

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAX = 50, MIN = 10;
const float D = 10;

struct Review {
    float rating;
    string comment;
    Review * next = nullptr;
};

class Movie {
    private: string title;
    Review * reviews;

    // helper functions
    void copy_review(const Review * );
    void clear_review();

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
    // constructor
    Movie();
    // copy constructor
    Movie(const Movie & );

    // destructor
    ~Movie();

    // copy assignment operator
    Movie & operator = (const Movie & );

    // other methods
    void print() const;
    void adds_review_head(float r, string c);
};

int main() {
    // declarations
    vector < Movie > movies;
    string t;
    float r;
    string c;
    srand(time(0));

    // file input
    ifstream fin;
    fin.open("input.txt");
    if (fin.good()) {
        while (getline(fin, t)) {
            Movie temp_movie;
            // Ignore blank lines between movies.
            if (t.empty()) {
                continue;
            }
            temp_movie.set_title(t);

            while (getline(fin, c) && !c.empty()) {
                r = (rand() % (MAX - MIN + 1) + MIN) / D;
                temp_movie.adds_review_head(r, c);
            }
            movies.push_back(temp_movie);
        }

        fin.close();

        cout << fixed << setprecision(1);
        for (Movie m: movies) {
            m.print();
        }

    } else
        cout << "File not found.\n";

    return 0;
}

//Function definition
// constructor
Movie::Movie() {
    title = "";
    reviews = nullptr;
}
// copy constructor
Movie::Movie(const Movie & other): title(other.title), reviews(nullptr) {
    copy_review(other.reviews);
}

// destructor
Movie::~Movie() {
    clear_review();
}

// copy assignment operator
Movie & Movie::operator = (const Movie & other) {
    if (this != & other) {
        title = other.title;
        clear_review();
        copy_review(other.reviews);
    }
    return * this;
}

// other methods
void Movie::print() const {
    // print() prints out the movie's title, reveiws and average rating
    // arguments: none(natually refers to the Movie object)
    // returns: none
    cout << "\nMovie Title: " << title << endl;

    int count = 0;
    Review * r_ptr = reviews;
    float rating_sum = 0;
    while (r_ptr) {
        count++;
        cout << "\t> Review #" << count << ": " << r_ptr -> rating << ": " << r_ptr -> comment << endl;
        rating_sum += r_ptr -> rating;
        r_ptr = r_ptr -> next;
    }
    cout << "\t> Average: " << rating_sum / count << endl << endl;
}

void Movie::adds_review_head(float r, string c) {
    // adds_review_head() adds a review (rating + comment) to the head of the list
    // arguments: the rating, the comment
    // returns: none
    Review * new_rev = new Review;
    new_rev -> rating = r;
    new_rev -> comment = c;

    if (!reviews) {
        reviews = new_rev;
    } else {
        new_rev -> next = reviews;
        reviews = new_rev;
    }
}

// helper functions
void Movie::copy_review(const Review * source) {
    // copy_review() copy over the reviews from a review source
    // arguments: a pinter to the reweiw source
    // returns: none
    Review * r_ptr = nullptr;
    while (source) {
        Review * new_rev = new Review;
        new_rev -> rating = source -> rating;
        new_rev -> comment = source -> comment;
        new_rev -> next = nullptr;

        // add the new reweiw to the tail
        if (!r_ptr) {
            reviews = new_rev;
        } else {
            r_ptr -> next = new_rev;
        }
        r_ptr = new_rev;
        source = source -> next;
    }
}

void Movie::clear_review() {
    // clear_review() deletes the linked list of rewiews
    // arguments: none
    // returns: none
    Review * current = reviews;
    while (current) {
        reviews = current -> next;
        delete current;
        current = reviews;
    }
    reviews = nullptr;
}