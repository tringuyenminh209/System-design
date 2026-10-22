# 97 - Trie | Cây tiền tố (insert / search / starts_with)
# Đề: Cấu trúc lưu tập chuỗi, hỗ trợ thêm, tìm chính xác và tìm theo tiền tố.
# Ràng buộc: Chuỗi bất kỳ.
# Ý tưởng: Mỗi nút là dict con theo ký tự; khóa "$" đánh dấu kết thúc từ.
# Độ phức tạp: Time O(độ dài từ) mỗi thao tác / Space O(tổng ký tự).
# Thực tế: Gợi ý gõ, autocomplete, kiểm tra tiền tố.


class Trie:
    def __init__(self):
        self.root = {}

    def insert(self, w):
        n = self.root
        for c in w:
            n = n.setdefault(c, {})
        n["$"] = True   # đánh dấu kết thúc từ

    def _walk(self, w):
        n = self.root
        for c in w:
            if c not in n:
                return None
            n = n[c]
        return n

    def search(self, w):
        n = self._walk(w)
        return bool(n) and "$" in n

    def starts_with(self, p):
        return self._walk(p) is not None


if __name__ == "__main__":
    # Test case
    t = Trie()
    t.insert("apple")
    assert t.search("apple")
    assert not t.search("app")
    assert t.starts_with("app")
    assert not t.starts_with("bpp")

    print("OK")
