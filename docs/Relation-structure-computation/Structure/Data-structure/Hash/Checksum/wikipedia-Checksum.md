# [Checksum](https://en.wikipedia.org/wiki/Checksum)

A **checksum** is a small-sized [datum](https://en.wikipedia.org/wiki/Datum) derived from a block of [digital data](https://en.wikipedia.org/wiki/Digital_data) for the purpose of [detecting errors](https://en.wikipedia.org/wiki/Error_detection) that may have been introduced during its [transmission](https://en.wikipedia.org/wiki/Telecommunication) or [storage](https://en.wikipedia.org/wiki/Computer_storage). By themselves, checksums are often used to verify data integrity but are not relied upon to verify data [authenticity](https://en.wikipedia.org/wiki/Authentication).

The [procedure](https://en.wikipedia.org/wiki/Algorithm) which generates this checksum is called a **checksum function** or **[checksum algorithm](https://en.wikipedia.org/wiki/Checksum_algorithm)**. Depending on its design goals, a good checksum algorithm will usually output a significantly different value, even for small changes made to the input. This is especially true of [cryptographic hash functions](https://en.wikipedia.org/wiki/Cryptographic_hash_function), which may be used to detect many data corruption errors and verify overall [data integrity](https://en.wikipedia.org/wiki/Data_integrity); if the computed checksum for the current data input matches the stored value of a previously computed checksum, there is a very high probability the data has not been accidentally altered or corrupted.

> NOTE: Hash code can be used as checksum.

[Check digits](https://en.wikipedia.org/wiki/Check_digit) and [parity bits](https://en.wikipedia.org/wiki/Parity_bit) are special cases of checksums, appropriate for small blocks of data (such as [Social Security numbers](https://en.wikipedia.org/wiki/Social_Security_number), [bank account](https://en.wikipedia.org/wiki/Bank_account) numbers, [computer words](https://en.wikipedia.org/wiki/Word_(data_type)), single [bytes](https://en.wikipedia.org/wiki/Byte), etc.). Some [error-correcting codes](https://en.wikipedia.org/wiki/Error-correcting_code) are based on special checksums which not only detect common errors but also allow the original data to be recovered in certain cases.



# 补充

## [What Is a Checksum (and Why Should You Care)?](https://www.howtogeek.com/363735/what-is-a-checksum-and-why-should-you-care/)



## [Git](https://git-scm.com/) Has Integrity

在[Pro Git book](https://git-scm.com/book/en/v2)的[1.3 Getting Started - What is Git?](https://git-scm.com/book/en/v2/Getting-Started-What-is-Git%3F)节中描述了git中checksum的使用情况。



## [Practical Application of Cryptographic Checksums](http://www.peterjockisch.de/texte/computerartikel/Kryptographische-Pruefsummen/Kryptographische-Pruefsummen_EN.html)

总结的非常好