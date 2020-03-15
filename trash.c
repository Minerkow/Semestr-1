int rabin_karp(const char *needle, const char *haystack) {
    unsigned n, target, cur, count = 0, left = 0, right = strlen(needle);
    unsigned len = strlen(needle);

    target = get_hash(needle, needle + right);
    cur = get_hash(haystack, haystack + right);
    n = pow_mod(R, right - 1, Q);

    while(haystack[right] != 0) {
        if(cur == target)
        {
            while (count < len)
            {
                if(needle[count] != haystack[left + count])
                    break;

                count++;
            }
            if(count == len)
                return left;
            count = 0;
        }
        cur = update_hash(cur, n, haystack[left], haystack[right]);
        left += 1;
        right += 1;
    }

    return -1;
}
