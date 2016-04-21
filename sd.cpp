#include<iostream>
#include<vector>
#include<fstream>

using namespace std;
fstream fin("input.txt");

vector<int> turns(int m, int n, vector<vector<int> > F)
{
    vector<int> A(10);
    for (int i = 0; i < 10; i++)
    {
        A[i] = 0;
}
    //hor
    for (int j = 0; j < 9; j++)
    {
        A[F[m][j]]++;
    }
    //vert
    for (int j = 0; j < 9; j++)
    {
        A[F[j][n]]++;
    }
    //sqr
    int x, y;
    x = (m / 3) * 3;
    y = (n / 3) * 3;
    for (int i = x; i < x + 3; i++)
    {
        for (int j = y; j < y + 3; j++)
        {
            A[F[i][j]]++;
        }
    }
    vector<int> T;
    for (int i = 1; i < 10; i++)
    {
        if (A[i] == 0)
        {
            T.push_back(i);
        }
    }
    return T;
}

vector<vector<vector<int> > > priority (vector<vector<int> > F)
{
    vector<vector<vector<int> > > P;
    for (int i = 0; i < 9; i++)
    {
        vector<vector<int> > B;
        for (int j = 0; j < 9; j++)
        {
            vector<int> T = turns(i, j, F);
            B.push_back(T);
        }
        P.push_back(B);
    }
    return P;
}

vector<vector<int> > coun(vector<vector<vector<int> > > P)
{
    vector<vector<int> > C;
    for(int i = 0; i < 9; i++)
    {
        vector<int> A(9);
        for (int j = 0; j < 9; j++)
        {
            A[j] = P[i][j].size();
        }
        C.push_back(A);
    }
    return C;
}

bool solve(vector<vector<int> > &F)
{
    vector<vector<vector<int> > > P = priority(F);
    vector<vector<int> > C = coun(P);

    int k = 10;
    int x = 0;
    int y = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if((k > C[i][j])&&(F[i][j] == 0))
            {
                k = C[i][j];
                x = i;
                y = j;
            }
        }
    }
    if (k == 10)
    {
        return 1;
    }
    vector<int> T = turns(x, y, F);
    if (T.size() == 0)
    {
        return 0;
    }
    for(int i = 0; i < T.size(); i++)
    {
        F[x][y] = T[i];
        if (solve(F))
        {
            return 1;
        }
    }
    F[x][y] = 0;
    return 0;
}

int main()
{
    vector<vector<int> > F;
    for (int i = 0; i < 9; i++)
    {
        vector<int> A;
        for (int j = 0; j < 9; j++)
        {
            A.push_back(0);
            cout << A[j] << " ";
        }
        F.push_back(A);
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            fin >> F[i][j];
            cout << F[i][j] << " ";
        }
        cout << endl;
    }
    //F[0][0] = 8;
    solve(F);
    cout << "dec" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << F[i][j] << " ";
        }
        cout << endl;
    }
}




