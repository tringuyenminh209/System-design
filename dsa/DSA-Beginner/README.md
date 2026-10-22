# DSA Beginner — Tài liệu Luyện tập Thuật toán Căn bản (Dành cho Java)

Tài liệu này được biên soạn dành cho bạn tự luyện tập code giải thuật bằng **Java**.
> **Quy tắc học tập:** Không xem code giải sẵn. Hãy đọc kỹ **Mô tả bài toán**, **Ràng buộc**, **Ý tưởng tiếp cận** và tự mình implement mã nguồn bằng Java, sau đó chạy thử với các **Test cases mẫu** được cung cấp ở mỗi bài.

---

## Mục lục 20 bài toán

| STT | Mã bài | Tên bài toán | Chủ đề chính | Kỹ năng rèn luyện |
|:---:|:---|:---|:---|:---|
| 01 | `01-sum-array` | Tổng các phần tử mảng | Mảng 1 chiều | Duyệt mảng, tránh tràn số với `long` |
| 02 | `02-max-element` | Phần tử lớn nhất | Mảng 1 chiều | Tìm cực trị, kỹ thuật khởi tạo biến |
| 03 | `03-min-element` | Phần tử nhỏ nhất | Mảng 1 chiều | Tìm cực trị, xử lý số âm |
| 04 | `04-count-even-odd` | Đếm số chẵn và số lẻ | Mảng 1 chiều | Phân loại dữ liệu, toán tử modulo số âm |
| 05 | `05-reverse-array` | Đảo ngược mảng | Two Pointers | Kỹ thuật hai con trỏ, hoán vị tại chỗ |
| 06 | `06-factorial` | Giai thừa $n!$ | Toán học & Số học | Vòng lặp tích lũy, giới hạn kiểu số nguyên |
| 07 | `07-fibonacci-nth` | Số Fibonacci thứ $n$ | Quy hoạch động cơ bản | Tối ưu không gian $O(1)$, lặp thay vì đệ quy |
| 08 | `08-is-prime` | Kiểm tra số nguyên tố | Số học | Tối ưu hóa kiểm tra tới $\sqrt{n}$ |
| 09 | `09-gcd` | Ước chung lớn nhất (GCD) | Thuật toán cổ điển | Thuật toán Euclid, phép chia lấy dư |
| 10 | `10-lcm` | Bội chung nhỏ nhất (LCM) | Số học | Mối liên hệ GCD-LCM, mẹo chia trước nhân sau |
| 11 | `11-sum-digits` | Tổng các chữ số | Xử lý số học | Tách từng chữ số bằng `% 10` và `/ 10` |
| 12 | `12-count-digits` | Đếm số chữ số | Xử lý số học | Xử lý số 0, số âm và vòng lặp chia |
| 13 | `13-reverse-number` | Đảo ngược số nguyên | Xử lý số học | Xây dựng lại số nguyên theo chiều ngược |
| 14 | `14-palindrome-number`| Số đối xứng | Xử lý số học | Kiểm tra tính đối xứng của dữ liệu |
| 15 | `15-power` | Lũy thừa nhanh $a^b$ | Chia để trị / Bitwise | Binary Exponentiation giảm độ phức tạp xuống $O(\log b)$ |
| 16 | `16-average-array` | Trung bình cộng của mảng | Mảng & Toán học | Ép kiểu số thực `double`, tránh phép chia nguyên |
| 17 | `17-count-vowels` | Đếm số nguyên âm | Chuỗi ký tự (String) | Duyệt chuỗi, xử lý ký tự hoa/thường |
| 18 | `18-linear-search` | Tìm kiếm tuyến tính | Thuật toán tìm kiếm | Duyệt tuần tự mảng chưa sắp xếp, trả về index |
| 19 | `19-second-largest` | Phần tử lớn thứ hai | Mảng & Xếp hạng | Kỹ thuật duy trì 2 biến cực trị phân biệt |
| 20 | `20-count-pos-neg` | Đếm số âm và số dương | Mảng 1 chiều | Phân loại dữ liệu, xử lý phần tử 0 |

---

## Hướng dẫn thiết lập khi code bằng Java

### 1. Khuôn mẫu hàm kiểm thử (Test Runner)
Bạn có thể tạo một file Java đơn giản (ví dụ `Solution.java`) với cấu trúc kiểm tra nhanh như sau:

```java
public class Solution {
    // Viết các phương thức giải thuật ở đây
    
    public static void main(String[] args) {
        // Viết các câu lệnh test để kiểm tra logic
        System.out.println("Bắt đầu kiểm thử...");
        // Ví dụ:
        // System.out.println(sumArray(new int[]{1, 2, 3, 4}) == 10 ? "PASS" : "FAIL");
    }
}
```

### 2. Các điểm cần đặc biệt lưu ý trong Java
1. **Tràn số (`Overflow`)**:
   - `int` trong Java có kích thước 32-bit (từ $-2 \cdot 10^9$ đến $+2 \cdot 10^9$).
   - Khi tính tổng mảng, giai thừa hoặc tích các số lớn, luôn cân nhắc trả về kiểu `long` (64-bit).
