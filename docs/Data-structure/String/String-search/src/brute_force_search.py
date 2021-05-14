def brute_force_search(txt, pat):
    """
    Given a text txt and a pattern pat, prints all occurrences of pat in txt.
    https://www.geeksforgeeks.org/naive-algorithm-for-pattern-searching/
    :param txt:
    :param pat:
    :return:
    """
    txt_len = len(txt)
    pat_len = len(pat)
    for i in range(txt_len - pat_len + 1):
        for j in range(pat_len):
            if txt[i + j] != pat[j]:
                break
        if j == pat_len - 1:
            print(txt[i:i + pat_len])
        j = 0


# Driver Code
if __name__ == '__main__':
    txt = "AABAACAADAABAAABAA"
    pat = "AABA"
    brute_force_search(txt, pat)
