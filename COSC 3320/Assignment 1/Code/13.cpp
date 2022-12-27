int count = 0;

//set n to number of columns

for(int i = 1; i<n-1; i++)
{
    for(int j = i; j<n; j++)
    {
        for(int k = i; k<j; k++)
        {
            //using function to calculate k values
            s[i,j] = s[i,k] + s[k+1,j] + n_i + n_k+1 + n_j+1 
            //increment counter
            counter++;
        }
    }
}
avg = sumOF(s[i,j]/count)