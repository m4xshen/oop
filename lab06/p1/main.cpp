#include <cctype>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char **argv) {
  std::ifstream file(argv[1]);
  std::ofstream out(argv[2]);
  std::string buffer;

  int words = 0;
  int sentences = 0;
  int max_sent_len = 0;
  int sent_len = 0;
  int max_word_len = 0;
  std::vector<std::string> max_words;

  while (file >> buffer) {
    // remove non word character
    std::string word;
    for (char c : buffer)
      if (isalpha(c) || c == '\'')
        word.push_back(c);

    if (word.length() > max_word_len) {
      max_word_len = word.length();
      max_words.clear();
    }

    if (word.length() == max_word_len)
      max_words.push_back(word);

    sent_len++;
    if (buffer.back() == '.') {
      if (sent_len > max_sent_len) max_sent_len = sent_len;
      sent_len = 0;
      sentences++;
    }
    words++;
  }
  file.close();

  out << "The number of words is: " << words << "\n";
  out << "The number of sentences is: " << sentences << "\n";
  out << "The longest sentence has a length of: " << max_sent_len << "\n";
  out << "The longest word has a length of: " << max_word_len << "\n";
  out << "The longest words are: ";
  for (std::string word : max_words) {
    out << word << " ";
  }
  out.close();

  return 0;
}
