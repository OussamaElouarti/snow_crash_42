<h1>Level01</h1>

In level00 we already got the hash for flag01 42hDRfypTqqnw,we need to decrypt it

Using johnthereaper to decrypt the hash

```
john level01.hash
```
We got

```
macboook@Teslas-Macbook Ressources % john level01.hash 
Loaded 1 password hash (descrypt, traditional crypt(3) [DES 128/128 SSE2])
No password hashes left to crack (see FAQ)
macboook@Teslas-Macbook Ressources % john --show level01.hash 
?:abcdefg

1 password hash cracked, 0 left
```

Logged into flag00

Launched getflag -> f2av5il02puano7naaf6adaaf
