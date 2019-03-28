#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int i, j, chars_sum = 0, quesmark_sum = 0,missing;
	map<char, int>mp;
	string ZS_word, alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
//****************************************************************
	cin >> ZS_word;
	if (ZS_word.length() >= 26)
	{
		for (i = 0; i < ZS_word.length() - 25; i++)           // loop from i = 0 ---> the size - 25 to leave the last 26 chars
		{                                                   // because we divide the string into segments of 26 chars and check
			mp.clear();                                     // if there are chars less than 26 in the end we won't find a solution
			chars_sum = 0; quesmark_sum = 0;

			for (j = i; j < i + 26; j++)                   // strting from i take 26 chars and Checking
			{                                              // if they can be the solution
				if (ZS_word[j] == '?')                     // if not continue --> erasing what we did and increment (i)
					quesmark_sum++;                        // to take another segment of 26 chars
				else if (mp[ZS_word[j]] == 0)
				{
					chars_sum++;
					mp[ZS_word[j]] = 1;
				}

			}

			if (chars_sum + quesmark_sum != 26)            // if the condition = 26
				continue;                                  // then the segment is the solution
														   // time to replace '?' with the missing letters
			int k = 0;
			for (j = i; j < i + 26; j++)
			{

				if (mp[alphabet[k]] == 0)
				{
					missing = ZS_word.find('?', i);          // loop to replace '?' with the missing letters
					if (missing == -1)                       // break when there are no more '?'
						break;
					ZS_word[missing] = alphabet[k];
				}
				k++;
			}

			for (j = 0; j < ZS_word.length(); j++)              // Now we have the correct segment 
			{                                                   // Time to replace all '?' in the original String
				missing = ZS_word.find('?');                    // with any char (i.e.'A') to elimintae all '?'
				if (missing == -1)
					break;
				ZS_word[missing] = 'A';
			}

			cout << ZS_word;
			return 0;
		}	                                 
	}
	cout << "-1";                                           // (-1) when we don't find a segment that may be the solution
	
	return 0;
}