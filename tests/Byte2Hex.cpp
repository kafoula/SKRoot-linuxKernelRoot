#include <iostream>
#include <cstddef>
#include <string>
const char HEX[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                      '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
std::string bytesToHexString(const std::byte *input, size_t length) {
  std::string str;
  str.reserve(length << 1);
  for (size_t i = 0; i < length; ++i) {
    int t = static_cast<int>(input[i]);
    int a = t / 16;
    int b = t % 16;
    str.append(1, HEX[a]);
    str.append(1, HEX[b]);
  }
  return str;
}
int main() {
  const std::byte input[] = {std::byte{0x12}, std::byte{0x34}, std::byte{0x56}};
  size_t length = sizeof(input) / sizeof(input[0]);

  std::string output = bytesToHexString(input, length);
  std::cout << output << std::endl;
}