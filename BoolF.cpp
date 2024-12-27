#include <bits/stdc++.h>
using namespace std;

#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define file()                                            \
    freopen("inputfiles/10 Nodes/1/inp.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int GENE[110][110];
int Kmin[110][110];
int number_of_genes = 8;
int number_of_rows = 8;

map<int, vector<int>> actualOutput;

double TP = 0, FP = 0, FN = 0, TN=0;

//This functio is used for getting TP, FP, FN, and TN
void updateVar(vector<int> &actual, vector<int> &current,int n)
{

    map<int, int> mp;
    for (int i = 0; i < actual.size(); i++)
    {
        mp[actual[i]]++;
    }

    for (int i = 0; i < current.size(); i++)
    {
        mp[current[i]]++;
    }

    int cntcommon = 0;
    for (auto it : mp)
    {
        if (it.second >= 2)
        {
            cntcommon++;
        }
    }

    FN += actual.size() - cntcommon;
    FP += current.size() - cntcommon;
    TP += cntcommon;
  
    TN +=(n-1);
    TN -= actual.size();
    TN -= (current.size() - cntcommon);
}


vector<string> UpdatedSignGenerator(int n)
{
    vector<string> perms;
    vector<string> perms1;

    perms.push_back("0");
    perms.push_back("1");

    for (int i = 1; i < n; i++)
    {
        for (string str : perms)
        {
            perms1.push_back(str + "0");
            perms1.push_back(str + "1");
        }

        perms.clear();
        perms = perms1;
        perms1.clear();
    }

    return perms;
}

//Belows function performs the tasks of 'Check' subroutines Or operation 
int Operation_Or(vector<int> &serial, vector<string> &sign, int tar)
{

    int x = serial.size();
    int z, res, err_cnt, tot_error = INT_MAX;
    for (int i = 0; i < sign.size(); i++)
    {
        z = x;

        err_cnt = 0;
        for (int row = 0; row < (number_of_rows - 1); row++)
        {
            res = 0;
            for (int ss = 0; ss < z; ss++)
            {

                if (sign[i][ss] == '0')
                {
                    res |= (GENE[row][serial[ss]]);
                }
                else
                {
                    int inter = 0;
                    if (GENE[row][serial[ss]] == 0)
                    {
                        inter = 1;
                    }
                    else
                    {
                        inter = 0;
                    }
                    res |= inter;
                }
            }

            if (res != GENE[row + 1][tar])
            {
                err_cnt++;
            }
        }
        // total calculation for error cnt
        tot_error = min(err_cnt, tot_error);
        if (tot_error == 0)
        {
            return (number_of_rows-1);
        }
    }
    return (number_of_rows-tot_error-1);
}

//Belows function performs the tasks of 'Check' subroutines And operation 
int Operation_And(vector<int> &serial, vector<string> &sign, int tar)
{

    int x = serial.size();
    int z, res, err_cnt, tot_error = INT_MAX;
    for (int i = 0; i < sign.size(); i++)
    {
        z = x;

        err_cnt = 0;
        for (int row = 0; row < (number_of_rows - 1); row++)
        {
            res = 1;
            for (int ss = 0; ss < z; ss++)
            {

                if (sign[i][ss] == '0')
                {
                    res &= (GENE[row][serial[ss]]);
                }
                else
                {
                    int inter = 0;
                    if (GENE[row][serial[ss]] == 0)
                    {
                        inter = 1;
                    }
                    else
                    {
                        inter = 0;
                    }
                    res &= inter;
                }
            }

            if (res != GENE[row + 1][tar])
            {
                err_cnt++;
            }
        }
        // total calculation for error cnt
        tot_error = min(err_cnt, tot_error);
        if (tot_error == 0)
        {
            int inter = (number_of_rows-1);
       //     cout<<"ANDok "<<inter<<" "<<"inside"<<endl;
            return inter;
        }
    }
  
    int inter=(number_of_rows-tot_error-1);
    return inter;
}

class GroupGenerator
{
private:
    int number_of_genes;
    int r;
    vector<int> index;
    bool hasNext = true;

    void moveIndex()
    {
        int i = rightmostIndexBelowMax();
        if (i >= 0)
        {
            index[i] = index[i] + 1;
            for (int j = i + 1; j < r; j++)
            {
                index[j] = index[j - 1] + 1;
            }
        }
        else
        {
            hasNext = false;
        }
    }

    int rightmostIndexBelowMax()
    {
        for (int i = r - 1; i >= 0; i--)
        {
            if (index[i] < number_of_genes - r + i)
            {
                return i;
            }
        }
        return -1;
    }

public:
    GroupGenerator(int Nogene, int row)
    {
        number_of_genes = Nogene;
        r = row;
        index.resize(r);
        for (int i = 0; i < r; i++)
        {
            index[i] = i;
        }
    }

    bool hasNextCombination()
    {
        return hasNext;
    }

    std::vector<int> nextCombination()
    {
        if (!hasNext)
        {
            return vector<int>();
        }
        vector<int> result(r);
        for (int i = 0; i < r; i++)
        {
            result[i] = index[i];
        }
        moveIndex();
        return result;
    }

    vector<pair<int, vector<int>>> test1(int cur, vector<vector<string>> &Signstore)
    {
        GroupGenerator c(number_of_genes, r); // O(number_of_genes)

        // vector<vector<int>> Groups;
      
        int counter = 0;
        vector<string> inter;
        inter = Signstore[r]; // All permutation
        vector<pair<int, vector<int>>> minError;
        vector<pair<int, vector<int>>> ret; // it will return the minimum value to the main function
        vector<int> empty;
        int marker=0;
        int curMinError = -1;
        // for (int jj = 0; jj < inter.size(); jj++)
        // {
        //     cout << inter[jj] << endl;
        // }
        while (c.hasNextCombination()) // O(number_of_genes*10)
        {
            vector<int> a = c.nextCombination();
            counter++;
            // You can print the combination here if needed
            int cnt = 0;
            // cout<<a[0]<<endl;
            for (int i = 0; i < r; i++) // O(10)
            {
                // cout << a[i] << " ";

                if (a[i] == cur)
                {
                    cnt++;
                    break;
                }
            }

            // cout<<"Cur "<<cur<<endl;

            if (!cnt)
            {

                int ORok = Operation_Or(a, inter, cur);

                if (ORok == (number_of_rows-1))
                {
                    ret.push_back(make_pair((number_of_rows-1), a));

                    return ret;
                }
                else
                {
                    if (curMinError < ORok)
                    {
                        minError.push_back(make_pair(ORok, a));
                        curMinError=ORok;
                    }
                }
                int ANDok = Operation_And(a, inter, cur);
             
                if(ANDok==(number_of_rows-1))
                {
                    ret.push_back(make_pair((number_of_rows-1), a));
                   
                    return ret;
                }
                else
                {
                    if (curMinError < ANDok)
                    {
                        minError.push_back(make_pair(ANDok, a));
                        curMinError=ANDok;
                    }
                }

               
            }
        }

       

        sort(minError.rbegin(), minError.rend());

        ret.push_back(make_pair(minError[0].first, minError[0].second));
        return ret;
    }
};

int main()
{
    optimize();
    double finalFscore = 0;
    double finalAccuracy = 0;
    double finalPrecision = 0;
    double finalRecall = 0;
    double finalMCC=0;
    double finalFPR=0;
    clock_t start, end;
    start = clock();
    // Precalculating permutation set
    vector<string> inter;
    inter.push_back("00");
    vector<vector<string>> Signstore;
    Signstore.push_back(inter);
    for (int i = 1; i <= min(number_of_genes - 1, 6); i++)
    { // O(10*1024)
        inter = UpdatedSignGenerator(i);
        // cout<<"SIGN GROUP SIZE "<<inter.size()<<endl;
        Signstore.push_back(inter);
        inter.clear();
    }

  
     
         string Network_input = "sampleNetwork/inp.txt";
         string output = "sampleOutput.txt";


        freopen(Network_input.c_str(), "r", stdin);
        freopen(output.c_str(), "a", stdout);


        cin >> number_of_genes >> number_of_rows;
        
        int checker = 0;
        for (int i = 0; i < number_of_rows; i++)
        {
            for (int j = 0; j < number_of_genes; j++)
            {
                checker++;

                cin >> GENE[i][j];

            }
        
        }
       
     
        fclose(stdin);
        string goldStandardNetwork = "sampleNetwork/outp.txt";
    

        ifstream inputFile(goldStandardNetwork);
        int first, second, third;
        cout<<"Sample Output"<<endl;
        while (inputFile >> first >> second >> third)
        {

            auto it = std::find(actualOutput[third].begin(), actualOutput[third].end(), first);

            // Check if the element was found

            if (it == actualOutput[third].end())
            {
                actualOutput[third].push_back(first);
            }
    
        }
        // output file modification end
        int res = 0;
        vector<vector<int>> Group;
        for (int i = 0; i < number_of_genes; i++) // for k=4 seconds O(3764376*4*4*100*4*100) / 10^7
        {
            // cout<<i<<endl;
            vector<pair<int, vector<int>>> minTracker;
            vector<pair<int, vector<int>>> res;
            int cnt = 0;
            for (int k = 1; k <= min(number_of_genes - 1, 4); k++) // O(3764376*4*4*4*4)
            {
              
                GroupGenerator generator(number_of_genes, k);

                res = generator.test1(i, Signstore); // Combination Generation

                // cout<<res<<" "<<i<<" "<<k<<endl;

                if (res[0].first == (number_of_rows-1))
                {
                  
                    minTracker.push_back(make_pair(res[0].first, res[0].second));
                    cnt++;
                    break;
                }
                 else
                {

                    minTracker.push_back(make_pair(res[0].first, res[0].second));
                }
              
            }
          
            if(cnt == 0)
            {
             
               
                sort(minTracker.rbegin(), minTracker.rend());
                int ind=0,mini=minTracker[0].first;
                while(minTracker[ind].first==mini&&ind<minTracker.size())
                {
                       ind++;
                       if(ind>=minTracker.size()){
                              ind--;
                              break;
                       }
                       if(minTracker[ind].first<mini)
                       {                       
                          ind--;
                          break;
                       }
                }
                //cout << " Number of Error is  " <<(number_of_rows-1)-minTracker[ind].first << " ";
                cout << " Regulatory gene for = "<< i+1 <<" ---> ";
                for (int kk = 0; kk < minTracker[ind].second.size(); kk++)
                {
                    cout << minTracker[ind].second[kk]+1 << " ";
                }
                cout << endl;
                vector<int> act = actualOutput[i];
               sort(act.begin(),act.end());
                cout << "Actual genes for = " << i+1 << " --->  ";
                for (int ii = 0; ii < act.size(); ii++)
                {
                    cout << act[ii]+1 << " ";
                }
                cout << endl;
                updateVar(actualOutput[i], minTracker[ind].second, number_of_genes);
                // cout<<TP<<" "<<FP<<" "<<FN<<endl;
                //FN+=actualOutput[i].size();
            }
            else
            {
                sort(minTracker.rbegin(), minTracker.rend());
                cout << "Current genes for= " << i+1 << " --->  ";
                //cout<<minTracker[0].second.size()<<" hi "<<endl;
                for (int ii = 0; ii < minTracker[0].second.size(); ii++)
                {
                    cout << minTracker[0].second[ii]+1 << " ";
                }
                cout << endl;

                vector<int> act = actualOutput[i];
               sort(act.begin(), act.end());
                cout << "Actual genes for = " << i+1 << " --->  ";
                for (int ii = 0; ii < act.size(); ii++)
                {
                    cout << act[ii]+1 << " ";
                }
                cout << endl;

                updateVar(actualOutput[i],minTracker[0].second, number_of_genes);
                // cout<<TP<<" "<<FP<<" "<<FN<<endl;
            }
        }

    
      cout << "TP " << TP << " "
             << " FP " << FP << " "
             << " TN " <<TN << " "
             << " FN " << FN << " "
             << "parameters" << endl;
        cout << endl;
        double preci = TP / (TP + FP);
        double recall = TP / (TP + FN);
        double FPR = (double)FP / (FP + TN);
        double fsc = 2 * preci * recall / (preci + recall);
        double numerator = (TP * TN) - (FP * FN);
        double denominator = sqrt((double)(TP + FP) * (TP + FN) * (TN + FP) * (TN + FN));
        double MCC = numerator / denominator;
        cout << "Fscore for this file = " << fsc << endl;
        cout << "Recall/TPR for this file is " << recall << endl;
        cout << "FPR for this file is " << FPR << endl;
        cout << "MCC for this file is " << MCC << endl;
        cout << "Precision for this file is" << preci << endl;
        cout << endl;

     
        finalFscore += fsc;
        finalRecall += recall;
        finalPrecision += preci;
        finalMCC+=MCC;
        finalFPR+=FPR;
        actualOutput.clear();
    

    return 0;
}
