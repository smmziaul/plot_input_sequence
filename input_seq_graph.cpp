#include <iostream>

using namespace std;

# define no_of_rows 100
# define no_of_cols 100

int main ()
{
    int which_row = no_of_rows - 1, which_col = 0;

    int seq[] =
    {3, 1, 4, 1};
    // {3, 1, 2, 3, 6, 2, 3, 6};

    bool ask_user =
        true;
    // false;

    int count, peak_which_row = 0, peak_which_col = -1, temp = 0;

    char plot[no_of_rows][no_of_cols] = {};

    // initializing the graph
    for(int i = 0; i < no_of_rows; i++)
    {
        for(int j = 0; j < no_of_cols; j++)
        {
            plot[i][j] = ' ';
        }
    }

    if(ask_user)
    {
        cout << "\nenter the number of elements in your input sequence: ";
        cin >> count;

        if(count <= 0)
        {
            cout <<"input length is either 0 or negative... exiting";
            return 0;
        }

        cout << "\nenter " << count << " elements one by one: ";
        for(int i = 0; i < count; i++)
        {
            cin >> seq[i];
        }
    }
    else
    {
        count = sizeof(seq)/sizeof(int);
    }

    // print user input sequence
    cout<<"\nthe given input sequence is: \n";
    for(int i = 0; i < count; i++)
    {
        cout << seq[i] << "  ";
    }

    cout << "\n";
    cout << "\n";

    // finding the peak
    for(int i = 0; i < count; i++)
    {
        peak_which_col += seq[i];
        if(i % 2 == 0)
        {
            temp = temp + seq[i] - 1;
            if(temp > peak_which_row)
            {
                peak_which_row = temp;
            }
        }
        else
        {
            temp = temp - (seq[i] - 1);
        }
    }
    peak_which_row++;

    // printing the co-ordinates of the highest peak
    // cout<< "peak which row: " << peak_which_row << ", peak which col: " << peak_which_col << endl << endl ;

    for (int i = 0; i < count; i++)
    {
        if(i % 2 == 0)
        {
            // go upwards
            for(int j = 0; j < seq[i]; j++)
            {
                plot[which_row--][which_col++] = '/';
                if(j == seq[i] - 1
                        && which_row == no_of_rows - peak_which_row - 1
                  )
                {
                    plot[which_row-1][which_col] = '|';

                    plot[which_row-1][which_col-1] = '/';

                    plot[which_row][which_col-1] = '<';
                    plot[which_row][which_col+1] = '>';

                    plot[which_row-1][which_col+1] = '\\';
                    plot[which_row-2][which_col] = '0';
                }
                else
                {
//                    cout<<"could not find peak"<<endl;
                }
            }
            which_row++;
        }
        else
        {
            // go downwards
            for(int j = 0; j < seq[i]; j++)
            {
                if(j == 0
                        && which_col == peak_which_col
                  )
                {
                    which_col += 1;
                    plot[which_row++][which_col++] = '\\';
                }
                else
                {
                    plot[which_row++][which_col++] = '\\';
                }
            }
            which_row--;
        }
    }

    // plot graph
    for(int i = 0; i < no_of_rows; i++)
    {
        for (int j = 0; j < no_of_cols; j++)
        {
            cout << plot[i][j];
        }
        cout << "\n";
    }

    return 0;
}
