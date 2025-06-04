class Solution
{
    public String answerString(String word, int numFriends)
    {
        int N = word.length();

        // Step 1: Handle base case where all friends can split the string
        if (numFriends == 1)
        {
            return word;
        }

        // Step 2: Find the lexicographically largest character in the string
        char c = 'a'; // Default character to find the largest
        for (char ch : word.toCharArray())
        {
            if (ch > c)
            {
                c = ch;
            }
        }

        String maxString = ""; 

        // Step 3: Iterate through the positions of the largest character
        for (int pos = 0; pos < N; pos++)
        {
            if (word.charAt(pos) == c)
            {
                // Step 4: Compute the maximum allowable substring length from this position
                int lAllowed = Math.min(N - pos, N - numFriends + 1);

                if (lAllowed <= 0)
                {
                    continue;
                }

                // Step 5: Extract the substring and compare with the current maximum
                String s = word.substring(pos, pos + lAllowed);
                if (s.compareTo(maxString) > 0)
                {
                    maxString = s; // Update the maximum string
                }
            }
        }

        // Step 6: Return the result
        return maxString;
    }
}