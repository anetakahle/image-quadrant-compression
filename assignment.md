_Quadrant compression_ is a way of encoding black-and-white pictures. In its full generality, it works as follows: As input it gets an image of size 2^k\times 2^k2 
k
 ×2 
k
  and it outputs a string. If the whole image is black or white, the output is 0 or 1, respectively. Otherwise we split the image into four smaller quadrants (each of same size), we encode these separately, and use ([LU][RU][LD][RD]) as output, where [LU] is the encoding of the left-upper quadrant, [RU] the encoding of the right-upper quadrant etc. For example, a 4 × 4 picture whose only black pixel is the second pixel of the first row is encoded as ((1011)111), a 4 × 4 picture with all pixels black is encoded as 0.

In this task we will use a special lossy variant of this compression. It works identically to the lossless compression, except that a picture of size greater than 1 × 1 must always be encoded using quadrants (even if it is already solid black or white), and from these four quadrants, one will always be encoded as solid black, one as solid white, and only the remaining two quadrants will be encoded recursively. (Picture of size 1 × 1 can be encoded arbitrarily.) The encoding quality of course depends on which quadrants are encoded as black, white, and which are encoded recursively. Your task is to find such encoding that minimises the number of pixels which have one color in the original image, and another color after applying compression.

For the nearly white picture from the first paragraph, one of optimal encodings and the picture obtained by decoding it look as follows:
```
    1 0 1 1
    1 1 1 1
    1 1 1 1
    1 1 1 1
    
       ↓
    
((1011)(1101)01)

       ↓
    
    1 0 1 1
    1 1 0 1
    0 0 1 1
    0 0 1 1
```
The number of changed pixels is 5.

You will get a raster black-and-white image of size 2^k \times 2^k2 
k
 ×2 
k
 . Output the number of pixels which will be changed after encoding the image optimally.

### Input
On input, you are given a picture in the PBM format. Specifically, the first line contains a string P1, the second line contain two space-separated integers N and M denoting the width and height of the image (in our case, N = M = 2^kN=M=2 
k
  for some kk). Each of the following M lines contains N space-separated integers, each of them either 0 (if the corresponding pixel is white) or 1 (if it is black).

You may assume the input is always in this format, although the PBM format is more general (and can contain comments, for example).

The width and height of the image will not exceed 2048.

### Output
Output a single number: the number of pixels that will have their colors changed after we encode the image using an optimal lossy quadrant encoding.

### Input example
```
P1
4 4
1 0 1 1
1 1 1 1
1 1 1 1
1 1 1 1
```
### Output example
```
5
```
