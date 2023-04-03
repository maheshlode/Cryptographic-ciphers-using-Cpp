# Cryptographic-ciphers-using-Cpp

Cryptographic Ciphers using C++
This repository contains menu driven implementation of following cryptographic ciphers using C++.

The ciphers that have been implemented are as follows:

1. Caesar Cipher
2. Substitution Cipher
3. Affine Cipher
4. Vigenere Cipher
5. Playfair Cipher

## Caesar Cipher
The Caesar Cipher is a simple substitution cipher where each letter in the plaintext is shifted a certain number of places down the alphabet.
For example, with a shift of 1, A would be replaced by B, B would become C, and so on.

## Substitution Cipher
The Substitution Cipher is a more complex substitution cipher where each letter in the plaintext is replaced by another letter according to a predetermined key.

## Affine Cipher
The Affine Cipher is a more advanced substitution cipher where each letter in the plaintext is replaced by another letter according to two keys, one of which is a multiplier and the other is an offset(additive).
Affine cipher combines both the additive and multiplicative cipher by using two keys, say 5 and r. Let p represent the position of the plaintext character in the alphabet, and c the position of the corresponding ciphertext character. Compute c from p by using the equation ###c = s(p + r)(mod 26).
This type of cipher is called an affine cipher.

## Vigenere Cipher
The Vigenere Cipher is a polyalphabetic substitution cipher.the enciphering scheme invented by Vigenere uses a one-to-several correspondence
between plaintext letters and ciphertext letters. Vigenere’s system, therefore, is an
example of a polyalphabetic substitution cipher, one in which a plurality of cipher
alphabets is employed within the same message.

## Playfair Cipher
The Playfair Cipher is a polygraphic substitution cipher and it was actually invented by his good friend Charles Wheatstone with whom Playfair spent many hours working on recreational cryptology. Playfair’s method requires a table of only 25 cells.