2. **Phép chia số nguyên**:
   - Trong Java, `5 / 2` cho ra `2` (bị mất phần thập phân). Muốn ra `2.5`, phải ép kiểu ít nhất 1 toán hạng sang `double`: `(double) 5 / 2`.
3. **Số âm với toán tử chia dư (`%`)**:
   - Trong Java, `-7 % 2` bằng `-1`, không phải `1`. Khi cần kiểm tra số chẵn, hãy so sánh `x % 2 == 0`.
4. **Trả về nhiều giá trị**:
   - Java không có kiểu tuple tích hợp sẵn như Python hay C++. Để trả về một cặp kết quả (ví dụ số chẵn, số lẻ), bạn có thể dùng mảng `int[]`: `return new int[]{evenCount, oddCount};`.

---

## Chi tiết từng bài toán

---

### Bài 01: Tổng các phần tử mảng (`01-sum-array`)

- **Mục tiêu:** Rèn luyện kỹ năng duyệt tuần tự mảng 1 chiều và tích lũy giá trị.
- **Mô tả:** Cho một mảng số nguyên `a`. Tính và trả về tổng của tất cả các phần tử có trong mảng.
- **Chữ ký hàm gợi ý (Java):**
  ```java
  public static long sumArray(int[] a)
  ```
- **Ràng buộc:**
  - Kích thước mảng: $0 \le n \le 10^5$.
  - Giá trị phần tử: $-10^9 \le a[i] \le 10^9$.
- **Ý tưởng tiếp cận:**
  1. Khởi tạo một biến tích lũy kiểu `long` với giá trị ban đầu là `0`.
  2. Sử dụng vòng lặp (vòng lặp `for` thông thường hoặc for-each) duyệt qua từng phần tử của mảng và cộng dồn vào biến tích lũy.
  3. Trả về kết quả sau khi duyệt xong.
- **Độ phức tạp:** Thời gian $O(n)$, Bộ nhớ phụ $O(1)$.
- **Trường hợp biên (Edge Cases):**
  - Mảng rỗng (`length == 0`): Trả về `0`.
  - Mảng chứa cả số âm và số dương: Phép cộng vẫn phải đúng khi triệt tiêu nhau.
- **Test cases mẫu:**
  | Đầu vào `a` | Kết quả mong đợi | Giải thích |
  |:---|:---|:---|
  | `[1, 2, 3, 4]` | `10` | $1 + 2 + 3 + 4 = 10$ |
  | `[]` | `0` | Mảng rỗng |
  | `[-1, 1]` | `0` | Số âm và dương bù trừ nhau |

---

### Bài 02: Phần tử lớn nhất (`02-max-element`)

- **Mục tiêu:** Rèn luyện kỹ năng tìm giá trị cực đại trong tập dữ liệu.
- **Mô tả:** Cho một mảng số nguyên không rỗng `a`. Tìm và trả về giá trị phần tử lớn nhất trong mảng.
- **Chữ ký hàm gợi ý (Java):**
  ```java
  public static int maxElement(int[] a)
  ```
- **Ràng buộc:**
  - $n \ge 1$.
  - $-10^9 \le a[i] \le 10^9$.
- **Ý tưởng tiếp cận:**
  1. Khởi tạo biến `max` bằng giá trị của phần tử đầu tiên: `max = a[0]`.
  2. Duyệt từ phần tử thứ hai (`index = 1`) đến cuối mảng.
  3. Nếu phần tử hiện tại `a[i] > max`, cập nhật `max = a[i]`.
  4. Trả về `max`.
- **Lưu ý bẫy thường gặp:**
  - **Không** khởi tạo `max = 0`, vì nếu mảng toàn số âm (ví dụ `[-5, -2, -9]`), kết quả trả về `0` sẽ bị sai!
- **Độ phức tạp:** Thời gian $O(n)$, Bộ nhớ phụ $O(1)$.
- **Test cases mẫu:**
  | Đầu vào `a` | Kết quả mong đợi | Ghi chú |
  |:---|:---|:---|
  | `[3, 7, 2, 9, 4]` | `9` | Mảng số dương thông thường |
  | `[-5, -2, -9]` | `-2` | Mảng toàn số âm |
  | `[42]` | `42` | Mảng chỉ có 1 phần tử |

---

### Bài 03: Phần tử nhỏ nhất (`03-min-element`)

- **Mục tiêu:** Kỹ năng tìm giá trị cực tiểu.
- **Mô tả:** Cho một mảng số nguyên không rỗng `a`. Tìm và trả về giá trị phần tử nhỏ nhất trong mảng.
- **Chữ ký hàm gợi ý (Java):**
  ```java
  public static int minElement(int[] a)
  ```
- **Ràng buộc:**
  - $n \ge 1$.
  - $-10^9 \le a[i] \le 10^9$.
