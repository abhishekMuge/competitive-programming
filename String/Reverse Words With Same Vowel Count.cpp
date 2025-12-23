class Solution
{
public:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u';
    }

    string reversedString(string s)
    {
        int n = s.size();
        int i = 0;

        // ---- First word ----
        int firstVowelCount = 0;
        while (i < n && s[i] != ' ')
        {
            if (isVowel(s[i]))
                firstVowelCount++;
            i++;
        }

        // ---- Remaining words ----
        while (i < n)
        {
            // Skip space
            i++;

            int start = i;
            int vowelCount = 0;

            while (i < n && s[i] != ' ')
            {
                if (isVowel(s[i]))
                    vowelCount++;
                i++;
            }

            if (vowelCount == firstVowelCount)
            {
                reverse(s.begin() + start, s.begin() + i);
            }
        }

        return s;
    }
};
