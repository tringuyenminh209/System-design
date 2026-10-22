# 50 - GCD of Array | Ước chung lớn nhất của cả mảng
# Đề: Tìm ước chung lớn nhất của mọi phần tử trong mảng.
# Ràng buộc: Mảng không rỗng.
# Ý tưởng: gcd tích lũy qua reduce.
# Độ phức tạp: Time O(n log(max)) / Space O(1).
# Thực tế: Rút gọn dãy tỉ lệ, tìm bước chung.

from math import gcd
from functools import reduce


def gcd_array(a):
    return reduce(gcd, a)


if __name__ == "__main__":
    # Test case
    assert gcd_array([12, 18, 24]) == 6
    assert gcd_array([7]) == 7
    assert gcd_array([5, 10, 15]) == 5

    print("OK")