- **Ý tưởng tiếp cận:**
  1. Khởi tạo biến `min = a[0]`.
  2. Duyệt từ `index = 1` đến cuối mảng.
  3. Nếu `a[i] < min`, cập nhật `min = a[i]`.
- **Độ phức tạp:** Thời gian $O(n)$, Bộ nhớ phụ $O(1)$.
- **Test cases mẫu:**
  | Đầu vào `a` | Kết quả mong đợi | Ghi chú |
  |:---|:---|:---|
  | `[3, 7, 2, 9, 4]` | `2` | Số nhỏ nhất là 2 |
  | `[-5, -2, -9]` | `-9` | Số âm nhỏ nhất là -9 |
  | `[42]` | `42` | Mảng có 1 phần tử |

---

### Bài 04: Đếm số lượng số chẵn và số lẻ (`04-count-even-odd`)

- **Mục tiêu:** Kỹ năng kiểm tra điều kiện chẵn/lẻ và phân loại dữ liệu.
- **Mô tả:** Cho một mảng số nguyên `a`. Đếm và trả về số lượng phần tử chẵn và số lượng phần tử lẻ.
- **Chữ ký hàm gợi ý (Java):**
  ```java
  public static int[] countEvenOdd(int[] a)
  ```
- **Ràng buộc:**
  - $0 \le n \le 10^5$.
  - Mảng có thể chứa số dương, số âm và số 0.
- **Ý tưởng tiếp cận:**
  1. Dùng 2 biến đếm `evenCount = 0` và `oddCount = 0`.
  2. Duyệt qua từng số `x` trong mảng:
     - Trong Java, để an toàn với số âm, ta kiểm tra: `if (x % 2 == 0) evenCount++; else oddCount++;`.
  3. Trả về mảng 2 phần tử: `new int[]{evenCount, oddCount}`.
- **Lưu ý bẫy Java:**
  - Số `0` được tính là số chẵn.
  - Số lẻ âm như `-3 % 2` trong Java sẽ trả về `-1`, do đó không được viết `if (x % 2 == 1)` vì sẽ bỏ sót các số lẻ âm.
- **Độ phức tạp:** Thời gian $O(n)$, Bộ nhớ phụ $O(1)$.
- **Test cases mẫu:**
  | Đầu vào `a` | Kết quả mong đợi | Giải thích |
  |:---|:---|:---|
  | `[1, 2, 3, 4, 5]` | `[2, 3]` | 2 số chẵn (2, 4), 3 số lẻ (1, 3, 5) |
  | `[2, 4, 6]` | `[3, 0]` | Toàn bộ là số chẵn |
  | `[-2, -3, 0]` | `[2, 1]` | -2 và 0 là chẵn; -3 là lẻ |

---

### Bài 05: Đảo ngược mảng tại chỗ (`05-reverse-array`)

- **Mục tiêu:** Làm quen với kỹ thuật Hai con trỏ (**Two Pointers**) và thao tác mảng in-place (không tạo mảng mới).
- **Mô tả:** Đảo ngược thứ tự các phần tử của mảng `a` tại chỗ mà không sử dụng mảng phụ.
- **Chữ ký hàm gợi ý (Java):**
  ```java
  public static void reverseArray(int[] a)
  ```
- **Ràng buộc:**
  - $0 \le n \le 10^5$.
- **Ý tưởng tiếp cận:**
  1. Đặt 2 con trỏ: `left = 0` (đầu mảng) và `right = a.length - 1` (cuối mảng).
  2. Khi `left < right`:
     - Hoán đổi giá trị giữa `a[left]` và `a[right]` thông qua biến tạm `temp`.
     - Tăng `left++`.
     - Giảm `right--`.
- **Độ phức tạp:** Thời gian $O(n)$, Bộ nhớ phụ $O(1)$.
- **Test cases mẫu:**
  | Đầu vào `a` | Kết quả sau khi đảo | Ghi chú |
  |:---|:---|:---|
  | `[1, 2, 3]` | `[3, 2, 1]` | Mảng có độ dài lẻ |
  | `[1, 2, 3, 4]` | `[4, 3, 2, 1]` | Mảng có độ dài chẵn |
  | `[5]` | `[5]` | Mảng có 1 phần tử |
  | `[]` | `[]` | Mảng rỗng |

---

### Bài 06: Tính giai thừa $n!$ (`06-factorial`)

- **Mục tiêu:** Rèn luyện vòng lặp nhân dồn và kiểm soát giới hạn tràn số nguyên.
- **Mô tả:** Cho số nguyên $n \ge 0$. Tính giá trị giai thừa $n! = 1 \times 2 \times 3 \times \dots \times n$. Quy ước $0! = 1$.
- **Chữ ký hàm gợi ý (Java):**
  ```java
  public static long factorial(int n)
  ```
- **Ràng buộc:**
  - $0 \le n \le 20$.
