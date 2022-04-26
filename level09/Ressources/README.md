### Level09

Same as level before SUID plus token

-But this time we can  cat token => f4kmm6p|=� p�n��DB�Du{ ��

-the suid binary take an arg

```
 ./level09 aaaa => abcd
  ./level09 1111 => 1234
 ```
 
-So the binary increment by 1 everytime maybe its a script to encrypt the token 

-Lets create a c script to decrypt it you can find it in the same folder

``` ./a.out \`cat token\` => f3iji1ju5yuevaus41q1afiuq ```

-Its the pass for flag09

-getflag => s5cAJpM8ev6XHw998pRWG728z
