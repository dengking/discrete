def kmp_search(pattern, text):
    """

    :param pattern:
    :param text:
    :return:
    """
    # 1) Construct the failure array
    failure = get_failure_array(pattern)

    # 2) Step through text searching for pattern
    i, j = 0, 0  # index into text, pattern
    while i < len(text):
        if pattern[j] == text[i]:
            if j == (len(pattern) - 1):
                return True
            j += 1
        elif j > 0:
            # if this is a prefix in our pattern
            # just go back far enough to continue
            j = failure[j - 1]
            continue
        i += 1
    return False


def get_failure_array(pattern):
    """
    关于本函数的分析，参见对应文档
    :param pattern:
    :return:
    """
    failure = [0]
    i = 0
    j = 1
    while j < len(pattern):
        if pattern[i] == pattern[j]:
            i += 1
        elif i > 0:
            i = failure[i - 1]
            continue
        j += 1
        failure.append(i)
    return failure


if __name__ == '__main__':
    pass