- **Ý tưởng tiếp cận:**
  1. Khởi tạo `result = 1L` (kiểu `long`).
  2. Chạy vòng lặp từ `i = 2` đến `n`, mỗi bước gán `result *= i`.
  3. Trả về `result`.
- **Lưu ý bẫy Java:**
  - Với $n \ge 13$, $n!$ sẽ vượt quá $2 \cdot 10^9$ (giới hạn của `int`). Do đó bắt buộc phải dùng kiểu `long`.
  - Với $n \le 20$, kết quả tối đa là $20! \approx 2.43 \cdot 10^{18}$, vừa vặn trong kiểu `long` của Java (tối đa $\approx 9.22 \cdot 10^{18}$).
- **Độ phức tạp:** Thời gian $O(n)$, Bộ nhớ phụ $O(1)$.
- **Test cases mẫu:**
  | Đầu vào `n` | Kết quả mong đợi | Ghi chú |
  |:---|:---|:---|
  | `0` | `1` | Quy ước toán học $0! = 1$ |
  | `5` | `120` | $1 \times 2 \times 3 \times 4 \times 5 = 120$ |
  | `10` | `3628800` | |
  | `20` | `2432902008176640000` | Kiểm tra độ chính xác kiểu `long` |

---

### Bài 07: Số Fibonacci thứ $n$ (`07-fibonacci-nth`)

- **Mục tiêu:** Hiểu rõ sự khác biệt giữa thuật toán đệ quy $O(2^n)$ và thuật toán lặp tối ưu $O(n)$ không gian $O(1)$.
- **Mô tả:** Dãy số Fibonacci được định nghĩa:
  - $F(0) = 0$
  - $F(1) = 1$
  - $F(n) = F(n-1) + F(n-2)$ với mọi $n \ge 2$.
  Cho số nguyên $n$, tính $F(n)$.
- **Chữ ký hàm gợi ý (Java):**
  ```java
  public static long fibonacci(int n)
  ```
- **Ràng buộc:**
  - $0 \le n \le 90$.
- **Ý tưởng tiếp cận:**
  1. Nếu $n == 0$ trả về `0`. Nếu $n == 1$ trả về `1`.
  2. Khởi tạo 2 biến `prev2 = 0L` và `prev1 = 1L`.
  3. Lặp từ `i = 2` đến `n`:
     - `current = prev1 + prev2`
     - Cập nhật: `prev2 = prev1`, `prev1 = current`
  4. Trả về `prev1`.
- **Độ phức tạp:** Thời gian $O(n)$, Bộ nhớ phụ $O(1)$.
- **Test cases mẫu:**
  | Đầu vào `n` | Kết quả mong đợi |
  |:---|:---|
  | `0` | `0` |
  | `1` | `1` |
  | `10` | `55` |
  | `90` | `2880067194370816120` |

---

### Bài 08: Kiểm tra số nguyên tố (`08-is-prime`)

- **Mục tiêu:** Kỹ năng tối ưu hóa bài toán số học từ $O(n)$ xuống $O(\sqrt{n})$.
- **Mô tả:** Cho số nguyên $n$. Kiểm tra xem $n$ có phải là số nguyên tố hay không (trả về `boolean`).
- **Chữ ký hàm gợi ý (Java):**
  ```java
  public static boolean isPrime(long n)
  ```
- **Ràng buộc:**
  - $n$ có thể lên tới $10^{18}$ (kiểu `long`).
- **Ý tưởng tiếp cận:**
  1. Số nguyên tố là số nguyên lớn hơn 1 chỉ có 2 ước dương là 1 và chính nó.
  2. Do đó: Nếu $n \le 1 \rightarrow$ trả về `false`.
  3. Nếu $n == 2$ hoặc $n == 3 \rightarrow$ trả về `true`.
  4. Nếu $n \% 2 == 0$ hoặc $n \% 3 == 0 \rightarrow$ trả về `false`.
  5. Cho vòng lặp $i$ chạy từ $5$ và tăng bước nhảy $6$ (kiểm tra các số dạng $6k \pm 1$):
     - Điều kiện dừng: $i \times i \le n$.
     - Nếu $n \% i == 0$ hoặc $n \% (i + 2) == 0 \rightarrow$ trả về `false`.
  6. Nếu không tìm thấy ước nào, trả về `true`.
- **Lưu ý bẫy:**
  - Kiểm tra `i * i <= n` khi $i$ kiểu `long` có thể bị tràn nếu $i > 3 \cdot 10^9$. Để an toàn, có thể dùng `i <= n / i`.
- **Độ phức tạp:** Thời gian $O(\sqrt{n})$, Bộ nhớ phụ $O(1)$.
- **Test cases mẫu:**
  | Đầu vào `n` | Kết quả mong đợi | Giải thích |
  |:---|:---|:---|
  | `1` | `false` | Số 1 không phải số nguyên tố |
  | `2` | `true` | Số nguyên tố chẵn duy nhất |
  | `17` | `true` | Số nguyên tố lẻ |
  | `18` | `false` | Chia hết cho 2, 3, 6, 9 |
  | `-7` | `false` | Số âm không phải số nguyên tố |

