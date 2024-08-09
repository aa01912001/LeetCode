題號: 1054. Distant Barcodes
難度: Medium

## 問題描述
In a warehouse, there is a row of barcodes, where the `ith` barcode is `barcodes[i]`.

Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.


**Example 1:**
Input: barcodes = [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,1,2,1,2]

**Constraints:**

- `1 <= barcodes.length <= 10000`
- `1 <= barcodes[i] <= 10000`


**解決思路:**
此題不難想出透過greedy的方式，我們只需要每回合挑出兩個當前頻率最高的code放至解答之後即可。因為頻率越高的code，我們會希望它優先進行間隔的擺放。

因此我們可以採用max heap來記錄每個code當前的剩餘個數還有多少。