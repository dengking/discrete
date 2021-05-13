# Checksum



## wikipedia [Checksum](https://en.wikipedia.org/wiki/Checksum)

A **checksum** is a small-sized [datum](https://en.wikipedia.org/wiki/Datum) derived from a block of [digital data](https://en.wikipedia.org/wiki/Digital_data) for the purpose of [detecting errors](https://en.wikipedia.org/wiki/Error_detection) that may have been introduced during its [transmission](https://en.wikipedia.org/wiki/Telecommunication) or [storage](https://en.wikipedia.org/wiki/Computer_storage). By themselves, checksums are often used to verify **data integrity** but are not relied upon to verify data [authenticity](https://en.wikipedia.org/wiki/Authentication).

The [procedure](https://en.wikipedia.org/wiki/Algorithm) which generates this checksum is called a **checksum function** or **[checksum algorithm](https://en.wikipedia.org/wiki/Checksum_algorithm)**. Depending on its design goals, a good checksum algorithm will usually output a significantly different value, even for small changes made to the input. This is especially true of [cryptographic hash functions](https://en.wikipedia.org/wiki/Cryptographic_hash_function), which may be used to detect many data corruption errors and verify overall [data integrity](https://en.wikipedia.org/wiki/Data_integrity); if the computed checksum for the current data input matches the stored value of a previously computed checksum, there is a very high probability the data has not been accidentally altered or corrupted.

> NOTE: Hash code can be used as checksum.

[Check digits](https://en.wikipedia.org/wiki/Check_digit) and [parity bits](https://en.wikipedia.org/wiki/Parity_bit) are special cases of checksums, appropriate for small blocks of data (such as [Social Security numbers](https://en.wikipedia.org/wiki/Social_Security_number), [bank account](https://en.wikipedia.org/wiki/Bank_account) numbers, [computer words](https://en.wikipedia.org/wiki/Word_(data_type)), single [bytes](https://en.wikipedia.org/wiki/Byte), etc.). Some [error-correcting codes](https://en.wikipedia.org/wiki/Error-correcting_code) are based on special checksums which not only detect common errors but also allow the original data to be recovered in certain cases.

> NOTE: 
>
> 1、[parity bits](https://en.wikipedia.org/wiki/Parity_bit) 指的是 "奇偶校验位"

## 补充

### howtogeek [What Is a Checksum (and Why Should You Care)?](https://www.howtogeek.com/363735/what-is-a-checksum-and-why-should-you-care/)

#### Checksums Explained

To produce a checksum, you run a program that puts that file through an [algorithm](https://www.howtogeek.com/howto/44052/htg-explains-what-are-computer-algorithms-and-how-do-they-work/). Typical algorithms used for this include MD5, SHA-1, SHA-256, and SHA-512.

The algorithm uses a cryptographic hash function that takes an input and produces a string (a sequence of numbers and letters) of a fixed length. The input file can be a small 1 MB file or a massive 4 GB file, but either way, you’ll end up with a checksum of the same length. Checksums may also be called “hashes.”

#### When Checksums Are Useful

You can use checksums to check files and other data for errors that occur during transmission or storage. For example, a file might not have properly downloaded due to network issues, or hard drive problems could have caused corruption in a file on disk.

#### What’s the Difference Between MD5, SHA-1, and SHA-256 Sums?

Checksums are a useful way to ensure that a file doesn’t have an error. If a random error occurs due to download problems or hard drive issues, the resulting checksum will be different, even if it’s just a tiny error.

However, these cryptographic hash functions aren’t perfect. Security researchers have found “[collisions](https://www.howtogeek.com/238705/what-is-sha-1-and-why-will-retiring-it-kick-thousands-off-the-internet/)” with the [MD5](https://www.mscs.dal.ca/~selinger/md5collision/) and [SHA-1](https://security.googleblog.com/2017/02/announcing-first-sha1-collision.html) functions. In other words, they’ve found two different files that produce the same MD5 or SHA-1 hash, but are different.

This is unlikely to happen through random chance, but an attacker could use this technique to disguise a malicious file as a legitimate file. That’s why you shouldn’t rely on MD5 or SHA-1 sums to verify that a file is authentic—just to check for corruption.

There haven’t been any reports of an SHA-256 collision yet, which is why applications are now creating SHA-256 sums instead of MD5 sums and SHA-1 sums. SHA-256 is a stronger, more secure algorithm.



### [Git](https://git-scm.com/) Has Integrity

> 在[Pro Git book](https://git-scm.com/book/en/v2)的[1.3 Getting Started - What is Git?](https://git-scm.com/book/en/v2/Getting-Started-What-is-Git%3F)节中描述了git中checksum的使用情况。

Everything in Git is checksummed before it is stored and is then referred to by that checksum. This means it’s impossible to change the contents of any file or directory without Git knowing about it. This functionality is built into Git at the lowest levels and is integral to its philosophy. You can’t lose information in transit or get file corruption without Git being able to detect it.

The mechanism that Git uses for this checksumming is called a **SHA-1 hash**. This is a 40-character string composed of hexadecimal characters (0–9 and a–f) and calculated based on the contents of a file or directory structure in Git. A SHA-1 hash looks something like this:



### peterjockisch [Practical Application of Cryptographic Checksums](http://www.peterjockisch.de/texte/computerartikel/Kryptographische-Pruefsummen/Kryptographische-Pruefsummen_EN.html)

总结的非常好