---

### Bài 09: Ước chung lớn nhất — GCD (`09-gcd`)

- **Mục tiêu:** Hiểu và cài đặt thuật toán Euclid kinh điển.
- **Mô tả:** Cho 2 số nguyên không âm $a$ và $b$. Tìm ước chung lớn nhất của chúng.
- **Chữ ký hàm gợi ý (Java):**
  ```java
  public static long gcd(long a, long b)
  ```
- **Ràng buộc:**
  - $0 \le a, b \le 10^{18}$.
- **Ý tưởng tiếp cận (Thuật toán Euclid):**
  1. Sử dụng tính chất: $\gcd(a, b) = \gcd(b, a \pmod b)$.
  2. Lặp chừng nào $b \ne 0$:
     - Gán tạm `temp = a % b`.
     - `a = b`.
     - `b = temp`.
  3. Khi $b = 0$, kết quả chính là $a$.
- **Độ phức tạp:** Thời gian $O(\log(\min(a, b)))$, Bộ nhớ phụ $O(1)$.
- **Test cases mẫu:**
  | Đầu vào `(a, b)` | Kết quả mong đợi | Ghi chú |
  |:---|:---|:---|
  | `(12, 18)` | `6` | Ước chung lớn nhất của 12 và 18 là 6 |
  | `(5, 0)` | `5` | Ước chung của số $a$ và 0 là $a$ |
  | `(7, 13)` | `1` | Hai số nguyên tố cùng nhau |

---

### Bài 10: Bội chung nhỏ nhất — LCM (`10-lcm`)

- **Mục tiêu:** Vận dụng mối liên hệ giữa GCD và LCM, kiểm soát thứ tự phép toán để tránh tràn số.
- **Mô tả:** Cho hai số nguyên dương $a$ và $b$. Tìm bội chung nhỏ nhất của chúng.
- **Chữ ký hàm gợi ý (Java):**
  ```java
  public static long lcm(long a, long b)
  ```
- **Ràng buộc:**
  - $1 \le a, b \le 10^9$.
- **Ý tưởng tiếp cận:**
  - Công thức toán học: $\text{lcm}(a, b) = \frac{a \times b}{\gcd(a, b)}$.
  - **Mẹo tránh tràn số:** Nếu tính $a \times b$ trước, tích có thể lên tới $10^{18}$ và dễ bị tràn nếu dữ liệu lớn hơn một chút. Hãy thực hiện phép chia trước:
    $$\text{lcm}(a, b) = \left(\frac{a}{\gcd(a, b)}\right) \times b$$
- **Độ phức tạp:** Thời gian $O(\log(\min(a, b)))$, Bộ nhớ phụ $O(1)$.
- **Test cases mẫu:**
  | Đầu vào `(a, b)` | Kết quả mong đợi |
  |:---|:---|
  | `(4, 6)` | `12` |
  | `(3, 5)` | `15` |
  | `(6, 6)` | `6` |

---

### Bài 11: Tổng các chữ số (`11-sum-digits`)

- **Mục tiêu:** Kỹ năng trích xuất từng chữ số của một số nguyên qua hệ thập phân.
- **Mô tả:** Cho một số nguyên $n$. Tính và trả về tổng các chữ số của $|n|$.
- **Chữ ký hàm gợi ý (Java):**
  ```java
  public static int sumDigits(long n)
  ```
- **Ràng buộc:**
  - $-10^{18} \le n \le 10^{18}$.
- **Ý tưởng tiếp cận:**
  1. Lấy giá trị tuyệt đối của $n$: Nếu $n < 0$, gán $n = -n$.
  2. Khởi tạo `sum = 0`.
  3. Lặp chừng nào $n > 0$:
     - Lấy chữ số hàng đơn vị: `digit = (int) (n % 10)`.
     - Cộng `digit` vào `sum`.
     - Bỏ chữ số hàng đơn vị: `n = n / 10`.
  4. Trả về `sum`.
- **Test cases mẫu:**
  | Đầu vào `n` | Kết quả mong đợi | Giải thích |
  |:---|:---|:---|
  | `123` | `6` | $1 + 2 + 3 = 6$ |
  | `0` | `0` | Số 0 có tổng chữ số là 0 |
  | `-99` | `18` | Xét trị tuyệt đối: $9 + 9 = 18$ |

---

### Bài 12: Đếm số chữ số (`12-count-digits`)

- **Mục tiêu:** Xử lý điều kiện biên với số 0 và số âm trong bài toán tách chữ số.
- **Mô tả:** Cho số nguyên $n$. Đếm số lượng chữ số của $n$. Quy ước số `0` có 1 chữ số.
- **Chữ ký hàm gợi ý (Java):**
  ```java
  public static int countDigits(long n)
  ```
- **Ràng buộc:**
  - $-10^{18} \le n \le 10^{18}$.
