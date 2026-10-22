# 78 - Jump Game | Có tới được ô cuối không
# Đề: Mỗi ô cho bước nhảy tối đa a[i]; xuất phát ô 0, có tới ô cuối?
# Ràng buộc: Phần tử >= 0.
# Ý tưởng: Greedy - theo dõi chỉ số xa nhất "reach" có thể tới.
# Độ phức tạp: Time O(n) / Space O(1).
# Thực tế: Tư duy tham lam, cập nhật tầm với tối đa.


def can_jump(a):
    reach = 0
    for i, step in enumerate(a):
        if i > reach:
            return False
        reach = max(reach, i + step)
    return True


if __name__ == "__main__":
    # Test case
    assert can_jump([2, 3, 1, 1, 4])
    assert not can_jump([3, 2, 1, 0, 4])
    assert can_jump([0])

    print("OK")
