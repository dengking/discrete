# [Rolling hash](https://en.wikipedia.org/wiki/Rolling_hash)

A **rolling hash** (also known as recursive hashing or rolling checksum) is a [hash function](https://en.wikipedia.org/wiki/Hash_function) where the input is hashed in a window that moves through the input.

A few hash functions allow a rolling hash to be computed very quickly—the new hash value is rapidly calculated given only the old hash value, the old value removed from the window, and the new value added to the window—similar to the way a [moving average](https://en.wikipedia.org/wiki/Moving_average) function can be computed much more quickly than other low-pass filters.

One of the main applications is the [Rabin–Karp string search algorithm](https://en.wikipedia.org/wiki/Rabin–Karp_string_search_algorithm), which uses the rolling hash described below. Another popular application is the [rsync](https://en.wikipedia.org/wiki/Rsync) program, which uses a checksum based on Mark Adler's [adler-32](https://en.wikipedia.org/wiki/Adler-32) as its rolling hash. Low Bandwidth Network Filesystem (LBFS) uses a [Rabin fingerprint](https://en.wikipedia.org/wiki/Rabin_fingerprint) as its rolling hash.

At best, rolling hash values are [pairwise independent](https://en.wikipedia.org/wiki/Pairwise_independent)[[1\]](https://en.wikipedia.org/wiki/Rolling_hash#cite_note-lemirekaser-1) or strongly [universal](https://en.wikipedia.org/wiki/Universal_hashing). They cannot be [3-wise independent](https://en.wikipedia.org/wiki/K-independent_hashing), for example.