- **Ý tưởng tiếp cận:**
  1. Nếu $n == 0$, lập tức trả về `1`.
  2. Đổi dấu nếu $n < 0$.
  3. Dùng biến `count = 0`. Lặp chia `n /= 10` cho đến khi `n == 0`, mỗi lần tăng `count++`.
- **Độ phức tạp:** Thời gian $O(\text{số chữ số}) = O(\log_{10} |n|)$, Bộ nhớ phụ $O(1)$.
- **Test cases mẫu:**
  | Đầu vào `n` | Kết quả mong đợi | Ghi chú |
  |:---|:---|:---|
  | `123` | `3` | Có 3 chữ số |
  | `0` | `1` | Trường hợp biên quan trọng |
  | `-4567` | `4` | Số âm 4 chữ số |

---

### Bài 13: Đảo ngược số nguyên (`13-reverse-number`)

- **Mục tiêu:** Kỹ năng dựng lại số nguyên theo chiều ngược từ các chữ số đã tách.
- **Mô tả:** Cho một số nguyên không âm $n$. Đảo ngược thứ tự các chữ số của nó. Ví dụ: $123 \rightarrow 321$, $120 \rightarrow 21$.
- **Chữ ký hàm gợi ý (Java):**
  ```java
  public static long reverseNumber(long n)
  ```
- **Ràng buộc:**
  - $0 \le n \le 10^{18}$.
- **Ý tưởng tiếp cận:**
  1. Khởi tạo `reversed = 0L`.
  2. Lặp khi $n > 0$:
     - Lấy chữ số cuối: `digit = n % 10`.
     - Đẩy chữ số vào đuôi số mới: `reversed = reversed * 10 + digit`.
     - Giảm $n$: `n = n / 10`.
  3. Trả về `reversed`.
- **Độ phức tạp:** Thời gian $O(\log_{10} n)$, Bộ nhớ phụ $O(1)$.
- **Test cases mẫu:**
  | Đầu vào `n` | Kết quả mong đợi | Ghi chú |
  |:---|:---|:---|
  | `123` | `321` | |
  | `120` | `21` | Chữ số 0 ở đầu tự động triệt tiêu trong hệ thập phân |
  | `0` | `0` | |

---

### Bài 14: Kiểm tra số đối xứng (`14-palindrome-number`)

- **Mục tiêu:** Kết hợp thuật toán đảo số để kiểm tra đối xứng.
- **Mô tả:** Cho số nguyên $n$. Kiểm tra xem $n$ có đọc xuôi và ngược giống nhau hay không. Quy ước: Số âm luôn **không** đối xứng (vì có dấu `-`).
- **Chữ ký hàm gợi ý (Java):**
  ```java
  public static boolean isPalindrome(long n)
  ```
- **Ý tưởng tiếp cận:**
  1. Nếu $n < 0 \rightarrow$ trả về `false`.
  2. Nếu $n$ tận cùng là chữ số 0 (và $n \ne 0$) $\rightarrow$ trả về `false`.
  3. Lưu lại bản sao số gốc: `original = n`.
  4. Đảo ngược số $n$ (như bài 13) được `reversed`.
  5. So sánh `reversed == original`.
- **Độ phức tạp:** Thời gian $O(\log_{10} n)$, Bộ nhớ phụ $O(1)$.
- **Test cases mẫu:**
  | Đầu vào `n` | Kết quả mong đợi | Giải thích |
  |:---|:---|:---|
  | `121` | `true` | Đọc xuôi và ngược đều là 121 |
  | `123` | `false` | Đảo ngược là 321 khác 123 |
  | `-121` | `false` | Đảo ngược thành 121-, không đối xứng |
  | `0` | `true` | Số 0 đối xứng |

---

### Bài 15: Lũy thừa nhanh $a^b$ (`15-power`)

- **Mục tiêu:** Hiểu thuật toán Lũy thừa nhị phân (**Binary Exponentiation**) để giảm độ phức tạp từ $O(b)$ xuống $O(\log b)$.
- **Mô tả:** Cho số nguyên $a$ và số mũ không âm $b$. Tính giá trị $a^b$.
- **Chữ ký hàm gợi ý (Java):**
  ```java
  public static long power(long a, long b)
  ```
- **Ràng buộc:**
  - $b \ge 0$, kết quả vừa trong kiểu `long`.
- **Ý tưởng tiếp cận (Lũy thừa nhị phân):**
  - Ta có tính chất:
    - Nếu $b$ chẵn: $a^b = (a^2)^{b/2}$.
    - Nếu $b$ lẻ: $a^b = a \times a^{b-1}$.
  - Thuật toán vòng lặp:
    1. `result = 1L`, `base = a`.
    2. Chừng nào $b > 0$:
       - Nếu $b$ lẻ (`(b & 1) == 1`): `result *= base`.
       - `base *= base`.
       - `b >>= 1` (chia đôi $b$).
    3. Trả về `result`.
- **Độ phức tạp:** Thời gian $O(\log b)$, Bộ nhớ phụ $O(1)$.
- **Test cases mẫu:**
  | Đầu vào `(a, b)` | Kết quả mong đợi | Ghi chú |
  |:---|:---|:---|
  | `(2, 10)` | `1024` | $2^{10} = 1024$ |
  | `(5, 0)` | `1` | Bất kỳ số nào mũ 0 cũng bằng 1 |
  | `(3, 3)` | `27` | $3^3 = 27$ |

---

### Bài 16: Trung bình cộng của mảng (`16-average-array`)

- **Mục tiêu:** Xử lý ép kiểu dữ liệu số thực trong Java và tránh mất dữ liệu do phép chia nguyên.
- **Mô tả:** Cho mảng số nguyên không rỗng `a`. Tính và trả về giá trị trung bình cộng của các phần tử dưới dạng số thực (`double`).
- **Chữ ký hàm gợi ý (Java):**
  ```java
  public static double average(int[] a)
  ```
- **Ràng buộc:**
  - $n \ge 1$.
- **Ý tưởng tiếp cận:**
  1. Khởi tạo `long sum = 0L` để chứa tổng (tránh tràn số khi mảng có nhiều phần tử lớn).
  2. Duyệt qua mảng và cộng từng phần tử vào `sum`.
  3. Trả về `(double) sum / a.length`.
- **Lưu ý quan trọng trong Java:**
  - Phải ép kiểu `(double) sum` trước khi chia cho `a.length`. Nếu viết `sum / a.length` rồi mới gán sang `double`, kết quả đã bị cắt cụt phần thập phân trước khi ép kiểu.
- **Độ phức tạp:** Thời gian $O(n)$, Bộ nhớ phụ $O(1)$.
- **Test cases mẫu:**
  | Đầu vào `a` | Kết quả mong đợi | Ghi chú |
  |:---|:---|:---|
  | `[1, 2, 3, 4]` | `2.5` | Tổng = 10, độ dài = 4 $\rightarrow$ 2.5 |
  | `[5]` | `5.0` | 1 phần tử |
  | `[-2, 2]` | `0.0` | Tổng = 0 |

---

### Bài 17: Đếm số nguyên âm trong chuỗi (`17-count-vowels`)

- **Mục tiêu:** Kỹ năng thao tác với chuỗi (`String`) và ký tự (`char`) trong Java.
- **Mô tả:** Cho một chuỗi ký tự `s`. Đếm số lượng ký tự nguyên âm (`a, e, i, o, u`) xuất hiện trong chuỗi (không phân biệt chữ hoa hay chữ thường).
- **Chữ ký hàm gợi ý (Java):**
  ```java
  public static int countVowels(String s)
  ```
- **Ý tưởng tiếp cận:**
  1. Khởi tạo `count = 0`.
  2. Duyệt qua từng ký tự `c` trong chuỗi `s` (hoặc dùng `s.toCharArray()`):
     - Chuyển `c` về chữ thường: `char lower = Character.toLowerCase(c);`.
     - Kiểm tra nếu `lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u'`, tăng `count++`.
  3. Trả về `count`.
- **Độ phức tạp:** Thời gian $O(n)$, Bộ nhớ phụ $O(1)$.
- **Test cases mẫu:**
  | Đầu vào `s` | Kết quả mong đợi | Giải thích |
  |:---|:---|:---|
  | `"hello"` | `2` | 'e' và 'o' |
  | `"XYZ"` | `0` | Không có nguyên âm |
  | `"AeIoU"` | `5` | Toàn bộ 5 nguyên âm hoa/thường |
  | `""` | `0` | Chuỗi rỗng |

---

### Bài 18: Tìm kiếm tuyến tính (`18-linear-search`)

- **Mục tiêu:** Làm quen với thuật toán tìm kiếm cơ bản nhất trên dữ liệu chưa sắp xếp.
- **Mô tả:** Cho mảng số nguyên `a` và giá trị cần tìm `target`. Trả về **chỉ số (index) đầu tiên** mà `target` xuất hiện trong mảng. Nếu không tìm thấy, trả về `-1`.
- **Chữ ký hàm gợi ý (Java):**
  ```java
  public static int linearSearch(int[] a, int target)
  ```
- **Ý tưởng tiếp cận:**
  1. Duyệt từ `i = 0` đến `a.length - 1`.
  2. Tại mỗi vị trí, nếu `a[i] == target`, trả về ngay lập tức chỉ số `i`.
  3. Nếu duyệt hết toàn bộ mảng mà không gặp `target`, trả về `-1`.
- **Độ phức tạp:** Thời gian $O(n)$, Bộ nhớ phụ $O(1)$.
- **Test cases mẫu:**
  | Đầu vào `(a, target)` | Kết quả mong đợi | Ghi chú |
  |:---|:---|:---|
  | `([4, 2, 7, 1], 7)` | `2` | Phần tử 7 nằm ở index 2 |
  | `([4, 2, 7, 1], 9)` | `-1` | Số 9 không tồn tại trong mảng |
  | `([], 1)` | `-1` | Mảng rỗng |
  | `([5, 5, 5], 5)` | `0` | Trả về index đầu tiên tìm thấy |

---

### Bài 19: Phần tử lớn thứ hai (`19-second-largest`)

- **Mục tiêu:** Kỹ năng phân tích thứ bậc và cập nhật nhiều trạng thái đồng thời chỉ trong 1 lần duyệt.
- **Mô tả:** Cho mảng số nguyên `a`. Tìm và trả về giá trị lớn thứ hai trong mảng. Lưu ý: Giá trị lớn thứ hai phải **khác** giá trị lớn nhất. Nếu mảng không tồn tại giá trị lớn thứ hai thỏa mãn (ví dụ mảng ít hơn 2 phần tử, hoặc mọi phần tử đều bằng nhau), trả về `-1`.
- **Chữ ký hàm gợi ý (Java):**
  ```java
  public static int secondLargest(int[] a)
  ```
- **Ý tưởng tiếp cận:**
  1. Sử dụng 2 biến: `first = Integer.MIN_VALUE` và `second = Integer.MIN_VALUE`.
  2. Duyệt qua từng số `x` trong mảng:
     - Nếu `x > first`:
       - `second = first`
       - `first = x`
     - Ngược lại nếu `x < first` và `x > second`:
       - `second = x`
  3. Sau vòng lặp:
     - Nếu `second == Integer.MIN_VALUE` (nghĩa là không tìm thấy số nào nhỏ hơn `first`), trả về `-1`.
     - Ngược lại trả về `second`.
- **Độ phức tạp:** Thời gian $O(n)$, Bộ nhớ phụ $O(1)$ (chỉ 1 lần duyệt mảng).
- **Test cases mẫu:**
  | Đầu vào `a` | Kết quả mong đợi | Giải thích |
  |:---|:---|:---|
  | `[3, 1, 4, 1, 5]` | `4` | Số lớn nhất là 5, lớn nhì là 4 |
  | `[5, 5, 4]` | `4` | 5 xuất hiện 2 lần, số lớn nhì phân biệt là 4 |
  | `[7, 7, 7]` | `-1` | Tất cả đều bằng nhau, không có số lớn nhì |
  | `[10]` | `-1` | Chỉ có 1 phần tử |

---

### Bài 20: Đếm số dương và số âm (`20-count-pos-neg`)

- **Mục tiêu:** Kỹ năng duyệt và lọc theo nhiều phân loại, xử lý phần tử trung tính (số 0).
- **Mô tả:** Cho mảng số nguyên `a`. Đếm số lượng phần tử dương ($x > 0$) và số lượng phần tử âm ($x < 0$). Các phần tử bằng `0` sẽ bị bỏ qua.
- **Chữ ký hàm gợi ý (Java):**
  ```java
  public static int[] countPosNeg(int[] a)
  ```
- **Ý tưởng tiếp cận:**
  1. Khởi tạo 2 biến đếm: `posCount = 0` và `negCount = 0`.
  2. Duyệt qua từng phần tử `x`:
     - Nếu `x > 0`: tăng `posCount++`.
     - Nếu `x < 0`: tăng `negCount++`.
     - Nếu `x == 0`: bỏ qua, không đếm.
  3. Trả về mảng 2 phần tử: `new int[]{posCount, negCount}`.
- **Độ phức tạp:** Thời gian $O(n)$, Bộ nhớ phụ $O(1)$.
- **Test cases mẫu:**
  | Đầu vào `a` | Kết quả mong đợi | Giải thích |
  |:---|:---|:---|
  | `[-1, 0, 2, 3, -4]` | `[2, 2]` | 2 số dương (2, 3), 2 số âm (-1, -4), số 0 bỏ qua |
  | `[0, 0]` | `[0, 0]` | Toàn số 0 |
  | `[1, 5, 10]` | `[3, 0]` | Toàn số dương |
  | `[]` | `[0, 0]` | Mảng rỗng |

---

## Lời khuyên khi bắt đầu luyện tập với Java

1. **Tạo file theo cấu trúc bài:** Bạn có thể tạo một package hoặc thư mục `src/` và đặt tên các file theo số bài:
   - `Problem01SumArray.java`
   - `Problem02MaxElement.java`
   - ...
2. **Tự tay viết test cases:** Luôn kiểm tra tối thiểu 3 trường hợp:
   - Một trường hợp dữ liệu thông thường.
   - Một trường hợp dữ liệu nhỏ nhất / rỗng / số 0.
   - Một trường hợp số âm hoặc số lớn tiềm ẩn nguy cơ tràn số.
3. **Phân tích độ phức tạp:** Sau khi code xong một bài, hãy tự đặt câu hỏi: "Thuật toán này chạy mất bao nhiêu thời gian và tốn bao nhiêu bộ nhớ phụ?". Cố gắng đạt được độ phức tạp thời gian $O(n)$ hoặc $O(1)$ như đã định hướng ở từng bài.
